#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

int main ()
{

	int n;

	cin >> n;

	if (n == 1 || n == 2)
	{
		cout << -1;
		return 0;
	}

	for (int i = n; i > 0; i--)
		cout << i << " ";

	return 0;

}	