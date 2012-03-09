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
        
        
        
        //Consting all getters so that they can be called by any const refs
        int GetID() const; //Get automatically-generated ID
        
        int GetCurrentTravel() const; 
        int GetAverageTravel() const;
        void UpdateTravel(int data);


        int GetOverallUsage() const;        
        int GetCurrentUsage() const;
        void IncrementUsage();
		

        void SetOverallUsage(int num);
        int GetAccidents() const;
		void IncrementAccidents();
		
        bool IsBlocked() const;
        void SetBlocked(bool isBlocked);
        
        bool IsOneWay() const;
        void SetOneWay(bool isOneWay);
        
        string GetName() const;
        void SetName(string mName);

		
		bool operator==(const Road &other) const;
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
