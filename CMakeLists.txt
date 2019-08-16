cmake_minimum_required(VERSION 3.5)
project(libsqrt VERSION 1.0.0 LANGUAGES CXX)

list(INSERT CMAKE_MODULE_PATH 0 ${CMAKE_SOURCE_DIR}/cmake)

find_package(Exponent 1.0 REQUIRED)

add_library(sqrt
    src/sqrt.cpp
)

add_library(Sqrt::sqrt ALIAS sqrt)

target_include_directories(sqrt
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_compile_features(sqrt PRIVATE cxx_auto_type)
target_compile_options(sqrt PRIVATE $<$<CXX_COMPILER_ID:GNU>:-Wall>)

target_link_libraries(sqrt
    PRIVATE
        Exponent::Exponent
)

include(GNUInstallDirs)
set(INSTALL_CONFIGDIR ${CMAKE_INSTALL_LIBDIR}/cmake/Sqrt)

install(TARGETS sqrt
    EXPORT sqrt-targets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

set_target_properties(sqrt PROPERTIES EXPORT_NAME Sqrt)

install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install(EXPORT sqrt-targets
  FILE
    SqrtTargets.cmake
  NAMESPACE
    Sqrt::
  DESTINATION
    ${INSTALL_CONFIGDIR}
)

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/SqrtConfigVersion.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY AnyNewerVersion
)

configure_package_config_file(${CMAKE_CURRENT_LIST_DIR}/cmake/SqrtConfig.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/SqrtConfig.cmake
    INSTALL_DESTINATION ${INSTALL_CONFIGDIR}
)

install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/SqrtConfig.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/SqrtConfigVersion.cmake
    DESTINATION ${INSTALL_CONFIGDIR}
)

export(EXPORT sqrt-targets FILE ${CMAKE_CURRENT_BINARY_DIR}/SqrtTargets.cmake NAMESPACE Sqrt::)

export(PACKAGE Sqrt)

add_subdirectory(test)