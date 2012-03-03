/*************************************************************************
 * Author: German Irias
 * Program: Event.cpp
 * Description: This is the implementation of the Car class for
 * 				 for the Traffic Graph API
 *************************************************************************/
#include <iostream>
#include "main.cpp"
#include "event.h"
using namespace std;

namespace tfg
{
        //=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-Constructors/Destructor=-=-=-=-=-=-=-=-=-=-=-
		
		//Default constructors will not work because of dynamic arrays
        Event::Event()
              :myID(maxID++)
        {
        }
        
        ~Event();
        
        
        //Consting all getters so that they can be called by any const refs
        int GetID() const; //Get automatically-generated ID
        
        string GetType() const;
        void SetType(string mType);
        
        void CreateEvent(Position *mPos, string mType);
		
		
		
        
    	
		/*
		//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-Overloaders=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
		bool operator==(const Intersection &other) const
		{
			if(myID = other.myID)
				return true;
				
			return false;
		}
		
		const unsigned long maxID; //Auto-inc when creating a new Event. That way every Event has a UID
        unsigned long myID;
   	    */
}

