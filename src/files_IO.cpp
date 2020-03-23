#include "files_IO.h"
#include "ploy_operate.h"

/**
 * @brief 从文件中读取字符串至Vector
 */
std::vector<std::string> ReadPloyFromFiles()
{
	std::vector<std::string> ployStrVec;
	std::ifstream infile;
	infile.open("input.txt");
	std::string ployStrA, ployStrB;
	infile >> ployStrA >> ployStrB;
	ployStrVec.push_back(ployStrA);
	ployStrVec.push_back(ployStrB);
	infile.close();
	return ployStrVec;
}

/**
 * @brief 将字符串写入文件
 */
void WritePloyToFiles(std::vector<PloyTitle*>& ployVec)
{
	std::ofstream outfile;
	outfile.open("output.txt", std::ios::trunc);
	for (auto ployPtr: ployVec)
	{
		outfile << PloyToStr(ployPtr) << std::endl;
	}
	outfile.close();
}
