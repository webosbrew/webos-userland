cmake_minimum_required(VERSION 3.22)
project(webos_userland C)

set(CMAKE_C_STANDARD 11)

include_directories(include)

add_library(EGL SHARED src/dummy.c)
set_target_properties(EGL PROPERTIES VERSION 1.4.0 SOVERSION 1)
target_link_options(EGL PRIVATE ${CMAKE_SOURCE_DIR}/src/EGL.lds)

add_library(GLESv1_CM SHARED src/dummy.c)
set_target_properties(GLESv1_CM PROPERTIES VERSION 1.1.0 SOVERSION 1)
target_link_options(GLESv1_CM PRIVATE ${CMAKE_SOURCE_DIR}/src/GLESv1_CM.lds)

add_library(GLESv2 SHARED src/dummy.c)
set_target_properties(GLESv2 PROPERTIES VERSION 2.1.0 SOVERSION 2)
target_link_options(GLESv2 PRIVATE ${CMAKE_SOURCE_DIR}/src/GLESv2.lds)

add_library(wayland-egl SHARED src/dummy.c)
set_target_properties(wayland-egl PROPERTIES VERSION 1.10.0 SOVERSION 1)
target_link_options(wayland-egl PRIVATE ${CMAKE_SOURCE_DIR}/src/wayland-egl.lds)

install(TARGETS EGL GLESv1_CM GLESv2 wayland-egl DESTINATION lib)

install(DIRECTORY ${CMAKE_SOURCE_DIR}/include/
        DESTINATION include
        FILES_MATCHING PATTERN "*.h")

install(DIRECTORY ${CMAKE_SOURCE_DIR}/share/pkgconfig
        DESTINATION share/pkgconfig
        FILES_MATCHING PATTERN "*.pc")