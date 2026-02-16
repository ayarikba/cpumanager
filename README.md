# CpuManager

Cpu Manager tool for Deb based systems

## Programming Language

This application is written in **C++** (C++17 standard) and uses the **Qt framework** (Qt5 or Qt6) for the graphical user interface.

## Building for Windows

To build a Windows executable (.exe):

### Prerequisites
- CMake 3.5 or higher
- C++ compiler (MSVC, MinGW, or similar)
- Qt5 or Qt6 development libraries for Windows

### Build Steps

1. Install Qt for Windows from https://www.qt.io/download
2. Open CMake GUI or use command line:
   ```bash
   mkdir build
   cd build
   cmake .. -G "Your Generator" -DCMAKE_PREFIX_PATH=C:\Qt\6.x\msvc2019_64
   cmake --build . --config Release
   ```
3. The executable `CpuManager.exe` will be created in the build directory

### Notes
- The CMakeLists.txt is configured to build a WIN32_EXECUTABLE on Windows
- You may need to deploy Qt libraries alongside the .exe using Qt's windeployqt tool

## Building for Linux

```bash
mkdir build
cd build
cmake ..
make
sudo make install
```

## Technology Stack

- **Language**: C++ 17
- **GUI Framework**: Qt (Qt5/Qt6)
- **Build System**: CMake
- **Platform Support**: Linux (primary), Windows (cross-platform capable)
