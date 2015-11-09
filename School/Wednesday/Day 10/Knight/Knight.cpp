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

int n, m, d [51][51];

int main ()
{

	freopen ("knight.in", "r", stdin);
	freopen ("knight.out", "w", stdout);

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			d [i][j] = 0;

	d [2][3] = 1;
	d [3][2] = 1;
	d [1][1] = 1;

	for (int i = 3; i <= n; i++)
		for (int j = 1; j <= m; j++)
			d [i][j] = d [i - 2][j - 1] + d [i - 1][j - 2];

	cout << d [n][m];	

	return 0;

}	