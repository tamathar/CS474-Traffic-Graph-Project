/*************************************************************************
 * Author: German Irias
 * Program: Position.cpp
 * Description: This is the implementation of the Car class for
 * 				 for the Traffic Graph API
 *************************************************************************/
#include <iostream>
#include "position.h"
using namespace std;

namespace tfg
{
        //=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-Constructors/Destructor=-=-=-=-=-=-=-=-=-=-=-
		
        //defaults constructors will not work because of our dynamic arrays
    	Position::Position()
    	{
    	    road = new Road;
    	    intersection = new Intersection;
    	    road = NULL;
    	    intersection = NULL;
    	}	
    	
    	Position::Position(const Position & other)
    	{
    	    road = new Road;
    	    intersection = new Intersection;
    	    road = NULL;
    	    intersection = NULL;
    	}
    	
    	Position::~Position()
    	{
    	    delete road;
    	    delete intersection;
    	}	
    
        //this function will take both parameters, but only one will be set
        //because a car can only be either on a road or on an intersection
        void Position::setRoad(Road * rd)
        {
            road = rd;
            if (rd != NULL)
                setIntersection(NULL);
        }
        
        void Position::setIntersection(Intersection * in)
        {
            intersection = in;
            if (in != NULL)
                setRoad(NULL);
        }
    	
    	Road Position::getRoad() const
    	{
    	    return *road;
    	}
    	
    	Intersection Position::getIntersection() const
    	{
    	    return *intersection;
    	}
        
		/*
		//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-Overloaders=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
		bool operator==(const Intersection &other) const
		{
			if(myID = other.myID)
				return true;
				
			return false;
		}
		
		/*Road * road;
    	  Intersection * intersection;
   	    */
}

