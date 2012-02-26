/*
 *
 * Created By Joseph Quigley 02/18/2011
 * 
 */

#ifndef Road_h
#define Road_h
#include <iostream>
#include "intersection.h"
using namespace std;

namespace tfg
{
	class Road	
	{
    public:
        //Default constructor is not allowed due to needing beginning and end. Can be constructed w/ or w/o a name
        Road(Intersection *mBeginning, Intersection *mEnd); 
        Road(Intersection *mBeginning, Intersection *mEnd, string mName); 
        
        
        //Consting all getters so that they can be called by any const refs
        int GetID() const; //Get automatically-generated ID
        
        int GetCurrentTravel() const;
        void SetCurrentTravel(int time);
        
        int GetAverageTravel();
        void SetAverageTravel(int time) const;
        
        int GetCurrentUsage() const;
        void SetCurrentUsage(int num);
		
		int GetAverageUsage() const;
        void SetAverageUsage(int num);
        
		int GetAccidents() const;
		//no setter because its only supposed to be changed with accidents
		
        bool IsBlocked() const;
        void SetBlocked(bool isBlocked);
        
        bool IsOneWay() const;
        void SetOneWay(bool isOneWay);
        
        string GetName() const;
        void SetName(string mName);
        
        //Road objects are broken up into the segments between intersections/nodes
        bool SetBeginning(Intersection *intersection);

        
        bool SetEnd(Intersection *intersection);
		
		bool operator==(const Road &other) const;
		const Road & operator=(const Road &other);
		
    private:
		//Road(); //we don't want the class to ever not have a beginning and end, so we don't want ppl calling the default
		
        const unsigned long maxID; //Auto-inc when creating a new road. That way every road has a UID
        
        unsigned long myID;
        unsigned long currentTravel; //Unsigned gives more space, time can't be negative
        unsigned short averageTravel; //average time can be teeny
		unsigned int currentUsage; //for use with currentTravel
        unsigned int overallUsage; //for use with averageTravel
		unsigned int accidents;
        bool blocked:1; //Using a bitfield to save space, since there could be millions of road objects on a map
        bool oneWay:1;
        string name;
        Intersection *beginning;
        Intersection *end;
        
	}    
}
#endif	
