#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <ctime>
#include <stack>
#include <queue>
#include <deque>
#include <utility>
#include <iterator>

#define NAME ""
#define INF 1000000000
#define EPS 0.0000000001

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

ull sqr (ll a)
{
	ull c = a * a;

	return c;
}	

using namespace std;

int n, a [201], q [3], k [201], t [201], cnt [100] = {0};

void qs (int l, int r)
{
	int i = l;
	int j = r;
	int x = a [l + rand () % (r - l + 1)];

	while (i <= j)
	{
		while (a [i] < x)
			i++;

		while (a [j] > x)
			j--;

		if (i <= j)
		{
			swap (a [i], a [j]);
			swap (t [i], t [j]);
			i++;
			j--;
		}
	}

	if (l < j)
		qs (l, j);

	if (i < r)
		qs (i, r);
}	

int main ()
{

//	ifstream in (NAME".in");
//	ofstream out (NAME".out");

//	freopen ("t.in", "r", stdin);
//	freopen ("t.out", "w", stdout);

	cin >> n;

	for (int i = 1; i <= (2 * n); i++)
	{
		cin >> a [i];
		t [i] = i;
	}	

	qs (1, 2 * n);

	bool flag = false;

	int ans = n * n;	

	for (int i = 1; i < (2 * n); i++)
	{
		if (a [i] == a [i + 1])
		{
			if (k [t [i]] == 0)
			{
				k [t [i]] = 1;
				q [1]++;
				cnt [a [i]]++;
			}	

			k [t [i + 1]] = (k [t [i]] == 1) ? 2 : 1;

			flag = true;
			cnt [a [i]]++;

			if (cnt [a [i]] > 2)
				ans -= n;

			if (k [t [i + 1]] == 1)
				q [1]++;
			else
				q [2]++;
		}
		else	
		{
			if (flag)
			{
				flag = false;
				continue;
			}	

			if (q [1] > q [2])
			{
				k [t [i]] = 2;
				q [2]++;
			}
			else
			{
				k [t [i]] = 1;
				q [1]++;
			}
		}	
	}

	if (q [1] > q [2])
	{
		k [t [2 * n]] = 2;
		q [2]++;
	}
	
	if (q [1] < q [2])
	{
		k [t [2 * n]] = 1;
		q [1]++;
	}

	cout << ans << endl;	

	for (int i = 1; i <= (2 * n); i++)
		cout << k [i] << " ";

	cout << endl;	

	return 0;

}	