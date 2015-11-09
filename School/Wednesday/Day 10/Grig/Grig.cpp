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

int n, k, d [31];

int main ()
{

	freopen ("grig.in", "r", stdin);
	freopen ("grig.out", "w", stdout);

	cin >> n >> k;

	for (int i = 1; i <= n; i++)
		d [i] = 0;	

	for (int i = 2; i <= k + 1; i++)
		d [i] = d [i - 1] + 1;

	for (int i = k + 2; i <= n; i++)
		for (int j = 1; j <= k; j++)
			d [i] += d [i - j];

	cout << d [n];	

	return 0;

}	