#include <regex>
#include <cstring>

#include "parse_string.h"
#include "ploy_operate.h"

/**
 * @brief 验证多项式字符串是否为正确格式
 */
bool VerifyPloy(const std::string& ployStr)
{
	std::regex fullPloy("[a-zA-Z]+\\=((" + regexPolyItemUniversal + ")|(" + regexPloyItemPureNum + "))+");
	return std::regex_match(ployStr, fullPloy);
}

/**
 * @brief 转换字符串为多项式的单项结构
 */
PloyItem* parseStrToPloyItem(const std::smatch& smt)
{
	PloyItem* itemPtr = new PloyItem;
	//! 获取通用多项式匹配式子表达式的数量
	auto markCount = std::regex(regexPolyItemUniversal).mark_count();
	if (smt.size() == markCount + 1)
	{
		//! 该表达式类型为通用式
		itemPtr->coef = atof(smt[1].str().c_str());
		itemPtr->expn = atoi(smt[5].str().c_str());
	}
	else
	{
		//! 该表达式类型为纯数字
		itemPtr->coef = atof(smt[0].str().c_str());
		itemPtr->expn = 1;
	}
	//! 判断是否合法
	if (itemPtr->coef == 0)
	{
		delete itemPtr;
		itemPtr = nullptr;
	}
	return itemPtr;
}

/**
 * @brief 转换字符串为多项式
 */
PloyTitle* parseStrToPloy(const std::string& ployStr)
{
	if (!VerifyPloy(ployStr))
	{
		return nullptr;
	}
	PloyTitle* ployPtr = new PloyTitle;
	std::smatch resultTmp;
	//! 提取多项式名称
	std::regex regexPloyTitle("^[a-zA-Z]+\\=");
	regex_search(ployStr, resultTmp, regexPloyTitle);
	ployPtr->name = resultTmp.str();
	//! 更新多项式字符串
	std::string restPloyStr = resultTmp.suffix();
	//! 逐项提取多项式的各个单项结构
	std::regex regexPloyItem("(" + regexPolyItemUniversal + ")|(" + regexPloyItemPureNum + ")");
	while (std::regex_search(restPloyStr, resultTmp, regexPloyItem))
	{
		PloyItem* itemPtr = parseStrToPloyItem(resultTmp);
		InsertItemToPloy(ployPtr, itemPtr);
		restPloyStr = resultTmp.suffix();
	}
	return ployPtr;
}