/*
 *
 * Created By Joseph Quigley 02/18/2011
 *
 */

#ifndef Data_h
#define Data_h

#include <vector>
#include "road.h"
#include "position.h"
using namespace std;

namespace tfg
{
	class Data
	{
    public:
        static Data* Instance();

        vector<Road> *ParseRoads();
        void GetRoads();
        
        void ParseClosures();
        void GetClosures();
        
        void ParseAccidents();
        void GetAccidents();

    private:
        Data() {}
        Data(Data const&){};             // copy constructor is private
        Data& operator=(Data const&){ return *this; };  // assignment operator is private
        static Data* m_pInstance;

        
        
        Position **positions;

	};
}
#endif
