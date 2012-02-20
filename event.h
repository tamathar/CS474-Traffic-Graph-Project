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
        //Default constructors will not work because of dynamic arrays
        Event();
        Event(const Event & other);
        Event(Position *mPos, string mType, unsigned long mTimeStamp);
        Event(Position *mPos, string mType);
        ~Event();
        
        
        //Consting all getters so that they can be called by any const refs
        int GetID() const; //Get automatically-generated ID
        
        string GetType() const;
        void SetType(string mType);
        
        void CreateEvent(Position *mPos, string mType);
        
    private:
        const unsigned long maxID; //Auto-inc when creating a new Event. That way every Event has a UID
        
        unsigned long myID;
        
	}    
}
#endif	