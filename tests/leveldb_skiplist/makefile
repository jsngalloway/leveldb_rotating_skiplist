# CC=g++
# CFLAGS=-O3 -L ../leveldb/leveldb/build -I ../leveldb/leveldb/include

# db_test: db_test.cpp
# 	$(CC) -o db_test db_test.cpp $(CFLAGS)
INC=-I/include -I/leveldb -I/port -I/util -I/third_party -I/third_party/googletest/googlemock -I /third_party/googletest/googletest/include/gtest
db_test: basic_skiplist.cc makefile
	g++ basic_skiplist.cc -o basic_skiplist -std=c++11 $(INC)