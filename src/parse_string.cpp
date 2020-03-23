#include <iostream>
#include <cstring>
#include <regex>

#include "parse_string.h"
#include "ploy_operate.h"

/**
 * @brief 验证多项式字符串是否为正确格式
 */
bool VerifyPloy(const std::string& ployStr)
{
	std::regex regexFullPloy("[a-zA-Z]+\\=((" + polyItemUniversalStr + ")|(" + ployItemPureNumStr + "))+");
	return std::regex_match(ployStr, regexFullPloy);
}

/**
 * @brief 转换字符串为多项式的单项结构
 */
PloyItem* parseStrToPloyItem(const std::string& matchStr)
{
	PloyItem* itemPtr = new PloyItem;
	itemPtr->next = nullptr;

	std::smatch smt;
	std::regex_search(matchStr, smt, regexUni);

	if (!smt.empty())	//! 该表达式类型为通用式
	{
		//! 正则式的两个捕获smt[1]和smt[2]分别对应系数与指数
		//! 当未捕获到对应位置的数据时，smt[1]/smt[2]的matched的值为false
		//! 对应的是值为1被省略的情况
		itemPtr->coef = smt[1].matched != false ? atof(smt[1].str().c_str()) : 1;
		itemPtr->expn = smt[2].matched != false ? atoi(smt[2].str().c_str()) : 1;
	}
	else	//! 该表达式类型为纯数字
	{	
		//! matchStr的值即为该数字
		itemPtr->coef = atof(matchStr.c_str());
		itemPtr->expn = 0;
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
	//! 检查字符串是否符合多项式的格式 */
	if (!VerifyPloy(ployStr))
	{
		return nullptr;
	}
	PloyTitle* ployPtr = new PloyTitle;
	std::smatch result;

	//! 提取多项式名称
	std::regex regexPloyTitle("^([a-zA-Z])+\\=");
	regex_search(ployStr, result, regexPloyTitle);
	ployPtr->name = result[1].str();
	ployPtr->head = nullptr;

	//! 更新多项式字符串
	std::string restStr = result.suffix();

	//! 逐项提取多项式的各个单项结构
	std::regex regexPloyItem("(?:" + polyItemUniversalStr + ")|(?:" + ployItemPureNumStr + ")");
	std::regex_iterator<std::string::const_iterator> begin(restStr.cbegin(), restStr.cend(), regexPloyItem);
	for (auto iter = begin; iter != std::sregex_iterator(); iter++)
	{
		PloyItem* itemPtr = parseStrToPloyItem(iter->str());
		InsertItemToPloy(ployPtr, itemPtr);
	}
	
	return ployPtr;
}