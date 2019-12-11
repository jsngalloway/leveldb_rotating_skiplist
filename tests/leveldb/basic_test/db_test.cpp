
// Simple C++ program to display "Hello World" 
  
// Header file for input output functions 
#include<iostream>
#include <cassert>
#include "leveldb/db.h"
  
using namespace std; 

string str_status(bool ok){
    if(ok){
        return "OK";
    } else {
        return "ERROR";
    }
}

int main() 
{ 
    // prints hello world 

    leveldb::DB* db;
    leveldb::Options options;
    options.create_if_missing = true;
    leveldb::Status status = leveldb::DB::Open(options, "/tmp/testdb", &db);
    assert(status.ok());
    cout << "Created databse.\t\t\t\tStatus: " << str_status(status.ok()) << endl;

    string value1 = "monkeys like bananas";
    string key1 = "monkey";

    //Put
    status = db->Put(leveldb::WriteOptions(), key1, value1);
    cout << "Set [" << key1 << "] to [" << value1 << "]\t\tStatus: " << str_status(status.ok()) << endl; //Expect OK


    //Get
    string value;
    status = db->Get(leveldb::ReadOptions(), key1, &value);
    cout << "Got [" << key1 << "] as [" << value << "]\t\tStatus: " << str_status(status.ok()) << endl; //Expect OK

    //Delete
    status = db->Delete(leveldb::WriteOptions(), key1);
    cout << "Deleted pair ["<<key1<<"], ["<<value1<<"]\tStatus: "<< str_status(status.ok()) << endl; //Expect OK

    //Get
    string new_value;
    status = db->Get(leveldb::ReadOptions(), key1, &new_value);
    cout << "Got [" << key1 << "] as [" << new_value << "]\t\t\t\tStatus: " << str_status(status.ok()) <<  " (Expected [ERROR])" << endl; //Expect ERROR


    delete db;
    cout << "Closed database." << endl;

    return 0; 
}