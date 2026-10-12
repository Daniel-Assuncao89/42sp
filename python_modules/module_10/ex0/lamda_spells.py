def artifact_sorter(artifacts: list[dict]) -> list[dict]:
    """Sort artifacts by 'power', highest first."""
    return sorted(artifacts, key=lambda artifact: artifact["power"],
                  reverse=True)


def power_filter(mages: list[dict], min_power: int) -> list[dict]:
    """Keep only mages whose power is >= min_power."""
    return list(filter(lambda mage: mage["power"] >= min_power, mages))


def spell_transformer(spells: list[str]) -> list[str]:
    """Wrap every spell name as '* name *'."""
    return list(map(lambda spell: "* " + spell + " *", spells))


def mage_stats(mages: list[dict]) -> dict:
    """Return max, min and average power of the mages."""
    if not mages:
        return {"max_power": 0, "min_power": 0, "avg_power": 0.0}
    return {
        "max_power": max(mages, key=lambda mage: mage["power"])["power"],
        "min_power": min(mages, key=lambda mage: mage["power"])["power"],
        "avg_power": round(
            sum(map(lambda mage: mage["power"], mages)) / len(mages), 2
        ),
    }


if __name__ == "__main__":
    artifacts = [
        {"name": "Crystal Orb", "power": 85, "type": "orb"},
        {"name": "Fire Staff", "power": 92, "type": "staff"},
        {"name": "Ice Wand", "power": 60, "type": "wand"},
    ]
    mages = [
        {"name": "Alex", "power": 80, "element": "fire"},
        {"name": "Jordan", "power": 55, "element": "ice"},
        {"name": "Riley", "power": 95, "element": "wind"},
    ]

    print("Testing artifact sorter...")
    ordered = artifact_sorter(artifacts)
    print(f"{ordered[0]['name']} ({ordered[0]['power']} power) comes "
          f"before {ordered[1]['name']} ({ordered[1]['power']} power)")

    print("\nTesting power filter...")
    strong = power_filter(mages, 70)
    print("Mages with power >= 70:", [m["name"] for m in strong])

    print("\nTesting spell transformer...")
    print(" ".join(spell_transformer(["fireball", "heal", "shield"])))

    print("\nTesting mage stats...")
    print(mage_stats(mages))
