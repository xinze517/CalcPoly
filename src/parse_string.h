#ifndef PARSE_STRING_H_INCLUDE
#define PARSE_STRING_H_INCLUDE

#include "struct.h"	

/**
 * @brief ͨ�ö���ʽ����ƥ��ʽ
 * ����ƥ������-2x^-2��-2x^2��2x^2��-2x��-x��2x��2x����ʽ�ĵ���
 */
const std::string regexPolyItemUniversal = "([+-]?([0-9]+(\\.[0-9]+)?)?)[xX](\\^([+-]?[0-9]+))?";
/**
 * @brief ��������ƥ��ʽ
 * ����ƥ�䴿���ֹ��ɵĵ����-2��2��
 */
const std::string regexPloyItemPureNum = "[+-]?[0-9]+(\\.[0-9]+)?";	

//! ��֤����ʽ�ַ����Ƿ�Ϊ��ȷ��ʽ */
bool VerifyPloy(const std::string& ployStr);
//! ת���ַ���Ϊ����ʽ�ĵ���ṹ */
PloyItem* parseStrToPloyItem(const std::smatch& smt);
//! ת���ַ���Ϊ����ʽ */
PloyTitle* parseStrToPloy(const std::string& ployStr);


#endif //PARSE_STRING_H_INCLUDE