# Minimalistic CMAKE Template
![C++](https://camo.githubusercontent.com/c59efb57803dde7f352f4932a468a7f39fa2fb5f/68747470733a2f2f696d672e736869656c64732e696f2f62616467652f632532422532422d31312f31342f31372f32302d626c75652e737667)
![Build CI Test](https://github.com/FoxMD/CMake_template/workflows/Ubuntu%20CI%20Test/badge.svg)
![Build CI Test](https://github.com/FoxMD/CMake_template/workflows/Windows%20CI%20Test/badge.svg)
[![codecov](https://codecov.io/gh/FoxMD/CMake_template/branch/master/graph/badge.svg)]([https://codecov.io/gh/FoxMD/CMake_template])
## How to build
Use cmake -S . -Bbuild -G "MinGW Makefiles"

### For Catch2 set up conan package

Configuration:
[settings]
arch=x86_64
arch_build=x86_64
build_type=Release
compiler=gcc
compiler.libcxx=libstdc++11
compiler.version=9
os=Linux
os_build=Windows
[options]
[build_requires]
[env]

### Generators
  Visual Studio 17 2022        = Generates Visual Studio 2022 project files.
                                 Use -A option to specify architecture.</br>
  Visual Studio 16 2019        = Generates Visual Studio 2019 project files.
                                 Use -A option to specify architecture.</br>
  Visual Studio 15 2017 [arch] = Generates Visual Studio 2017 project files.
                                 Optional [arch] can be "Win64" or "ARM".</br>
  Visual Studio 14 2015 [arch] = Generates Visual Studio 2015 project files.
                                 Optional [arch] can be "Win64" or "ARM".</br>
  Visual Studio 12 2013 [arch] = Generates Visual Studio 2013 project files.
                                 Optional [arch] can be "Win64" or "ARM".</br>
  Visual Studio 11 2012 [arch] = Generates Visual Studio 2012 project files.
                                 Optional [arch] can be "Win64" or "ARM".</br>
  Visual Studio 10 2010 [arch] = Deprecated.  Generates Visual Studio 2010
                                 project files.  Optional [arch] can be
                                 "Win64" or "IA64".</br>
  Visual Studio 9 2008 [arch]  = Generates Visual Studio 2008 project files.
                                 Optional [arch] can be "Win64" or "IA64".</br>
  Borland Makefiles            = Generates Borland makefiles.</br>
  NMake Makefiles              = Generates NMake makefiles.</br>
  NMake Makefiles JOM          = Generates JOM makefiles.</br>
  MSYS Makefiles               = Generates MSYS makefiles.</br>
  MinGW Makefiles              = Generates a make file for use with
                                 mingw32-make.</br>
  Green Hills MULTI            = Generates Green Hills MULTI files
                                 (experimental, work-in-progress).</br>
  Unix Makefiles               = Generates standard UNIX makefiles.</br>
  Ninja                        = Generates build.ninja files.</br>
  Ninja Multi-Config           = Generates build-<Config>.ninja files.</br>
  Watcom WMake                 = Generates Watcom WMake makefiles.</br>
  CodeBlocks - MinGW Makefiles = Generates CodeBlocks project files.</br>
  CodeBlocks - NMake Makefiles = Generates CodeBlocks project files.</br>
  CodeBlocks - NMake Makefiles JOM
                               = Generates CodeBlocks project files.</br>
  CodeBlocks - Ninja           = Generates CodeBlocks project files.</br>
  CodeBlocks - Unix Makefiles  = Generates CodeBlocks project files.</br>
  CodeLite - MinGW Makefiles   = Generates CodeLite project files.</br>
  CodeLite - NMake Makefiles   = Generates CodeLite project files.</br>
  CodeLite - Ninja             = Generates CodeLite project files.</br>
  CodeLite - Unix Makefiles    = Generates CodeLite project files.</br>
  Eclipse CDT4 - NMake Makefiles
                               = Generates Eclipse CDT 4.0 project files.</br>
  Eclipse CDT4 - MinGW Makefiles
                               = Generates Eclipse CDT 4.0 project files.</br>
  Eclipse CDT4 - Ninja         = Generates Eclipse CDT 4.0 project files.</br>
  Eclipse CDT4 - Unix Makefiles= Generates Eclipse CDT 4.0 project files.</br>
  Kate - NMake Makefiles       = Generates Kate project files.</br>
  Kate - Ninja                 = Generates Kate project files.</br>
  Kate - Unix Makefiles        = Generates Kate project files.</br>
                               = Generates Sublime Text 2 project files.</br>
  Sublime Text 2 - NMake Makefiles
                               = Generates Sublime Text 2 project files.</br>
  Sublime Text 2 - Ninja       = Generates Sublime Text 2 project files.</br>
  Sublime Text 2 - Unix Makefiles
                               = Generates Sublime Text 2 project files.</br>
