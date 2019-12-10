LIB=-L../../synchrobench/c-cpp/build
INC=-I../../synchrobench/c-cpp/include -I../../synchrobench/c-cpp/src/atomic_ops -I../../synchrobench/c-cpp/src/skiplists/rotating

rsl_test: rsl_test.cpp Makefile
	# g++ rsl_test.cpp -o rsl_test -lpthread -pthread $(LIB) $(INC)
	gcc rsl_test.cpp -o rsl_test -lpthread -pthread $(LIB) $(INC) -O3 -DNDEBUG -DLOCKFREE -m64 -D_REENTRANT -fno-strict-aliasing -DINTEL -Wno-unused-value -Wno-format