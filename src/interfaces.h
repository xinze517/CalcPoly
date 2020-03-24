#ifndef INTERFACES_H_INCLUDE
#define INTERFACES_H_INCLUDE

#include <iostream>
#include <vector>

#include "struct.h"
#include "ploy_operate.h"
#include "files_IO.h"

/**
 * @brief ��ȡѡ������
 */
int SelectResult();

/**
 * @brief ��ʼ��
 * ���ļ������ն��������ݳ�ʼ��
 */
void Init(std::vector<PloyTitle*>& ployVec);

/**
 * @brief ��ǰ��������ʽֵ
 */
void Calc(std::vector<PloyTitle*>& ployVec);

/**
 * @brief ����ѡ��չʾ��ͬ�ı��ʽ�Ľ��
 */
void ShowResult(std::vector<PloyTitle*>& ployVec);

/**
 * @brief ���ݶ���ʽ�����ض���ʽָ��
 */
PloyTitle* GetPloyByName(std::vector<PloyTitle*>& ployVec, const std::string& name);

/**
 * @brief ���ն���ʽ����ռ�õ����пռ�
 */
void RecoverSpace(std::vector<PloyTitle*>& ployVec);

/**
 * @brief �������ʽ�����ʾ���
 */
void ShowMsg(const std::string& prefix, const std::string& content, bool newLine = true);

#endif //INTERFACES_H_INCLUDE