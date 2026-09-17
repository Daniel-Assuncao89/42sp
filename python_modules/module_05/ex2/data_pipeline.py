# ************************************************************************* #
#                                                                           #
#                                                      :::      ::::::::    #
#  data_pipeline.py                                  :+:      :+:    :+:    #
#                                                  +:+ +:+         +:+      #
#  By: dassunca <dassunca@student.42sp.org.br>   +#+  +:+       +#+         #
#                                              +#+#+#+#+#+   +#+            #
#  Created: 2026/09/13 19:01:06 by dassunca        #+#    #+#               #
#  Updated: 2026/09/13 19:01:29 by dassunca        ###   ########.fr        #
#                                                                           #
# ************************************************************************* #

import abc
import typing


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


class ExportPlugin(typing.Protocol):
    """Structural interface (duck typing) for any export plugin."""

    def process_output(self, data: list[tuple[int, str]]) -> None:
        ...


class DataStream:
    """Routes stream elements to processors and exports consumed data
    through pluggable, duck-typed export plugins."""

    def __init__(self) -> None:
        self._processors: list[DataProcessor] = []

    def register_processor(self, proc: DataProcessor) -> None:
        """Register a new data processor to handle stream elements."""
        self._processors.append(proc)

    def process_stream(self, stream: list[typing.Any]) -> None:
        """Route each element of the stream to the first processor
        whose validate() accepts it. Print an error if none accept it."""
        for element in stream:
            handled = False
            for proc in self._processors:
                if proc.validate(element):
                    proc.ingest(element)
                    handled = True
                    break
            if not handled:
                print(
                    f"DataStream error - Can't process element in stream: "
                    f"{element}"
                )

    def print_processors_stats(self) -> None:
        """Print processing statistics for each registered processor."""
        if not self._processors:
            print("No processor found, no data")
            return
        for proc in self._processors:
            name = type(proc).__name__
            total = proc._total_processed
            remaining = len(proc._storage)
            print(
                f"{name}: total {total} items processed, "
                f"remaining {remaining} on processor"
            )

    def output_pipeline(self, nb: int, plugin: ExportPlugin) -> None:
        """Consume up to nb items from each registered processor and
        export them through the given (duck-typed) plugin."""
        for proc in self._processors:
            batch: list[tuple[int, str]] = []
            for _ in range(nb):
                if not proc._storage:
                    break
                batch.append(proc.output())
            if batch:
                plugin.process_output(batch)


class CsvExportPlugin:
    """Exports data as a manually-built CSV line (values only)."""

    def process_output(self, data: list[tuple[int, str]]) -> None:
        values = [value for _, value in data]
        print("CSV Output:")
        print(",".join(values))


class JsonExportPlugin:
    """Exports data as a manually-built JSON object string."""

    def process_output(self, data: list[tuple[int, str]]) -> None:
        pairs = [f'"item_{rank}": "{value}"' for rank, value in data]
        print("JSON Output:")
        print("{" + ", ".join(pairs) + "}")


if __name__ == "__main__":
    print("=== Code Nexus - Data Pipeline ===\n")

    print("Initialize Data Stream...\n")
    stream = DataStream()
    print("== DataStream statistics ==")
    stream.print_processors_stats()

    print("\nRegistering Processors")
    numeric = NumericProcessor()
    text = TextProcessor()
    log = LogProcessor()
    stream.register_processor(numeric)
    stream.register_processor(text)
    stream.register_processor(log)

    batch1 = [
        "Hello world",
        [3.14, -1, 2.71],
        [
            {"log_level": "WARNING", "log_message": "Telnet access! Use ssh instead"},
            {"log_level": "INFO", "log_message": "User wil is connected"},
        ],
        42,
        ["Hi", "five"],
    ]
    print(f"\nSend first batch of data on stream: {batch1}\n")
    stream.process_stream(batch1)
    print("== DataStream statistics ==")
    stream.print_processors_stats()

    print("\nSend 3 processed data from each processor to a CSV plugin:")
    stream.output_pipeline(3, CsvExportPlugin())
    print("\n== DataStream statistics ==")
    stream.print_processors_stats()

    batch2 = [
        21,
        ["I love AI", "LLMs are wonderful", "Stay healthy"],
        [
            {"log_level": "ERROR", "log_message": "500 server crash"},
            {"log_level": "NOTICE", "log_message": "Certificate expires in 10 days"},
        ],
        [32, 42, 64, 84, 128, 168],
        "World hello",
    ]
    print(f"\nSend another batch of data: {batch2}")
    stream.process_stream(batch2)
    print("== DataStream statistics ==")
    stream.print_processors_stats()

    print("\nSend 5 processed data from each processor to a JSON plugin:")
    stream.output_pipeline(5, JsonExportPlugin())
    print("\n== DataStream statistics ==")
    stream.print_processors_stats()