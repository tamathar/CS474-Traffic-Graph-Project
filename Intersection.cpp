/*************************************************************************
 * Author: Thomas Scroggins
 * Program: Intersection.cpp
 * Description: This is the implementation of the Intersection class for
 * 				 for the Traffic Graph API
 *************************************************************************/

#include "intersection.h"
using namespace std;


namespace tfg
{

        //=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-Constructors/Destructor=-=-=-=-=-=-=-=-=-=-=-
      unsigned long Intersection::maxID = 0;

		
        Intersection::Intersection()
			:myID(maxID++),
			 usage(0),
			 accidents(0),
			 blocked(0),
			 wasTraversed(0),
			 arraySize(1),
			 elementCount(0)
		{	
			
            roads = new RoadObj[arraySize];
            
            /*
            roads = new Road*[arraySize];
			intersections = new Intersection*[arraySize];
            */
		}
		
        Intersection::Intersection(const Intersection & other)
			:myID(maxID++),
			 usage(other.usage),
			 accidents(other.accidents),
			 blocked(other.blocked),
			 wasTraversed(0),
			 arraySize(other.arraySize),
			 elementCount(other.elementCount)			 
		{
			
            
            roads = new RoadObj[arraySize];
            /*
            roads = new Road*[arraySize];
			intersections = new Intersection*[arraySize];
            */
            
            
			for(int i = 0; i < elementCount; i++)
			{
				/*roads[i] = other.roads[i];
				intersections[i] = other.intersections[i];
                */
                
                roads[i] = other.roads[i];
			}
		}
		
   		Intersection::~Intersection()
		{
			delete []roads;
			//delete []intersections;
		}
        
        //=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-Getters/Setters=-=-=-=-==-=-=-=-=-=-=-=-=-
        //All getters are standard. Setters are explained individually.
        int Intersection::GetID() const
        {
            return (int)myID;
        }
		
        
		int Intersection::GetElementCount() const
		{
			 return elementCount;
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
		
		//Standard setter
		void Intersection::IncrementAccidents()
		{
			accidents++;
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
        
	    void Intersection::SetTraversed(bool state) 
	    {
            wasTraversed = state;
        }

        bool Intersection::GetTraversed()
        {
            return wasTraversed;
        }
		
		//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-Add Roads=-=-=-=-=-=-=-=-=-=-=-=-=-=-
		
        void Intersection::AddRoad(Road *mRoad, Intersection *mIntersection)
		{
			AddRoadWork(mRoad, mIntersection);
			mIntersection->AddRoadWork(mRoad, this);
		}

		void Intersection::AddRoadWork(Road *mRoad, Intersection *mIntersection)
		{
			if(elementCount == arraySize)
			{
				arraySize *= 2;
                RoadObj *rtemp = new RoadObj[arraySize];
				//Road **rtemp = new Road*[arraySize];
				//Intersection **itemp = new Intersection*[arraySize];

				for(int i = 0; i < elementCount; i++)
				{
					/*rtemp[i] = roads[i];
					itemp[i] = intersections[i];				
                    */
                    
                    rtemp[i] = roads[i];
				}
				delete []roads;
				//delete []intersections;
				roads = rtemp;
				//intersections = itemp;
			}
			roads[elementCount].road = mRoad;
            roads[elementCount++].intersection = mIntersection;
			//intersections[elementCount++] = mIntersection;			
		}
		
		//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-Overloaders=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
		bool Intersection::operator==(const Intersection &other) const
		{
			if(elementCount != other.elementCount)
				return 0;
			
			for(int i = 0; i < elementCount; i++)
				//if(intersections[i] != other.intersections[i])
                if(roads[i].intersection != other.roads[i].intersection)
					return 0;

			return 1;
		}
		
		const Intersection & Intersection::operator=(const Intersection &other)
		{
			usage = other.usage;
			blocked = other.blocked;
			elementCount = other.elementCount;
			arraySize = other.arraySize;
			
			delete []roads;
			//delete []intersections;
			
            
            roads = new RoadObj[arraySize];
			//roads = new Road*[arraySize];
			//intersections = new Intersection*[arraySize];
			
			for(int i = 0; i < elementCount; i++)
			{
				roads[i] = other.roads[i];
				//intersections[i] = other.intersections[i];
			}
            
            return *this;
		}

		Road * Intersection::FindRoad( Intersection * end)
		{
			for(int i = 0; i < elementCount; i++)
			{
				//if(end == intersections[i])
                if(end == roads[i].intersection)
					return roads[i].road;
			}
			return NULL;
		}   

        Intersection::RoadObj *Intersection::GetRoads()
        {
            return roads;
        }
        
//		Road ** Intersection::GetRoads()
//        {
//        	return roads;
//        }
//
//		Intersection ** Intersection::GetIntersections()
//        {
//        	return intersections;
//        }

}        

        /*const unsigned long maxID;
        unsigned long myID;
        unsigned int usage;
        bool blocked:1; //Using a bitfield to save space, since there could be millions of Intersection objects on a map
        Road *roads;
		int roadCount;*/
        
    
