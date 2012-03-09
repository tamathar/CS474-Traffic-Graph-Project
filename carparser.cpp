#include <ctime>
#include "graph.h"
using namespace std;
using namespace tfg;

void UpdateCarData(int id)
{
	
}

int main()
{
	//fake data to play around on
	//Road first

	Road roads0("Yo");
	Road roads1("Sup");
	Road roads2("Bye");
	Road roads3("Yup");
	Road roads4("Nope");
	
	//Now intersections
	Intersection inters0;
	Intersection inters1;
	Intersection inters2;
	Intersection inters3;						 
	inters0.AddRoad(&roads0, &inters1);cout << inters0.GetElementCount();
	inters1.AddRoad(&roads1, &inters2);cout << inters1.GetElementCount();
	inters2.AddRoad(&roads2, &inters3);cout << inters2.GetElementCount();
	inters3.AddRoad(&roads3, &inters0);cout << inters3.GetElementCount();
	inters0.AddRoad(&roads4, &inters2);cout << inters0.GetElementCount();

	//finally cars
	Car protocar;
	protocar.SetTime(0);
	Position faux(&inters[0]);
	protocar.UpdatePosition(&faux);
	

	
	Car cars[10] = {Car(protocar),Car(protocar),Car(protocar),Car(protocar),Car(protocar),Car(protocar),Car(protocar),Car(protocar),Car(protocar),Car(protocar)};

	while(true)
	{
		for(int i = 0; i < 10; i++) cout << cars[i].GetID() << endl;
	
		int id, accident, newtime, positionid, posid2;
		positionid = -1;
		cin >> id;
		if(id == -1)
		{
			cin >> id;
			break;
		}
		


		cin >> accident;
		cin >> newtime;
		cin >> positionid;
		if(accident != 0)
			cin >> posid2;

		id++; //offset for protocar
		if(accident == 0 && &inters[positionid] != cars[id].GetPosition()->beginning)
		{
			
			Road * target = ((cars[id].GetPosition())->beginning)->FindRoad(&inters[positionid]);
			
			target->IncrementUsage();
			int time = newtime - cars[id].GetStoredTime();
			target->UpdateTravel(time);
			cars[id].SetTime(newtime);
		
			Position temp(&inters[positionid]);
			target->UpdatePosition(&temp);
		}		
				
		sleep(2);
	}
}
