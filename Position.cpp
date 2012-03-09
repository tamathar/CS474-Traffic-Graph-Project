/*************************************************************************
 * Author: German Irias
 * Program: Position.cpp
 * Description: This is the implementation of the Position class for
 * 				 for the Traffic Graph API
 *************************************************************************/
#include "position.h"

namespace tfg
{
        //=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-Constructors/Destructor=-=-=-=-=-=-=-=-=-=-=-
		
        // Constructor: position is in road
    	Position::Position(Intersection* b, Intersection* e)
    		:beginning(b),
    		 end(e)
    	{
    	}
    	
    	// Constructor: position is in intersection
    	Position::Position(Intersection* b)
    		:beginning(b),
    		 end(NULL)
    	{
    	}		
    	
    	// Copy constructor
    	Position::Position(const Position & other)
    		:beginning(other.beginning),
    		 end(other.end)
    	{
    	}
}

