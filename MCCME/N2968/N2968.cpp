#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <assert.h>
#include <time.h>

#define DEBUG
#define ASSERT
#define NAMEIN "input.txt"
#define NAMEOUT "output.txt"

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

int n, a [1000010], b [10000000], x, y, z, k, q;

int main ()
{

	ifstream in (NAMEIN);
	ofstream out (NAMEOUT);

	in >> n;

	if (n == 1)
		return 0;

	a [1] = 0;

	for (int i = 2; i <= n; i++)
	{
		x = a [i - 1] + 1;
		y = x + 1;
		z = x + 1;

		if (i % 2 == 0)
			y = a [i / 2] + 1;

		if (i % 3 == 0)
			z = a [i / 3] + 1;

		a [i] = min (x, min (y, z));
	}

	k = n;
	q = a [n];

	while (k > 1)
	{
		if (a [k - 1] == q - 1)
		{
			b [q] = 1;
			k--;
			q--;
			continue;
		}

		if (a [k / 2] == q - 1 && k % 2 == 0)
		{
			b [q] = 2;
			k /= 2;
			q--;
			continue;
		}

		if (a [k / 3] == q - 1 && k % 3 == 0)
		{
			b [q] = 3;
			k /= 3;
			q--;
			continue;
		}
	}

	for (int i = 1; i <= a [n]; i++)
		out << b [i];	

	return 0;

}	