/************************************************************************
/Author: Thomas Scroggins
/Program: Road.cpp
/Description: This is the implementation file for the road class of 
/             the tfg project API
************************************************************************/

#include <iostream>
#include "intersection.h"
using namespace std;
//using namespace tgf;

   

		// We can't make a road without a beginning and end. Additionally, the default copy constructor will work. 
		// By default roads start as two-way, but can be changed
		   unsigned long Road::maxID = 0;
		  
      Road::Road()
        :myID(),
         currentUsage(),
         overallUsage(),
         blocked(),
         oneWay(),
         beginning(),
         end()
      {}
       
        Road::Road(Intersection * mBeginning,  Intersection * mEnd) 
			: myID(maxID++), 
			  currentUsage(0), 
			  overallUsage(0),
			  blocked(0), 
			  oneWay(0)
		{
			beginning = mBeginning;
			end = mEnd;
		}

        Road::Road( Intersection * mBeginning, Intersection  * mEnd, string mName) 
			: myID(maxID++), 
			  currentUsage(0), 
			  overallUsage(0),
			  blocked(0), 
			  oneWay(0),
			  name(mName)
		{
			beginning = mBeginning;
			end = mEnd;
		}


		//We don't have destructor bc we don't actually own the addresses of the pointers
        
		//=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-Getters/Setters=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
		// All getters are standard. All setters have explanation inline.
		
        int Road::GetID() const
		{
			return myID;
		}
        
        int Road::GetCurrentTravel() const
		{
			return currentTravel;
		}
 
		//This setter averages it with our current value so that no one can 
		//mess with the value to much. We assume that usage has already been incremented.
		void Road::SetCurrentTravel(int time)
		{
			currentTravel = (time + currentTravel*(currentUsage-1))/currentUsage;
			SetAverageTravel(time); //we want this to set the other as well   
		}
        
    int Road::GetAverageTravel() const
		{
			return averageTravel;
		}
  

		//This setter averages it with our current value so that no one can 
		//mess with the value to much. We assume that usage has already been incremented.  
		void Road::SetAverageTravel(int time)
		{           cout << overallUsage;
			averageTravel = (time + averageTravel*(overallUsage-1))/overallUsage;
		}
        
        int Road::GetCurrentUsage() const
		{
			return currentUsage;
		}
		
		//This will stay basic - car has the duty to be responsible        
		void Road::SetCurrentUsage(int num)
		{
			currentUsage = num;
		}

        int Road::GetOverallUsage() const
		{
			return overallUsage;
		}
		
		//This will stay basic - car has the duty to be responsible        
		void Road::SetOverallUsage(int num)
		{
			overallUsage = num;
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
			return name;
		}
        
		void Road::SetName(string mName)
		{
			//basic setter
			name = mName;
		}
        
        bool Road::SetBeginning(Intersection *intersection)
		{	
			//copy pointer, not object
			beginning = intersection;
		}
         
        bool Road::SetEnd(Intersection *intersection)
		{
			//copyt pointer, not object
			end = intersection;
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
			myID = other.myID;
			currentTravel = other.currentTravel;
			averageTravel = other.averageTravel;
			currentUsage = other.currentUsage;
			overallUsage = other.overallUsage;
			blocked = other.blocked;
			oneWay = other.oneWay;
			name = other.name;
			beginning = other.beginning;
			end = other.end;
		}
        
        /* Private Vars
        const unsigned long maxID;         
        unsigned long myID;
        unsigned long currentTravel;
        unsigned short averageTravel;
        unsigned int usage;
        bool blocked:1;
		bool oneWay:1;
        string name;
        Intersection *beginning;
        Intersection *end;
       	*/
