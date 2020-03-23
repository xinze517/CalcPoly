#ifndef FILES_IO_H_INCLUDE
#define FILES_IO_H_INCLUDE

#include <vector>
#include <string>
#include <iostream>
#include <fstream>

#include "struct.h"

std::vector<std::string> ReadPloyFromFiles();

void WritePloyToFiles(std::vector<PloyTitle*>& ployVec);

#endif //FILES_IO_H_INCLUDE
