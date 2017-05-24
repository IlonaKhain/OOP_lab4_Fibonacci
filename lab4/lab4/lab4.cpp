// lab4.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Fibonacci.h"
#include<algorithm>
#include <string>
#include <vector>
#include <iostream>
using namespace std;
int main()
{
	fibonacci<int> f(10);
	for (auto it = f.cbegin();it != f.cend(); ++it)
	{
		cout << *it << endl;
	}
	cout <<"Is 55 exist? "<< binary_search(f.cbegin(), f.cend(), 54)<<endl;
	vector<string> testvector_str;
	fibonacci<string> f1(5);
	for (auto it = f1.cbegin();it != f1.cend(); ++it)
	{
		testvector_str.push_back(*it);
		cout <<(*it) << endl;
	}
	sort(testvector_str.begin(), testvector_str.end());
	cout << "stl sort" << endl;
	for (int i = 0; i < testvector_str.size(); i++)
	{
		cout << testvector_str[i] << endl;
	}
	fibonacci<int> f2(5,-5,9);
	vector<int> testvector;
	for (auto it = f2.cbegin();it != f2.cend(); ++it)
	{
		testvector.push_back(*it);
		cout << *it << endl;
	}
	 sort(testvector.begin(),testvector.end());
	 cout << "stl sort" << endl;
	 for (int i = 0; i < testvector.size(); i++)
	 {
		 cout << testvector[i]<<endl;
	 }
	

	
	system("pause");
    return 0;
}

