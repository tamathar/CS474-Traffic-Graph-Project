/*
 *
 * Created By German Irias & Joseph Quigley 02/18/2011
 * This class implements the Singleton class pattern.
 *
 */

#ifndef Event_h
#define Event_h
#include "position.h"
#include "road.h"

namespace tfg
{
	class Event	
	{
    public:
    	// Get the only instance of an event.
        static Event *Get();

		// Create an event. 
		// Pass in a position and a bool that says whether
		// the event is an accident
        void CreateEvent(Position *position, bool accident = false);
        // Remove an event. 
		// Pass in a position and a bool that says whether
		// the event is an accident
        void RemoveEvent(Position *position, bool accident = false);
        // Create an accident event. 
		// Pass in a position. It calls CreateEvent() with (accident == true)
        void CreateAccident(Position *position);
        // Remove an accident event. 
		// Pass in a position. It calls RemoveEvent() with (accident == true)
        void RemoveAccident(Position *position);
        // Create a maintenance event. This function is called by clients; it
        // means a street is closed for maintenance, so it is blocked. 
		// Pass in a position.
        void CreateMaintenance(Position *position);
        // Remove a maintenance event. This function is called by clients; it
        // means maintenance on a street is done, so it is unblocked. 
		// Pass in a position.
        void RemoveMaintenance(Position *position);          
              
    private:
        //Default constructors will not work because of dynamic arrays
        Event(){};
        Event& operator=(Event const&);
        ~Event();
        Event(const Event & others);
        static Event *m_pInstance;
	};    
}
#endif	
