#ifndef PARSE_STRING_H_INCLUDE
#define PARSE_STRING_H_INCLUDE

#include <regex>

#include "struct.h"	

/**
 * @brief ͨ�ö���ʽ����ƥ��ʽ
 * ����ƥ������-2x^-2��-2x^2��2x^2��-2x��-x��2x��2x����ʽ�ĵ���
 */
const std::string polyItemUniversalStr = "([+-]?(?:[0-9]+(?:\\.[0-9]+)?)?)[xX](?:\\^([+-]?[0-9]+))?";
const std::regex regexUni(polyItemUniversalStr);
/**
 * @brief ��������ƥ��ʽ
 * ����ƥ�䴿���ֹ��ɵĵ����-2��2��
 */
const std::string ployItemPureNumStr = "[+-]?[0-9]+(?:\\.[0-9]+)?";
const std::regex regexPureNum(ployItemPureNumStr);

bool VerifyPloy(const std::string& ployStr);

PloyItem* parseStrToPloyItem(const std::string& matchStr);

PloyTitle* parseStrToPloy(const std::string& ployStr);

#endif //PARSE_STRING_H_INCLUDE