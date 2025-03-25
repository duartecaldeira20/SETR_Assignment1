cmake_minimum_required(VERSION 3.16.3)
project(DoubleLinkedList VERSION 1.0)
add_subdirectory(LibFolder)
add_executable(main src/main.c)

list(APPEND EXTRA_LIBS LibFolder)
list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/LibFolder")

target_link_libraries(main PUBLIC ${EXTRA_LIBS})

target_include_directories(main PUBLIC ${EXTRA_INCLUDES})

