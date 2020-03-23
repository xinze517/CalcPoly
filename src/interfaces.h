#ifndef INTERFACES_H_INCLUDE
#define INTERFACES_H_INCLUDE

#include <iostream>
#include <vector>

#include "struct.h"
#include "ploy_operate.h"
#include "files_IO.h"

int SelectResult();

void Init(std::string& ployStrA, std::string& ployStrB);

void Calc(PloyTitle* ployA, PloyTitle* ployB, std::vector<PloyTitle*>& resultVec);

void ShowResult(std::vector<PloyTitle*>& resultVec);

PloyTitle* GetPloyByName(std::vector<PloyTitle*>& resultVec, const std::string& name);

void RecoverSpace(std::vector<PloyTitle*>& resultVec);
#endif //INTERFACES_H_INCLUDE