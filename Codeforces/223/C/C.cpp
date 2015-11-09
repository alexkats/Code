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
#include <ctime>
#include <cctype>
#include <cassert>
#include <memory>
#include <stack>
#include <queue>
#include <deque>
#include <utility>
#include <iterator>

#define NAME "c"
#define INF 1000000000
#define EPS 0.000000001
#define INFLONG 1000000000000000000
#define pb push_back
#define mp make_pair
#define frs first
#define snd second
#define rep0(i, n) for (int i = 0; i < n; i++)
#define rep(i, l, r) for (int i = l; i < r; i++)
#define repd0(i, n) for (int i = (n - 1); i > -1; i--)
#define repd(i, l, r) for (int i = (r - 1); i > (l - 1); i--)

#ifdef WIN32
	#define lld "%I64d"
#else
	#define lld "%lld"
#endif

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

using namespace std;

int main ()
{
	srand (time (0));

	freopen (NAME".in", "r", stdin);
	freopen (NAME".out", "w", stdout);

	scanf ("%d", &n);

	rep0(i, n)
	{
		scanf ("%d", &type [i]);

		if (type [i])
			scanf ("%d %d", &len [i], &c [i]);
		else
			scanf ("%d", &val [i]);
	}

	scanf ("%d", &m);

	rep0(i, m)
	{
		scanf ("%d", &a);
		num.pb (a);
	}	

	int curr = 0;

	rep0(i, n)
	{
		if (num.size () == 0)
			break;

		while (num.size () > 0 && num [0] <= curr)
		{
				

	return 0;
}	