set (LIB_SRCS dll.c dll.h)

set(LIB_TYPE STATIC)

add_library(LibFolder ${LIB_TYPE} ${LIB_SRCS})

