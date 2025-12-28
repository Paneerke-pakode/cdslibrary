cmake_minimum_required(VERSION 3.10)
project(cdslib C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "-Wall -Wextra -Werror")

# ------- Library --------
add_library(cdslib
        src/hashmap.c
        src/heap.c
        src/list.c
        src/queue.c
        src/stack.c
        src/tree.c
)

target_include_directories(cdslib PUBLIC include)

# ---------------- Tests ------------------
add_executable(test_list tests/test_list.c)
target_link_libraries(test_list cdslib)

add_executable(test_stack tests/test_stack.c)
target_link_libraries(test_stack cdslib)

add_executable(test_tree tests/test_tree.c)
target_link_libraries(test_tree cdslib)

add_executable(test_heap tests/test_heap.c)
target_link_libraries(test_heap cdslib)

add_executable(test_queue tests/test_queue.c)
target_link_libraries(test_queue cdslib)

add_executable(test_hashmap tests/test_hashmap.c)
target_link_libraries(test_hashmap cdslib)



