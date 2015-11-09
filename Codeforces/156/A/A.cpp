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

int n, a, m, q [3];

int main ()
{
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> a;
		
		if (i % 3 == 0)
			q [0] += a;

		if (i % 3 == 1)
			q [1] += a;

		if (i % 3 == 2)
			q [2] += a;
	}

	m = max (max (q [1], q [2]), q [0]);

	if (q [1] == m)
		cout << "chest";
	else
		if (q [2] == m)
			cout << "biceps";
		else
			cout << "back";
				
	return 0;

}	