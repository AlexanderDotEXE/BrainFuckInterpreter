# 🧠 BrainfuckMachine

> A fast and simple Brainfuck interpreter written in modern C++.

![C++](https://img.shields.io/badge/language-C%2B%2B17-blue)
![License](https://img.shields.io/badge/license-MIT-green)
![Platform](https://img.shields.io/badge/platform-cross--platform-lightgrey)

---

## 📖 Overview

**BrainfuckMachine** is a minimalist, educational interpreter for the esoteric programming language [Brainfuck](https://esolangs.org/wiki/Brainfuck).  
It’s designed to be lightweight, easy to understand, and fully documented.

The interpreter reads a Brainfuck program from a file, cleans and preprocesses the source code, and then executes it using a memory band (tape) model similar to the original language specification.

---

## 🧩 Features

- ✅ Fully working Brainfuck interpreter  
- ⚙️ Fast preprocessing of matching brackets  
- 🧱 Simple `Band` memory model implementation  
- 🪶 Lightweight and dependency-free  
- 🧰 Clean modular codebase (`Band`, `ProgramLoader`, `BrainfuckMachine`)  
- 🗒️ Well-documented with Doxygen-style comments  

---

## 🏗️ Project Structure

```
BrainfuckMachine/
│
├── src/
│   ├── main.cpp
│   ├── Band.hpp
│   ├── BrainfuckMachine.hpp
│   ├── ProgramLoader.h
│   ├── OpcodeDefinitions.h
│   └── (optional) ProgramLoader.cpp
│
├── examples/
│   ├── hello_world.bf
│   └── fibonacci.bf
│
└── README.md
```

---

## ⚡ Building

You can compile the interpreter with any C++17 (or newer) compiler.

### Using `g++`
```bash
g++ -std=c++17 -O2 -o brainfuck src/main.cpp
```

### Using `CMake` (recommended)
```bash
mkdir build && cd build
cmake ..
make
```

This will produce an executable called `brainfuck` (or `brainfuck.exe` on Windows).

---

## ▶️ Usage

To run a Brainfuck program, provide the path to a `.bf` file using the `--file` flag:

```bash
./brainfuck --file examples/hello_world.bf
```

### Example Output
```
Hello World!
```

If no file is found or the argument is missing, an error message is displayed:
```
Error: Could not find or load the specified Brainfuck file.
```

---

## 🧮 Example Brainfuck Program

**hello_world.bf**
```brainfuck
++++++++++[>+++++++>++++++++++>+++>+<<<<-]
>++.>+.+++++++..+++.>++.<<+++++++++++++++.
>.+++.------.--------.>+.>.
```

Output:
```
Hello World!
```

---

## 🧠 How It Works

| Component | Description |
|------------|-------------|
| **Band** | Implements the memory tape. Supports cell increment/decrement and index wrapping. |
| **BrainfuckMachine** | The core interpreter. Parses, executes, and manages loops efficiently. |
| **ProgramLoader** | Reads and cleans Brainfuck source code from files, removing comments and invalid symbols. |
| **OpcodeDefinitions** | Defines valid Brainfuck instruction symbols (like `+`, `-`, `>`, `<`, `[`, `]`, etc.). |

---

## 🧰 Example Code Snippet

```cpp
#include "BrainfuckMachine.hpp"
#include "ProgramLoader.h"

int main() {
    std::string code = ProgramLoader::loadProgramFromFile("hello_world.bf");

    if (code.empty()) {
        std::cerr << "Failed to load program.\n";
        return 1;
    }

    BrainfuckMachine machine;
    machine.execute(code.c_str());
    return 0;
}
```

---

## 💬 Comment Syntax

This interpreter also supports **inline comments** starting with `;;`, which are ignored by the loader:

```brainfuck
;; This line is ignored
+++++ ++ ;; Increment memory cell
```

---

## 🧑‍💻 Author

**Alexander Gorka**  
[GitHub](https://github.com/AlexanderDotEXE)

---

## 📜 License

This project is released under the **MIT License**.  
See [`LICENSE`](LICENSE) for details.

---

## 💡 Future Improvements

- [ ] Add Brainfuck debugger / step mode  
- [ ] Support for extended Brainfuck dialects  
- [ ] Interactive REPL mode  
- [ ] Better error diagnostics (invalid loops, I/O issues)  
- [ ] Unit tests and CI workflow  

---

### ASCII Icon

```
░▒▓███████▓▒░░▒▓███████▓▒░ ░▒▓██████▓▒░░▒▓█▓▒░▒▓███████▓▒░░▒▓████████▓▒░▒▓█▓▒░░▒▓█▓▒░░▒▓██████▓▒░░▒▓█▓▒░░▒▓█▓▒░ 
░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░ 
░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░ 
░▒▓███████▓▒░░▒▓███████▓▒░░▒▓████████▓▒░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓██████▓▒░ ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░      ░▒▓███████▓▒░  
░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░ 
░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░ 
░▒▓███████▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░       ░▒▓██████▓▒░ ░▒▓██████▓▒░░▒▓█▓▒░░▒▓█▓▒░ 
                                                                                                                
                                                                                                                
                                     [B R A I N F * C K Interpreter]
```

---

> “The challenge of Brainfuck isn’t in writing programs — it’s in understanding how a machine thinks.” 🧠
