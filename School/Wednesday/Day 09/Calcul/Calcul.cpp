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

int n, a [1000001], b [1000001], x, y, z, q [1000001], k, r;

int main ()
{

//	freopen ("calcul.in", "r", stdin);
//	freopen ("calcul.out", "w", stdout);

	cin >> n;

	if (n == 1)
	{
		cout << 0 << endl << 1;
		return 0;
	}

	if (n == 2)
	{
		cout << 1 << endl << 1 << " " << 2;
		return 0;
	}

	if (n == 3)
	{
		cout << 1 << endl << 1 << " " << 3;
		return 0;
	}	

	a [1] = 0;
	a [2] = 1;
	a [3] = 1;
	q [1] = 0;
	q [2] = 2;
	q [3] = 1;

	for (int i = 4; i <= n; i++)
	{
		x = 1000000;
		y = 1000000;
		z = 1000000;

		if (i % 3 == 0)
			x = a [i / 3] + 1;

		if (i % 2 == 0)
			y = a [i / 2] + 1;	

		z = a [i - 1] + 1;
		a [i] = min (x, min (y, z));
		
		if (x == min (x, min (y, z)))
			q [i] = 1;

		if (y == min (x, min (y, z)))
			q [i] = 2;

		if (z == min (x, min (y, z)))
			q [i] = 3;	
	}

	//cout << a [n] << endl << 1;

	k = a [n];
	b [k] = n;

	while (q [b [k]] > 0)
	{
		r = q [b [k]];

		if (r == 1)
		{
			k--;
			b [k] = b [k + 1] / 3;
		}

		if (r == 2)
		{
			k--;
			b [k] = b [k + 1] / 2;
		}

		if (r == 3)
		{
			k--;
			b [k] = b [k + 1] - 1;
		}
	}

	for (int i = 1; i <= a [n]; i++)
		cout << " " << b [i];	

	return 0;
}	