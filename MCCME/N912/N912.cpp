#include <iostream>
#include <map>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int a [40], i, n, b [40], c [40];

int main ()
{

	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);

	cin >> n;

	a [1] = 2;
	a [2] = 4;
	b [1] = 0;
	b [2] = 1;
	c [1] = 1;
	c [2] = 2;

	for (int i = 3; i <= n; i++)
	{
		a [i] = 2 * a [i - 1] - b [i - 1];
		c [i] = a [i - 1] - c [i - 1] - a [i - 2];
		b [i] = a [i] - a [i - 1] - c [i];
	}

	cout << a [n];	

	return 0;

}	