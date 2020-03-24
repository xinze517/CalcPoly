#ifndef PLOY_OPERATE_H_INCLUDE
#define PLOY_OPERATE_H_INCLUDE

#include "struct.h"

//! ADD表示加法，SUB表示减法,使用命名空间存放 */
namespace OPFLAG
{
	constexpr auto ADD = 1;
	constexpr auto SUB = -1;
}

//! double精度误差 */
constexpr auto DOUBLE_EPS = 1e-8;

//! double类型数值比较 */
#define IS_DOUBLE_EQUAL(m, n) (fabs(m - n) < DOUBLE_EPS)

/**
 * @brief 向多项式中添加单项
 */
void InsertItemToPloy(PloyTitle * ployPtr, PloyItem * itemPtr);

/**
 * @brief 多项式加减法
 */
PloyTitle* AddandSubForPloy(PloyTitle* ployA, PloyTitle* ployB, int opFlag);

/**
 * @brief 多项式乘法
 */
PloyTitle* MulForPloy(PloyTitle* ployA, PloyTitle* ployB);

/**
 * @brief 多项式转文本
 */
std::string PloyToStr(PloyTitle* ployPtr);

/**
 * @brief 回收多项式空间占用
 */
void ReomvePloy(PloyTitle* ployPtr);

#endif //PLOY_OPERATE_H_INCLUDE