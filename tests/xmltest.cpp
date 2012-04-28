#include <iostream>
#include "../libs/tinyxml2.h"
using namespace tinyxml2;

int main()
{	XMLDocument doc;
	doc.LoadFile( "LaneClosures.xml" );
	
	/*static const char* xml = 
		"<?xml version=\"1.0\"?>"
		"<!DOCTYPE PLAY SYSTEM \"play.dtd\">"
		"<PLAY>"
		"<TITLE>A Midsummer Night's Dream</TITLE>"
		"</PLAY>";
	doc.Parse(xml);*/
	XMLElement* networkid = doc.RootElement()->FirstChildElement();
	
	

	std::cout  << networkid->GetText() << std::endl;
	
}
