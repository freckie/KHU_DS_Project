#include<string>
#include<map>

#include"LinkedList.h"
#include"ArrayList.h"
#include"BinaryTree.h"

using namespace std;

int main(void)
{
	kmh::Array<std::string, 2> arr{ "Seoul", "Busan" };
	for (auto it : arr)
		cout << it << " ";
	cout << endl;

	kmh::BinaryTree<int> bt;
	bt.add(5);
	bt.add(7);
	bt.add(1);
	bt.add(4);
	bt.add(3);

	for (auto it : bt)
		cout << it << " ";
}