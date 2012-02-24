/************************************************************************
/Author: Thomas Scroggins
/Program: Road.cpp
/Description: This is the implementation file for the road class of 
/             the tfg project API
************************************************************************/

#include <iostream>
#include "intersection.h"
using namespace std;

namespace tfg
{
	class Road	
	{
    public:
        //=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-Constructors/Destructors=--=-=-=-=-=-=-=-=-=-=-=
		
		// We can't make a road without a beginning and end. Additionally, the default copy constructor will work. 
		// By default roads start as two-way, but can be changed
		
        Road(Intersection *mBeginning, Intersection *mEnd) 
			: myID(maxID++), 
			  usage(0), 
			  blocked(0), 
			  oneWay(0)
		{
			beginning = mBeginning;
			end = mEnd;
		}

        Road(Intersection *mBeginning, Intersection *mEnd, string mName) 
			: myID(maxID++), 
			  usage(0), 
			  blocked(0), 
			  oneWay(0),
			  name(mName)
		{
			beginning = mBeginning;
			end = mEnd;
		}


		
        ~Road()
		{
			delete beginning;
			delete end;
		}
        
		//=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-Getters/Setters=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
		// All getters are standard. All setters have explanation inline.
		
        int GetID() const
		{
			return myID;
		}
        
        int GetCurrentTravel() const
		{
			return currentTravel;
		}
       		
		void SetCurrentTravel(int time)
		{
			//for now basic
			currentTravel = time;
		}
        
        int GetAverageTravel() const
		{
			return averageTravel;
		}
        
		void SetAverageTravel(int time)
		{
			//for now basic
			averageTravel = time;
		}
        
        int GetUsage() const
		{
			return usage;
		}
        
		void SetUsage(int num)
		{
			//This will stay basic - car has the duty to be responsible
			usage = num;
		}
        
        bool IsBlocked() const
		{
			return blocked;
		}
        
		void SetBlocked(bool isBlocked)
		{
			//This is just your basic setter
			if(isBlocked)
				blocked = 1;
			
			blocked = 0;
		}
        
        bool IsOneWay() const
		{
			return oneWay;
		}
        
		void SetOneWay(bool isOneWay)
		{
			//This is just your basic setter
			if(isOneWay)
				oneWay = 1;
			
			oneWay = 0;
		}
        
        string GetName() const
		{
			return name;
		}
        
		void SetName(string mName)
		{
			//basic setter
			name = mName;
		}
        
        bool SetBeginning(Intersection *intersection)
		{	
			//copy pointer, not object
			begginning = intersection;
		}
         
        bool SetEnd(Intersection *intersection)
		{
			//copyt pointer, not object
			end = intersection;
		}
        
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
