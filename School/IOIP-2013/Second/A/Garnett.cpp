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
#define NAME "garnett"

typedef long long LL;

using namespace std;

int n, m, cx [5], cy [5], a, mx, my, m1, m2, s1, s2;
bool flag;

int main ()
{

	freopen (NAME".in", "r", stdin);
	freopen (NAME".out", "w", stdout);

	cin >> n >> m;
	int q = 0;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			cin >> a;

			if (a == 1)
			{
				q++;
				cx [q] = j;
				cy [q] = i;
			}
		}

	if (cx [1] == cx [2])
	{
		my = max (cy [2] - 1, n - cy [1]);
		cout << my * m << endl;
		return 0;
	}

	if (cy [1] == cy [2])
	{
		mx = max (cx [2] - 1, m - cx [1]);
		cout << mx * n << endl;
		return 0;
	}

	if (cx [1] < cx [2])
		flag = true;
	else
		flag = false;

	s1 = m * (cy [2] - 1);

	if (flag)
		s2 = n * (cx [2] - 1);
	else
		s2 = n * (m - cx [2]);

	m1 = max (s1, s2);
	s1 = m * (n - cy [1]);

	if (flag)
		s2 = n * (m - cx [1]);
	else
		s2 = n * (cx [1] - 1);

	m2 = max (s1, s2);

	cout << max (m1, m2) << endl;	

	return 0;

}	