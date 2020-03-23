#include <iostream>
#include <cstring>
#include <regex>

#include "parse_string.h"
#include "ploy_operate.h"

/**
 * @brief ��֤����ʽ�ַ����Ƿ�Ϊ��ȷ��ʽ
 */
bool VerifyPloy(const std::string& ployStr)
{
	std::regex regexFullPloy("[a-zA-Z]+\\=((" + polyItemUniversalStr + ")|(" + ployItemPureNumStr + "))+");
	return std::regex_match(ployStr, regexFullPloy);
}

/**
 * @brief ת���ַ���Ϊ����ʽ�ĵ���ṹ
 */
PloyItem* parseStrToPloyItem(const std::string& matchStr)
{
	PloyItem* itemPtr = new PloyItem;
	itemPtr->next = nullptr;

	std::smatch smt;
	std::regex_search(matchStr, smt, regexUni);

	if (!smt.empty())	//! �ñ��ʽ����Ϊͨ��ʽ
	{
		//! ����ʽ����������smt[1]��smt[2]�ֱ��Ӧϵ����ָ��
		//! ��δ���񵽶�Ӧλ�õ�����ʱ��smt[1]/smt[2]��matched��ֵΪfalse
		//! ��Ӧ����ֵΪ1��ʡ�Ե����
		itemPtr->coef = smt[1].matched != false ? atof(smt[1].str().c_str()) : 1;
		itemPtr->expn = smt[2].matched != false ? atoi(smt[2].str().c_str()) : 1;
	}
	else	//! �ñ��ʽ����Ϊ������
	{	
		//! matchStr��ֵ��Ϊ������
		itemPtr->coef = atof(matchStr.c_str());
		itemPtr->expn = 0;
	}
	//! �ж��Ƿ�Ϸ�
	if (itemPtr->coef == 0)
	{
		delete itemPtr;
		itemPtr = nullptr;
	}
	return itemPtr;
}

/**
 * @brief ת���ַ���Ϊ����ʽ
 */
PloyTitle* parseStrToPloy(const std::string& ployStr)
{
	//! ����ַ����Ƿ���϶���ʽ�ĸ�ʽ */
	if (!VerifyPloy(ployStr))
	{
		return nullptr;
	}
	PloyTitle* ployPtr = new PloyTitle;
	std::smatch result;

	//! ��ȡ����ʽ����
	std::regex regexPloyTitle("^([a-zA-Z])+\\=");
	regex_search(ployStr, result, regexPloyTitle);
	ployPtr->name = result[1].str();
	ployPtr->head = nullptr;

	//! ���¶���ʽ�ַ���
	std::string restStr = result.suffix();

	//! ������ȡ����ʽ�ĸ�������ṹ
	std::regex regexPloyItem("(?:" + polyItemUniversalStr + ")|(?:" + ployItemPureNumStr + ")");
	std::regex_iterator<std::string::const_iterator> begin(restStr.cbegin(), restStr.cend(), regexPloyItem);
	for (auto iter = begin; iter != std::sregex_iterator(); iter++)
	{
		PloyItem* itemPtr = parseStrToPloyItem(iter->str());
		InsertItemToPloy(ployPtr, itemPtr);
	}
	
	return ployPtr;
}