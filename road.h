/*
 *
 * Created By Joseph Quigley 02/18/2011
 * 
 */

#ifndef Road_h
#define Road_h
#include <iostream>
using namespace std;

namespace tfg
{
  class Intersection;

	class Road	
	{
    public:
        Road();
        Road(const Road &other);
        Road(string mName); 
        
        
        //Brief: This method returns an object's id.
        //Result: The unique ID of the class instance.
        int GetID() const;
        
        //Brief: This method returns the average travel time since the last time blocked was set or cleared.
        //Result: The value of currentTravel
        int GetCurrentTravel() const; 
        
        //Brief: This method returns the average travel time since the road was constructed
        //Result: The value of averageTravel
        int GetAverageTravel() const;
        
        //Brief: This method takes in the time of a car's transit and averages it with currentTravel and averageTravel
 		//Param: data - a time in seconds
        void UpdateTravel(int data);

		//Brief: Returns the number of cars that have used the Road since it was created
		//Result: The value of overallUsage
        int GetOverallUsage() const;       
        
        //Brief: Returns the number of cars that have used the Road since blocked was last set or cleared
        //Result: The value of currentUsage 
        int GetCurrentUsage() const;
        
        //Brief: Adds one to both current and overall usage
        void IncrementUsage();
		
		//Brief: Gets the number of accidents on the road since it was created
		//Return: The value of accidents
        int GetAccidents() const;
        
        //Brief: Adds 1 to accidents
		void IncrementAccidents();
		
		//Brief: Gets whether the road is blocked or not
		//Return: The value of blocked
        bool IsBlocked() const;
        
        //Brief: Sets whether the road is blocked or not and resets usage count
        //Param: isBlocked - whether we're setting to true or to false
        void SetBlocked(bool isBlocked);
        
        //Brief: Gets whether or not the road is one way
        //Return: True if one way, false if not
        bool IsOneWay() const;
        
        //Brief: Set whether the road is one way or not
        //Param: isOneWay - what value we're to set oneWay to 
        void SetOneWay(bool isOneWay);
        
        //Brief: Get the name of the road
        //Return: A string holding the name
        string GetName() const;
        
        //Brief: Sets the name of the road
        //Param: nName - The value we are setting name to
        void SetName(string mName);

		//Brief: Standard boolean == operator
		//Return: true if the roads are equal, false if not
		bool operator==(const Road &other) const;
		
		//Brief: Standard assignment operator
		//Return: ref to *this for chaining
		const Road & operator=(const Road &other);
		
    private:        
        static unsigned long maxID; //Auto-inc when creating a new road. That way every road has a UID
        unsigned long myID;
        unsigned long currentTravel; //Unsigned gives more space, time can't be negative
        unsigned short averageTravel; //average time can be teeny
	    unsigned int currentUsage; //for use with currentTravel
        unsigned int overallUsage; //for use with averageTravel
	    unsigned int accidents;
        bool blocked:1; //Using a bitfield to save space, since there could be millions of road objects on a map
        bool oneWay:1;
        string name;

        
	};    
}
#endif	
