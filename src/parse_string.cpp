#include <regex>
#include <cstring>

#include "parse_string.h"
#include "ploy_operate.h"

/**
 * @brief ��֤����ʽ�ַ����Ƿ�Ϊ��ȷ��ʽ
 */
bool VerifyPloy(const std::string& ployStr)
{
	std::regex fullPloy("[a-zA-Z]+\\=((" + regexPolyItemUniversal + ")|(" + regexPloyItemPureNum + "))+");
	return std::regex_match(ployStr, fullPloy);
}

/**
 * @brief ת���ַ���Ϊ����ʽ�ĵ���ṹ
 */
PloyItem* parseStrToPloyItem(const std::smatch& smt)
{
	PloyItem* itemPtr = new PloyItem;
	//! ��ȡͨ�ö���ʽƥ��ʽ�ӱ��ʽ������
	auto markCount = std::regex(regexPolyItemUniversal).mark_count();
	if (smt.size() == markCount + 1)
	{
		//! �ñ��ʽ����Ϊͨ��ʽ
		itemPtr->coef = atof(smt[1].str().c_str());
		itemPtr->expn = atoi(smt[5].str().c_str());
	}
	else
	{
		//! �ñ��ʽ����Ϊ������
		itemPtr->coef = atof(smt[0].str().c_str());
		itemPtr->expn = 1;
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
	if (!VerifyPloy(ployStr))
	{
		return nullptr;
	}
	PloyTitle* ployPtr = new PloyTitle;
	std::smatch resultTmp;
	//! ��ȡ����ʽ����
	std::regex regexPloyTitle("^[a-zA-Z]+\\=");
	regex_search(ployStr, resultTmp, regexPloyTitle);
	ployPtr->name = resultTmp.str();
	//! ���¶���ʽ�ַ���
	std::string restPloyStr = resultTmp.suffix();
	//! ������ȡ����ʽ�ĸ�������ṹ
	std::regex regexPloyItem("(" + regexPolyItemUniversal + ")|(" + regexPloyItemPureNum + ")");
	while (std::regex_search(restPloyStr, resultTmp, regexPloyItem))
	{
		PloyItem* itemPtr = parseStrToPloyItem(resultTmp);
		InsertItemToPloy(ployPtr, itemPtr);
		restPloyStr = resultTmp.suffix();
	}
	return ployPtr;
}