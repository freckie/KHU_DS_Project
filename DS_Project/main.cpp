/*#include"Application.h"

using namespace std;

int main(void)
{
	Application app;
	app.run();

	return 0;
}*/

#include"AuthorType.h"
#include"Map.h"

#include<string>
#include<iostream>

using namespace std;

int main(void)
{
	kmh::Map<AuthorType, int> map;
	AuthorType temp("A");
	//map.emplace(temp, 0);
	kmh::Pair<AuthorType, int> p1(temp, 0);
	map.add(p1);

	AuthorType temp2("B");
	map.add(kmh::make_map_pair<AuthorType, int>(temp2, 1));

	AuthorType temp3("C");
	map.add(kmh::Pair<AuthorType, int>(temp3, 0));

	for(auto it = map.begin(); it!=map.end(); ++it)
	{
		(*it).key.display_name();
		cout << (*it).val << endl;
	}
}