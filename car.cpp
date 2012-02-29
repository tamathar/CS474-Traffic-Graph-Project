/*************************************************************************
 * Author: German Irias
 * Program: Car.cpp
 * Description: This is the implementation of the Car class for
 * 				 for the Traffic Graph API
 *************************************************************************/
#include <iostream>
#include "main.cpp"
#include "car.h"
using namespace std;

namespace tfg
{
        //=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-Constructors/Destructor=-=-=-=-=-=-=-=-=-=-=-
		
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
    	
    	int Car::GetTimestamp() const
    	{
    	    ;	// return timestamp
    	}
    	
    	Position Car::GetPosition() const
    	{
    	    return *pos;	// return position
    	}
    	
    	void Car::SetPosition(Position p)
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
    /*const unsigned long maxID; 
    int myID;		
    bool accident;	
  	int timestamp;	
   	Position pos;	
   	int speed;	
   	*/
