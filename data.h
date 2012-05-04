/**
 * @author      German Irías <gei08a@acu.edu>
 * @version     2
 * @since       2012-04-20
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
        
        /**
         * Interface to singleton
         *
         * Use Data::Interface()->MethodName() to call methods in this class.
         
         * @return Pointer to Data singleton instance
         */
        static Data* Instance();

        
        /**
         * Downloads and parses a road data xml file
         *
         * @param Url to road data xml file 
         * @return STL Vector of Road objects
         */
        vector<Road> *ParseRoads(std::string url);
        
        
        /**
         * Downloads and parses a road and lane closure data xml file, adding that data to the Events container
         *
         * @param Url to closure data xml file 
         */
        void ParseClosures(std::string url);
        
        
        /**
         * Downloads and parses a road accident data xml file, adding that data to the Events container
         *
         * @param Url to accident data xml file 
         */
        void ParseAccidents(std::string url);

    private:
        Data() {}
        Data(Data const&){};             // copy constructor is private
        Data& operator=(Data const&){ return *this; };  // assignment operator is private
        static Data* m_pInstance;
        
        Position **positions;

	};
}
#endif
