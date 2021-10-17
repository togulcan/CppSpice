## Build the CppSpice library.
##
cmake_minimum_required(VERSION 3.8)

project(CppSpice
    VERSION 0.1.0.0
    LANGUAGES CXX
)

# Define project targets.

add_library(CppSpice
    src/module.cpp
)
add_library(CppSpice::CppSpice ALIAS CppSpice)

target_include_directories(CppSpice
PUBLIC
    # Interface paths are relative to the installation path, not the current
    # directory.
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_compile_features(CppSpice
PUBLIC
    cxx_std_11
)

target_compile_options(CppSpice
PRIVATE
    -Wall
    $<$<CXX_COMPILER_ID:GNU>:-pedantic>
)


# Generate package config files.

include(CMakePackageConfigHelpers)

configure_package_config_file(
    ${CMAKE_CURRENT_LIST_DIR}/cmake/CppSpice-config.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/CppSpice-config.cmake
INSTALL_DESTINATION
    ${CMAKE_INSTALL_LIBDIR}/cmake/CppSpice
)

write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/CppSpice-config-version.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY AnyNewerVersion
)


# Define installation rules.

include(GNUInstallDirs)

install(
TARGETS 
    CppSpice
EXPORT CppSpice-targets
LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

install(DIRECTORY include/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(
FILES
    ${CMAKE_CURRENT_BINARY_DIR}/CppSpice-config.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/CppSpice-config-version.cmake
DESTINATION
    ${CMAKE_INSTALL_LIBDIR}/cmake/CppSpice
)

install(EXPORT CppSpice-targets
    FILE CppSpice-targets.cmake
    NAMESPACE CppSpice::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/CppSpice
)


# Export targets. If an external project adds this project to its build tree
# via `add_subdirectory()`, then `find_package()` will work without
# requiring this project to be installed.

export(EXPORT CppSpice-targets
    FILE ${CMAKE_CURRENT_BINARY_DIR}/CppSpice-targets.cmake
    NAMESPACE CppSpice::
)
export(PACKAGE CppSpice)


# Add subdirectories to build.

add_subdirectory(test)
