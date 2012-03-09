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
        static Event *Get();
        //Consting all getters so that they can be called by any const refs

        void CreateEvent(Position *position, bool accident = false);
        void RemoveEvent(Position *position, bool accident = false);
        void CreateAccident(Position *position);
        void RemoveAccident(Position *position);
        void CreateMaintenance(Position *position);
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
