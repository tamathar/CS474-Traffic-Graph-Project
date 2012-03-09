/*
 *
 * Created By Joseph Quigley 02/18/2011
 * 
 */

#ifndef Intersection_h
#define Intersection_h
#include "road.h"
using namespace std;

namespace tfg
{

	class Intersection	
	{
    public:
        struct RoadObj {
            Road *road;
            Intersection *intersection;
        };
        
        //Default constructors will not work because of dynamic arrays
        Intersection();
        Intersection(const Intersection & other);
        ~Intersection();
        
        
        //Brief: This method returns an object's id.
        //Result: The unique ID of the class instance.
        int GetID() const;
        
        //Brief: This method returns number of RoadObj objects in an Intersection.
        //Result: The number of objects in the class instance.
        int GetElementCount() const;
        
        //Brief: This method returns the usage of the road.
        //Result: Road usage.
        int GetUsage() const;
        
        //Brief: This sets a road's usage.
        void SetUsage(int num);
        
        //Brief: This method returns the most recent nubmer of accidents since the road was cleared.
        //Result: The number of accidents.
		int GetAccidents() const;
        
        //Brief: This method returns the most recent nubmer of accidents since the road was cleared.
        //Result: The number of accidents.
        int GetLifeTimeAccidents() const;
        
        //Brief: Record a new accident
		void IncrementAccidents();
		
        //Brief: This method returns the state of the road (for accidents or maintenance).
        //Result: State of the road
        bool IsBlocked() const;
        
        //Brief: This method sets the state of the road (for accidents of maintenance).
        void SetBlocked(bool isBlocked);
        
        
        //Brief: This method links two intersections together through a road.
        void AddRoad(Road *mRoad, Intersection *mIntersection);
        
        
		bool operator==(const Intersection &other) const;
		const Intersection & operator=(const Intersection &other);     
		
		//Brief: Get a road connected to this intersection and another
		Road * FindRoad(Intersection * end);
        
        //Brief: This method returns all the roads attached to an intersection.
        RoadObj *GetRoads();
        
        //Brief: This method returns the state of the road (for accidents or maintenance).
        void AddRoadWork(Road *mRoad, Intersection *mIntersection);
        
        //Brief: Sets the traversed flag for use with floodfill algorithms
        void SetTraversed(bool state);
        
        //Brief: Gets the traversed flag for use with floodfill algorithms
        bool GetTraversed();
        
    private:
        static unsigned long maxID; //Auto-inc when creating a new Intersection. That way every Intersection has a UID
        unsigned long myID;
        unsigned int usage;
		unsigned int accidents;
        unsigned int lifeTimeAccidents;
        bool blocked:1; //Using a bitfield to save space, since there could be millions of Intersection objects on a map
		bool wasTraversed:1; //For generating the graph from any starting road
		int arraySize;
		int elementCount;
        
        RoadObj *roads;

	};    
}
#endif	
