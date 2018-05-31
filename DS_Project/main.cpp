#include<string>
#include<map>

#include"LinkedList.h"
#include"ArrayList.h"
#include"BinaryTree.h"

using namespace std;

int main(void)
{
	kmh::BinaryTree<int> bt;
	bt.add(5);
	bt.add(7);
	bt.add(1);
	bt.add(4);
	bt.add(3);

	pre_order(bt, [](int val) { cout << val << " "; });
}