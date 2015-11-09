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

long long n, m, a [21][21], b [21][21], c [3][3];

int main ()
{

	freopen ("cylon.in", "r", stdin);
	freopen ("cylon.out", "w", stdout);

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> a [i][j];

	cin >> c [1][1] >> c [1][2] >> c [2][1] >> c [2][2];

	b [1][1] = a [1][1] / c [2][2];

	for (int i = 2; i <= m; i++)
		b [1][i] = (a [1][i] - b [1][i - 1] * c [2][1]) / c [2][2];

	for (int i = 2; i <= n; i++)
		b [i][1] = (a [i][1] - b [i - 1][1] * c [1][2]) / c [2][2];

	for (int i = 2; i <= n; i++)
		for (int j = 2; j <= m; j++)
			b [i][j] = (a [i][j] - b [i - 1][j - 1] * c [1][1] - b [i - 1][j] * c [1][2] - b [i][j - 1] * c [2][1]) / c [2][2];

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
			cout << b [i][j] << " ";

		cout << endl;
	}	

	return 0;

}	