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
Graph::Graph(Road &sourceRoad) {
    
    string outputFileName = "graph.data";
    string renderedGraphFileName = "trafficgraph.png";
    ofstream output;
    output.open (outputFileName.c_str() );
    if (output.is_open() ) {
        output << "graph RoadAnalysis {\n";
        output << "node [shape=point];\n";
        TraverseGraph(output, sourceRoad);
        output << "}";
        output.close();
        
        
        if(fork() == 0) { //Child process
            string command = "neato -Tpng " + outputFileName + " -o " + renderedGraphFileName;
            FILE * file = popen(command.c_str(), "w");
            pclose(file);
            
            #if __APPLE__ //Open Preview on the Mac for the image just rendered
            command = "open " + renderedGraphFileName;
            file = popen(command.c_str(), "w");
            pclose(file);
            #endif
            
            exit(0);
        }
    }
}

/*============================================
 *
 * Private Member Functions
 *
 ============================================*/
void Graph::TraverseGraph(ofstream &output, Road &road) {
    if (&road != 0) {
        if (!road.GetTraversed() ) {
            road.SetTraversed(true);
            
            Road *beginning  = road.GetBeginning();
            Road *end  = road.GetEnd();
            
            
            string edgeType = road.IsOneWay() == true ? " -> " : " -- ";
            string roadStatus = road.IsBlocked() == true ? " [color=red] " : "[color=green] ";
            
            
            for (int i=0; i<2; i++) {
                Road *tmpRoad = beginning;
                string name = road.GetName();
                
                if (i == 1) {
                    tmpRoad = end;
                    name = end->GetName();
                }
                
                string label = " [label=\"" + name + "\"] ";
                
                if (tmpRoad != 0) {
                    if (!tmpRoad->GetTraversed() ) {
                        output << road.GetID() << edgeType << tmpRoad->GetID() << roadStatus << label << ";\n";
                    }
                }
                
                
            }
            
            
            TraverseGraph(output,  *beginning);
            TraverseGraph(output,  *end);
        }
    }
}