# OSS Child Process Manager

*C++

---

## Overview
A command-line program that forks multiple child processes and manages their execution, demonstrating controlled concurrency and iteration.

---

## Features

- **Process forking**  
  The master ('oss') spawns each 'user' child via 'fork()' & 'execvp()', up to a total of _N_ processes (set by '-n _N_', default: 1).
- **Concurrency control**  
  Ensures that no more than _M_ children run at once (set by '-s _M_', default: 1); parent blocks on 'wait()' to free slots. 
- **Configurabale iterations**  
  Pass '-t _T_' to specify how many loops each child performs (default: 1).
- **Robust CLI parsing**  
  Optional flags '-n', 's', and '-t' default to 1 if not provided; when used they require a positive integer. The '-h' flag displays usage. Missing or non-numaric flag arguments produce clear error messages.

  ---

  ## Build & Run

  ```bash
  # 1. Clone
  git clone git@github.com:mgarson/oss-child-process-manager.git
  cd oss-child-process-manager

  # 2. Build
  make
  
