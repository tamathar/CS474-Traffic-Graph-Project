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
		// All getters are standard. All setters have explanation by declaration
		
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
			
		}
        
        int GetAverageTravel() const
		{
			return averageTravel;
		}
        //void SetAverageTravel(int time);
        
        int GetUsage() const
		{
			return usage;
		}
        //void SetUsage(int num);
        
        bool IsBlocked() const
		{
			return blocked;
		}
        //void SetBlocked(bool isBlocked);
        
        bool IsOneWay() const
		{
			return oneWay;
		}
        //void SetOneWay(bool isOneWay);
        
        string GetName() const
		{
			return name;
		}
        //void SetName(string mName);
        
        //=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-Set Beginning/Ending (technically setters) =-=-=-=-=-=-=-=-=-=-=-=
        bool SetBeginning(Intersection *intersection);
        bool SetBeginning(unsigned long iID);
        
        bool SetEnd(Intersection *intersection);
        bool SetEnd(unsigned long iID);
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
