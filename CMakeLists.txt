cmake_minimum_required(VERSION 3.17...3.24 FATAL_ERROR)


project(fib VERSION 0.1.0 LANGUAGES CXX)
include(GNUInstallDirs)

add_library(fib src/fib.cpp)
add_library(fib::fib ALIAS fib)
target_include_directories(fib PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)
install(TARGETS fib EXPORT fibTargets)

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    fibConfigVersion.cmake VERSION ${PACKAGE_VERSION}
    COMPATIBILITY SameMajorVersion
)

install(
    EXPORT fibTargets
    NAMESPACE fib::
    DESTINATION ${CMAKE_INSTALL_DATADIR}/cmake/fib
    
)
install(
    FILES "fibConfig.cmake" ${CMAKE_CURRENT_BINARY_DIR}/fibConfigVersion.cmake
    DESTINATION ${CMAKE_INSTALL_DATADIR}/cmake/fib
)

include(CPack)
