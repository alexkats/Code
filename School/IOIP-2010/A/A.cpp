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
//#define NAME "a"

typedef long long LL;

using namespace std;

int n, x [110], v [110];
float r, tmin;

void swap (int &a, int &b)
{
	int t = a;

	a = b;
	b = t;
}

void QSort (int l, int r)
{
	int i = l;
	int j = r;
	int m = x [l + rand () % (r - l)];

	while (i <= j)
	{
		while (x [i] < m)
			i++;

		while (x [j] > m)
			j--;

		if (i <= j)
		{
			swap (x [i], x [j]);
			swap (v [i], v [j]);
			i++;
			j--;
		}
	}

	if (l < j)
		QSort (l, j);

	if (i < r)
		QSort (i, r);
}	

int main ()
{

//	freopen (NAME".in", "r", stdin);
//	freopen (NAME".out", "w", stdout);

	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> x [i] >> v [i];

	QSort (1, n);

	tmin = 1e9;

	for (int i = 1; i < n; i++)
	{
		r = float (x [i + 1] - x [i]) / float (v [i] - v [i + 1]);

		if (r < tmin && r > 0)
			tmin = r;
	}

	cout << tmin << endl;	

	return 0;

}	