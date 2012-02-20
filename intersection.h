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

namespace tfg
{
	class Intersection	
	{
    public:
        //Default constructors will not work because of dynamic arrays
        Intersection();
        Intersection(const Intersection & other);
        Intersection(Road *mRoads); //Array of Road
        ~Intersection();
        
        
        //Consting all getters so that they can be called by any const refs
        int GetID() const; //Get automatically-generated ID
        
        int GetNumRoads() const;
        void SetNumRoads(int num);
        
        int GetUsage();
        void SetUsage(int num) const;
        
        bool IsBlocked() const;
        void SetBlocked(bool isBlocked);
        
        bool AddRoad(Road *mRoad);
        bool AddRoad(unsigned long rID);
        
        bool RemoveRoad(Road *mRoad);
        bool RemoveRoad(unsigned long rID);
        
        
    private:
        const unsigned long maxID; //Auto-inc when creating a new Intersection. That way every Intersection has a UID
        
        unsigned long myID;
        unsigned int usage;
        bool blocked:1; //Using a bitfield to save space, since there could be millions of Intersection objects on a map
        Road *roads;
        
	}    
}
#endif	