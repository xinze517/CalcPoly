#ifndef PARSE_STRING_H_INCLUDE
#define PARSE_STRING_H_INCLUDE

#include <regex>

#include "struct.h"	

/**
 * @brief 通用多项式正则匹配式
 * 用于匹配形如-2x^-2、-2x^2、2x^2、-2x、-x、2x、2x等形式的单项
 */
const std::string polyItemUniversalStr = "([+-]?(?:[0-9]+(?:\\.[0-9]+)?)?)[xX](?:\\^([+-]?[0-9]+))?";
const std::regex regexUni(polyItemUniversalStr);
/**
 * @brief 纯数字项匹配式
 * 用于匹配纯数字构成的单项，如-2、2等
 */
const std::string ployItemPureNumStr = "[+-]?[0-9]+(?:\\.[0-9]+)?";
const std::regex regexPureNum(ployItemPureNumStr);

bool VerifyPloy(const std::string& ployStr);

PloyItem* parseStrToPloyItem(const std::string& matchStr);

PloyTitle* parseStrToPloy(const std::string& ployStr);

#endif //PARSE_STRING_H_INCLUDE