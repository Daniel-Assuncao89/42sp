*This project has been created as part of the 42 curriculum by hequeiro, dassunca*

# The repository must clearly indicate both learners’ contributions in the README.md file.

# During the defense, both learners must be present and able to explain any part of the code.

# You must document in your repository (e.g., README.md) the rationale for your thresholds, the internal techniques used in each regime, and a brief complexity argument (upper bounds) for time and space within the Push_swap model.

# Description
# Instructions
# Resources
Miro was the online platform selected to create diagrams to help us visualize the workflow of different directions and approaches that the program could take.
Jira was used to keep tracks of which features and bugs exactly the pair should work on. This was useful cause we could work separately and manage to join everything at the end and make it work without problems.
AI was used to help us figure out the best way to implement different algorithms.

# Usage Examples
```Shell
$> ./push_swap 3 2 1
$> sa
$> ra
```

# Feature List

# Algorithms
A detailed explanation and justification of the algorithms selected for the project.

Since I'm using arrays, there are 2 approachs to handling the removing of a number from an array and insertion on another.
One is to remove the first element of each array and pass the next number to the previous.
    For example, in array: [1, 2, 3, 4].
    Remove the '1', making it be: ['X', 2, 3, 4].
    Pass the 2 to the first position: [2, 'X', 3, 4].
    Repeat the process over and over, until the last position is empty: [2, 3, 4, 'X'].
This is not efficient cause it would make take a lot of steps to move the single number from the "top" to move it to another stack.

So my alternative to that is to store the numbers in reverse. The "bottom" of the stack is actually in the first index, and the "top" is in the last index.
Since the only changes only remove or add actions happen at the end of the array, this makes it easier for operations to work.

---
After implementing ra and rb, I can tell that using Linked List is way more performatic to "move all numbers".

## Selection Sort
The way my Selection Sort works in this adaptation for 2 stacks is that it searches the lowest number in Stack A, moves it to the top and pushes it to Stack B
This process it's repeated constantly until Stack A it's empty and Stack B is ordered in the inverse order. So then the last thing to be done is to push them  back to Stack A.

## Bubble Sort
The way my Bubble Sort works in this adaptation for 2 stacks is that it compares the 2 numbers at the top of the stack,
the higher one stays at the top and then the whole stacks gets rotated downwards. This is repeated for the whole amount of numbers in the stack -1 every iteration.
At the end of the iteration the number at the top it's pushed to Stack B and the whole process is repeated but with -1 number.
When Stack A gets emtpy and Stack B full, all numbers from B gets pushed to A again.
