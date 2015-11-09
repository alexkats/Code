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
#include <time.h>
#include <cassert>
#include <assert.h>

#define DEBUG
#define ASSERT
#define NAME "Help"

using namespace std;

typedef long long LL;

LL n, a [100001];

void swap (LL &a, LL &b)
{
	LL t = a;

	a = b;
	b = t;
}

void QSort (LL l, LL r)
{
	LL i = l;
	LL j = r;
	LL x = a [l + rand () % (r - l)];

	while (i <= j)
	{
		while (a [i] < x)
			i++;

		while (a [j] > x)
			j--;

		if (i <= j)
		{
			swap (a [i], a [j]);
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
	freopen (NAME".in", "r", stdin);
	freopen (NAME".out", "w", stdout);

	cin >> n;

	for (LL i = 1, i <= n; i++)
		cin >> a [i];

	QSort (1, n);

	for (LL i = 1; i <= n; i++)
		cout << a [i] << " ";

	cout << endl;

	return 0;
}	