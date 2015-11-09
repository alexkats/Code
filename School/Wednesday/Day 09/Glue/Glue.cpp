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

string wa = "Wrong answer";

long long n, m, k, t, a [102][102], q [10001], c [10001][1001];
bool visited [102][102];

bool neighbor (long long coord, long long t)
{
	long long i, j;

	if (coord % m == 0)
		j = m;
	else
		j = coord % m;

	i = (coord - j) / m + 1;

	visited [i][j] = true;	

	if (a [i - 1][j] == t && !visited [i - 1][j] || a [i + 1][j] == t && !visited [i + 1][j] || a [i][j - 1] == t && !visited [i][j - 1] || a [i][j + 1] == t && !visited [i][j + 1])
		return true;
	else
		return false;
}	

int main ()
{
	freopen ("glue.in", "r", stdin);
	freopen ("glue.out", "w", stdout);

	cin >> n >> m;
	cin >> k;
	
	t = n * m / k;

	for (int i = 1; i <= t; i++)
		q [i] = 0;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			cin >> a [i][j];

			q [a [i][j]]++;

			if (q [a [i][j]] > k)
			{
				cout << wa;
				return 0;
			}

			if (a [i][j] > t || a [i][j] < 1)
			{
				cout << wa;
				return 0;
			}

			c [a [i][j]][q [a [i][j]]] = (i - 1) * m + j;	
		}

	if (k == 1)
	{
		cout << "OK";
		return 0;
	}	

	for (int i = 1; i <= t; i++)
		for (int j = 1; j <= k; j++)
			if (!neighbor (c [i][j], i))
			{
				cout << wa;
				return 0;
			}	

	cout << "OK";	

	return 0;
}	