#ifndef PLOY_OPERATE_H_INCLUDE
#define PLOY_OPERATE_H_INCLUDE

#include "struct.h"

//! ADD��ʾ�ӷ���SUB��ʾ����,ʹ�������ռ��� */
namespace OPFLAG
{
	constexpr auto ADD = 1;
	constexpr auto SUB = -1;
}

//! double������� */
constexpr auto DOUBLE_EPS = 1e-8;

//! double������ֵ�Ƚ� */
#define IS_DOUBLE_EQUAL(m, n) (fabs(m - n) < DOUBLE_EPS)

/**
 * @brief �����ʽ����ӵ���
 */
void InsertItemToPloy(PloyTitle * ployPtr, PloyItem * itemPtr);

/**
 * @brief ����ʽ�Ӽ���
 */
PloyTitle* AddandSubForPloy(PloyTitle* ployA, PloyTitle* ployB, int opFlag);

/**
 * @brief ����ʽ�˷�
 */
PloyTitle* MulForPloy(PloyTitle* ployA, PloyTitle* ployB);

/**
 * @brief ����ʽת�ı�
 */
std::string PloyToStr(PloyTitle* ployPtr);

/**
 * @brief ���ն���ʽ�ռ�ռ��
 */
void ReomvePloy(PloyTitle* ployPtr);

#endif //PLOY_OPERATE_H_INCLUDE