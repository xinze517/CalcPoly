#ifndef PLOY_OPERATE_H_INCLUDE
#define PLOY_OPERATE_H_INCLUDE

#include "struct.h"

//! ADD��ʾ�ӷ���SUB��ʾ����,ʹ�������ռ��� */
namespace OPFLAG
{
	constexpr auto ADD = 1;
	constexpr auto SUB = -1;
}

void InsertItemToPloy(PloyTitle * ployPtr, PloyItem * itemPtr);

PloyTitle* AddandSubForPloy(PloyTitle* ployA, PloyTitle* ployB, int opFlag);

PloyTitle* MulForPloy(PloyTitle* ployA, PloyTitle* ployB);

std::string PloyToStr(PloyTitle* ployPtr);

#endif //PLOY_OPERATE_H_INCLUDE