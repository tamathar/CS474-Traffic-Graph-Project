//
//  main.cpp
//  Traffic-Graph-API
//
//  Created by Joseph Quigley on 4/18/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <string>
#include <cstdlib>
#include "libs/tinyxml2.h"

using namespace std;

string version = "2.0.0.1";

void usage(string name);
void usage(string name) {
    
    //Get the actual executable name, trim all chars before the last / (directory)
    long int fileNameBegins = name.find_last_of("/");
    
    name = name.substr(fileNameBegins+1, name.length());
    
    
    cout << " Traffic Graph API client version " << version << "\n\
 Usage:\n\t" << name << " <data-url> <png-output-path>\n";
}

int main(int argc, char *argv[]) {
    for (int i=0; i<argc; i++) {
        if (strncmp(argv[i], "-v", 2) == 0 || strncmp(argv[i], "-h", 2) == 0 || argc == 1 ) {
            usage(string(argv[0]));
            exit(0);
        }
    }
    
    if (argc > 2) { //Has output file param
        
    }
    else { //Just input file param
        
    }
}
