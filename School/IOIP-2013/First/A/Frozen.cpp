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
#include <time.h>
#include <cassert>
#include <assert.h>

#define DEBUG
#define ASSERT
#define NAME "frozen"

typedef long long LL;

using namespace std;

int n, x, y, z, xstart, ystart, zstart, xfinish, yfinish, zfinish, q;

int main ()
{

	freopen (NAME".in", "r", stdin);
	freopen (NAME".out", "w", stdout);

	cin >> n;

	if (n == 1)
	{
		cin >> x;

		cin >> xstart >> xfinish;

		if (xstart > 0)
			q++;

		if (xfinish < x)
			q++;

		cout << q << endl;

		return 0;
	}

	if (n == 2)
	{
		cin >> x >> y;

		cin >> xstart >> ystart >> xfinish >> yfinish;

		if (xstart > 0)
			q++;

		if (ystart > 0)
			q++;

		if (xfinish < x)
			q++;

		if (yfinish < y)
			q++;

		cout << q << endl;

		return 0;
	}

	if (n == 3)
	{
		cin >> x >> y >> z;

		cin >> xstart >> ystart >> zstart >> xfinish >> yfinish >> zfinish;

		if (xstart > 0)
			q++;

		if (ystart > 0)
			q++;

		if (zstart > 0)
			q++;

		if (xfinish < x)
			q++;

		if (yfinish < y)
			q++;

		if (zfinish < z)
			q++;

		cout << q << endl;

		return 0;
	}	

	return 0;

}	