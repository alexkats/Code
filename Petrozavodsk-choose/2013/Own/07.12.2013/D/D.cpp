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
#include <bitset>
#include <map>
#include <cassert>
#include <cctype>
#include <ctime>
#include <stack>
#include <queue>
#include <deque>
#include <utility>
#include <iterator>
 
#define NAME "pinball"
#define INF 1000000000
#define EPS 0.000000001
#define sqr(a) a*a
#define mp make_pair
#define pb push_back
#define rep0(i, n) for (int i = 0; i < n; i++)
#define rep(i, l, r) for (int i = l; i < r; i++)
#define repd0(i, n) for (int i = (n - 1); i > -1; i--)
#define repd(i, l, r) for (int i = (r - 1); i > (l - 1); i--)
 
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld; 
 
using namespace std;

int n;
int ans = 0;
int d [50], dn [50], a [50], an [50];

int cnt (int a)
{
	int res = 0;
		
	while (a != 0)
	{
		res += (a % 10);
		a /= 10;
	}

	return res;
}	

int main ()
{

	freopen (NAME".in", "r", stdin);
	freopen (NAME".out", "w", stdout);

	scanf ("%d", &n);

	if (n == 0)
	{
		puts ("1");
		return 0;
	}

	if (n == 1)
	{
		puts ("2");
		return 0;
	}

	int curr = 3;
	d [0] = 2;
	d [1] = 2;
	dn [0] = 2;
	dn [1] = 2;
	an [0] = 1;
	an [1] = 1;

	while (1)
	{
		rep0(i, curr - 1)
		{
			d [i] = dn [i];
			a [i] = an [i];
		}	
	
		rep0(i, curr)
		{
			if (i == 0)
			{
				dn [i] = d [i] + 1;
				an [i] = 1;
				continue;
			}	

			if (i == curr - 1)
			{
				dn [i] = d [i - 1] + 1;
				an [i] = 1;	
				continue;
			}
   	
			dn [i] = max (d [i - 1], d [i]);
			an [i] = a [i - 1] + a [i];
			dn [i] += cnt (an [i]);
		}

		if (curr == n + 1)
			break;

		curr++;	
	}

	rep0(i, n + 1)
		ans = max (ans, dn [i]);

	printf ("%d\n", ans);	

	return 0;

}	