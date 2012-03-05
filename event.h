/*
 *
 * Created By Joseph Quigley 02/18/2011
 * 
 */

#ifndef Event_h
#define Event_h
#include <iostream>
#include "position.h"
using namespace std;

namespace tfg
{
	class Event	
	{
    public:
        static Event &GetInstance();
        //Consting all getters so that they can be called by any const refs
        int GetID(); //Get automatically-generated ID
        
        string GetType() const;
        void SetType(string mType);
        
        void CreateEvent(Position *mPos, string mType);
                
    private:
        //Default constructors will not work because of dynamic arrays
        Event();
        ~Event();
        Event(const Event & others);
        const Event &operator =(const Event & others);

        static unsigned long maxID; //Auto-inc when creating a new Event. That way every Event has a UID
        string type;
        unsigned long myID;
        
	};    
}
#endif	
