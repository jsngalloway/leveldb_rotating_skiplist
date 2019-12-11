
// Simple C++ program to display "Hello World" 
  
// Header file for input output functions 
#include<iostream>
#include <cassert>
#include "leveldb/db.h"
#include<time.h>
#include <cstdlib>
#include <map> 
#include <chrono>
#include <list> 
  
using namespace std; 

string str_status(bool ok){
    if(ok){
        return "OK";
    } else {
        return "ERROR";
    }
}

bool insert(leveldb::DB* db, string key, string value){
    return (db->Put(leveldb::WriteOptions(), key, value)).ok();
}

string lookup(leveldb::DB* db, string key){
        string value = "";
        if( !(db->Get(leveldb::ReadOptions(), key, &value)).ok() ){
            cout << "Error on lookup: " << key << endl;
        }
        return value;
}

bool remove(leveldb::DB* db, string key, string value){
    return(db->Delete(leveldb::WriteOptions(), key)).ok();
}

int main() 
{
    leveldb::DB* db;
    leveldb::Options options;
    options.create_if_missing = true;
    leveldb::Status status = leveldb::DB::Open(options, "/tmp/testdb", &db);
    assert(status.ok());
    cout << "Created databse.\t\t\t\tStatus: " << str_status(status.ok()) << endl;

    size_t OPERATIONS = 100;
    float percent_insert = 0.2;
    float percent_lookup = 0.7;
    float percent_delete = 0.1;
    list<string> inserted_values;
    srand(time(0)); 
    chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();
    for(size_t n = OPERATIONS; n > 0; n--){
        float r = ((double) rand() / (RAND_MAX));
        if (r < percent_insert) {
            //insert
            string val = "DOG";//std::to_string((char)(rand()%40));
            if(!insert(db, std::to_string(n), val)){
                cout << "INSERT ERROR" << endl;
            } else {
                inserted_values.push_back(std::to_string(n));
            }
            cout << "inserting: (" << std::to_string(n) << ", " << val << ")."<<endl;
        } else if ((r + percent_insert) < percent_lookup) {
            //lookup
            cout << "conducting lookup " << endl;
            int k_len = inserted_values.size();
            int index = rand() % k_len;
            std::list<std::string>::iterator it = inserted_values.begin();
            std::advance(it, index);
            string lookup_key  = *it;
            // string lookup_key = inserted_values[index];
            // cout << "Looking up key: " << lookup_key << endl;
            if(lookup(db, lookup_key).empty()){
                cout << "Lookup error" << endl;
            }
        } else if ((r + percent_insert + percent_lookup) < percent_delete){
            //delete
            // cout << "conducting delete " << endl;
            // int k_len = inserted_values.size();
            // int index = rand() % k_len;
            // std::list<std::string>::iterator it = inserted_values.begin();
            // std::advance(it, index);
            // string lookup_key  = *it;
            // // string lookup_key = inserted_values[index];
            // // cout << "Looking up key: " << lookup_key << endl;
            // if(lookup(db, lookup_key).empty()){
            //     cout << "Lookup error" << endl;
            // }
        }
    }
    chrono::high_resolution_clock::time_point end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed_time = chrono::duration_cast<chrono::duration<double>>(end - start);

    std::cout << "It took me " << elapsed_time.count()*1000000 << " microseconds.";


    delete db;
    cout << "Completed test." << endl;

    return 0;
}