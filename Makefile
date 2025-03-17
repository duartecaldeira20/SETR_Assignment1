CC = gcc
CFLAGS = -Wall -g
TARGET = test.exe
SRC = main.c dll_init.c dll_insert.c  # Adiciona aqui os teus outros arquivos .c conforme forem criados

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)
