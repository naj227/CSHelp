//hashset implementation will go here 
// i believe this is the document where we weill write 
// the functions implementing a hashset
#include <stdio.h>
#include <stdlib.h>
#include "hashset.hpp"
extern "C"{
  #include "linkedlist.h"
}
#include <iostream>


    //unsigned: a type of modifier for integer data types (a variable can only store non-negative values)
    //size_t: unsigned integer type designed to represent the size of objects in memory 
    //explicit: constructor (can be called with single arguments)

    // Initialize an empty hash set with a given number of buckets
    HashSet::HashSet(size_t insitial_size){
      bucket_count = initial_size; 
      element_count = 0; 
      load_threshold = 70; 
      load_factor = 0; 

      array = new List*[bucket_count]; 
      for(size_t i = 0; i < bucket_count; i++){
        array[i] = nullptr;  
      }
      
    
    }
  
      // Destructor: Free all allocated memory
      HashSet::~HashSet(){
        clear(); 
        delete[] array; 
      }
  
      // Generate a prehash for an item
      unsigned long HashSet::prehash(int item) const{ // CONST: the constant cannot be modified 
        return static_cast<unsigned long>(item) * 2654435761UL; 
                                                    //^ knuth's multiplicative hash constant (golden ratio prime)
      }
  
      // Convert prehash value into a valid bucket index
      unsigned long HashSet::hash(unsigned long prehash) const{
        return prehash % bucket_count; 
      }
  
      // Insert item into the set. Returns true if inserted, false if already present.
      // Rehashes if inserting will increase the load factor past the threshold.
      bool HashSet::insert(int item){
        //checking if inserting the item would exceed the load threshold 
        if((element_count +1) * 100 / bucket_count > load_threshold){
          rehash(bucket_count * 2); 
        }
      //calculating the bucket index for item 
      unsigned long bucket = hash(prehash(item)); 

      //if the bucket is empty, create a new list 
      if(array[bucket] == nullptr){
        array[bucket] = new List(); 
      }
      
        //push back calculated index to isnert the item into the list 
       HashSet[index].push_back(item); 
        return true;
    }

      //NEED TO REHASH IF INSERTING WILL INCREASE THE LOAD FACTOR 

      // Remove an item from the set. Returns true if removed, false if not found.
      bool remove(int item){
        //i probably have to insert some sort of loop
        int index = hash(item); 
        HashSet[index].remove(key); 
        return true; 
      }
  
      // Check if the item exists in the set
      bool contains(int item) const{
        int index = hash(item); 
        for(const HashSet& val : HashSet[index]){
          if(val == item){
            return true; 
          }
        }
        return false; 
      }
  
      // Return the number of elements in the hash set
      size_t HashSet::count() const{
        return element_count:
      }
  
      // Return the current load factor as a percentage
      unsigned int load() const;
  
      // Set a new load factor threshold for resizing
      void set_load_threshold(unsigned int threshold);
  
      // Remove all elements from the hash set
      void clear();
  
      // Print the hash table (format is implementation-dependent)
      void print() const;
    
/*
https://blog.devgenius.io/how-to-implement-a-hashset-data-structure-in-c-using-a-hash-table-approach-9581e51da8df 
https://en.cppreference.com/w/cpp/language/language_linkage 
*/
