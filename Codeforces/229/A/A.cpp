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

#define NAME "a"
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

int n;
int used_hor [110], used_vert [110];

int main ()
{
	srand (time (0));

//	freopen (NAME".in", "r", stdin);
//	freopen (NAME".out", "w", stdout);
	memset (used_hor, 0, sizeof (used_hor));
	memset (used_vert, 0, sizeof (used_vert));

	scanf ("%d", &n);

	rep0(i, n)
	{
		int a, b;
		scanf ("%d%d", &a, &b);
		used_hor [a]++;
		used_vert [b]++;
	}

	int hor = 0;
	int vert = 0;
		
	rep0(i, 101)
	{
		if (used_hor [i])
			hor++;

		if (used_vert [i])
			vert++;
	}

	int ans = min (hor, vert);

	printf ("%d\n", ans);	

	return 0;
}	