
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

bool remove(leveldb::DB* db, string key){
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

    double TEST_DURATION_S = 10;
    size_t pre_population_size = 256;
    float percent_insert = 0.00;
    float percent_lookup = 0.95;
    float percent_delete = 0.00;
    float percent_updates = 0.05;
    list<string> inserted_values;

    for(size_t i = pre_population_size; i > 0; i--){
        string val = "DOG";
        if(!insert(db, std::to_string(i+1), val)){
            cout << "(PRE)INSERT ERROR" << endl;
        } else {
            inserted_values.push_back(std::to_string(i+1));
        }
    }

    srand(time(0));
    chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();
    size_t n = pre_population_size;
    size_t ins = 0;
    size_t lkup = 0;
    size_t del = 0;
    while(chrono::duration_cast<chrono::duration<double>>(chrono::high_resolution_clock::now() - start).count() < TEST_DURATION_S){
        float r = ((double) rand() / (RAND_MAX));
        if (r < percent_insert) {
            //insert
            string val = "DOG";//std::to_string((char)(rand()%40));
            if(!insert(db, std::to_string(n+1), val)){
                cout << "INSERT ERROR" << endl;
            } else {
                inserted_values.push_back(std::to_string(n+1));
                ins++;
            }
            // cout << "inserting: (" << std::to_string(n+1) << ", " << val << ")."<<endl;
        } else if (r < percent_insert + percent_lookup) {
            //lookup
            if(!inserted_values.empty()){
                int k_len = inserted_values.size();
                int index = rand() % k_len;
                std::list<std::string>::iterator it = inserted_values.begin();
                std::advance(it, index);
                string lookup_key  = *it;
                
                // cout << "Looking up key: " << lookup_key;
                if(lookup(db, lookup_key).empty()){
                    cout << "Lookup error" << endl;
                } else {
                    // cout << " Success" << endl;
                    lkup++;
                }
            }
        } else if (r < percent_insert + percent_lookup + percent_delete){
            // delete
            if(!inserted_values.empty()){
                int k_len = inserted_values.size();
                int index = rand() % k_len;
                std::list<std::string>::iterator it = inserted_values.begin();
                std::advance(it, index);
                string lookup_key  = *it;
                // string lookup_key = inserted_values[index];
                // cout << "deleting key: " << lookup_key << endl;
                if(!remove(db, lookup_key)){
                    cout << "Delete error" << endl;
                } else {
                    // cout << " Success" << endl;
                    inserted_values.erase(it);
                    del++;
                }
            }
        }
        n++;
        // end = chrono::high_resolution_clock::now();
        // chrono::duration<double> elapsed_time = chrono::duration_cast<chrono::duration<double>>(chrono::high_resolution_clock::now() - start);

    }
    chrono::high_resolution_clock::time_point end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed_time = chrono::duration_cast<chrono::duration<double>>(end - start);

    std::cout << "It took me " << elapsed_time.count()*1000 << "ms (" << elapsed_time.count() << " seconds)" << endl;
    cout << "COMPLETED: " << (n - pre_population_size) << " (" << (n - pre_population_size) - (del + ins + lkup) << " failed)" << endl;
    cout << "Inserts: " << ins << endl;
    cout << "Lookup: " << lkup << endl;
    cout << "Delete: " << del << endl;
    delete db;
    cout << "Completed test." << endl;

    return 0;
}