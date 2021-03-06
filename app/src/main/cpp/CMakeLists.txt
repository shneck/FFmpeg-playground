cmake_minimum_required(VERSION 3.4.1)

set(ffmpeg_DIR ${CMAKE_SOURCE_DIR}/../libs/ffmpeg)

add_library(libavcodec SHARED IMPORTED)
set_target_properties(libavcodec PROPERTIES IMPORTED_LOCATION
    ${ffmpeg_DIR}/lib/${ANDROID_ABI}/libavcodec.so)

add_library(libavfilter SHARED IMPORTED)
set_target_properties(libavfilter PROPERTIES IMPORTED_LOCATION
    ${ffmpeg_DIR}/lib/${ANDROID_ABI}/libavfilter.so)

add_library(libavformat SHARED IMPORTED)
set_target_properties(libavformat PROPERTIES IMPORTED_LOCATION
    ${ffmpeg_DIR}/lib/${ANDROID_ABI}/libavformat.so)

add_library(libavutil SHARED IMPORTED)
set_target_properties(libavutil PROPERTIES IMPORTED_LOCATION
    ${ffmpeg_DIR}/lib/${ANDROID_ABI}/libavutil.so)

add_library(libswresample SHARED IMPORTED)
set_target_properties(libswresample PROPERTIES IMPORTED_LOCATION
    ${ffmpeg_DIR}/lib/${ANDROID_ABI}/libswresample.so)

add_library(libswscale SHARED IMPORTED)
set_target_properties(libswscale PROPERTIES IMPORTED_LOCATION
    ${ffmpeg_DIR}/lib/${ANDROID_ABI}/libswscale.so)

add_library(native-lib SHARED
            native-lib.cpp)

target_include_directories(native-lib PRIVATE
                           ${ffmpeg_DIR}/include)

find_library(log-lib log)
target_link_libraries(native-lib
                      libavcodec
                      libavfilter
                      libavformat
                      libavutil
                      libswresample
                      libswscale
                      ${log-lib} )