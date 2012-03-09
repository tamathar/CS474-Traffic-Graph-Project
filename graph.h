#ifndef Graph_h
#define Graph_h
#include <iostream>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "Intersection.h"
#include "event.h"
using namespace std;

namespace tfg {
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
                    
            Graph(Intersection &sourceIntersection);
            Graph(const Graph & other);
            
        private:
            Graph();
            void TraverseGraph(ofstream &output, Intersection &intersection);

    };
}	
		
#endif	