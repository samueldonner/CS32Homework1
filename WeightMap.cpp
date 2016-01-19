#include <iostream>
#include "WeightMap.h"

using namespace std;

WeightMap::WeightMap()
{
    Map m_weightMap;
}

bool WeightMap::enroll(std::string name, double startWeight)
{
    if(!m_weightMap.contains(name) && m_weightMap.size()<DEFAULT_MAX_ITEMS)
    {
        
    }
}

const double weight(std::string name)
{
    return 0;
}

bool adjustWeight(std::string name, double amt)
{
    return true;
}

const int size()
{
    return 0;
}

const void print()
{
    
}