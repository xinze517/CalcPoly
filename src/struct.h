#ifndef STRUCTH_INCLUDE
#define STRUCTH_INCLUDE

#include <string>

/**
 * @brief ����ʽ�еĵ���ṹ
 */
typedef struct PloyItem
{
	double coef;				/**< ϵ�� */
	int expn;					/**< ָ�� */
	struct PloyItem* next;
}PloyItem;

/**
 * @brief ����ʽ����
 * ��Ŷ���ʽ�����ƺ�����ĵ�ַ
 */
typedef struct PloyTitle
{
	std::string name;			/**< ����ʽ�� */
	PloyItem* head;				/**< �����ַ */
}PloyTitle;

#endif //STRUCTH_INCLUDE