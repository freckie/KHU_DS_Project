#include<string>
#include<map>

#include"LinkedList.h"
#include"ArrayList.h"
#include"BinaryTree.h"

using namespace std;

int main(void)
{
	kmh::BinaryTree<string> bt;
	bt.add("First");
	bt.add("Second");
	bt.add("Third");
	bt.add("Fourth");
	bt.add("Fifth");

	in_order(bt, [](auto val) { cout << val->data << " "; });
	bt.make_empty();

	return 0;
}