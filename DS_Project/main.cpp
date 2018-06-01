#include<string>
#include<map>

#include"LinkedList.h"
#include"ArrayList.h"
#include"BinaryTree.h"

using namespace std;

int main(void)
{
	string pages = "15-243";
	int a, b, c;
	size_t pos = pages.find("-");
	auto d = pages.substr(0, pos - 0);
	auto e = pages.substr(pos+1);
	a = atoi(d.c_str());
	b = atoi(e.c_str());
	cout << a << endl << b << endl;
	cout << b - a + 1;

	/*
	kmh::BinaryTree<string> bt;
	bt.add("First");
	bt.add("Second");
	bt.add("Third");
	bt.add("Fourth");
	bt.add("Fifth");

	in_order(bt, [](auto val) { cout << val->data << " "; });
	bt.make_empty();*/

	return 0;
}