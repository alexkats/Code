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

typedef long long LL;

using namespace std;

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
	int x = c [l + rand () % (r - l)];

	while (i <= j)
	{
		while (c [i] < x)
			i++;

		while (c [j] > x)
			j--;

		if (i <= j)
		{
			swap (c [i], c [j]);
			swap (num [i], num [j]);
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

	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		cin >> a [i];

	for (int i = 1; i <= n; i++)
		cin >> b [i];

	for (int i = 1; i <= n; i++)
		c [i] = b [i];

	for (int i = 1; i <= n; i++)
		num [i] = i;	

	QSort (1, n);

	for (int i = 1; i <= n; i++)
	{
		m [num [n - i + 1]] = c [n - i + 1];
		ind [i] = num [n - i + 1];
		d [i] = 0;
		dp [i] = 0;
	}

	d [1] = m [1];
	dp [1] = ind [1];	

	for (int i = 2; i <= n; i++)
	{	
		if (d [i - 1] == 0)
		{
			d [i] = 0;
			dp [i] = 0;
			continue;
		}

		if (dp [i - 1] == d [i - 1])
		{
			d [i] = 0;
			dp [i] = 0;
			continue;
		}

		d [i] = 	

	return 0;

}	