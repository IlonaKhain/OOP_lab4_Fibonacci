// Lab4_Fibonacci.cpp: определяет экспортированные функции для приложения DLL.
//

#include "stdafx.h"
#include "Fibonacci.h"
#include <iostream>
using namespace std;

int main()
{
	//test with binary search
	fibonacci<int> f(5, 0, 1);
for (auto it = f.cbegin(); it = f.cend(); it++)
{
	cout << *it << endl;
}
	return 0;
}


