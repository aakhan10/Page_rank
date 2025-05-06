# PageRank Algorithm in C++

## Overview
This project implements the PageRank algorithm using C++. It supports interactive input or file-based input for testing directed graphs represented by adjacency matrices.

## Files Included
- `project.cpp`: Main C++ implementation.
- `Makefile`: For compiling the program with `make`.
- `test1.txt` to `test5.txt`: Example test case files with various graph structures.

## How to Compile
Use the provided Makefile:
```
make
```

Or compile manually:
```
g++ -std=c++20 -Wall -Wextra project.cpp -o pagerank
```

## How to Run

### Option 1: Interactive Input
You will be prompted to enter the number of nodes and the adjacency matrix.

```
./project
```

### Option 2: Using Input Files
Redirect input from a `.txt` file:

```
./project < test1.txt
```

Each test file format:
- First line: number of nodes (n)
- Next n lines: adjacency matrix (n x n), row by row

## Sample Output
```
Final PageRank Scores:
Node 0: 0.318...
Node 1: 0.278...
Node 2: 0.402...
```

## Author
Anwaar Khan
