## Introduction
This is a C++ project in development made to learn how to use OpenGL. The main objective is to create a basic particle simulator.

## Project Structure
The project has been refactored to follow standard C++ conventions:
* **src/**: Contains the source code implementation.
* **include/**: Contains the header files and class declarations.
* **bin/**: Destination for the compiled executable.
* **build/**: Destination for intermediate object files.

## Authors
- **Developer**: [Luís Rafael Sena](https://github.com/ifuaslaerl)

## Prerequisites

### Arch Linux
Install the required libraries and development tools using pacman:
```bash
sudo pacman -S glew glfw glm base-devel
```

### Ubuntu / Debian
Install the dependencies using apt-get:
```bash
sudo apt-get update
sudo apt-get install libglew-dev libglfw3-dev libglm-dev build-essential
```

## Build & Run

The project uses a Makefile to manage the build process.

* **Run the simulation:**
    ```bash
    make run
    ```

* **Run in Debug mode:**
    (Enables console output for particle positions and velocities)
    ```bash
    make debug
    ```

* **Clean build files:**
    (Removes the `bin/` and `build/` directories)
    ```bash
    make clean
    ```
