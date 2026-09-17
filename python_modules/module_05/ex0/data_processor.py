# ************************************************************************* #
#                                                                           #
#                                                      :::      ::::::::    #
#  data_processor.py                                 :+:      :+:    :+:    #
#                                                  +:+ +:+         +:+      #
#  By: dassunca <dassunca@student.42sp.org.br>   +#+  +:+       +#+         #
#                                              +#+#+#+#+#+   +#+            #
#  Created: 2026/09/13 15:57:48 by dassunca        #+#    #+#               #
#  Updated: 2026/09/13 18:46:51 by dassunca        ###   ########.fr        #
#                                                                           #
# ************************************************************************* #

import typing
import abc


class DataProcessor(abc.ABC):
    """Abstract base defining the common data-processing interface."""

    def __init__(self) -> None:
        self._storage: list[str] = []
        self._total_processed: int = 0

    @abc.abstractmethod
    def validate(self, data: typing.Any) -> bool:
        """Return True if data is suitable for this processor."""
        ...

    @abc.abstractmethod
    def ingest(self, data: typing.Any) -> None:
        """Process (and store) the given data."""
        ...

    def output(self) -> tuple[int, str]:
        """Extract the oldest stored item along with its processing rank."""
        if not self._storage:
            raise IndexError("No data available to output.")
        rank = self._total_processed - len(self._storage)
        value = self._storage.pop(0)
        return (rank, value)


class NumericProcessor(DataProcessor):
    """Processes int, float, and lists of both (mixed types allowed)."""

    def validate(self, data: typing.Any) -> bool:
        if isinstance(data, bool):
            return False
        if isinstance(data, (int, float)):
            return True
        if isinstance(data, list):
            return all(
                isinstance(item, (int, float)) and not isinstance(item, bool)
                for item in data
            )
        return False

    def ingest(self, data: int | float | list[int | float]) -> None:
        if not self.validate(data):
            raise ValueError("Improper numeric data.")
        converted = (
            [str(data)]
            if isinstance(data, (int, float))
            else [str(item) for item in data]
        )
        self._storage.extend(converted)
        self._total_processed += len(converted)


class TextProcessor(DataProcessor):
    """Processes str and lists of str."""

    def validate(self, data: typing.Any) -> bool:
        if isinstance(data, str):
            return True
        if isinstance(data, list):
            return all(isinstance(item, str) for item in data)
        return False

    def ingest(self, data: str | list[str]) -> None:
        if not self.validate(data):
            raise ValueError("Improper text data.")
        converted = [data] if isinstance(data, str) else list(data)
        self._storage.extend(converted)
        self._total_processed += len(converted)


class LogProcessor(DataProcessor):
    """Processes dict[str, str] log entries, and lists of such dicts."""

    REQUIRED_KEYS = {"log_level", "log_message"}

    def _is_valid_entry(self, entry: typing.Any) -> bool:
        if not isinstance(entry, dict):
            return False
        if not self.REQUIRED_KEYS.issubset(entry.keys()):
            return False
        return all(
            isinstance(key, str) and isinstance(value, str)
            for key, value in entry.items()
        )

    def validate(self, data: typing.Any) -> bool:
        if isinstance(data, dict):
            return self._is_valid_entry(data)
        if isinstance(data, list):
            return all(self._is_valid_entry(item) for item in data)
        return False

    def ingest(
        self, data: dict[str, str] | list[dict[str, str]]
    ) -> None:
        if not self.validate(data):
            raise ValueError("Improper log data.")
        entries = [data] if isinstance(data, dict) else data
        converted = [
            f"{entry['log_level']}: {entry['log_message']}"
            for entry in entries
        ]
        self._storage.extend(converted)
        self._total_processed += len(converted)


if __name__ == "__main__":
    print("=== Code Nexus - Data Processor ===\n")

    print("Testing Numeric Processor...")
    numeric = NumericProcessor()
    print(f"Trying to validate input '42': {numeric.validate(42)}")
    print(f"Trying to validate input 'Hello': {numeric.validate('Hello')}")
    print("Test invalid ingestion of string 'foo' without prior validation:")
    try:
        numeric.ingest("foo")  # type: ignore[arg-type]
    except ValueError as exc:
        print(f"Got exception: {exc}")
    data = [1, 2, 3, 4, 5]
    print(f"Processing data: {data}")
    numeric.ingest(data)
    print("Extracting 3 values...")
    for _ in range(3):
        rank, value = numeric.output()
        print(f"Numeric value {rank}: {value}")

    print("\nTesting Text Processor...")
    text = TextProcessor()
    print(f"Trying to validate input '42': {text.validate(42)}")
    text_data = ["Hello", "Nexus", "World"]
    print(f"Processing data: {text_data}")
    text.ingest(text_data)
    print("Extracting 1 value...")
    rank, value = text.output()
    print(f"Text value {rank}: {value}")

    print("\nTesting Log Processor...")
    log = LogProcessor()
    print(f"Trying to validate input 'Hello': {log.validate('Hello')}")
    log_data = [
        {"log_level": "NOTICE", "log_message": "Connection to server"},
        {"log_level": "ERROR", "log_message": "Unauthorized access!!"},
    ]
    print(f"Processing data: {log_data}")
    log.ingest(log_data)
    print("Extracting 2 values...")
    for _ in range(2):
        rank, value = log.output()
        print(f"Log entry {rank}: {value}")