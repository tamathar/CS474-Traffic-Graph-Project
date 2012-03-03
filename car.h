#ifndef Car_h
#define Car_h
#include "position.h"
#include "event.h"

using namespace std;

namespace tfg
{
	class Car {
    public:
    	Car();	// default constructor
    	Car(const Car& other);
    	~Car();	// default destructor
    
    	int GetID() const;	// return id
    	void SetID(int id);	// set id
    	bool GetAccident() const;	// return accident
    	void SetAccident(bool acc);	// set accident
    	struct tm * GetTimestamp() const;	// return timestamp
    	//void SetTimestamp(int ts);	// set timestamp
    	Position GetPosition() const;	// return position
    	void SetPosition(Position p);		// set position
    	int GetSpeed() const;		// return speed
    	void SetSpeed(int sp);		// set speed
    	void SpawnEvent(string type, Position pos);	// spawn an event, describing what event it was and where in the graph
    	void UpdatePosition();	// update where in the graph the car is
    	void StopTracking();	// stop updating position
    
    private:
        unsigned long maxID; //Auto-inc when creating a new Car. That way every Car has a UID
    	int myID;		// unique id for each car in the graph
    	bool accident;	// true if it had an accident, false otherwise
    	int timestamp;	// current time
    	Position * pos;	// tells where in the graph is the car
    	int speed;	// tells the speed at which the car goes
    
    };
}

#endif
