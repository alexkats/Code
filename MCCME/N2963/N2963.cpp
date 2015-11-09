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
#define NAMEIN "input"
#define NAMEOUT "output"

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

int n;
ll a [1000010], x, y, z;

int main ()
{

	ifstream in (NAMEIN".txt");
	ofstream out (NAMEOUT".txt");

	in >> n;

	if (n == 1)
	{
		out << 0 << endl;
		return 0;
	}

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

	out << a [n] << endl;	

	return 0;

}	