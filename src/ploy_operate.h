#ifndef PLOY_OPERATE_H_INCLUDE
#define PLOY_OPERATE_H_INCLUDE

#include "struct.h"

//! ADD表示加法，SUB表示减法,使用命名空间存放 */
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