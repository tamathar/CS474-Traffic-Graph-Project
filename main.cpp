//
//  main.cpp
//  Traffic-Graph-API
//
//  Created by Joseph Quigley on 3/3/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "graph.h"

using namespace std;

int main() {
    Road one, two, three, four;
    
    one.SetBeginning(&one);
    one.SetEnd(&two);
    
    two.SetBeginning(&three);
    two.SetEnd(&one);
    
    three.SetBeginning(&four);
    three.SetEnd(&one);
    
    four.SetBeginning(&one);
    four.SetEnd(&two);
        
    one.SetName("Campus Ct");
    two.SetName("Ambler");
    three.SetName("Judge Ely");
    three.SetOneWay(true);
    
    four.SetName("16th");
    
    
    Road five(two);
    five.SetBeginning(&three);
    five.SetEnd(&four);
    
    
    Graph newGraph(one);
    
    cout << "Done\n";
}