#include <iostream>
#include "WeightMap.h"

using namespace std;

WeightMap::WeightMap()
{
    Map m_weightMap;
}

bool WeightMap::enroll(std::string name, double startWeight)
{
    if(!m_weightMap.contains(name) && m_weightMap.size()<DEFAULT_MAX_ITEMS && startWeight >= 0.0)
    {
        m_weightMap.insert(name, startWeight);
        return true;
    }
    return false;
}

double WeightMap::weight(std::string name) const
{
    double weight;
    if( m_weightMap.get(name,weight) )
    {
        return weight;
    }
    return -1;
}

bool WeightMap::adjustWeight(std::string name, double amt)
{
    if(!m_weightMap.contains(name) || weight(name)+amt<0 )
    {
        return false;
    }
    
    double weight;
    m_weightMap.insert(name,weight+amt);
    return true;
}

int WeightMap::size() const
{
    return m_weightMap.size();
}

void WeightMap::print() const
{
    for( int i = 0; i < m_weightMap.size(); i++ )
    {
        std::string nameHolder;
        double weightHolder;
        m_weightMap.get(i, nameHolder, weightHolder);
        
        cout << nameHolder << " " << weightHolder << endl;
    }
}