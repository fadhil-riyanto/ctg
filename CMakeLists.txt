cmake_minimum_required(VERSION 3.6)
PROJECT(ctg)
find_package( CURL )
find_package( json-c )
set(CMAKE_C_FLAGS_DEBUG "-Wall -Wextra -Werror")
set(CMAKE_C_COMPILER "clang")

SET(soure_library
    src/ctg.c
    src/req_curl.c
    src/fetcher.c
    src/tg_method.c
    src/key_value.c
    src/http_func.c
)

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/include)
ADD_LIBRARY(ctg_lib STATIC "${soure_library}")

add_executable(ctg_src main.c)
target_link_libraries(ctg_src ctg_lib curl json-c)
set_target_properties(ctg_src PROPERTIES OUTPUT_NAME "ctgbot_telegram")