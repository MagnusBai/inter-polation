CXX = g++ 
C = gcc

OPENCV_CFLAGS = $(shell pkg-config --cflags opencv)
INCLUDE = -I src/ -I $(OPENCV_CFLAGS)

OPENCV_LDFLAGS = $(shell pkg-config --libs opencv)
LDFLAGS = $(OPENCV_LDFLAGS)

utils.o: src/utils.c src/utils.h
	$(C) -c $<

all: test_running

test_running.o: tool/test_running.cc
	$(CXX) $(INCLUDE) -c $<

test_running: test_running.o utils.o
	$(CXX) $^ $(LDFLAGS) -o $@

clean:
	find -name "*.o" -delete
	rm -f test_running