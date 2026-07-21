*This project has been created as part of the 42 curriculum by dassunca*
## 1. Description
	This project is part of the 42 curriculum and implements get_next_line, a function that reads and returns one line at a time from a file descriptor.

	The goal of the project is to handle file input progressively using the read system call, dynamic memory allocation, and a persistent internal state between function calls. The function must correctly return each line, including the newline character when present, and return NULL when there is nothing left to read or when an error occurs.

	The implementation supports different BUFFER_SIZE values defined at compilation time. This means the function cannot assume that a full line will be read in a single call to read. Instead, it must accumulate partial reads until a complete line is found or the end of the file is reached.

## 2. Instructions
  Clone the project using the following command at the bash:
	`git clone <copy the url repository>`
	After cloning it, get into the folder created and execute the next command.
	Compilation command execution at the bash/terminal, the value at the BUFFER_SIZE is only for example, any number can be used.
			` - cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 *.c`
	
## 3. Resources
	1. Linux manual page for read(2)
	2. Linux manual page for malloc(3) and free(3)
	3. cppreference — C storage duration and static variables
	4. Peer discussions and manual testing
	
	AI was used to construct the README file and to clarify some concepts.

## Algorithm and Data Structure Justification

The selected algorithm is based on an incremental reading strategy using a static stash buffer.

A file descriptor does not provide data line by line. The read function only returns a block of bytes whose size is limited by BUFFER_SIZE. Because of that, a single call to read may return only part of a line, exactly one line, or multiple lines at once.

To handle this correctly, the implementation maintains a static string called the stash. This stash stores all data that has already been read from the file descriptor but has not yet been returned to the caller.

The algorithm follows these steps:

Read from the file descriptor into a temporary buffer.
Append the newly read data to the stash.
Continue reading until the stash contains a newline character or until the end of the file is reached.
Extract the next line from the stash.
Update the stash so it keeps only the remaining content after the extracted line.
Return the extracted line to the caller.

This approach was chosen because it correctly separates temporary read operations from persistent state management. The temporary buffer only stores the most recent block read from the file descriptor, while the stash preserves unfinished or extra content across multiple calls.

Dynamic memory allocation is necessary because the line length is unknown in advance and may be larger than BUFFER_SIZE. The function therefore builds the line progressively instead of relying on a fixed-size array.

The returned line is allocated dynamically and becomes the responsibility of the caller, who must free it after use. Internal temporary buffers and obsolete stash content are freed inside the implementation to avoid memory leaks.

This design handles the main edge cases:

lines shorter than BUFFER_SIZE;
lines longer than BUFFER_SIZE;
files with multiple lines read in a single call;
files without a final newline;
empty files;
invalid file descriptors or read errors.