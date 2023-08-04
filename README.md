## I used the following to create the project:
- C++ 20
- STL
- JSON parser nlohmann library
- multithreading
- Google GTest
- CMake/Make
  
## About The Project

The project is an assignment for one of the courses I attended and is currently in the development phase.

The program is responsible for synchronizing and updating files between directories, named machines for the purposes of the project.

In the final version, the program will synchronize files between directories, utilizing multithreading, and transmit the output to 4 receivers using separate threads.

## Required:

- cmake VERSION 3.14 
- make 
- C++20

## Build:
Use terminal commands:
```bash 
  mkdir build
```

```bash
  cd build
```

```bash
  cmake ..
```

```bash
  make
```

## How to run project:

### There is a 3 different mode:

### 1. Debuging mode 
```./HealthLumenSolution-debug.exe``` ( windows version ), ```./HealthLumenSolution-debug``` ( linux version )
### 2. Test mode 
```./HealthLumenSolution-gt.exe``` ( windows version ), ```./HealthLumenSolution-gt``` ( linux version )
### 3. Normal mode 
```./HealthLumenSolution.exe``` ( windows version ), ```./HealthLumenSolution``` ( linux version )
