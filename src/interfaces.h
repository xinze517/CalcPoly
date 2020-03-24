#ifndef INTERFACES_H_INCLUDE
#define INTERFACES_H_INCLUDE

#include <iostream>
#include <vector>

#include "struct.h"
#include "ploy_operate.h"
#include "files_IO.h"

/**
 * @brief 获取选择内容
 */
int SelectResult();

/**
 * @brief 初始化
 * 由文件或由终端输入数据初始化
 */
void Init(std::vector<PloyTitle*>& ployVec);

/**
 * @brief 提前计算各表达式值
 */
void Calc(std::vector<PloyTitle*>& ployVec);

/**
 * @brief 根据选项展示不同的表达式的结果
 */
void ShowResult(std::vector<PloyTitle*>& ployVec);

/**
 * @brief 根据多项式名返回多项式指针
 */
PloyTitle* GetPloyByName(std::vector<PloyTitle*>& ployVec, const std::string& name);

/**
 * @brief 回收多项式向量占用的所有空间
 */
void RecoverSpace(std::vector<PloyTitle*>& ployVec);

/**
 * @brief 以组合形式输出提示语句
 */
void ShowMsg(const std::string& prefix, const std::string& content, bool newLine = true);

#endif //INTERFACES_H_INCLUDE