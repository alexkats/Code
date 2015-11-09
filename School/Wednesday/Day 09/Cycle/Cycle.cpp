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

void dfs (int i)
{
	visited [i] = 1;

	for (int j = 1; j <= n; j++)
	{
		if (a [i][j] && visited [j] != 2)
			dfs (j);

int main ()
{

	freopen ("cycle.in", "r", stdin);
	freopen ("cycle.out", "w", stdout);

	cin >> n >> m;

	for (int i = 1; i <= m; i++)
	{
		cin >> x >> y;
		a [x][y] = true;
	}

		

	return 0;

}	