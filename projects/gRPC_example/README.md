# gRPC Example Project

This project demonstrates a simple gRPC server and client implementation using C++.

## Building the Project

This project samples uses C++23 features, so compiling it is a bit demanding:

### General Requirements
1. **Linux:**  
   - Compiler: `clang` (version 18 or above)  
   - Libraries: `libc++` and `libc++abi` (version 18 or above)  

2. **Windows:**  
   - Compiler: `Visual Studio 2022` (version 17.5 or above)  
   - Note: Only `msvc` (`cl.exe`) has been tested. Using `clang++` is unlikely to work.  

### Additional Notes
This project samples relies on the **gRPC library**, so the initial compilation process can take **10-15 minutes**, depending on your internet speed and system performance.  On **Windows**, it is recommended to open **VSCode** through the `Developer PowerShell for VS 2022` terminal. This ensures that most environment variables and configurations are properly set up.

---

> apart from needing to run a command for conan in the terminal, you should be able to compile directly using the vscode CMake tools plugin without any cmake-related commands.
### With vcpkg

[vcpkg installation guide](https://learn.microsoft.com/en-us/vcpkg/get_started/get-started?pivots=shell-bash)

- On Windows, if you have installed the Visual Studio C++ module, you should theoretically have vcpkg installed. You can check by opening the `Developer Powershell for VS 2022` terminal and executing `$env:VCPKG_ROOT`. If it exists, execute the command `vcpkg x-update-baseline --add-initial-baseline`.

Execute in terminal:
```sh
cmake --preset ninja
```

```sh
cmake --build --preset ninja-debug
```

> If on Linux, if your default compiler is not clang, please set your compiler to clang in CMakePresets.json ninja config.


### With conan

[conan installation guide](https://docs.conan.io/2/installation.html)

My Linux conan profile configuration:
```ini
[settings]
os=Linux
arch=x86_64
compiler=clang
compiler.version=19
compiler.cppstd=gnu17
compiler.libcxx=libc++
build_type=Release

[conf]
tools.cmake.cmaketoolchain:generator=Ninja
tools.build:compiler_executables={"c": "clang", "cpp": "clang++"}
```

Execute in terminal:
```sh
conan install . --build=missing -s build_type=Debug
```

```sh
cmake --preset ninja-conan-debug
```

```sh
cmake --build --preset ninja-conan-debug
```
