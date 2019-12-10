include ../../synchrobench/c-cpp/common/Makefile.common
ROOT=../../synchrobench/c-cpp
LIB=-L$(ROOT)/build
INC=-I$(ROOT)/include -I$(ROOT)/src/atomic_ops -I$(ROOT)/src/skiplists/rotating
# INC=-I$(ROOT)/src/skiplists/rotating 

rsl_test: rsl_test.cpp Makefile
	# g++ rsl_test.cpp -o output $(ROOT)/build/skiplist.o  -lpthread $(LIB) $(INC) $(CFLAGS)
	# gcc rsl_test.cpp -o rsl_test -lpthread -pthread $(LIB) $(INC) -O3 -DNDEBUG -DLOCKFREE -m64 -D_REENTRANT -fno-strict-aliasing -DINTEL -Wno-unused-value -Wno-format
	# gcc -O3 -DNDEBUG -DMUTEX -m64 -D_REENTRANT -fno-strict-aliasing -I$(ROOT)/src/atomic_ops -I$(ROOT)/include $(ROOT)/build/garbagecoll.o $(ROOT)/build/ptst.o $(ROOT)/build/skiplist.o $(ROOT)/build/nohotspot_ops.o $(ROOT)/build/intset.o $(ROOT)/build/background.o $(ROOT)/build/test.o -o $(ROOT)/bin/lockfree-rotating-skiplist -m64 -lpthread
	gcc -O3 -DNDEBUG -DMUTEX -m64 -D_REENTRANT -fno-strict-aliasing -I$(ROOT)/src/atomic_ops -I$(ROOT)/include $(ROOT)/build/garbagecoll.o $(ROOT)/build/ptst.o $(ROOT)/build/skiplist.o $(ROOT)/build/nohotspot_ops.o $(ROOT)/build/intset.o $(ROOT)/build/background.o -o $(ROOT)/bin/lockfree-rotating-skiplist -m64 -lpthread
