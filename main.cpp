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
using namespace tfg;

int main() {
    Intersection a, b, c, d, e, f, g,h,i;
    
    Road ambler("Ambler"), judgely("Judge Ely"), sixteenth("16th St"), campusct("Campus Ct"), judgely2("Judge Ely"), judgely3("Judge Ely"), en10("EN 10th"), en10_2("EN 10th"), en12("EN 16.5 st");
    
    ambler.SetOneWay(true);
    judgely.SetBlocked(true);
    

    a.AddRoad(&ambler, &b);
    b.AddRoad(&judgely, &c);
    c.AddRoad(&sixteenth, &d);
    d.AddRoad(&campusct, &a);
    e.AddRoad(&judgely2, &b);
    f.AddRoad(&judgely3, &c);
    g.AddRoad(&en10, &f);
    h.AddRoad(&en10_2, &f);
    c.AddRoad(&en12, &i);
    
    
    ambler.IncrementAccidents();
    ambler.IncrementAccidents();
    
    judgely.IncrementAccidents();
    
    en10.UpdateTravel(6);
    en10.UpdateTravel(19);
    
    en12.SetOneWay(true);
    
    c.IncrementAccidents();
    c.IncrementAccidents();

    
    Graph newGraph(a, 1.8);
    
    
    cout << "Done\n";
}