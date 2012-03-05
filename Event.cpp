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
        static unsigned long maxID = 0;
        string type = "";
        //=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-Constructors/Destructor=-=-=-=-=-=-=-=-=-=-=-
		Event &Event::GetInstance()
        {
            static Event instance;
            return instance;
        }
    
        int Event::GetID()
        {
            myID = maxID++; //Get automatically-generated ID
            return myID;
        }
        
        string Event::GetType() const
        {
            return type;
        }

        void Event::SetType(string mType)
        {
            type = mType;
        }        
        
        void Event::CreateEvent(Position *mPos, string mType)
        {
            ;
        }
		
		/*
		const unsigned long maxID; //Auto-inc when creating a new Event. That way every Event has a UID
        unsigned long myID;
   	    */
}

