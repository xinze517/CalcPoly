#include <iostream>
#include <sstream>
#include <iomanip>
#include <cmath>

#include "ploy_operate.h"

//! double精度误差 */
constexpr auto DOUBLE_EPS = 1e-15;

/**
 * @brief 向多项式链表中插入单项式
 * 自动合并同类项、按指数大小升序插入
 */
void InsertItemToPloy(PloyTitle* ployPtr, PloyItem* itemPtr)
{

    PloyItem* curPtr = ployPtr->head;
    PloyItem* prePtr = nullptr;

    if (curPtr == nullptr)  //! 当多项式链表为空时，直接接入 */
    {
        itemPtr->next = nullptr;
        ployPtr->head = itemPtr;
    }
    else
    {
        while (curPtr != nullptr && itemPtr->expn > curPtr->expn)
        {
            prePtr = curPtr;
            curPtr = curPtr->next;
        }
        if (prePtr == nullptr)  //! 待插入项在链表首 */
        {
            itemPtr->next = curPtr;
            ployPtr->head = itemPtr;
        }
        else if (curPtr == nullptr) //! 待插入项在链表尾 */
        {
			prePtr->next = itemPtr;
			itemPtr->next = nullptr;
        }
        else if(itemPtr->expn < curPtr->expn)  //! 待插入项在链表中 */
        {
            prePtr->next = itemPtr;
            itemPtr->next = curPtr;
        }
        else    //! 存在与待插入项指数相同的项 */
        {
            curPtr->coef += itemPtr->coef;
			if (fabs(curPtr->coef) <= DOUBLE_EPS)   //! 判断加和后的结果是否为0 */
			{
				prePtr->next = curPtr->next;
				delete curPtr;
			}
            delete itemPtr; //! 回收插入项空间 */
        }
    }
}

/**
 * @brief 执行多项式加法或减法操作
 * 'A + B'或'A - B'
 */
PloyTitle * AddandSubForPloy(PloyTitle* ployA, PloyTitle* ployB, int opFlag)
{
    PloyTitle* ployPtr = new PloyTitle;
    PloyItem* newSpacePtr = nullptr;
    PloyItem* itemPtr = nullptr;
    ployPtr->head = nullptr;
    ployPtr->name = ployA->name + (opFlag == 1 ? "+" : "-") + ployB->name;

    //! 将多项式 A 全部项置入新多项式中 */
    for (itemPtr = ployA->head; itemPtr != NULL; itemPtr = itemPtr->next)
    {
        newSpacePtr = new PloyItem;
        newSpacePtr->coef = itemPtr->coef;
        newSpacePtr->expn = itemPtr->expn;
        newSpacePtr->next = nullptr;

        InsertItemToPloy(ployPtr, newSpacePtr);
    }
    //! 将多项式 B 全部项经 op 操作后置入新多项式中 */
	for (itemPtr = ployB->head; itemPtr != NULL; itemPtr = itemPtr->next)
	{
		newSpacePtr = new PloyItem;
		newSpacePtr->coef = itemPtr->coef * opFlag;
		newSpacePtr->expn = itemPtr->expn;
		newSpacePtr->next = nullptr;

		InsertItemToPloy(ployPtr, newSpacePtr);
	}

    return ployPtr;
}

/**
 * @brief 执行多项式乘法操作
 * 'A * B'
 */
PloyTitle* MulForPloy(PloyTitle* ployA, PloyTitle* ployB)
{
    PloyTitle* ployPtr = new PloyTitle;
	PloyItem* newSpacePtr = nullptr;
	PloyItem* itemPtrA = nullptr;
    PloyItem* itemPtrB = nullptr;
	ployPtr->head = nullptr;
    ployPtr->name = ployA->name + "*" + ployB->name;

	//! 将多项式 A 全部项置入新多项式中 */
	for (itemPtrA = ployA->head; itemPtrA != NULL; itemPtrA = itemPtrA->next)
	{
		for (itemPtrB = ployB->head; itemPtrB != NULL; itemPtrB = itemPtrB->next)
		{
            newSpacePtr = new PloyItem;
            newSpacePtr->coef = itemPtrA->coef * itemPtrB->coef;
            newSpacePtr->expn = itemPtrA->expn + itemPtrB->expn;
            newSpacePtr->next = nullptr;

            InsertItemToPloy(ployPtr, newSpacePtr);
		}
	}

    return ployPtr;
}

/**
 * @brief 按格式返回多项式的字符串
 */
std::string PloyToStr(PloyTitle* ployPtr)
{
    std::stringstream ss;

    PloyItem* itemPtr = ployPtr->head;
    if (itemPtr == nullptr)
    {
        ss << "多项式为空！无法转换";
    }
    else
    {
        //! 多项式名 */
        ss << ployPtr->name << "=";
        while (itemPtr)
        {
            //组合符号
            if(itemPtr->coef > 0 && itemPtr != ployPtr->head)
            {
                ss << "+";
            }
            else if (itemPtr->coef < 0)
            {
                ss << "-";
            }
            //组合系数
            if (itemPtr->coef != 1)
            {
                ss << std::fixed << std::setprecision(1) << fabs(itemPtr->coef);
            }
            //组合指数
            if (itemPtr->expn != 0)
            {
                ss << "x";
				if (itemPtr->expn != 1)
				{
                    ss << "^" << itemPtr->expn;
				}
            }
            itemPtr = itemPtr->next;
        }
    }
    return ss.str();
}