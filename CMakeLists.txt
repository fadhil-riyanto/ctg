cmake_minimum_required(VERSION 3.6)
PROJECT(ctg)

SET(soure_library
    src/ctg.c
    src/req_curl.c
)

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/include)
ADD_LIBRARY(ctg_lib STATIC "${soure_library}")

add_executable(ctg_src main.c)
target_link_libraries(ctg_src ctg_lib)
set_target_properties(ctg_src PROPERTIES OUTPUT_NAME "ctgbot_telegram")