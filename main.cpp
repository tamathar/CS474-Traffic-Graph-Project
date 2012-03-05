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
    
    one.SetBeginning(&two);
    one.SetEnd(&three);
    
    two.SetBeginning(&three);
    two.SetEnd(&four);
    
    three.SetBeginning(&four);
    three.SetEnd(&one);
    
    Road five(two);
    
    four.SetBeginning(&one);
    four.SetEnd(&five);
        
    one.SetName("Campus Ct");
    two.SetName("Ambler");
    three.SetName("Judge Ely");
    three.SetOneWay(true);
    
    four.SetName("16th");
    
    
    
    
    
    Graph newGraph(one);
    
    cout << "Done\n";
}