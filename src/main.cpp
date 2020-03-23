#include "interfaces.h"
#include "parse_string.h"

int main()
{
	std::string ployStrA, ployStrB;
	std::vector<PloyTitle*> resultVec;

	//! ��ȡ�ַ��� */
	Init(ployStrA, ployStrB);
	//! ���ɶ���ʽ */
	PloyTitle* ployPtrA = parseStrToPloy(ployStrA);
	PloyTitle* ployPtrB = parseStrToPloy(ployStrB);
	//! ��ǰ����������� */
	Calc(ployPtrA, ployPtrB, resultVec);
	//! ѭ������ */
	while (true)
	{
		ShowResult(resultVec);
	}
}