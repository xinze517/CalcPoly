#include "interfaces.h"

/**
 * @brief 读取选项
 */
int SelectResult()
{
	std::cout << "[Option] 请输入选项：";
	int option;
	std::cin >> option;
	return option;
}

/**
 * @brief 初始化多项式字符串
 */
void Init(std::string& ployStrA, std::string& ployStrB)
{
	std::cout << "[Program] 多项式计算程序" << std::endl;
	std::cout << "[1] 使用文件输入多项式" << std::endl;
	std::cout << "[2] 使用终端输入多项式" << std::endl;
	
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
		std::cout << "[input] 请输入多项式A：";
		std::cin >> ployStrA;
		std::cout << "[input] 请输入多项式B：";
		std::cin >> ployStrB;
	}
		break;
	default:
		break;
	}
}


/**
 * @brief 提前继续所有表达式结果
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
 * @brief 根据选项输出多项式计算结构
 */
void ShowResult(std::vector<PloyTitle*>& resultVec)
{
	std::cout << std::endl;
	std::cout << "[Info] 输入选项以进行相关操作" << std::endl;
	std::cout << "[1] A+B" << "\t\t[2] A-B" << "\t\t[3] A*B" << std::endl;
	std::cout << "[4] B-A" << "\t\t[5] Exit" << "\t\t[0] 输出全部结果至 output.txt" << std::endl;
	
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
 * @brief 根据多项式名获取多项式
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
 * @brief 回收空间
 */
void RecoverSpace(std::vector<PloyTitle*>& resultVec)
{
}
