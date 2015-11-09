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
#define NAME ""

typedef long long LL;

using namespace std;

int n, m, q, a [100010], k, x;
char ch;

int main ()
{
	freopen (NAME".in", "r", stdin);	
	freopen (NAME".out", "w", stdout);
	
	cin >> n >> m;
	q = 0;	
	
	for (int i = 1; i <= n; i++)
		cin >> a [i];

	r = q;	

	for (int i = 1; i < n; i++)
		if (a [i] > a [i + 1])
			q++;	

	for (int i = 1; i <= m; i++)
	{
		cin >> ch; 

		if (ch == 33)
			cin >> k >> x;

		if (ch == 63)
			if (q == 0)
				cout << "YES";
			else
				cout << "NO";	

		if (ch == 33)
		{
			if (a [k] > a [k + 1] && a [k + 1] >= x)
				q--;

			if (a [k] <= a [k + 1] && a [k + 1] < x)
				q++;

			if (a [k - 1] > a [k] && a [k - 1] <= x)
				q--;

			if (a [k - 1] <= a [k] && a [k - 1] > x)
				q++;	
	}

	return 0;
}	