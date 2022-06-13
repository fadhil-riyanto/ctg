cmake_minimum_required(VERSION 3.6)
PROJECT(ctg)
find_package( CURL )
find_package( json-c )
find_package( pthread )
set(CMAKE_C_FLAGS_DEBUG "")
set(CMAKE_C_COMPILER "clang")

SET(soure_library
    src/ctg.c
    src/req_curl.c
    src/tg_method.c
    src/key_value.c
    src/http_func.c
)

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/include)
ADD_LIBRARY(ctg_lib STATIC "${soure_library}")

add_executable(ctg_src main.c)
target_link_libraries(ctg_src ctg_lib curl json-c pthread)
set_target_properties(ctg_src PROPERTIES OUTPUT_NAME "ctgbot_telegram")