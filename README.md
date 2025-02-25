# push_swap

**push_swap** is an algorithmic project that sorts numbers using a stack-based approach with a limited set of instructions. The goal is to achieve the most efficient sorting with the fewest operations.

---
## Table of Contents
- [Introduction](#introduction)
- [Features](#features)
- [File Structure](#file-structure)
- [Installation](#installation)
- [Usage](#usage)
- [Bonus Features](#bonus-features)
- [Contributing](#contributing)
- [License](#license)

---
## Introduction
The **push_swap** project is a sorting algorithm implemented with stack operations. It is designed to find the optimal sequence of moves to sort a set of numbers using two stacks and predefined commands. The project is a part of the 42 School curriculum, focusing on algorithm efficiency and problem-solving skills.

---
## Features
- **Sorting Algorithm:** Efficiently sorts numbers using two stacks (A and B).
- **Minimal Instructions:** Uses a limited set of commands (push, swap, rotate, and reverse rotate).
- **Optimisation:** Implements an efficient strategy to minimise the number of operations.
- **Bonus Features:** Includes a checker program for validating sorting sequences.

---
## File Structure
```
dexter88xd-pushswap/
├── README.md
├── LICENSE
├── Makefile
├── pushswap.h
├── bonus/
│   ├── check_numbers_bonus.c
│   ├── follow_instructions_bonus.c
│   ├── main_bonus.c
│   ├── push_swap_bonus.c
│   ├── reverse_rotate_bonus.c
│   └── rotate_bonus.c
├── libft/
│   ├── Makefile
│   ├── libft.h
│   └── src/
│       ├── ft_atoi.c
│       ├── ft_bzero.c
│       ├── ... (other utility functions)
│       ├── get_next_line.c
│       └── get_next_line_utils.c
└── src/
    ├── check_numbers.c
    ├── dumping_stacks.c
    ├── find_cheap_cost.c
    ├── find_min_max.c
    ├── main.c
    ├── push_swap.c
    ├── reverse_rotate.c
    ├── rotate.c
    ├── setting_target.c
    ├── sorting.c
    └── update_stack.c
```

---
## Installation
### **Step 1: Clone the Repository**
```bash
git clone https://github.com/Dexter88xD/push_swap.git
cd push_swap
```
### **Step 2: Compile the Project**
To build the sorting program, run:
```bash
make
```
To build the bonus checker program, run:
```bash
make bonus
```

### **Cleaning Up**
Remove object files:
```bash
make clean
```
Remove executables and object files:
```bash
make fclean
```
Recompile everything:
```bash
make re
```

---
## Usage
### **Sorting Numbers**
To sort a set of numbers, run:
```bash
./push_swap <list of numbers>
```
Example:
```bash
./push_swap 3 2 5 1 4
```

### **Checking Sorting Sequences (Bonus)**
The bonus checker validates sorting sequences:
```bash
./checker_linux <list of numbers>
```
Example:
```bash
./checker_linux 3 2 5 1 4
```
If the numbers are sorted correctly using `push_swap`, the checker will output `OK`. Otherwise, it will output `KO`.

---
## Bonus Features
The bonus version includes:
- **Checker program**: Verifies if a given sequence of commands correctly sorts the numbers.
- **Additional error handling**: Detects invalid inputs and duplicate numbers.

---
## Contributing
Feel free to contribute by:
- Reporting bugs or suggesting improvements via issues.
- Submitting pull requests with optimised algorithms or bug fixes.

---
## License
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.


