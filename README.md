# WK_7_memory_management
# Dynamic Student Email Address Management System (in C)

## Overview

This project is a C-based system for managing student email addresses in a cohort using **dynamic memory allocation**. It allows you to **add**, **display**, and **manage memory efficiently** for a list of student emails without predefining the size of the list.

The key goal is to optimize memory usage and demonstrate effective use of `malloc`, `realloc`, and `free` in a practical application.

---

## Features

-  Add student email addresses (uses dynamic allocation)
-  Display all stored email addresses
-  Automatic resizing of storage using `realloc`
-  Complete memory cleanup using `free`

---

## How It Works

1. **Storage**:
   - Email addresses are stored as dynamically allocated C strings (`char *`) inside a dynamically growing array (`char **`).

2. **Dynamic Allocation**:
   - As emails are added, the array of pointers is resized using `realloc`.

3. **Display**:
   - All stored email addresses can be printed with indices.

4. **Memory Optimization**:
   - Each email uses only as much memory as it needs.
   - On program exit, all allocated memory is properly freed.

---

Clone the repository onto your machine and compile the `main.c` file using `gcc -o <output_file_name>` then run the executable.
