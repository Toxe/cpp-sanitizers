cmake_minimum_required(VERSION 3.12)
project("C++ Sanitizers" LANGUAGES CXX)

# default compiler options and warnings
include(cmake/DefaultCompilerOptionsAndWarnings.cmake)

# static analyzers
include(cmake/StaticAnalyzers.cmake)

# sanitizers
include(cmake/Sanitizers.cmake)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

add_subdirectory(src)
