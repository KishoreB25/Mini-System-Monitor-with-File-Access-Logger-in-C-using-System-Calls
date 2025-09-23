# Makefile for Mini System Monitor
CC = gcc
CFLAGS = -Iinclude -Wall -Wextra

SRC = src/main.c src/process.c src/file_logger.c src/system_info.c
OBJ = $(SRC:.c=.o)

TARGET = mini_sys_monitor

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJ) $(TARGET)
