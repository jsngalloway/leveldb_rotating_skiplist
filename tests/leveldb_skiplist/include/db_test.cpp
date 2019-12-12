
// Simple C++ program to display "Hello World" 
  
// Header file for input output functions 
#include <iostream>
#include <cassert>
#include "leveldb/db.h"

  
using namespace std; 
  
// main function - 
// where the execution of program begins 
int main() 
{ 
    // prints hello world 
    cout<<"Hello World"<<endl; 

    leveldb::DB* db;
    leveldb::Options options;
    options.create_if_missing = true;
    leveldb::Status status = leveldb::DB::Open(options, "/tmp/testdb", &db);
    assert(status.ok());
    cout << "completed test." << endl;
      
    return 0; 
} 