//
//  data.cpp
//  Traffic-Graph-API
//
//  Created by Joseph Quigley on 4/28/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "data.h"
#include <iostream>

namespace tfg {

Data* Data::m_pInstance = NULL; 


Data* Data::Instance()
{
    if (!m_pInstance)   // Only allow one instance of class to be generated.
        m_pInstance = new Data;
        return m_pInstance;
}


}