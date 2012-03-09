/*************************************************************************
 * Author: German Irias
 * Program: Car.cpp
 * Description: This is the implementation of the Car class for
 * 				 for the Traffic Graph API
 *************************************************************************/
#include <iostream>
#include "time.h"
#include "car.h"
using namespace std;

namespace tfg
{
        //=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-Constructors/Destructor=-=-=-=-=-=-=-=-=-=-=-
		unsigned long Car::maxID = 0;
        Car::Car()
			:myID(maxID++),
			 accident(0),
			 pos(0)
		{	
		}
		
        Car::Car(const Car & other)
			:myID(other.myID),
			 accident(other.accident)
		{
			*pos = other.GetPosition();
		}
		
        Car::~Car()
		{
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
    		if(pos != NULL)
    	    	Event::Get()->CreateAccident(pos);
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
    	
    	void Car::UpdatePosition(Position * p)
    	{
    	    pos = p;		// set position
    	}
    	
    	void Car::SpawnEvent(Position * p)
    	{
    	    ;	// spawn an event, describing what event it was and where in the graph
    	}
}
    /*static unsigned long maxID; 
    int myID;		
    bool accident;	
  	int timestamp;	
   	Position pos;	
   	int speed;	
   	*/
