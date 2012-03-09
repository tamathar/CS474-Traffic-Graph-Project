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
        //Default constructors will not work because of dynamic arrays
        Intersection();
        Intersection(const Intersection & other);
        ~Intersection();
        
        
        //Consting all getters so that they can be called by any const refs
        int GetID() const; //Get automatically-generated ID
        
        int GetElementCount() const;
        void SetElementCount(int num);
        
        int GetUsage() const;
        void SetUsage(int num);
        
		int GetAccidents() const;
		void IncrementAccidents();
		
        bool IsBlocked() const;
        void SetBlocked(bool isBlocked);
         
        void SetTraversed(bool state);
        bool GetTraversed();
               
        void AddRoad(Road *mRoad, Intersection *mIntersection);
        void AddRoadWork(Road *mRoad, Intersection *mIntersection);
        
		bool operator==(const Intersection &other) const;
		const Intersection & operator=(const Intersection &other);     
		
		// a getter for the event function to find things
		Road * FindRoad(Intersection * end);
        
    private:
        static unsigned long maxID; //Auto-inc when creating a new Intersection. That way every Intersection has a UID
        unsigned long myID;
        unsigned int usage;
		unsigned int accidents;
        bool blocked:1; //Using a bitfield to save space, since there could be millions of Intersection objects on a map
		bool wasTraversed:1; //For generating the graph from any starting road
		int arraySize;
		int elementCount;
        Road **roads;
		Intersection **intersections;

        
	};    
}
#endif	
