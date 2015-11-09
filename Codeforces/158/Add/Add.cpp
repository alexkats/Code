#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

int a, b, n;
bool flag;

int main ()
{

	cin >> a >> b >> n;

	for (int j = 0; j < 10; j++)
		if ((a * 10 + j) % b == 0)
		{
			flag = true;
			a = a * 10 + j;
			break;
		}

	if (!flag)
	{
		cout << -1;
		return 0;
	}


	cout << a;

	for (int i = 2; i <= n; i++)
		cout << 0;	

	return 0;

}	