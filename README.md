# SAXPYGenerator for Miranda SST Files

This repository contains the SAXPYGenerator source files written for the Miranda SST. The SAXPYGenerator is a component that generates SAXPY kernels, which are commonly used in performance analysis and testing of high-performance computing systems.
## Files
SAXPYGenerator.cc: The source code file for the SAXPY generator.

SAXPYGenerator.h: The header file for the SAXPY generator.

SAXPYGenerator_config.py: The Python script for configuring the generator.

CMakeLists.txt: The CMake file to build the SAXPYGenerator.
## Requirements
SST
CMake
## Building SAXPYGenerator
#### Clone the repository to your local machine.
git clone https://github.com/sstsimulator/sst-core.git

git clone https://github.com/sstsimulator/sst-elements.git
#### Navigate to the repository directory.
cd path/sst-elements-library-12.1.0/src/sst/elements/miranda/generators
#### Run CMake to configure the build.
cmake ..
#### Compile the source code.
make
#### After following these steps, the SAXPYGenerator will be built and the binary file will be created

After building the SAXPYGenerator, you can run it as a component of the Miranda SST. The SAXPYGenerator can be run using the Miranda SST command line interface
