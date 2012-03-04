#ifndef Graph_h
#define Graph_h
#include <iostream>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "road.h"
#include "intersection.h"
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
                
        //defaults constructors will not work because of our dynamic arrays
        Graph();
        Graph(const Graph & other);
        ~Graph();
        
        
        //This is our main function that will actually pass our data to 
        //GraphViz and will render the graph
        bool UpdateGraph(Criteria parameter) const; //Synonymn for CreateGraph
        bool UpdateGraph() const; //Synonymn for CreateGraph
    
        bool CreateGraph(Criteria parameter) const;
        bool CreateGraph() const;
        
        //These two are mainly for creating our graph when it is first being built.
        //probably will be called several times at the beginning of the client code
        //and then not touched again
        void AddRoad(const Road &road);
        
        //These might not need to be used, but w/o them we have no way of removing data.
        //could be used for what if purposes?
        void RemoveRoad(const Road &road);
        
        Road *GetRoads();
        
        //Standard getters and setters for how many roads/intersections
        //we have in our system.
        int GetNumRoads() const;
    
        string GraphToString() const;
        
    private:
        //A dynamic array of all our intersections
        Road *roads;
        Intersection *intersections;
        
        //how many intersections are in our array
        int dataSize;
        int numRoads;
    
        int intersectionDataSize;
        int numIntersections;

};
	
		
#endif	