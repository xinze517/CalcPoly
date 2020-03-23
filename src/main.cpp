#include "interfaces.h"
#include "parse_string.h"

int main()
{
	std::string ployStrA, ployStrB;
	std::vector<PloyTitle*> resultVec;

	//! 读取字符串 */
	Init(ployStrA, ployStrB);
	//! 生成多项式 */
	PloyTitle* ployPtrA = parseStrToPloy(ployStrA);
	PloyTitle* ployPtrB = parseStrToPloy(ployStrB);
	//! 提前计算各运算结果 */
	Calc(ployPtrA, ployPtrB, resultVec);
	//! 循环调用 */
	while (true)
	{
		ShowResult(resultVec);
	}
}