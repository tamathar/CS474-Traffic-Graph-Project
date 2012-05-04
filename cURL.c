#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <curl/curl.h>
#include "cURL.h"

const char *retrieveXML(const char *URL) {
  CURL *curl;
  CURLcode curl_res;

  long http_code;
  double c_length;  
  
  const char *fileName = "data.xml";
    
  FILE *dataFile;

  dataFile=fopen(fileName, "w");
  if(dataFile==NULL) {
    printf("\n\n--------------\nERROR opening file roads.xml\n--------------\n");
    exit(2);
  }
  
  //init curl session
  curl = curl_easy_init();
    
  //set url to download
  curl_easy_setopt(curl, CURLOPT_URL, URL);

  //set file handler to write
  curl_easy_setopt(curl, CURLOPT_WRITEDATA,  dataFile);

  //download the file
  curl_res = curl_easy_perform(curl);
  
    if(curl_res!=0) {
    printf("\n\n--------------\nERROR in dowloading file\n--------------\n");
    fclose(dataFile);
    curl_easy_cleanup(curl);
    exit(2);
  }

  
  //END: close all files and sessions
  fclose(dataFile);
  curl_easy_cleanup(curl);
    
  return fileName;

}
