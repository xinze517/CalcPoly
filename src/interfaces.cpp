#include "interfaces.h"
#include "parse_string.h"

/**
 * @brief 读取选项
 */
int SelectResult()
{
	ShowMsg("Option", "请输入选项：", false);
	int option;
	std::cin >> option;
	return option;
}

/**
 * @brief 初始化多项式字符串
 */
void Init(std::vector<PloyTitle*>& ployVec)
{
	ShowMsg("Info", "欢迎使用多项式计算程序");
	ShowMsg("1", "使用文件输入多项式");
	ShowMsg("2", "使用终端输入多项式");
	ShowMsg("0", "退出程序");
	
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
		ShowMsg("Input", "请输入多项式A：", false);
		std::cin >> ployStrA;
		ShowMsg("Input", "请输入多项式B：", false);
		std::cin >> ployStrB;
	}
		break;
	case 0:	//! 未输入正确选项则退出程序 */
	default:
		ShowMsg("Info", "已退出程序！");
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
		ShowMsg("Warn", "多项式转换失败，退出程序！");
		exit(0);
	}
	
}

/**
 * @brief 提前计算所有表达式结果
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
 * @brief 根据选项输出多项式计算结构
 */
void ShowResult(std::vector<PloyTitle*>& ployVec)
{
	std::cout << std::endl;
	ShowMsg("Info", "输入选项以进行相关操作");
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
		ShowMsg("Info", "计算结果已输出到 output.txt");
		break;
	case 0:
		RecoverSpace(ployVec);
		ShowMsg("Info", " 已退出程序！");
		exit(0);
	default:
		break;
	}
	std::cout << std::endl;
}

/**
 * @brief 根据多项式名获取多项式
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
 * @brief 回收空间
 */
void RecoverSpace(std::vector<PloyTitle*>& ployVec)
{
	for (auto ployPtr: ployVec)
	{
		ReomvePloy(ployPtr);
	}
	//! 清除vector元素 */
	ployVec.clear();
}

/**
 * @brief 输出提示信息
 */
void ShowMsg(const std::string& prefix, const std::string& content, bool newLine)
{
	std::cout << "[" + prefix + "] " + content;
	if (newLine)
	{
		std::cout << std::endl;
	}
}
