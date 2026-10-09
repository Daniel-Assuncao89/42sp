import sys
import importlib
from importlib import metadata
from typing import Any

PACKAGES: dict[str, str] = {
    "pandas": "Data manipulation ready",
    "numpy": "Numerical computation ready",
    "matplotlib": "Visualization ready",
}
N_POINTS: int = 1000
OUTPUT_FILE: str = "matrix_analysis.png"


def check_dependencies() -> tuple[dict[str, Any], list[str]]:
    """Try to import each package; return loaded modules and missing names."""
    loaded: dict[str, Any] = {}
    missing: list[str] = []
    print("Checking dependencies:")
    for name, description in PACKAGES.items():
        try:
            loaded[name] = importlib.import_module(name)
            version = metadata.version(name)
            print(f"[OK] {name} ({version}) - {description}")
        except ImportError:
            missing.append(name)
            print(f"[MISSING] {name} - {description.replace(' ready', '')}")
        except metadata.PackageNotFoundError:
            print(f"[OK] {name} (unknown version) - {description}")
    return loaded, missing


def print_install_help(missing: list[str]) -> None:
    pkgs = " ".join(missing)
    print(f"\nMissing dependencies: {', '.join(missing)}")
    print("\nInstall with pip:")
    print("  pip install -r requirements.txt")
    print(f"  (or: pip install {pkgs})")
    print("\nInstall with Poetry:")
    print("  poetry install")
    print(f"  (or: poetry add {pkgs})")
    print("  poetry run python loading.py")


def detect_manager() -> str:
    if "pypoetry" in sys.prefix or "poetry" in sys.executable.lower():
        return "Poetry (isolated env managed by Poetry)"
    if sys.prefix != sys.base_prefix:
        return "pip inside a virtual environment"
    return "pip in the global environment"


def compare_managers() -> None:
    print("\nPackage versions installed in this environment:")
    for name in PACKAGES:
        try:
            print(f"  {name:<12} {metadata.version(name)}")
        except metadata.PackageNotFoundError:
            print(f"  {name:<12} not installed")
    print(f"\nDetected manager: {detect_manager()}")
    print("\npip vs Poetry:")
    rows = [
        ("Dependency file", "requirements.txt", "pyproject.toml"),
        ("Install", "pip install -r", "poetry install"),
        ("Virtual env", "manual (venv)", "automatic"),
        ("Version lock", "pip freeze (manual)", "poetry.lock"),
        ("Resolver", "basic", "full dependency solver"),
    ]
    print(f"  {'':<16}{'pip':<22}{'Poetry'}")
    for label, pip_value, poetry_value in rows:
        print(f"  {label:<16}{pip_value:<22}{poetry_value}")


def generate_data(np: Any, pd: Any) -> Any:
    """Simulate Matrix data with numpy and wrap it in a DataFrame."""
    rng = np.random.default_rng(42)
    steps = np.arange(N_POINTS)
    signal = np.cumsum(rng.normal(0.0, 1.0, N_POINTS))
    noise = rng.normal(0.0, 0.5, N_POINTS)
    return pd.DataFrame({"step": steps, "signal": signal,
                         "noise": noise, "observed": signal + noise})


def analyze_and_plot(df: Any, plt: Any) -> None:
    df["trend"] = df["observed"].rolling(window=50).mean()
    stats = df["observed"].describe()
    print(f"Mean: {stats['mean']:.2f} | Std: {stats['std']:.2f} | "
          f"Min: {stats['min']:.2f} | Max: {stats['max']:.2f}")
    print("Generating visualization...")
    fig, (ax1, ax2) = plt.subplots(2, 1, figsize=(10, 7))
    ax1.plot(df["step"], df["observed"], color="#00ff7f", lw=0.8,
             label="observed")
    ax1.plot(df["step"], df["trend"], color="white", lw=1.5, label="trend")
    ax1.set_title("Matrix signal")
    ax1.legend()
    ax2.hist(df["noise"], bins=40, color="#39d98a")
    ax2.set_title("Noise distribution")
    fig.tight_layout()
    fig.savefig(OUTPUT_FILE)
    plt.close(fig)


def main() -> None:
    print("\nLOADING STATUS: Loading programs...\n")
    loaded, missing = check_dependencies()
    if missing:
        print_install_help(missing)
        sys.exit(1)
    try:
        import matplotlib
        matplotlib.use("Agg")
        plt = importlib.import_module("matplotlib.pyplot")
        print("\nAnalyzing Matrix data...")
        df = generate_data(loaded["numpy"], loaded["pandas"])
        print(f"Processing {len(df)} data points...")
        analyze_and_plot(df, plt)
    except (OSError, ValueError, KeyError) as error:
        print(f"Analysis failed: {error}", file=sys.stderr)
        sys.exit(1)
    print("\nAnalysis complete!")
    print(f"Results saved to: {OUTPUT_FILE}")
    compare_managers()


if __name__ == "__main__":
    main()
