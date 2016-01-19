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
#include <sstream>

using namespace std;

int main()
{
    
    WeightMap weightLoss;
    
    assert(weightLoss.size()==0);
    
    assert(weightLoss.enroll("Jacob", -3.14)==false);
    assert(weightLoss.enroll("Sam", 100.00)==true);
    assert(weightLoss.enroll("Sam", 70.00)==false);
    assert(weightLoss.size()==1);
    assert(weightLoss.weight("Sam")==100);
    
    assert(weightLoss.enroll("Ben",150.00)==true);
    assert(weightLoss.size()==2);
    
    assert(weightLoss.adjustWeight("Jacob", 50) == false);
    assert(weightLoss.adjustWeight("Sam", -50.00) == true);
    assert(weightLoss.weight("Sam") == 50.00);
    
    assert(weightLoss.adjustWeight("Sam",0)==true);
    assert(weightLoss.weight("Sam")==50);
    
    assert(weightLoss.enroll("Abs", 120.00)==true);
    assert(weightLoss.enroll("Georgie", 700.00)==true);
    
    weightLoss.print();
    
    assert(weightLoss.size() == 4);
    
    WeightMap weightLoss2;
    
    weightLoss2 = weightLoss;
    
    assert(weightLoss2.size() == 4);
    assert(weightLoss.weight("Sam")==50);
    assert(weightLoss2.enroll("Fatso1", 1000.00)==true);
    assert(weightLoss2.enroll("fatso2", 1000.00)==true);
    
    weightLoss2.print();
    
    
    WeightMap weightLoss3(weightLoss);
    weightLoss3.print();
    
    
    WeightMap weightLoss4;
    
    for(int i = 0; i < 200; i++ )
    {
        std:string nameHolder = "fatso" + std::to_string(i);
        weightLoss4.enroll(nameHolder, 1000.00);
    }
    
    assert(weightLoss4.size()==200);
    cout << "All tests passed!" << endl;
}