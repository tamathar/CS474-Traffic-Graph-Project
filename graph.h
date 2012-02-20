#ifndef Graph_h
#define Graph_h
#include <iostream>
#include "road.h"
#include "intersection.h"
#include "event.h"
using namespace std;

namespace tfg
{
	class Graph	
	{
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
			bool UpdateGraph(criteria parameter);
			
			//These two are mainly for creating our graph when it is first being built.
			//probably will be called several times at the beginning of the client code
			//and then not touched again
			void AddIntersection(const Intersection & intersection);
			void AddRoad(const Road & road);
			
			//These might not need to be used, but w/o them we have no way of removing data.
			//could be used for what if purposes?
			void RemoveIntersection(const Intersection & intersection);
			void RemoveRoad(const Road & road);
			
			//We have no setters for Roads or Intersections b/c we don't really want ppl
			//changing where our roads are
			const Road * GetRoads();
			const Intersection * GetIntersections();
			
			//Standard getters and setters for how many roads/intersections
			//we have in our system.
			int GetNumRoads();
			void SetNumRoads();
			int GetNumIntersections();
			void SetNumIntersections();
			
		private:
			//A dynamic array of all our roads
			Road * roads;
			
			//how many roads are in our array
			int numRoads;
			
			//A dynamic array of all our intersections
			Intersection * intersections;
			
			//how many intersections are in our array
			int numIntersections;

	}
	
	
	
	
		
}
#endif	