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
    Graph::Graph(Intersection &sourceIntersection, double spacing) {
        
        edgeSpacing = spacing;
        
        string outputFileName = "graph.data";
        string renderedGraphFileName = "trafficgraph.png";
        ofstream output;
        output.open (outputFileName.c_str() );
        if (output.is_open() ) {
            output << "graph RoadAnalysis {\n";
            output << "node [shape=square];\n";
            output << "pad=\"0.5\"; overlap=scale;\n";
            
            

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
                int accidents = intersection.GetAccidents();
                if (accidents > 0) {
                    stringstream ss;
                    ss << accidents;
                    
                    string sAccidents;
                    ss >> sAccidents;
                    
                    output << intersection.GetID() << " [label=\"" << sAccidents << "\"] [color=red];\n";
                }
                else {
                    output << intersection.GetID() << " [label=\"\"];\n";
                }
                      
                
                
                
                intersection.SetTraversed(true);
                
                Intersection::RoadObj *roads = intersection.GetRoads();
                
                for (int i=0; i<intersection.GetElementCount(); i++) {
                    string name = roads[i].road->GetName();
                    
                    
                    string isOneWay = roads[i].road->IsOneWay() == true ? " [dir=forward] " : " ";
                    string roadStatus = roads[i].road->IsBlocked() == true ? " [color=red] " : " ";
                    
                    
                    
                    
                    
                    if (!roads[i].intersection->GetTraversed() ) {
                        output << intersection.GetID() << " -- " << roads[i].intersection->GetID() << roadStatus << "[label=\"" << name;
                        
                        double labelLen = edgeSpacing;
                        
                        int roadAccidents = roads[i].road->GetAccidents();
                        if (roadAccidents > 0) {
                            output << "\\nAccidents: " << roadAccidents;
                            labelLen += 1;
                        }
                        
                        
                        int time = roads[i].road->GetAverageTravel();
                        if (time > 0) {
                            output << "\\nAvg Travel: " << time;
                            labelLen += 1;
                        }
                        
                        int usageCount = roads[i].road->GetOverallUsage();
                        if (usageCount > 0) {
                            output << "\\nLifetime Usage: " << usageCount;
                            labelLen += 1;
                        }
                        
                        int currentusage = roads[i].road->GetCurrentUsage();
                        if (currentusage > 0) {
                            output << "\\nCurrent Usage: " << currentusage;
                            labelLen += 1;
                        }
                        
                        
                        if (name.length() > 10) {
                            labelLen += 3;
                        }
                        
                        output << "\"] " << isOneWay << "[len=" << labelLen << "]" << ";\n";

                    }
                    
                }
                
                for (int i=0; i<intersection.GetElementCount(); i++) {
                    TraverseGraph(output, *roads[i].intersection);
                }
            }
        }
    }
}