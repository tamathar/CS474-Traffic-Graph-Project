//
//  graph.cpp
//  Traffic-Graph-API
//
//  Created by Joseph Quigley on 2/28/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//


#include "graph.h"

using namespace std;

namespace tfg {


    /*============================================
     *
     * Constructors
     *
     ============================================*/
    Graph::Graph(Intersection &sourceIntersection) {
        
        string outputFileName = "graph.data";
        string renderedGraphFileName = "trafficgraph.png";
        ofstream output;
        output.open (outputFileName.c_str() );
        if (output.is_open() ) {
            output << "graph RoadAnalysis {\n";
            output << "node [shape=point];\n";
            TraverseGraph(output, sourceIntersection);
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
    void Graph::TraverseGraph(ofstream &output, Intersection &intersection) {
        if (&intersection != 0) {
            if (!intersection.GetTraversed() ) {
                intersection.SetTraversed(true);
                
                
                Intersection::RoadObj *roads = intersection.GetRoads();
                for (int i=0; i<intersection.GetElementCount(); i++) {                    
                    string name = roads[i].road->GetName();
                    
                    string isOneWay = roads[i].road->IsOneWay() == true ? " [dir=forward] " : " ";
                    string roadStatus = roads[i].road->IsBlocked() == true ? " [color=red] " : " ";
                    
                    
                    string label;
                    if (name.length() > 0) {
                        label = " [label=\"" + name + "\"] ";
                    }
                    
                    if (roads[i].intersection != 0) {
                        if (!roads[i].intersection->GetTraversed() ) {
                            output << intersection.GetID() << " -- " << roads[i].intersection->GetID() << roadStatus << label << isOneWay << ";\n";
                        }
                    }
                    
                    TraverseGraph(output, *roads[i].intersection);
                }
                
                
                
                /*for (int i=0; i<2; i++) {
                    Intersection *tmpRoad = beginning;
                    string name = intersection.GetName();
                    
                    if (i == 1) {
                        tmpRoad = end;
                        name = end->GetName();
                    }
                    
                    string label;
                    if (name.length() > 0) {
                        label = " [label=\"" + name + "\"] ";
                    }
                    
                    if (tmpRoad != 0) {
                        if (!tmpRoad->GetTraversed() ) {
                            output << intersection.GetID() << " -- " << tmpRoad->GetID() << roadStatus << label << isOneWay << ";\n";
                        }
                    }
                }*/
                
                
//                TraverseGraph(output,  *beginning);
//                TraverseGraph(output,  *end);
            }
        }
    }
}