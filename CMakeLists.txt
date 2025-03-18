cmake_minimum_required(VERSION 3.20)
project(DoubleLinkedList VERSION 1.0)
add_subdirectory(LibFolder)
add_executable(main src/main.c)

list(APPEND EXTRA_LIBS LibFolder)
list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/LibFolder")

target_link_libraries(maindemo PUBLIC ${EXTRA_LIBS})

target_include_directories(maindemo PUBLIC ${EXTRA_INCLUDES})

