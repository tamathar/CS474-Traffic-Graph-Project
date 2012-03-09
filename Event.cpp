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
        		Road->SetBlocked(true);
        		if(accident)
        			Road->IncrementAccident();
        	}
        	else
        	{
        		Position->beginning->SetBlocked(true);
        		Position->beginning->IncrementAccident();
        	}
        		
        }
        
        void Event::RemoveEvent(Position *position, bool accident)
        {
        	if(position->end != 0)
        	{
        		Road * road = position->beginning->FindRoad(position->end);
        		Road->SetBlocked(false);
        	}
        	else
        		Position->beginning->SetBlocked(false);
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

