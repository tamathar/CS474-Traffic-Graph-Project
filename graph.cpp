//
//  graph.cpp
//  Traffic-Graph-API
//
//  Created by Joseph Quigley on 2/28/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "graph.h"

using namespace std;

/*============================================
 *
 * Constructors
 *
 ============================================*/
Graph::Graph() {
    numIntersections = 2;
    intersections = new Intersection*[numIntersections];
}

Graph::~Graph() {
    delete[] intersections;
}


/*============================================
 *
 * Member Functions
 *
 ============================================*/
void Graph::AddIntersection(const Intersection *intersection) {
    cout << intersection->GetID();
}


void Graph::RemoveIntersection(const Intersection *intersection) {
    
}

