CXX = g++ --std=c++11 
CC = gcc

OPENCV_CFLAGS = $(shell pkg-config --cflags opencv)
INCLUDE = -I src/ $(OPENCV_CFLAGS)

OPENCV_LDFLAGS = $(shell pkg-config --libs opencv)
LDFLAGS = $(OPENCV_LDFLAGS)
CFLAGS = -fpermissive 

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

$(OBJ_DIR)/mroc_interpolation.o: src/mroc_interpolation.c src/mroc_interpolation.h $(OBJ_DIR)
	$(CC) -c $< -o $@

$(OBJ_DIR)/mroc_demo_class_trace.o: src/mroc_demo_class_trace.cc src/mroc_demo_class_trace.h $(OBJ_DIR)/mroc_interpolation.o
	$(CXX) $(CFLAGS) -c $< -o $@

obj: $(OBJ_DIR) $(OBJ_DIR)/mroc_interpolation.o $(OBJ_DIR)/mroc_demo_class_trace.o

test: $(TEST_DIR) obj $(TEST_DIR)/test_linear_interpolation $(TEST_DIR)/test_trace_generator

$(TEST_DIR)/test_linear_interpolation: $(TEST_DIR)/test_linear_interpolation.o $(OBJ_DIR)/mroc_interpolation.o
	$(CXX) $^ $(LDFLAGS) -o $@

$(TEST_DIR)/test_linear_interpolation.o: test/test_linear_interpolation.cc
	$(CXX) -c $^ $(INCLUDE) -o $@

$(TEST_DIR)/test_trace_generator: $(TEST_DIR)/test_trace_generator.o $(OBJ_DIR)/mroc_interpolation.o $(OBJ_DIR)/mroc_demo_class_trace.o
	$(CXX) $^ $(LDFLAGS) -o $@

$(TEST_DIR)/test_trace_generator.o: test/test_trace_generator.cc
	$(CXX) -c $^ $(INCLUDE) -o $@


clean:
	rm -rf $(BUILD_DIR)