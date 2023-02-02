cmake_minimum_required(VERSION 3.0)

# Define project name
project(SAXPYGenerator)

# Find SST
find_package(SST REQUIRED)

# Define source files
set(SAXPYGENERATOR_SRC
    SAXPYGenerator.cc
)

# Create library
add_library(SAXPYGenerator ${SST_LIBRARIES}SAXPYGenerator.cc)

# Link against SST
target_link_libraries(SAXPYGenerator PRIVATE libcoreTestElement.so)

# Install library
install(TARGETS SAXPYGenerator DESTINATION lib)

# Install header files
install(FILES SAXPYGenerator.h DESTINATION include)
