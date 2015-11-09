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
 
#define NAME "paradox"
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
string s;
string st [10000], fin [10000];
int d [10000];
int p [10000] = {-1};

int main ()
{

	freopen (NAME".in", "r", stdin);
	freopen (NAME".out", "w", stdout);

	scanf ("%d", &n);

	rep0(i, n)
	{
		cin >> s;
		st [i] = s.substr (0, 3);
		fin [i] = s.substr (4, 3);
	}

	reverse (st, st + n);
	reverse (fin, fin + n);	

	d [0] = 1;

	rep0(i, n)
		p [i] = -1;

	rep(i, 1, n)
	{
		d [i] = 1;

		rep0(j, i)
		{
			if (st [i] == fin [j])
			{
				d [i] >= (d [j] + 1) ? p [i] = p [i] : p [i] = j;
				d [i] = max (d [i], d [j] + 1);
			}	
		}
	}

	int ans = 0;
	int curr = 0;

	rep0(i, n)
	{
		ans <= d [i] ? curr = i : curr = curr;
		ans = max (ans, d [i]);
	}	

	printf ("%d\n", ans);

	string res = "";
	res = fin [curr];

	while (1)
	{
		res = st [curr] + '-' + res;
		curr = p [curr];

		if (curr == -1)
			break;
	}

	printf ("%s\n", res.c_str ());

	return 0;

}	