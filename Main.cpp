#include "IntNum.h"

int main() {
	IntNum a;
	bool test = a.input();
	if (!test)
	{
		system("pause");
		return 1;
	}
	a.output();
	system("pause");
	return 0;
}