# OSS Child Process Manager

*C++, POSIX fork & wait*

---

## Overview
A command-line program that forks multiple child processes and manages their execution, demonstrating controlled concurrency and iteration.

---

## Features

- **Process forking**  
  The master (`oss`) spawns each `user` child via `fork()` + `execvp()`, up to a total of *N* processes (set by `-n N`, default: 1).
- **Concurrency control**  
  Ensures that no more than *M* children run at once (set by `-s M`, default: 1); parent blocks on `wait()` to free slots. 
- **Configurable iterations**  
  Pass `-t T` to specify how many loops each child performs (default: 1).
- **Robust CLI parsing**  
  Optional flags `-n`, `-s`, and `-t` default to 1 if not provided; when used they require a positive integer. The `-h` flag displays usage. Missing or non-numeric flag arguments produce clear     error messages.

---

## Build & Run

```bash
# 1. Clone
git clone git@github.com:mgarson/oss-child-process-manager.git
cd oss-child-process-manager

# 2. Build
make

# 3. Usage
./oss [-h] [-n N] [-s M] [-t T]

# Examples
./oss -n 5 -s 2    # Launch 5 children, 2 at a time
./oss -n 3 -t 10   # Launch 3 children, 1 at a time, each doing 10 iterations
