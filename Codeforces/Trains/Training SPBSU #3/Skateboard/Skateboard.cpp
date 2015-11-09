#include <iostream>
#include <map>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main ()
{

	freopen ("skateboard.in", "r", stdin);
	freopen ("skateboard.out", "w", stdout);

	int n, a [100001];
	int q = 0;

	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> a [i];

	for (int i = 1; i <= n; i++)
		if (a [i] > a [i - 1] && a [i] > a [i + 1])
			q++;

	cout << q;	

	return 0;

}	