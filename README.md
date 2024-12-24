
# OpenGL-Cpp-Boilerplate

This project has been tested on a Linux machine. Below is a list of necessary libraries and tools, along with their installation commands.

---

## Prerequisites

Ensure your system has a C++ compiler (like `g++`)

---

## Libraries and Tools

### 1. **GLFW**
GLFW is used for creating OpenGL contexts and managing windows and inputs.

Install it using:

```bash
sudo apt install libglfw3 libglfw3-dev
```

### 2. **GLAD**
GLAD is an OpenGL loader that manages function pointers for OpenGL.
The GLAD library is included in this project, so you don't need to install it separately.

### 3. **OpenGL Development Libraries**
These libraries are required to develop and compile OpenGL programs.

Install them using:

```bash
sudo apt install libgl1-mesa-dev
```

### 4. **Build Tools**
To compile and link your project, ensure you have `build-essential` installed:

```bash
sudo apt install build-essential
```


To install all the libraries and tools at once, run the following command:
```bash
sudo apt install libglfw3 libglfw3-dev libgl1-mesa-dev build-essential
```



## Project Structure

```plaintext
OpenGL-Cpp-Boilerplate/
├── .vscode/
│   ├── tasks.json  
├── glad/
│   ├── glad.c         
│   ├── glad.h          
│   └── khrplatform.h
└── main.cpp
```

---

## Additional Notes

- Verify your GPU supports the OpenGL version specified in the GLAD configuration.
- If any libraries are missing, double-check their installation or refer to your package manager for troubleshooting.

---

## Screenshots
![OpenGL-Boilerplate-Triangle-Demo](https://github.com/user-attachments/assets/4ce6fda9-605d-4540-a004-c954182e7718)
