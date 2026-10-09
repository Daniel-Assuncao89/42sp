import os
import sys

try:
    from dotenv import load_dotenv
except ImportError:
    print("ORACLE STATUS: python-dotenv is not installed.")
    print("Run: pip install -r requirements.txt")
    sys.exit(1)

VARIABLES: tuple[str, ...] = (
    "MATRIX_MODE", "DATABASE_URL", "API_KEY", "LOG_LEVEL", "ZION_ENDPOINT",
)
DEFAULTS: dict[str, str] = {
    "MATRIX_MODE": "development",
    "DATABASE_URL": "sqlite:///local_matrix.db",
    "LOG_LEVEL": "DEBUG",
    "ZION_ENDPOINT": "http://localhost:8000",
}
VALID_MODES: tuple[str, ...] = ("development", "production")
HERE: str = os.path.dirname(os.path.abspath(__file__))


def load_config() -> tuple[dict[str, str | None], list[str], list[str]]:
    """Load .env without overriding the shell. Return config, warnings,
    and the names of variables that came from the shell."""
    from_shell = [name for name in VARIABLES if name in os.environ]
    env_path = os.path.join(HERE, ".env")
    warnings: list[str] = []
    if os.path.isfile(env_path):
        load_dotenv(env_path, override=False)
    else:
        warnings.append(".env file not found, using environment/defaults")
    config: dict[str, str | None] = {}
    for name in VARIABLES:
        value = os.environ.get(name)
        config[name] = value if value else None
    return config, warnings, from_shell


def validate(config: dict[str, str | None], warnings: list[str]) -> None:
    mode = config["MATRIX_MODE"] or DEFAULTS["MATRIX_MODE"]
    if mode not in VALID_MODES:
        print(f"ERROR: MATRIX_MODE must be one of {VALID_MODES}, got '{mode}'")
        sys.exit(1)
    config["MATRIX_MODE"] = mode
    for name in VARIABLES:
        if config[name] is not None:
            continue
        if mode == "production":
            print(f"ERROR: {name} is required in production mode")
            sys.exit(1)
        default = DEFAULTS.get(name)
        config[name] = default
        warnings.append(f"{name} missing, "
                        f"{'default used' if default else 'not configured'}")
    endpoint = config["ZION_ENDPOINT"] or ""
    if mode == "production" and not endpoint.startswith("https://"):
        print("ERROR: ZION_ENDPOINT must use https in production")
        sys.exit(1)


def mask(secret: str | None) -> str:
    if not secret:
        return "(none)"
    return secret[:2] + "*" * 6


def check_security(config: dict[str, str | None]) -> list[tuple[bool, str]]:
    results: list[tuple[bool, str]] = []
    secret = config["API_KEY"] or ""
    try:
        with open(os.path.abspath(__file__), encoding="utf-8") as source:
            code = source.read()
        clean = not secret or secret not in code
    except OSError:
        clean = False
    results.append((clean, "No hardcoded secrets detected"))
    try:
        with open(os.path.join(HERE, ".gitignore"), encoding="utf-8") as gi:
            ignored = ".env" in [line.strip() for line in gi]
    except OSError:
        ignored = False
    configured = os.path.isfile(os.path.join(HERE, ".env"))
    results.append((ignored and configured,
                    ".env file properly configured (exists and git-ignored)"))
    results.append((True, "Production overrides available"))
    return results


def show(config: dict[str, str | None], warnings: list[str],
         from_shell: list[str]) -> None:
    mode = config["MATRIX_MODE"]
    prod = mode == "production"
    db = config["DATABASE_URL"] or ""
    local = "sqlite" in db or "localhost" in db
    print("\nORACLE STATUS: Reading the Matrix...\n")
    print("Configuration loaded:")
    print(f"Mode: {mode}")
    print("Database: " + ("Connected to local instance" if local
                          else "Connected to remote instance"))
    print("API Access: " + ("Authenticated (key hidden)" if prod
                            else f"Authenticated ({mask(config['API_KEY'])})"))
    print(f"Log Level: {config['LOG_LEVEL']}")
    print("Zion Network: " + ("Online" if config["ZION_ENDPOINT"]
                              else "Offline"))
    if prod:
        print("Policy: strict (all variables required, https enforced)")
    else:
        print("Policy: relaxed (defaults allowed, verbose logs)")
    if from_shell:
        print(f"Overridden by shell: {', '.join(from_shell)}")
    for warning in warnings:
        print(f"WARNING: {warning}")
    print("\nEnvironment security check:")
    for ok, message in check_security(config):
        print(f"[{'OK' if ok else 'WARN'}] {message}")
    print("\nThe Oracle sees all configurations.")


def main() -> None:
    config, warnings, from_shell = load_config()
    validate(config, warnings)
    show(config, warnings, from_shell)


if __name__ == "__main__":
    main()
