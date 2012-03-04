//
//  graph.cpp
//  Traffic-Graph-API
//
//  Created by Joseph Quigley on 2/28/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//


#include "graph.h"

using namespace std;


/*============================================
 *
 * Symbol singleton
 *
 ============================================*/

// Global static pointer used to ensure a single instance of the class.
Symbol* Symbol::m_pInstance = NULL;

Symbol* Symbol::Get() {
    if (!m_pInstance)   // Only allow one instance of class to be generated.
        m_pInstance = new Symbol;
        return m_pInstance;
}


/*============================================
 *
 * Constructors
 *
 ============================================*/
Graph::Graph() {
    numRoads = -1;
    dataSize = 2;
    
    roads = new Road[dataSize];
}

Graph::~Graph() {
    delete[] roads;
}


/*============================================
 *
 * Member Functions
 *
 ============================================*/

bool Graph::UpdateGraph() const { //Synonymn for CreateGraph
    return CreateGraph();
}

bool Graph::CreateGraph() const {
    string outputFileName = "graph.data";
    string renderedGraphFileName = "trafficgraph.png";
    ofstream output;
    output.open (outputFileName.c_str() );
    if (output.is_open() ) {
        //output << GraphToString();
        output.close();
    }
    else {
        return false;
    }
    
    if(fork() == 0) { //Child process
        execl("neato", "-Tpng", outputFileName.c_str(), "-o", renderedGraphFileName.c_str() );
        exit(0);
    }
    else {
        return false;
    }
    
    return true;
}


void Graph::AddRoad(const Road &road) {
    numRoads++;
    
    cout << "AddRoad() --> numRoads = " << numRoads << endl;
    
    
    if (numRoads >= dataSize) {
        dataSize *= 2;
        Road *newRoads = new Road[dataSize];
        
        for (int i=0; i<dataSize-1; i++) {
            newRoads[i] = roads[i];
        }
        
        delete [] roads;
        roads = newRoads;
        
    }
    
    roads[dataSize] = road;
}
 
void Graph::RemoveRoad(const Road &road) {
    for (int i=0; i<dataSize; i++) {
        if (roads[i] == road) {
            if (i < dataSize) {
                roads[i] = roads[dataSize];
            }
            dataSize--;
        }
    }
}

//We have no setters for Roads or roads b/c we don't really want people
//changing where our roads are
Road *Graph::GetRoads() {
    return roads;
}

//Standard getters and setters for how many roads/roads
//we have in our system.
int Graph::GetNumRoads() const {
    return numRoads+1;
}

string Graph::GraphToString() const {
    string output = "graph Road And Road Analysis {\n";
    
    cout << "Num roads: " << GetNumRoads() << endl;
    
    for (int i=0; i<GetNumRoads(); i++) {
        
        Road road = roads[i];
        
        cout << road.GetID() << endl;
        
        /*
        Road *roads = Road->GetRoads();
        
        for (int j=0; j<Road->GetRoadCount(); j++) {
            Road road = roads[j];
            cout << road.GetName() << endl;
            //output += road.GetBeginning();
            //output += " -- "  + road.GetEnd(); 
//            + Symbol::Get()->Name(road.GetName() )
        }*/
    }
    
    output += "}";
    
    return output;
}