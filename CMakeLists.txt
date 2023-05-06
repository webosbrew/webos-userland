cmake_minimum_required(VERSION 3.12)
project(webos_userland LANGUAGES C CXX)

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
target_link_options(wayland-egl PRIVATE ${CMAKE_SOURCE_DIR}/src/wayland-egl.lds)

add_library(NDL_directmedia SHARED src/dummy.c)
set_target_properties(NDL_directmedia PROPERTIES VERSION 1.0.0 SOVERSION 1)
target_link_options(NDL_directmedia PRIVATE ${CMAKE_SOURCE_DIR}/src/NDL_directmedia.lds)

add_library(playerAPIs SHARED src/dummy.c)
set_target_properties(playerAPIs PROPERTIES VERSION 1.0.0 SOVERSION 1)
target_link_options(playerAPIs PRIVATE ${CMAKE_SOURCE_DIR}/src/playerAPIs.lds)

add_library(AcbAPI SHARED src/dummy.c)
set_target_properties(AcbAPI PROPERTIES VERSION 1.0.0 SOVERSION 1)
target_link_options(AcbAPI PRIVATE ${CMAKE_SOURCE_DIR}/src/AcbAPI.lds)

add_library(helpers SHARED src/dummy.c)
set_target_properties(helpers PROPERTIES VERSION 2.0.0 SOVERSION 2)
target_link_options(helpers PRIVATE ${CMAKE_SOURCE_DIR}/src/helpers.lds)

install(TARGETS EGL GLESv1_CM GLESv2 NDL_directmedia playerAPIs wayland-egl AcbAPI helpers DESTINATION lib)

install(DIRECTORY ${CMAKE_SOURCE_DIR}/include/
        DESTINATION include
        FILES_MATCHING
            PATTERN "*.h"
            PATTERN "*.hpp")

install(DIRECTORY ${CMAKE_SOURCE_DIR}/share/pkgconfig/
        DESTINATION share/pkgconfig
        FILES_MATCHING PATTERN "*.pc")
