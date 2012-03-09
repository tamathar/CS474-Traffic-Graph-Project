/*
 *
 * Created By German Irias 02/18/2011
 *
 */

#ifndef Car_h
#define Car_h
#include "position.h"
#include "event.h"

namespace tfg
{
	class Car {
    public:
    	Car();	// default constructor
    	Car(const Car& other); // copy constructor
    	~Car();	// default destructor
    
    	int GetID() const;	// return id
    	void SetID(int id);	// set id
    	bool GetAccident() const;	// return accident
    	void SetAccident(bool acc);	// set accident
    	struct tm * GetTimestamp() const;	// return timestamp
    	Position GetPosition() const;	// return position
    	void UpdatePosition(Position * p);		// set position
    
    private:
        static unsigned long maxID; //Auto-inc when creating a new Car. That way every Car has a UID
    	int myID;		// unique id for each car in the graph
    	bool accident;	// true if it had an accident, false otherwise
    	int timestamp;	// current time
    	Position * pos;	// tells where in the graph is the car
    };
}

#endif
