# CC=g++
# CFLAGS=-O3 -L ../leveldb/leveldb/build -I ../leveldb/leveldb/include

# db_test: db_test.cpp
# 	$(CC) -o db_test db_test.cpp $(CFLAGS)
db_test: db_test.cpp Makefile
	g++ db_test.cpp -o db_test -lpthread -pthread -lleveldb -L ../leveldb/leveldb/build -I ../leveldb/leveldb/include -std=c++11