#include <iostream>
#include <string>
#include <cmath>
#include <map>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main ()
{

	freopen ("fib.in", "r", stdin);
	freopen ("fib.out", "w", stdout);

	int n, a [46];

	cin >> n;
	a [0] = 1;
	a [1] = 1;

	if (n == 0 || n == 1)
	{
		cout << 1;
		return 0;
	}

	for (int i = 2; i <= n; i++)
		a [i] = a [i - 1] + a [i - 2];

	cout << a [n];

	return 0;

}	