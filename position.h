#ifndef Position_h
#define Position_h
#include "road.h"
#include "intersection.h"

using namespace std;

namespace tfg {
	class Position {

    public:
        //defaults constructors will not work because of our dynamic arrays
    	Position();	
    	Position(const Position & other);
    	~Position();	
    
        //this function will take both parameters, but only one will be set
        //because a car can only be either on a road or on an intersection
        void setRoad(Road * rd);
        void setIntersection(Intersection * in);
    	Road getRoad() const;
    	Intersection getIntersection() const;
    
    private:
    	Road * road;
    	Intersection * intersection;
    
    };
}

#endif
