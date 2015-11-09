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

int n, x [101], d [101];

int main ()
{
	freopen ("nails.in", "r", stdin);
	freopen ("nails.out", "w", stdout);

	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> x [i];

	sort (x + 1, x + n + 1);

	d [2] = x [2] - x [1];
	d [3] = x [3] - x [1];
	d [4] = x [2] - x [1] + x [4] - x [3];

	for (int i = 5; i <= n; i++)
		d [i] = min (d [i - 2] + x [i] - x [i - 1], d [i - 3] + x [i] - x [i - 2]);

	cout << d [n];	

	return 0;
}	