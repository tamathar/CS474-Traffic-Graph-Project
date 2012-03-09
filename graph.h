#ifndef Graph_h
#define Graph_h
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "intersection.h"
#include "event.h"
#include "car.h"
#include <sstream>
using namespace std;

namespace tfg {
    class Graph {
        public:
            Graph(Intersection &sourceIntersection, double spacing); //Spacing between intersections
            Graph(const Graph & other);
            
        private:
            Graph();
            
            //Brief: This method is recursively called to create a flood fill
            void TraverseGraph(ofstream &output, Intersection &intersection);
            double edgeSpacing;

    };
}	
		
#endif	