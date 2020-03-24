#include "interfaces.h"

int main()
{
	std::vector<PloyTitle*> ployVec;

	//! 读取字符串、生成多项式 */
	Init(ployVec);
	//! 提前计算各运算结果 */
	Calc(ployVec);
	//! 循环调用 */
	while (true)
	{
		ShowResult(ployVec);
	}
}