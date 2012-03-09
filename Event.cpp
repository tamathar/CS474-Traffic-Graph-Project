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
        
		Event *Event::Get()
        {
            if (!m_pInstance) {
            	m_pInstance = new Event;
            }
            
            return m_pInstance;
        }        
        
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
        
        void Event::CreateAccident(Position *position)
        {
        	CreateEvent(position, true);
        }
        
        void Event::RemoveAccident(Position *position)
        {
        	RemoveEvent(position, true);
        }
        
        void Event::CreateMaintenance(Position *position)
        {
        	CreateEvent(position);
        }
        
        void Event::RemoveMaintenance(Position *position)
        {
        	RemoveEvent(position);
        }
}

