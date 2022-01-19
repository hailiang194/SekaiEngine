# SekaiEngine
Sekai Game engine - my 2D game engine built base on what I know about game development. This game engine can run on Windows, Linux and Web platform

## Library
* raylib 4.0.0

## Requirements
* git
* [CMake](https://cmake.org/download/)
* [Emscripten SDK](https://emscripten.org/docs/getting_started/downloads.html) (for Web platform)
* **MSCV** or **Makefile**
## Installation

### Linux user
If you use **Debian-based** or **Fedora**, you need to run the pre-installer script in scripts

First, you need to give the script the permission to execute
``` bash
sudo chmod +x scripts/pre-installer/linux/<os>/preinstaller.sh
```
Then run that script
``` bash
./scripts/pre-installer/linux/<os>/preinstaller.sh
```
Which ```<os>``` is **```debian```** if you use **Debian-based** distro and **```fedora```** if you use **Fedora-based**

### For Web platform
Because **raylib** require **emscripten SDK**, you need to install it to run it on web. The instruction is [here](https://emscripten.org/docs/getting_started/downloads.html)
