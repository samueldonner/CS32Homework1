//
//  Header.h
//  CS32Homework1
//
//  Created by Samuel Donner on 1/16/16.
//  Copyright © 2016 Samuel Donner. All rights reserved.
//

#ifndef Header_h
#define Header_h

class Map
{
public:
    Map();         // Create an empty map (i.e., one with no key/value pairs)
    
    bool empty();  // Return true if the map is empty, otherwise false.
    
    int size();    // Return the number of key/value pairs in the map.
    
    bool insert(const std::string& key, const double& value);
    // If key is not equal to any key currently in the map, and if the
    // key/value pair can be added to the map, then do so and return true.
    // Otherwise, make no change to the map and return false (indicating
    // that either the key is already in the map, or the map has a fixed
    // capacity and is full).
    
    bool update(const std::string& key, const double& value);
    // If key is equal to a key currently in the map, then make that key no
    // longer map to the value it currently maps to, but instead map to
    // the value of the second parameter; return true in this case.
    // Otherwise, make no change to the map and return false.
    
    bool insertOrUpdate(const std::string& key, const double& value);
    // If key is equal to a key currently in the map, then make that key no
    // longer map to the value it currently maps to, but instead map to
    // the value of the second parameter; return true in this case.
    // If key is not equal to any key currently in the map and if the
    // key/value pair can be added to the map, then do so and return true.
    // Otherwise, make no change to the map and return false (indicating
    // that the key is not already in the map and the map has a fixed
    // capacity and is full).
    
    bool erase(const std::string& key);
    // If key is equal to a key currently in the map, remove the key/value
    // pair with that key from the map and return true.  Otherwise, make
    // no change to the map and return false.
    
    const bool contains(const std::string& key);
    // Return true if key is equal to a key currently in the map, otherwise
    // false.
    
    const bool get(const std::string& key, double& value);
    // If key is equal to a key currently in the map, set value to the
    // value in the map that that key maps to, and return true.  Otherwise,
    // make no change to the value parameter of this function and return
    // false.
    
    const bool get(int i, std::string& key, double& value);
    // If 0 <= i < size(), copy into the key and value parameters the
    // key and value of one of the key/value pairs in the map and return
    // true.  Otherwise, leave the key and value parameters unchanged and
    // return false.  (See below for details about this function.)
    
    void swap(Map& other);
    // Exchange the contents of this map with the other one.
};

#endif /* Header_h */
