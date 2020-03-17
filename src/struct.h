#ifndef STRUCTH_INCLUDE
#define STRUCTH_INCLUDE

#include <string>

/**
 * @brief 多项式中的单项结构
 */
typedef struct PloyItem
{
	double coef;				/**< 系数 */
	int expn;					/**< 指数 */
	struct PloyItem* next;
}PloyItem;

/**
 * @brief 多项式标题
 * 存放多项式的名称和首项的地址
 */
typedef struct PloyTitle
{
	std::string name;			/**< 多项式名 */
	PloyItem* head;				/**< 首项地址 */
}PloyTitle;

#endif //STRUCTH_INCLUDE