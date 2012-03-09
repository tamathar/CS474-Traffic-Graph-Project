/*************************************************************************
 * Author: German Irias
 * Program: Event.cpp
 * Description: This is the implementation of the Car class for
 * 				 for the Traffic Graph API
 *************************************************************************/
#include <iostream>
#include "event.h"
using namespace std;

namespace tfg
{
        //=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-Constructors/Destructor=-=-=-=-=-=-=-=-=-=-=-
        Event *Event::m_pInstance = NULL;
        
        // Get the only instance of an event.
		Event *Event::Get()
        {
            if (!m_pInstance) {
            	m_pInstance = new Event;
            }
            
            return m_pInstance;
        }        
        
        // Create an event. 
		// Pass in a position and a bool that says whether
		// the event is an accident
        void Event::CreateEvent(Position *position, bool accident)
        {
        	if(position->end != 0)
        	{
        		Road * road = position->beginning->FindRoad(position->end);
        		road->SetBlocked(true);
        		if(accident)
        			road->IncrementAccidents();
        	}
        	else
        	{
        		position->beginning->SetBlocked(true);
        		position->beginning->IncrementAccidents();
        	}
        		
        }
        
        // Remove an event. 
		// Pass in a position and a bool that says whether
		// the event is an accident
        void Event::RemoveEvent(Position *position, bool accident)
        {
        	if(position->end != 0)
        	{
        		Road * road = position->beginning->FindRoad(position->end);
        		road->SetBlocked(false);
        	}
        	else
        		position->beginning->SetBlocked(false);
        }
        
        // Create an accident event. 
		// Pass in a position. It calls CreateEvent() with (accident == true)
        void Event::CreateAccident(Position *position)
        {
        	CreateEvent(position, true);
        }
        
        // Remove an accident event. 
		// Pass in a position. It calls RemoveEvent() with (accident == true)
        void Event::RemoveAccident(Position *position)
        {
        	RemoveEvent(position, true);
        }
        
        // Create a maintenance event. This function is called by clients; it
        // means a street is closed for maintenance, so it is blocked. 
		// Pass in a position.
        void Event::CreateMaintenance(Position *position)
        {
        	CreateEvent(position);
        }
        
        // Remove a maintenance event. This function is called by clients; it
        // means maintenance on a street is done, so it is unblocked. 
		// Pass in a position.
        void Event::RemoveMaintenance(Position *position)
        {
        	RemoveEvent(position);
        }
}

