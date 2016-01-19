//
//  Map.cpp
//  CS32Homework1
//
//  Created by Samuel Donner on 1/18/16.
//  Copyright © 2016 Samuel Donner. All rights reserved.
//

#include <iostream>
#include "Map.h"

using namespace std;

Map::Map()
{
    sizeCounter = 0;
}

const bool Map::empty()
{
    if( sizeCounter == 0 )
    {
        return true;
    }
    else
    {
        return false;
    }
}

const int Map::size()
{
    return sizeCounter;
}

bool Map::insert(const KeyType& key, const ValueType& value)
{
    if (contains(key))
        return false;
    
    pairs[sizeCounter].key = key;
    pairs[sizeCounter].value = value;
    sizeCounter++;
    return true;
}

bool Map::update(const KeyType& key, const ValueType& value)
{
    for( int i = 0; i < sizeCounter; i++ )
    {
        if(key == pairs[i].key)
        {
            pairs[i].value = value;
            return true;
        }
        
    }
    return false;
}

bool Map::insertOrUpdate(const KeyType& key, const ValueType& value)
{
    for( int i = 0; i < sizeCounter; i++ )
    {
        if(key == pairs[i].key)
        {
            pairs[i].value = value;
            return true;
        }
        
    }
    if( sizeCounter < DEFAULT_MAX_ITEMS-1 )
    {
        sizeCounter++;
        pairs[sizeCounter].key = key;
        pairs[sizeCounter].value = value;
        return true;
    }
    
    return false;
}

bool Map::erase(const KeyType& key)
{
    if(size()==1)
    {
        if(pairs[0].key == key)
        {
            sizeCounter--;
            return true;
        }
        
        return false;
    }
    else
    {
        for( int i = 0; i < sizeCounter; i++ )
        {
            if(key == pairs[i].key)
            {
                KeyType keyHolder;
                ValueType valueHolder;
                
                keyHolder = pairs[i].key;
                valueHolder = pairs[i].value;
                
                pairs[i].key = pairs[sizeCounter-1].key;
                pairs[i].value = pairs[sizeCounter-1].value;
                
                sizeCounter--;
                
                return true;
            }
            
        }
    }//end else
    return false;
}

const bool Map::contains(const KeyType& key)
{
    for( int i = 0; i < sizeCounter; i++ )
    {
        if(key == pairs[i].key)
        {
            return true;
        }
        
    }
    return false;
}

const bool Map::get(const KeyType& key, ValueType& value)
{
    for( int i = 0; i < sizeCounter; i++ )
    {
        if(key == pairs[i].key)
        {
            pairs[i].value = value;
            return true;
        }
        
    }
    return false;
}

const bool Map::get(int i, KeyType& key, ValueType& value)
{
    if( i >= 0 && i < size() )
    {
        key = pairs[i].key;
        value = pairs[i].value;
        return true;
    }
    return false;
}

void Map::swap(Map& other)
{
    dataStruct temp[DEFAULT_MAX_ITEMS];
    int otherSize = other.size();
    int thisMapSize = size();
    
    for( int i = 0; i < otherSize; i++ )
    {
        KeyType keyHolder;
        ValueType valueHolder;
        
        other.get(i,keyHolder,valueHolder);
        temp[i].key = keyHolder;
        temp[i].value = valueHolder;
        //copies other into temp
    }
    
    for( int i = 0; i < thisMapSize; i++ )
    {
        KeyType keyHolder;
        ValueType valueHolder;
        
        get(i,keyHolder,valueHolder);
        other.pairs[i].key = keyHolder;
        other.pairs[i].value = valueHolder;
        //copies thisMap into other
    }
    
    for( int i = 0; i < otherSize; i++)
    {
        insert(temp[i].key, temp[i].value);
    }
    
    int tempSize;
    tempSize = other.size();
    other.sizeCounter = thisMapSize;
    sizeCounter = tempSize;
    
    
}



