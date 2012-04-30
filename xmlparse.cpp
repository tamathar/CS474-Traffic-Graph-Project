#include <iostream>
#include "./libs/tinyxml2.h"
using namespace tinyxml2;
using namespace std;

void parseClosures(string fname)
{	
	XMLDocument doc;
	doc.LoadFile( "LaneClosures.xml" );
	XMLElement * root = doc.RootElement();
	XMLElement * parent = root->FirstChildElement()->NextSiblingElement()->FirstChildElement();


	do
	{
		XMLElement* networkid = parent->FirstChildElement();
		XMLElement* id = networkid->NextSiblingElement();
		XMLElement* Description = id->NextSiblingElement();
		XMLElement* StartName = Description->NextSiblingElement();
		XMLElement* XStartName = StartName->NextSiblingElement();
		XMLElement* EndName= XStartName->NextSiblingElement()->NextSiblingElement()->NextSiblingElement()->NextSiblingElement(); //burn geolocation
		XMLElement* XEndName = EndName->NextSiblingElement();

	
		std::cout  << "Network ID: " << networkid->GetText() << endl;
		std::cout  << "id: " << id->GetText() << endl;
		std::cout  << "Description: " << Description->GetText() << endl;
		std::cout  << "StartName: " << StartName->GetText() << endl;
		std::cout  << "XStartName: " << XStartName->GetText() << endl;
		std::cout  << "EndName: " << EndName->GetText() << endl;
		std::cout  << "XEndName: " << XEndName->GetText() << endl << endl;
		
		parent = parent->NextSiblingElement();
	} 
	while(parent);
	
}

void parseAccidents(string fname)
{	
	XMLDocument doc;
	doc.LoadFile( "Incidents.xml" );
	XMLElement * root = doc.RootElement();
	XMLElement * parent = root->FirstChildElement()->NextSiblingElement()->FirstChildElement();


	do
	{
		XMLElement* networkid = parent->FirstChildElement();
		XMLElement* id = networkid->NextSiblingElement();
		XMLElement* Description = id->NextSiblingElement();
		XMLElement* RoadName = Description->NextSiblingElement();
		XMLElement* XRoadName = RoadName->NextSiblingElement();
		XMLElement* Type= XRoadName->NextSiblingElement()->NextSiblingElement()->NextSiblingElement()->NextSiblingElement()->NextSiblingElement()->NextSiblingElement()->NextSiblingElement()->NextSiblingElement()->NextSiblingElement()->NextSiblingElement()->NextSiblingElement(); //burn geolocation
		

	
		std::cout  << "Network ID: " << networkid->GetText() << endl;
		std::cout  << "id: " << id->GetText() << endl;
		//std::cout  << "Description: " << Description->GetText() << endl;
		std::cout  << "RoadName: " << RoadName->GetText() << endl;
		std::cout  << "XRoadName: " << XRoadName->GetText() << endl;
		std::cout  << "Type: " << Type->GetText() << endl;

		
		parent = parent->NextSiblingElement();
	} 
	while(parent);
	
}

void parseRoads(string fname)
{
	XMLDocument doc;
	doc.LoadFile( "TrafficDetectors.xml" );
	XMLElement * root = doc.RootElement();
	XMLElement * parent = root->FirstChildElement();
	
	do
	{
		string ids = parent->Attribute("Id");
		string names = parent->Attribute("Name");
		string name1, name2;
		name1 = names.substr(0, names.find("@")-1);
		name2 = names.substr(names.find("@")+2);
		
		XMLElement * child = parent->FirstChildElement();
		int speed = child->IntAttribute("Speed");
		int volume = child->IntAttribute("Volume");
		int occupancy = child->IntAttribute("Occupancy");
		
		
		cout << "road ids: " << ids << endl;
		cout << "Names: " << names << endl;
		cout << "Name1: " << name1 << endl;
		cout << "Name2: " << name2 << endl;
		cout << "Speed: " << speed << endl;
		cout << "Volume: " << volume << endl;
		cout << "Occupancy: " << occupancy << endl << endl;
	
		parent = parent->NextSiblingElement();
	}
	while(parent);
}


int main()
{
	retrieveXML("http://www.daltrans.org/daltrans/roads.xml");
	
	string nothing;
	cout << "input anything to parse roads.";
	cin >> nothing;
	
	parseRoads("hllj");
	
	cout <<  "input anything to parse accidents.";
	cin >> nothing;
	
	parseAccidents("hllls");
	
	cout <<  "input anything to parse closures.";
	cin >> nothing;
	
	parseClosures("hlls");
}
/*<TrafficDetector xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:xsd="http://www.w3.org/2001/XMLSchema" Id="10043 2176" Name="EB SH183 @ Wingren EBL3of3" DataSourceId="10043" TmcId="DalTrans" Type="MainLane">
<Datum Id="2176" Status="NoData" Speed="30" Volume="9" Occupancy="5" LastUpdated="2012-04-28T12:44:54.390625-05:00"/>
</TrafficDetector>
*/

/*<Incident>
<NetworkId>01</NetworkId>
<Id>179e8ca2d2ca4da0b621bcd07e5071eb</Id>
<Description/>
<RoadName>US 75</RoadName>
<CrossStreetName>Royal Ln</CrossStreetName>
<Location Latitude="32.89851" Longitude="-96.769002"/>
<Latitude>32.89851</Latitude>
<Longitude>-96.769002</Longitude>
<LinkId>DEEE312A47BD4FFEB330A087038886D7</LinkId>
<Direction>South</Direction>
<Status>Verified</Status>
<UpdateType>New</UpdateType>
<AffectedLanes>RightShoulder</AffectedLanes>
<Classification>1</Classification>
<Severity>Unknown</Severity>
<Type>StalledVehicle</Type>
<TypeDescription/>
<RoadConditions>Unknown</RoadConditions>
<Weather>Unknown</Weather>
<ConfirmedDateTime>2012-04-28T13:12:49</ConfirmedDateTime>
<ClearedDateTime>0001-01-01T00:00:00</ClearedDateTime>
<NearestCameraId>43</NearestCameraId>
<NearestCameraName>US75 @ Royal</NearestCameraName>
</Incident>*/

/*	<LaneClosure>
<NetworkId>01</NetworkId>
<Id>1132b07df29d4ffd9cd14bbd5224a7aa</Id>
<Description>Alternating lanes closed.</Description>
<RoadStartName>US 75</RoadStartName>
<CrossStreetStartName>SH 121 (Sam Rayburn Tollway)</CrossStreetStartName>
<StartLocation Latitude="33.157624" Longitude="-96.64555"/>
<StartLatitude>33.157624</StartLatitude>
<StartLongitude>-96.64555</StartLongitude>
<RoadEndName>US 75</RoadEndName>
<CrossStreetEndName>Virginia Pkwy</CrossStreetEndName>
<EndLocation Latitude="33.198246" Longitude="-96.638683"/>
<EndLatitude>33.198246</EndLatitude>
<EndLongitude>-96.638683</EndLongitude>
<Direction>North</Direction>
<LinkId>Bogus Link 3</LinkId>
<UpdateType>Update</UpdateType>
<CurrentStatus>Opened</CurrentStatus>
<AffectedLanes>Unknown</AffectedLanes>
<HighwayConditions/>
<Source/>
<DaysClosed>
Monday Tuesday Wednesday Thursday Friday Saturday Sunday
</DaysClosed>
<StartTime>2012-04-28T20:30:00</StartTime>
<EndTime>2012-04-28T05:30:00</EndTime>
<StartDate>2012-04-27T00:00:00</StartDate>
<EndDate>2012-06-18T00:00:00</EndDate>
<Extent>
<Location Latitude="33.157624" Longitude="-96.64555"/>
<Location Latitude="33.198246" Longitude="-96.638683"/>
</Extent>
<NearestCameraId>621</NearestCameraId>
<NearestCameraName>US75 @ SH121 North</NearestCameraName>
</LaneClosure>*/
