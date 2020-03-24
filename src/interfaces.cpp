#include "interfaces.h"
#include "parse_string.h"

/**
 * @brief ��ȡѡ��
 */
int SelectResult()
{
	ShowMsg("Option", "������ѡ�", false);
	int option;
	std::cin >> option;
	return option;
}

/**
 * @brief ��ʼ������ʽ�ַ���
 */
void Init(std::vector<PloyTitle*>& ployVec)
{
	ShowMsg("Info", "��ӭʹ�ö���ʽ�������");
	ShowMsg("1", "ʹ���ļ��������ʽ");
	ShowMsg("2", "ʹ���ն��������ʽ");
	ShowMsg("0", "�˳�����");
	
	int option = SelectResult();
	std::string ployStrA, ployStrB;
	switch (option)
	{
	case 1:
	{
		std::vector<std::string> ployStrVec;
		ployStrVec = ReadPloyFromFiles();
		ployStrA = ployStrVec[0];
		ployStrB = ployStrVec[1];
		ShowMsg("Read", ployStrA);
		ShowMsg("Read", ployStrB);
	}
		break;
	case 2:
	{
		ShowMsg("Input", "���������ʽA��", false);
		std::cin >> ployStrA;
		ShowMsg("Input", "���������ʽB��", false);
		std::cin >> ployStrB;
	}
		break;
	case 0:	//! δ������ȷѡ�����˳����� */
	default:
		ShowMsg("Info", "���˳�����");
		exit(0);
		break;
	}
	PloyTitle* ployPtrA = parseStrToPloy(ployStrA);
	PloyTitle* ployPtrB = parseStrToPloy(ployStrB);
	if (ployPtrA && ployPtrB)
	{
		ployVec.push_back(ployPtrA);
		ployVec.push_back(ployPtrB);
	}
	else
	{
		ShowMsg("Warn", "����ʽת��ʧ�ܣ��˳�����");
		exit(0);
	}
	
}

/**
 * @brief ��ǰ�������б��ʽ���
 */
void Calc(std::vector<PloyTitle*>& ployVec)
{
	PloyTitle* ployPtrA = GetPloyByName(ployVec, "A");
	PloyTitle* ployPtrB = GetPloyByName(ployVec, "B");
	//A+B
	ployVec.push_back(AddandSubForPloy(ployPtrA, ployPtrB, OPFLAG::ADD));
	//A-B B-A
	ployVec.push_back(AddandSubForPloy(ployPtrA, ployPtrB, OPFLAG::SUB));
	ployVec.push_back(AddandSubForPloy(ployPtrB, ployPtrA, OPFLAG::SUB));
	//A*B
	ployVec.push_back(MulForPloy(ployPtrA, ployPtrB));
}

/**
 * @brief ����ѡ���������ʽ����ṹ
 */
void ShowResult(std::vector<PloyTitle*>& ployVec)
{
	std::cout << std::endl;
	ShowMsg("Info", "����ѡ���Խ�����ز���");
	std::cout << "[1] A" << "\t\t[2] B" << "\t\t[3] A+B" << "\t\t[4] A-B" << std::endl;
	std::cout << "[5] B-A" << "\t\t[6] A*B" << "\t\t[7] Export" << "\t[0] Exit" <<  std::endl;
	
	int option = SelectResult();

	switch (option)
	{
	case 1:
		ShowMsg("Output", PloyToStr(GetPloyByName(ployVec, "A")));
		break;
	case 2:
		ShowMsg("Output", PloyToStr(GetPloyByName(ployVec, "B")));
		break;
	case 3:
		ShowMsg("Output", PloyToStr(GetPloyByName(ployVec, "A+B")));
		break;
	case 4:
		ShowMsg("Output", PloyToStr(GetPloyByName(ployVec, "A-B")));
		break;
	case 5:
		ShowMsg("Output", PloyToStr(GetPloyByName(ployVec, "B-A")));
		break;
	case 6:
		ShowMsg("Output", PloyToStr(GetPloyByName(ployVec, "A*B")));
		break;
	case 7:
		WritePloyToFiles(ployVec);
		ShowMsg("Info", "������������� output.txt");
		break;
	case 0:
		RecoverSpace(ployVec);
		ShowMsg("Info", " ���˳�����");
		exit(0);
	default:
		break;
	}
	std::cout << std::endl;
}

/**
 * @brief ���ݶ���ʽ����ȡ����ʽ
 */
PloyTitle* GetPloyByName(std::vector<PloyTitle*>& ployVec, const std::string& name)
{
	for (auto ployPtr: ployVec)
	{
		if (ployPtr->name == name)
		{
			return ployPtr;
		}
	}
	return nullptr;
}

/**
 * @brief ���տռ�
 */
void RecoverSpace(std::vector<PloyTitle*>& ployVec)
{
	for (auto ployPtr: ployVec)
	{
		ReomvePloy(ployPtr);
	}
	//! ���vectorԪ�� */
	ployVec.clear();
}

/**
 * @brief �����ʾ��Ϣ
 */
void ShowMsg(const std::string& prefix, const std::string& content, bool newLine)
{
	std::cout << "[" + prefix + "] " + content;
	if (newLine)
	{
		std::cout << std::endl;
	}
}
