/*
 *
 * Created By Joseph Quigley 02/18/2011
 * 
 */

#ifndef Intersection_h
#define Intersection_h
#include <iostream>
#include "road.h"
using namespace std;

//namespace tfg
//{

	class Intersection	
	{
    public:
        //Default constructors will not work because of dynamic arrays
        Intersection();
        Intersection(const Intersection & other);
        Intersection(class Road *mRoads, int mRoadCount); //Array of Road
        ~Intersection();
        
        
        //Consting all getters so that they can be called by any const refs
        int GetID() const; //Get automatically-generated ID
        
        int GetRoadCount() const;
        void SetRoadCount(int num);
        
        int GetUsage() const;
        void SetUsage(int num);
        
		int GetAccidents() const;
		// no setter because its only supposed to be messed with by an accident
		
        bool IsBlocked() const;
        void SetBlocked(bool isBlocked);
        
        void AddRoad(Road *mRoad);
        
        bool RemoveRoad(Road *mRoad);
        
		bool operator==(const Intersection &other) const;
		const Intersection & operator=(const Intersection &other);        
        
    private:
        static unsigned long maxID; //Auto-inc when creating a new Intersection. That way every Intersection has a UID
        unsigned long myID;
        unsigned int usage;
		    unsigned int accidents;
        bool blocked:1; //Using a bitfield to save space, since there could be millions of Intersection objects on a map
        Road *roads;
		    int arraySize;
		    int roadCount;
        
	};    
//}
#endif	
