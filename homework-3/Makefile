CXX = g++
CC = gcc
CFLAGS = -Wall -I include 
CXXFLAGS = -Wall -I include -std=c++17
AR = ar 
BIN_DIR = build/bin
LIB_DIR = build/lib
OBJ_DIR = build/objects 
all: main test
	mkdir $(BIN_DIR) $(LIB_DIR) $(OBJ_DIR)
## mkdir -p build/lib
## mkdir -p build/objects
	mv *.o $(OBJ_DIR)
	mv *.a $(LIB_DIR)
	mv main $(BIN_DIR)

main: main.o liblinkedlist.a libhashset.a
## gcc main.o -o main -llinkedlist -L.
	$(CXX) $(OBJ_DIR)/main.o -o main -L$(LIB_DIR) -llinkedlist -lhashset

test: test.o liblinkedlist.a libhashset.a
## mkdir -p build/bin
## mkdir -p build/lib
## mkdir -p build/objects
## gcc test.o -o build/bin/test -llinkedlist -L.
## mv *.o build/objects
# #mv *.a build/lib
	mkdir -p $(BIN_DIR) $(LIB_DIR) $(OBJ_DIR)
	$(CXX) $(OBJ_DIR)/test.o -o$(BIN_DIR)/test -L$(LIB_DIR) -llinkedlist -lhashset

test.o: testing/test.cpp
## gcc testing/test.c -c -I include
	$(CXX) $(CXXFLAGS) -c testing/test.cpp -o $(OBJ_DIR)/test.o

main.o: src/bin/main.cpp
##gcc src/bin/main.c -c -I include
	$(CXX) $(CXXFLAGS) -c src/bin/main.cpp -o $(OBJ_DIR)/main.o

liblinkedlist.a: src/lib.c
## gcc src/lib.c -c -I include
## ar rs liblinkedlist.a lib.o
	$(CC) $(CFLAGS) -c src/lib.c -o $(OBJ_DIR)/lib.o
	$(AR) $(ARFLAGS) libilnkedlist.a $(OBJ_DIR)/lib.o

clean:
	rm -rf build

