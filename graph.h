#ifndef Graph_h
#define Graph_h
#include <iostream>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "road.h"
using namespace std;

class Symbol {
public:
    const string Blocked;
    const string OneWay;
    const string TwoWay;
    const string Intersection;
    const string HeavyTraffic;
    const string ModerateTraffic;
    const string LightTraffic;
    const string NoTraffic;
    
    string Name(string &name) const { return "[label=\"" + name + "\"]"; };
    static Symbol* Get();
    
private:
    Symbol() : // Private so that it can  not be called
    Blocked("[color=red]"),
    OneWay("->"),
    TwoWay("--"),
    Intersection("[shape=point]"),
    HeavyTraffic("[color=orange]"),
    ModerateTraffic("[color=yellow]"),
    LightTraffic("[color=green]"),
    NoTraffic(LightTraffic)
    {};
    
    Symbol(Symbol const&);             // copy constructor is private
    Symbol& operator=(Symbol const&);  // assignment operator is private
    static Symbol* m_pInstance;

};


class Graph {
    public:
        //This will be used for rendering the graph to show different traffic condintions
        enum Criteria
        {
            Usage,				//number of cars using road
            Congestion,			//current travel time
            AverageCongestion,	//overall travel time
            Accidents,			//show accidents on map
            AccidentHistory,	//How deadly is your road?
            All					//show ALL the data  XD
        };
                
        Graph(Road &sourceRoad);
        Graph(const Graph & other);
        
    private:
        Graph();
        void TraverseGraph(ofstream &output, Road &road);

};
	
		
#endif	