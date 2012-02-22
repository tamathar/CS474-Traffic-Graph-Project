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
    
    	int GetID();	// return id
    	void SetID(int id);	// set id
    	bool GetAccident();	// return accident
    	void SetAccident(bool accident);	// set accident
    	int GetTimestamp();	// return timestamp
    	void SetTimestamp(int timestamp);	// set timestamp
    	Position GetPosition();	// return position
    	void SetPosition(Position pos);		// set position
    	int GetSpeed();		// return speed
    	void SetSpeed(int speed);		// set speed
    	void SpawnEvent(string type, Position pos);	// spawn an event, describing what event it was and where in the graph
    	void UpdatePosition();	// update where in the graph the car is
    	void StopTracking();	// stop updating position
    
    private:
    	int id;		// unique id for each car in the graph
    	bool accident;	// true if it had an accident, false otherwise
    	int timestamp;	// current time
    	Position pos;	// tells where in the graph is the car
    	int speed;	// tells the speed at which the car goes
    
    };
}

#endif
