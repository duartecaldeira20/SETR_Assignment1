CC=gcc
CFLAGS=-Wall -g
TARGET=test.exe

all: $(TARGET)

$(TARGET): main.c dll_init.c
	$(CC) $(CFLAGS) -o $(TARGET) main.c dll_init.c

clean:
	rm -f $(TARGET)
