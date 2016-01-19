#include <iostream>
#include "newMap.h"

using namespace std;

Map::Map()
{
    sizeCounter = 0;
    m_maximumSize = DEFAULT_MAX_ITEMS;
    pairs = new dataStruct[DEFAULT_MAX_ITEMS];
    
}

Map::Map(int mapSize)
{
    sizeCounter = 0;
    m_maximumSize = mapSize;
    pairs = new dataStruct[mapSize];
}

Map::Map(const Map& other)
{
    m_maximumSize = other.m_maximumSize;
    sizeCounter = other.sizeCounter;
    pairs = new dataStruct[DEFAULT_MAX_ITEMS];
    for( int i = 0; i < other.size(); i++ )
    {
        KeyType keyHolder;
        ValueType valueHolder;
        
        other.get(i, keyHolder, valueHolder);
        insert(keyHolder, valueHolder);
    }
}

Map& Map::operator=(const Map& rhs)
{
    if(&rhs != this)
    {
        delete [] pairs;
        Map mapHolder(rhs);
        m_maximumSize = mapHolder.m_maximumSize;
        pairs = new dataStruct[mapHolder.m_maximumSize];
        sizeCounter = rhs.sizeCounter;
        for( int i = 0; i < rhs.size(); i++ )
        {
            KeyType keyHolder;
            ValueType valueHolder;
            
            mapHolder.get(i,keyHolder,valueHolder);
            insert(keyHolder,valueHolder);
        }
    }
    return *this;
}

Map::~Map()
{
    delete [] pairs;
}

bool Map::empty() const
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

int Map::size() const
{
    return sizeCounter;
}

bool Map::insert(const KeyType& key, const ValueType& value)
{
    if (contains(key) || size()>=m_maximumSize)
    {
        return false;
    }
    
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

bool Map::contains(const KeyType& key) const
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

bool Map::get(const KeyType& key, ValueType& value) const
{
    for( int i = 0; i < sizeCounter; i++ )
    {
        if(key == pairs[i].key)
        {
            value = pairs[i].value;
            return true;
        }
        
    }
    return false;
}

bool Map::get(int i, KeyType& key, ValueType& value) const
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
    Map tempMap;
    tempMap = other;
    other = *this;
    *this = tempMap;
    
}



