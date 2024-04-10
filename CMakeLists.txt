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
if (WAYLAND_EGL_SOVERSION_1)
  set_target_properties(wayland-egl PROPERTIES VERSION 1.0.0 SOVERSION 1)
endif()
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

add_library(pf-1.0 SHARED src/dummy.c)
set_target_properties(pf-1.0 PROPERTIES VERSION 1.0.0 SOVERSION 1)
target_link_options(pf-1.0 PRIVATE ${CMAKE_SOURCE_DIR}/src/pf-1.0.lds)

add_library(lgncopenapi SHARED src/dummy.c)
set_target_properties(lgncopenapi PROPERTIES VERSION 2.4.0 SOVERSION 2)
target_link_options(lgncopenapi PRIVATE ${CMAKE_SOURCE_DIR}/src/lgncopenapi.lds)

add_library(dile_audio_direct SHARED src/dummy.c)
set_target_properties(dile_audio_direct PROPERTIES VERSION 1.0.0 SOVERSION 1)
target_link_options(dile_audio_direct PRIVATE ${CMAKE_SOURCE_DIR}/src/dile_audio_direct.lds)
# hal_audio_direct needs to be linked to dile_audio_direct, so we provide one without SOVERSION for better compatibility
add_library(hal_audio_direct SHARED src/dummy.c)
target_link_libraries(dile_audio_direct PRIVATE hal_audio_direct)
add_library(hal_vfe SHARED src/dummy.c)
target_link_libraries(hal_audio_direct PRIVATE hal_vfe)

add_library(dile_boardinfo SHARED src/dummy.c)
target_link_options(dile_boardinfo PRIVATE ${CMAKE_SOURCE_DIR}/src/dile_boardinfo.lds)

add_library(dile_vdec_direct SHARED src/dummy.c)
set_target_properties(dile_vdec_direct PROPERTIES VERSION 1.0.0 SOVERSION 1)
target_link_options(dile_vdec_direct PRIVATE ${CMAKE_SOURCE_DIR}/src/dile_vdec_direct.lds)
# hal_vdec_direct needs to be linked to dile_vdec_direct, so we provide one without SOVERSION for better compatibility
add_library(hal_vdec_direct SHARED src/dummy.c)
target_link_libraries(dile_vdec_direct PRIVATE hal_vdec_direct)

add_library(dile_vt SHARED src/dummy.c)
set_target_properties(dile_vt PROPERTIES VERSION 0.1.0 SOVERSION 0)
target_link_options(dile_vt PRIVATE ${CMAKE_SOURCE_DIR}/src/dile_vt.lds)
# hal_vdec_direct needs to be linked to dile_vt, so we provide one without SOVERSION for better compatibility
add_library(hal_vt SHARED src/dummy.c)
target_link_libraries(dile_vt PRIVATE hal_vt dile_boardinfo)

add_library(media-resource-calculator SHARED src/dummy.c)
set_target_properties(media-resource-calculator PROPERTIES VERSION 1.0.0 SOVERSION 1)
target_link_options(media-resource-calculator PRIVATE ${CMAKE_SOURCE_DIR}/src/media-resource-calculator.lds)

install(TARGETS EGL GLESv1_CM GLESv2 NDL_directmedia playerAPIs wayland-egl AcbAPI helpers pf-1.0 lgncopenapi
        dile_audio_direct dile_boardinfo dile_vdec_direct dile_vt hal_audio_direct hal_vdec_direct hal_vt hal_vfe
        DESTINATION lib)

install(DIRECTORY ${CMAKE_SOURCE_DIR}/include/
        DESTINATION include
        FILES_MATCHING
            PATTERN "*.h"
            PATTERN "*.hpp")

install(DIRECTORY ${CMAKE_SOURCE_DIR}/share/pkgconfig/
        DESTINATION share/pkgconfig
        FILES_MATCHING PATTERN "*.pc")
