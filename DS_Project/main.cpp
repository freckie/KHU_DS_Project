#include<string>
#include<list>

#include"LinkedList.h"
#include"ArrayList.h"
#include"BinaryTree.h"

#include"PaperType.h"
#include"ConferenceType.h"

using namespace std;

int main(void)
{
	ConferenceType conf;
	conf.set_title("Industrial_4.0");
	conf.set_date("2018.06.02");

	PaperType* p1 = new PaperType;
	p1->set_title("Machine_Learning_#1");
	p1->set_author({"khuphj", "freckie"});
	p1->set_page("1-15");

	PaperType* p2 = new PaperType;
	p2->set_title("Machine_Learning_#2");
	p2->set_author({ "khuphj", "freckie", "xezout108" });
	p2->set_page("16-68");

	PaperType* p3 = new PaperType;
	p3->set_title("Advanced_Linear_Algebra");
	p3->set_author({ "freckie" });
	p3->set_page("69-74");

	conf.add_paper(p1);
	conf.add_paper(p2);
	conf.add_paper(p3);

	conf.display_record();

	cout << endl;

	cout << "찾기찾기 :: Advanced_Linear_Algebra" << endl;
	auto it = conf.find_paper("Advanced_Linear_Algebra");
	if (it.isNull())
		cout << "일치하는 결과 없음" << endl;
	else
		(*it)->display_record();
}