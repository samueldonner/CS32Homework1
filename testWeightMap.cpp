//
//  testWeightMap.cpp
//  CS32Homework1
//
//  Created by Samuel Donner on 1/18/16.
//  Copyright © 2016 Samuel Donner. All rights reserved.
//

#include "WeightMap.h"
#include <iostream>
#include <cassert>

using namespace std;

int main()
{
    
    WeightMap weightLoss;
    
    assert(weightLoss.size()==0);
    
    assert(weightLoss.enroll("Blah", -0.01)==false);
    assert(weightLoss.enroll("Jeff", 10.00)==true);
    assert(weightLoss.enroll("Jeff", 2.00)==false);
    assert(weightLoss.size()==1);
    assert(weightLoss.weight("Jeff")==10);
    
    cout << "All tests passed!" << endl;
}