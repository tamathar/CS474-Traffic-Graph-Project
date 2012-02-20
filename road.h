/*
 *
 * Created By Joseph Quigley 02/18/2011
 * 
 */

#ifndef Road_h
#define Road_h
#include <iostream>
#include "Intersection.h"
using namespace std;

namespace tfg
{
	class Road	
	{
    public:
        //Default constructors will not work because of dynamic arrays
        Road();
        Road(const Road & other);
        Road(Intersection *mBeginning, Intersection *mEnd); //
        ~Road();
        
        
        //Consting all getters so that they can be called by any const refs
        int GetID() const; //Get automatically-generated ID
        
        int GetCurrentTravel() const;
        void SetCurrentTravel(int time);
        
        int GetAverageTravel();
        void SetAverageTravel(int time) const;
        
        int GetUsage() const;
        void SetUsage(int num);
        
        bool IsBlocked() const;
        void SetBlocked(bool isBlocked);
        
        bool IsOneWay() const;
        void SetOneWay(bool isOneWay);
        
        string GetName() const;
        void SetName(string mName);
        
        //Road objects are broken up into the segments between intersections/nodes
        bool SetBeginning(Intersection *intersection);
        bool SetBeginning(unsigned long iID);
        
        bool SetEnd(Intersection *intersection);
        bool SetEnd(unsigned long iID);
        
    private:
        const unsigned long maxID; //Auto-inc when creating a new road. That way every road has a UID
        
        unsigned long myID;
        unsigned long currentTravel; //Unsigned gives more space, time can't be negative
        unsigned short averageTravel; //average time can be teeny
        unsigned int usage;
        bool blocked:1; //Using a bitfield to save space, since there could be millions of road objects on a map
        bool oneWay:1;
        string name;
        Intersection *beginning;
        Intersection *end;
        
	}    
}
#endif	