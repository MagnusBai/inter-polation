CXX = g++ 
CC = gcc

OPENCV_CFLAGS = $(shell pkg-config --cflags opencv)
INCLUDE = -I src/ $(OPENCV_CFLAGS)

OPENCV_LDFLAGS = $(shell pkg-config --libs opencv)
LDFLAGS = $(OPENCV_LDFLAGS)

BUILD_DIR = build
OBJ_DIR = $(BUILD_DIR)/obj
TEST_DIR = $(BUILD_DIR)/test
TOOL_DIR = $(BUILD_DIR)/tool

all: $(OBJ_DIR) $(TEST_DIR) $(TOOL_DIR) $(OBJ_DIR)/mroc_interpolation.o

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
$(TEST_DIR):
	mkdir -p $(TEST_DIR)
$(TOOL_DIR):
	mkdir -p $(TOOL_DIR)

$(OBJ_DIR)/mroc_interpolation.o: src/mroc_interpolation.c src/mroc_interpolation.h
	$(CC) -c $< -o $@

obj: $(OBJ_DIR) $(OBJ_DIR)/mroc_interpolation.o

test: $(TEST_DIR) obj $(TEST_DIR)/test_linear_interpolation

$(TEST_DIR)/test_linear_interpolation: $(TEST_DIR)/test_linear_interpolation.o $(OBJ_DIR)/mroc_interpolation.o
	$(CXX) $^ $(LDFLAGS) -o $@

$(TEST_DIR)/test_linear_interpolation.o: test/test_linear_interpolation.cc
	$(CXX) -c $^ $(INCLUDE) -o $@

clean:
	rm -rf $(BUILD_DIR)