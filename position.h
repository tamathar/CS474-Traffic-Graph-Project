/*
 *
 * Created By German Irias 02/18/2011
 *
 */
#ifndef Position_h
#define Position_h
#include "intersection.h"

using namespace std;

namespace tfg {
	class Position {

    public:
    	// Constructor: position is in road
    	Position(Intersection* b, Intersection* e);	
    	// Constructor: position is in intersection
    	Position(Intersection* b);
    	// Copy constructor
    	Position(const Position & other);	
    	// Assignment constructor
    	const Position & operator=(const Position & other);
    	// Pointer to the beginning of a road
    	Intersection * beginning;
    	// Pointer to the end of a road
    	Intersection * end;
    	
    };
}

#endif
