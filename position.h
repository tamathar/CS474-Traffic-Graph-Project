#ifndef Position_h
#define Position_h
#include "intersection.h"

using namespace std;
class Intersection;
namespace tfg {
	class Position {

    public:
        //defaults constructors will not work because of our dynamic arrays
    	Position(Intersection* b, Intersection* e);	
    	Position(Intersection* b);
    	Position(const Position & other);	
    	Intersection * beginning;
    	Intersection * end;
    };
}

#endif
