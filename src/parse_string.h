#ifndef PARSE_STRING_H_INCLUDE
#define PARSE_STRING_H_INCLUDE

#include "struct.h"	

/**
 * @brief 通用多项式正则匹配式
 * 用于匹配形如-2x^-2、-2x^2、2x^2、-2x、-x、2x、2x等形式的单项
 */
const std::string regexPolyItemUniversal = "([+-]?([0-9]+(\\.[0-9]+)?)?)[xX](\\^([+-]?[0-9]+))?";
/**
 * @brief 纯数字项匹配式
 * 用于匹配纯数字构成的单项，如-2、2等
 */
const std::string regexPloyItemPureNum = "[+-]?[0-9]+(\\.[0-9]+)?";	

//! 验证多项式字符串是否为正确格式 */
bool VerifyPloy(const std::string& ployStr);
//! 转换字符串为多项式的单项结构 */
PloyItem* parseStrToPloyItem(const std::smatch& smt);
//! 转换字符串为多项式 */
PloyTitle* parseStrToPloy(const std::string& ployStr);


#endif //PARSE_STRING_H_INCLUDE