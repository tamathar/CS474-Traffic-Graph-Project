//
//  main.cpp
//  Traffic-Graph-API
//
//  Created by Joseph Quigley on 4/18/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <string>
#include "libs/tinyxml2.h"
#include <curl/curl.h>

using namespace std;

string version = "2.0.0.1";

void usage();
void usage() {
    cout << " Traffic Graph API client version " << version << "\n\
 Usage:\n\t\
trafic-graph <data-url> <png-output-path>\n";
}

int main(int argc, char *argv[]) {
    for (int i=1; i<argc; i++) {
        if (strncmp(argv[i], "-v", 2) == 0 || strncmp(argv[i], "-h", 2) == 0 ) {
            usage();
            exit(0);
        }
    }
    
    if (argc > 1) { //has input file param
        
    }
    if (argc > 2) { //Has output file param
        
    }
}