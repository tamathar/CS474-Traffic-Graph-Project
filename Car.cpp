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
        // default constructor
		unsigned long Car::maxID = 0;
        Car::Car()
			:myID(maxID++),
			 accident(0),
			 pos(0)
		{	
		}
		
		// copy constructor
        Car::Car(const Car & other)
			:myID(other.myID),
			 accident(other.accident)
		{
			*pos = other.GetPosition();
		}
		
		// default destructor
        Car::~Car()
		{
		}
        
        //=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-Getters/Setters=-=-=-=-==-=-=-=-=-=-=-=-=-
		
		// each car has an ID (like a license plate), which is set when the
		// object is constructed. this function returns that ID
        int Car::GetID() const 
        {
            return myID;	// return id
        }

    	bool Car::GetAccident() const
    	{
    	    return accident;	// return accident
    	}
    	
    	// create an accident. Event is a singleton
    	void Car::SetAccident(bool acc)
    	{
    		if(pos != NULL)
    	    	Event::Get()->CreateAccident(pos);
    	}
    	
    	// return the clock time the car holds at time function is called
    	struct tm * Car::GetTimestamp() const
    	{
    	    time_t rawtime;
            struct tm * ptm;

            time ( &rawtime );

            ptm = gmtime ( &rawtime );	
            return ptm; // return timestamp
    	}
    	
    	// return where in the graph where the car is
    	Position Car::GetPosition() const
    	{
    	    return *pos;	// return position
    	}
    	
    	// change the position
    	void Car::UpdatePosition(Position * p)
    	{
    	    pos = p;		// set position
    	}
    	
}
    /*static unsigned long maxID; 
    int myID;		
    bool accident;	
  	int timestamp;	
   	Position pos;	
   	int speed;	
   	*/
