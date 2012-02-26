/*************************************************************************
 * Author: Thomas Scroggins
 * Program: Intersection.cpp
 * Description: This is the implementation of the Intersection class for
 * 				 for the Traffic Graph API
 *************************************************************************/

#include <iostream>
#include "road.h"
using namespace std;

namespace tfg
{
        //=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-Constructors/Destructor=-=-=-=-=-=-=-=-=-=-=-
		
        Intersection::Intersection()
			:myID(maxID++),
			 usage(0),
			 blocked(0),
			 arraySize(1),
			 numRoads(0)
		{	
			*roads = new Road[arraySize];
		}
		
        Intersection::Intersection(const Intersection & other)
			:myID(other.myID),
			 usage(other.usage),
			 blocked(other.blocked),
			 arraySize(other.arraySize),
			 roadCount(other.roadCount)
		{
			*roads = new Road[arraySize];
			for(int i = 0; i < roadCount; i++)
				roads[i] = other.roads[i];
		}
		
        Intersection::Intersection(Road *mRoads, int mRoadCount)
			:myID(maxID++),
			 usage(0),
			 blocked(0),
			 arraySize(mRoadCount),
			 numRoads(mRoadCount)
		{
			*roads = new Road[arraySize];
			for(int i = 0; i < roadCount; i++)
				roads[i] = other.roads[i];
		}
		
        Intersection::~Intersection()
		{
			delete []roads;
		}
        
        //=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-Getters/Setters=-=-=-=-==-=-=-=-=-=-=-=-=-
        //All getters are standard. Setters are explained individually.
		
		
        int Intersection::GetID() const
		{
			return maxID;
		}
        
		int Intersection::GetRoadCount() const
		{
			 return roadCount;
		}
		
		//This is a standard setter
		void Intersection::SetRoadCount(int num)
		{
			roadCount = num;
		}
        
        int Intersection::GetUsage() const
		{
			return usage;
		}
        
		//Standard setter
		void Intersection::SetUsage(int num)
		{
			usage = num;
		}
        
		int Intersection::GetAccidents() const
		{
			return accidents;
		}
		
        bool Intersection::IsBlocked() const
		{
			return blocked;
		}
        
		//standard setter
		void Intersection::SetBlocked(bool isBlocked)
		{
			if(isBlocked)
				blocked = 1;
			else
				blocked = 0;
		}
        
		
		
		//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-Add/Remove Roads=-=-=-=-=-=-=-=-=-=-=-=-=-=-
		
        void Intersection::AddRoad(Road *mRoad)
		{
			if(roadCount == arraySize)
			{
				arraySize *= 2;
				Road *temp = new Road[arraySize];
				for(int i = 0; i < roadCount; i++)
					temp[i] = roads[i];
				delete []roads;
				roads = temp;
			}
			
			roads[roadCount++] = *mRoad;
		}
        
        bool Intersection::RemoveRoad(Road *mRoad)
		{
			for( int i = 0; i < roadCount; i++)
				if(roads[i] == *mRoad)
				{
					roads[i] = roads[--roadCount];
					return true;
				}
				
			return false;
		}
		
		
		//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-Overloaders=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
		bool operator==(const Intersection &other) const
		{
			if(myID = other.myID)
				return true;
				
			return false;
		}
		
		const Intersection & operator=(const Intersection &other)
		{
			myID = other.myID;
			usage = other.usage;
			blocked = other.blocked;
			roadCount = other.roadCount;
			delete []roads;
			roads = new Road[roadCount];
			for(int i = 0; i < roadCount; i++)
				roads[i] = other.roads[i];
		}
}
        /*const unsigned long maxID;
        unsigned long myID;
        unsigned int usage;
        bool blocked:1; //Using a bitfield to save space, since there could be millions of Intersection objects on a map
        Road *roads;
		int roadCount;*/
        
    
