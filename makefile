CC = gcc
CFLAGS = -std=c11 -Wall

SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

SRC_FILES = $(SRC_DIR)/sort.c $(SRC_DIR)/test.c
OBJ_FILES = $(OBJ_DIR)/sort.o $(OBJ_DIR)/test.o
TARGET = $(BIN_DIR)/test

$(TARGET): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ_FILES)

$(OBJ_DIR)/sort.o: $(SRC_DIR)/sort.c $(SRC_DIR)/data_structure.h
	$(CC) $(CFLAGS) -c -o $(OBJ_DIR)/sort.o $(SRC_DIR)/sort.c

$(OBJ_DIR)/test.o: $(SRC_DIR)/test.c $(SRC_DIR)/sort.h
	$(CC) $(CFLAGS) -c -o $(OBJ_DIR)/test.o $(SRC_DIR)/test.c

.PHONY: clean
clean:
	rm -rf $(OBJ_DIR)/*.o $(TARGET)
