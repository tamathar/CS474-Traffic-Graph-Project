/*
 *
 * Created By Joseph Quigley 02/18/2011
 *
 */

#ifndef Data_h
#define Data_h
#include <iostream>
#include "position.h"
using namespace std;

namespace tfg
{
	class Data
	{
    public:
        Data();

        void ParseRoads();
        void ParseEvents();
        void GetRoads();
        void GetEvents();

    private:
        Position **positions;

	};
}
#endif
