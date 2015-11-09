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

int a, b, c, d, qw [4], qb [4];

int main ()
{

	freopen ("simple.in", "r", stdin);
	freopen ("simple.out", "w", stdout);

	for (int i = 1; i <= 3; i++)
	{
		cin >> a >> b >> c >> d;

		qw [i] = 0;
		qb [i] = 0;	

		if (a == 1)
			qb [i]++;
		else
			qw [i]++;

		if (b == 1)
			qb [i]++;
		else
			qw [i]++;

		if (c == 1)
			qb [i]++;
		else
			qw [i]++;

		if (d == 1)
			qb [i]++;
		else
			qw [i]++;
	}

	if (qb [1] == 0 && qw [2] == 0 && qw [3] == 0 || qw [1] == 0 && qb [2] == 0 && qb [3] == 0 || qb [2] == 0 && qw [1] == 0 && qw [3] == 0 || qw [2] == 0 && qb [1] == 0 && qb [3] == 0 || qb [3] == 0 && qw [1] == 0 && qw [2] == 0 || qw [3] == 0 && qb [1] == 0 && qb [2] == 0)
	{
		cout << "No";
		return 0;
	}

	if (qb [1] == 1 && qb [2] == 1 && qw [3] == 0 || qw [1] == 1 && qw [2] == 1 && qb [3] == 0 || qb [1] == 1 && qb [3] == 1 && qw [2] == 0 || qw [1] == 1 && qw [3] == 1 && qb [2] == 0 || qb [2] == 1 && qb [3] == 1 && qw [1] == 0 || qw [2] == 1 && qw [3] == 1 && qb [1] == 0)
	{
		cout << "No";
		return 0;
	}

	cout << "Yes";	

	return 0;

}	