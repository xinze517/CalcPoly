#include "interfaces.h"

/**
 * @brief ��ȡѡ��
 */
int SelectResult()
{
	std::cout << "[Option] ������ѡ�";
	int option;
	std::cin >> option;
	return option;
}

/**
 * @brief ��ʼ������ʽ�ַ���
 */
void Init(std::string& ployStrA, std::string& ployStrB)
{
	std::cout << "[Program] ����ʽ�������" << std::endl;
	std::cout << "[1] ʹ���ļ��������ʽ" << std::endl;
	std::cout << "[2] ʹ���ն��������ʽ" << std::endl;
	
	int option = SelectResult();

	switch (option)
	{
	case 1:
	{
		std::vector<std::string> ployStrVec;
		ployStrVec = ReadPloyFromFiles();
		ployStrA = ployStrVec[0];
		ployStrB = ployStrVec[1];
		std::cout << "[Read] " << ployStrA << std::endl;
		std::cout << "[Read] " << ployStrB << std::endl;
	}
		break;
	case 2:
	{
		std::cout << "[input] ���������ʽA��";
		std::cin >> ployStrA;
		std::cout << "[input] ���������ʽB��";
		std::cin >> ployStrB;
	}
		break;
	default:
		break;
	}
}


/**
 * @brief ��ǰ�������б��ʽ���
 */
void Calc(PloyTitle* ployA, PloyTitle* ployB, std::vector<PloyTitle*>& resultVec)
{
	//A+B
	resultVec.push_back(AddandSubForPloy(ployA, ployB, OPFLAG::ADD));
	//A-B B-A
	resultVec.push_back(AddandSubForPloy(ployA, ployB, OPFLAG::SUB));
	resultVec.push_back(AddandSubForPloy(ployB, ployA, OPFLAG::SUB));
	//A*B
	resultVec.push_back(MulForPloy(ployA, ployB));
}

/**
 * @brief ����ѡ���������ʽ����ṹ
 */
void ShowResult(std::vector<PloyTitle*>& resultVec)
{
	std::cout << std::endl;
	std::cout << "[Info] ����ѡ���Խ�����ز���" << std::endl;
	std::cout << "[1] A+B" << "\t\t[2] A-B" << "\t\t[3] A*B" << std::endl;
	std::cout << "[4] B-A" << "\t\t[5] Exit" << "\t\t[0] ���ȫ������� output.txt" << std::endl;
	
	int option = SelectResult();

	switch (option)
	{
	case 1:
		std::cout << "[output] " << PloyToStr(GetPloyByName(resultVec, "A+B"));
		break;
	case 2:
		std::cout << "[output] " << PloyToStr(GetPloyByName(resultVec, "A-B"));
		break;
	case 3:
		std::cout << "[output] " << PloyToStr(GetPloyByName(resultVec, "A*B"));
		break;
	case 4:
		std::cout << "[output] " << PloyToStr(GetPloyByName(resultVec, "B-A"));
		break;
	case 5:
		std::cout << "[output] " << PloyToStr(GetPloyByName(resultVec, "B*A"));
		break;
	case 6:
		exit(0);
	case 0:
		WritePloyToFiles(resultVec);
		break;
	default:
		break;
	}
	std::cout << std::endl;
}

/**
 * @brief ���ݶ���ʽ����ȡ����ʽ
 */
PloyTitle* GetPloyByName(std::vector<PloyTitle*>& resultVec, const std::string& name)
{
	for (auto ployPtr: resultVec)
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
void RecoverSpace(std::vector<PloyTitle*>& resultVec)
{
}
