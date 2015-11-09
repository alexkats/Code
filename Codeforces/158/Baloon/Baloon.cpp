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

using namespace std;

long long n, last, m, taken, now [100001], q, c;

int main ()
{

	cin >> n >> last;

	for (long long i = 1; i <= n; i++)
		cin >> now [i];

	m = now [1];
	taken = 1;	

	for (long long i = 2; i <= n; i++)
		if (now [i] < m)
		{
			taken = i;
			m = now [i];
		}
	if (last == taken)
		q = 0;
	else	
		if (last > taken)
			q = last - taken;
		else
			q = n - taken + last;	

	if (m == 0)
	{
		now [taken] = q;
		c = 0;

		for (long long i = taken + 1; c < q; i++)
		{
			c++;
			if (i % n == 0)
				now [n]--;
			else
				now [i % n]--;	
		}	

		for (long long i = 1; i <= n; i++)
			cout << now [i] << " ";	

		return 0;
	}	

	for (long long j = 1; j <= n; j++)
		now [j] -= m;

	now [taken] = n * m + q;
	c = 0;

	for (long long i = taken + 1; c < q; i++)
	{
		c++;

		if (i % n == 0)
			now [n]--;
		else
			now [i % n]--;	
	}	

	for (long long i = 1; i <= n; i++)
		cout << now [i] << " ";	

	return 0;

}	