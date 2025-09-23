# # Compiler and flags
# CC = gcc
# CFLAGS = -Iinclude -Wall -Wextra

# # Project structure
# SRC_DIR = src
# OBJ_DIR = obj
# BIN_DIR = bin

# # Files
# SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/process.c $(SRC_DIR)/file_logger.c $(SRC_DIR)/system_info.c
# OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
# TARGET = $(BIN_DIR)/mini_sys_monitor

# # Default target
# all: $(TARGET)

# # Link
# $(TARGET): $(OBJS)
# 	@mkdir -p $(BIN_DIR)
# 	$(CC) $(OBJS) -o $(TARGET)

# # Compile
# $(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
# 	@mkdir -p $(OBJ_DIR)
# 	$(CC) $(CFLAGS) -c $< -o $@

# # Run
# run: $(TARGET)
# 	./$(TARGET)

# # Clean build
# clean:
# 	rm -rf $(OBJ_DIR) $(BIN_DIR)

# CC = gcc
# CFLAGS = -Iinclude -Wall -Wextra

# SRC = src/main.c src/process.c src/file_logger.c src/sys_info.c
# OBJ = $(SRC:.c=.o)

# TARGET = mini_sys_monitor

# all: $(TARGET)

# $(TARGET): $(OBJ)
# 	$(CC) $(OBJ) -o $(TARGET)

# %.o: %.c
# 	$(CC) $(CFLAGS) -c $< -o $@

# run: $(TARGET)
# 	./$(TARGET)

# clean:
# 	rm -f $(OBJ) $(TARGET)

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
