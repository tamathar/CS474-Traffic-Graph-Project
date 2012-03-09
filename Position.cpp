/*************************************************************************
 * Author: German Irias
 * Program: Position.cpp
 * Description: This is the implementation of the Car class for
 * 				 for the Traffic Graph API
 *************************************************************************/
#include "position.h"

namespace tfg
{
        //=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-Constructors/Destructor=-=-=-=-=-=-=-=-=-=-=-
		
        //defaults constructors will not work because of our dynamic arrays
    	Position::Position(Intersection* b, Intersection* e)
    		:beginning(b),
    		 end(e)
    	{
    	}
    	
    	Position::Position(Intersection* b)
    		:beginning(b),
    		 end(NULL)
    	{
    	}		
    	
    	Position::Position(const Position & other)
    		:beginning(other.beginning),
    		 end(other.end)
    	{
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

