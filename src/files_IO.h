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
 * @brief 从文件中读取多项式文本
 */
std::vector<std::string> ReadPloyFromFiles();

/**
 * @brief 将多项式文本写入文件
 */
void WritePloyToFiles(std::vector<PloyTitle*>& ployVec);

#endif //FILES_IO_H_INCLUDE
