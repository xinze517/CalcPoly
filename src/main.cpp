#include "interfaces.h"

int main()
{
	std::vector<PloyTitle*> ployVec;

	//! ��ȡ�ַ��������ɶ���ʽ */
	Init(ployVec);
	//! ��ǰ����������� */
	Calc(ployVec);
	//! ѭ������ */
	while (true)
	{
		ShowResult(ployVec);
	}
}