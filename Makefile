# todo remove asserts - ndebug
CC = g++
FLAGS = -Wextra -Wall -Wvla -pthread -std=c++11  -g # to remove
FILES = Point.o tester.o ShapeAlgorithms.o

all: make_test
	./Test

make_test: $(FILES)
	$(CC) $(FLAGS) $(FILES) -o Test

db: make_test
	gdb Test

Point.o: Point.cpp
	$(CC) $(FLAGS) -c Point.cpp

ShapeAlgorithms.o: ShapeAlgorithms.cpp
	$(CC) $(FLAGS) -c ShapeAlgorithms.cpp

tester.o: tester.cpp
	$(CC) $(FLAGS) -c tester.cpp

clean:
	rm $(TESTING_FILES) Test
