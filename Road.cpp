/************************************************************************
/Author: Thomas Scroggins
/Program: Road.cpp
/Description: This is the implementation file for the road class of 
/             the tfg project API
************************************************************************/

#include "road.h"
using namespace std;


namespace tfg
{
   
	// By default roads start as two-way, but can be changed
    unsigned long Road::maxID = 0;
		  
		Road::Road()
			:myID(maxID++),
			currentUsage(0),
			overallUsage(0),
			blocked(0),
			oneWay(0)
		{}
       
		Road::Road(string name) 
			:myID(maxID++), 
			currentUsage(0), 
			overallUsage(0),
			blocked(0), 
			oneWay(0)
		{}

        Road::Road(const Road &other)
        	: myID(maxID++),
        	currentTravel(other.currentTravel),
        	averageTravel(other.averageTravel),
        	currentUsage(other.currentUsage),
        	overallUsage(other.overallUsage),
        	blocked(other.blocked),
        	oneWay(other.oneWay),
        	name(other.name)
        {}

		//=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-Getters/Setters=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
		// All getters are standard. All setters have explanation inline.
		
    	int Road::GetID() const
		{
			return (int)myID;
		}
        
    	int Road::GetCurrentTravel() const
		{
			return (int)currentTravel;
		}
       
    	int Road::GetAverageTravel() const
		{
			return averageTravel;
		}
    
		//This setter sets both average and current, and it averages it with our current value so that no one can 
		//mess with the value to much. We assume that usage has already been incremented.  
		void Road::UpdateTravel(int time)
		{
		  if(currentUsage!=0)
		    currentTravel = (time + currentTravel*(currentUsage-1))/currentUsage;
		  if(overallUsage !=0)
		  	averageTravel = (time + averageTravel*(overallUsage-1))/overallUsage;
		}
        
    	int Road::GetCurrentUsage() const
		{
			return currentUsage;
		}
		
		int Road::GetOverallUsage() const
		{
			return overallUsage;
		}
		
		//This will increment currentUsage and Overallusage, no other choice       
		void Road::IncrementUsage()
		{
		  currentUsage++;
			overallUsage++;			
		}
        
		int Road::GetAccidents() const
		{
			return accidents;
		}
		
        bool Road::IsBlocked() const
		{
			return blocked;
		}

		//For this setter, we change currentTravel and currentUsage.
		void Road::SetBlocked(bool isBlocked)
		{
			if(isBlocked)
				blocked = 1;
			else
				blocked = 0;
			
			//When we set or clear a wreck we have to reset our current travel info.
			currentTravel = 0;
			currentUsage = 0;

		}
        
        void Road::IncrementAccidents()
        {
        	accidents++;
        }
        
        bool Road::IsOneWay() const
		{
			return oneWay;
		}
        
		void Road::SetOneWay(bool isOneWay)
		{
			//This is just your basic setter
			if(isOneWay)
				oneWay = 1;
			else
				oneWay = 0;
		}
        
        string Road::GetName() const
		{
            if (this != 0) {
                return name;
            }
            return "Nothing";
		}
        
		void Road::SetName(string mName)
		{
			//basic setter
            if (this != 0) {
                name = mName;
            }
		}
 	
		
		//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-overloads=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-
		bool Road::operator==(const Road &other) const
		{
			if(myID == other.myID)
				return true;
				
			return false;
		}
		
		
		const Road & Road::operator=(const Road &other)
		{

            if (&other != this) {
                currentTravel = other.currentTravel;
                averageTravel = other.averageTravel;
                currentUsage = other.currentUsage;
                overallUsage = other.overallUsage;
                blocked = other.blocked;
                oneWay = other.oneWay;
                name = other.name;
            }
            return *this;
		}
}
