#include <iostream>
#include <string>
#include "DoubleLinkList.h"

struct data {
	std::string id;
	std::string val;
};
int main(){
	DoubleLinkList<data> A;
	data a,b;
	a.id = "1";
	a.val = "2";
	b.id = "bb";
	b.val = "bbb";
	A.HeadInsert(a);
	A.HeadInsert(b);
	auto p = A.GetHead()->next_;
	auto B = A;
	auto pp = B.GetHead()->next_;
	std::cout << pp->val_.id << " " << pp->val_.val << std::endl;
	system("pause");
    return 0;
}