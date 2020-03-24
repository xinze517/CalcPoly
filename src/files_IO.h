#ifndef FILES_IO_H_INCLUDE
#define FILES_IO_H_INCLUDE

#include <vector>
#include <string>
#include <iostream>
#include <fstream>

#include "struct.h"

const std::string INPUT_FILE = "input.txt";
const std::string OUTPUT_FILE = "output.txt";

/**
 * @brief ���ļ��ж�ȡ����ʽ�ı�
 */
std::vector<std::string> ReadPloyFromFiles();

/**
 * @brief ������ʽ�ı�д���ļ�
 */
void WritePloyToFiles(std::vector<PloyTitle*>& ployVec);

#endif //FILES_IO_H_INCLUDE
