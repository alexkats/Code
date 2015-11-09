#include <iostream>
#include <map>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int a [1000], n, k;

int main ()
{

	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);

	a [0] = 1;
	a [1] = 1;

	cin >> n;

	for (int i = 2; i <= n; i++)
		if (i % 2 == 0)
		{
			k = i / 2;
			a [i] = a [k] + a [k - 1];
		}	
		else
		{
			k = (i - 1) / 2;
			a [i] = a [k] - a [k - 1];
		}	

	cout << a [n];	

	return 0;

}	