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
        
        Event::Event(const Event & other);
              :myID(other.myID)
        {
        }
        
        Event(Position *mPos, string mType, unsigned long mTimeStamp);
        Event(Position *mPos, string mType);
        ~Event();
        
        
        //Consting all getters so that they can be called by any const refs
        int GetID() const; //Get automatically-generated ID
        
        string GetType() const;
        void SetType(string mType);
        
        void CreateEvent(Position *mPos, string mType);
		
		
		
        Car::Car()
			:myID(maxID++),
			 accident(0),
			 speed(0)
		{	
			pos = new Position;
		}
		
        Car::Car(const Car & other)
			:myID(other.myID),
			 accident(other.accident),
			 speed(other.speed)
		{
			pos = new Position;
		}
		
        Car::~Car()
		{
			delete pos;
		}
        
        //=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-Getters/Setters=-=-=-=-==-=-=-=-=-=-=-=-=-
        //All getters are standard. Setters are explained individually.
		
		
        int Car::GetID() const 
        {
            return myID;	// return id
        }

    	bool Car::GetAccident() const
    	{
    	    return accident;	// return accident
    	}
    	
    	void Car::SetAccident(bool acc)
    	{
    	    accident = acc;	// set accident
    	}
    	
    	struct tm * Car::GetTimestamp() const
    	{
    	    time_t rawtime;
            struct tm * ptm;

            time ( &rawtime );

            ptm = gmtime ( &rawtime );	
            return ptm; // return timestamp
    	}
    	
    	Position Car::GetPosition() const
    	{
    	    return *pos;	// return position
    	}
    	
    	void Car::UpdatePosition(Position p)
    	{
    	    *pos = p;		// set position
    	}
    	
    	int Car::GetSpeed() const
    	{
    	    return speed;		// return speed
    	}
    	
    	void Car::SetSpeed(int sp)
    	{
    	    speed = sp;		// set speed
    	}
    	
    	void SpawnEvent(string type, Position pos)
    	{
    	    ;	// spawn an event, describing what event it was and where in the graph
    	}
    	
    	void StopTracking()
    	{
    	    ;	// stop updating position
    	}
    	
		/*
		//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-Overloaders=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
		bool operator==(const Intersection &other) const
		{
			if(myID = other.myID)
				return true;
				
			return false;
		}
		
		const Intersection & operator=(const Intersection &other)
		{
			myID = other.myID;
			usage = other.usage;
			blocked = other.blocked;
			roadCount = other.roadCount;
			delete []roads;
			roads = new Road[roadCount];
			for(int i = 0; i < roadCount; i++)
				roads[i] = other.roads[i];
		}
		*/
}
    /*const unsigned long maxID; //Auto-inc when creating a new Event. That way every Event has a UID
      unsigned long myID;
   	*/
