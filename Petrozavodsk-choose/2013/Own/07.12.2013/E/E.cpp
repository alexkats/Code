#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
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

#define NAME "spy"
#define INF 1000000000
#define EPS 0.000000001
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

ll r;
ll ax, ay, bx, by;

ll sqr (ll a)
{
	return a * a;
}	

int main()
{

    freopen(NAME".in", "r", stdin);
    freopen(NAME".out", "w", stdout);

    scanf (lld, &r);
    scanf (lld" "lld, &ax, &ay);
    scanf (lld" "lld, &bx, &by);

    ll a = by - ay;
    ll b = ax - bx;
    ll c = (ay * (-b) - ax * a);

	if (ay == by)
	{
		a = 0;
		b = 1;
		c = -ay;
	}

	if (ax == bx)
	{
		a = 1;
		b = 0;
		c = -ax;
	}
    
    char ok = 0;

    if ((sqr (bx) + sqr (by)) >= (sqr (c) / (sqr (a) + sqr (b)) + sqr (bx - ax) + sqr (by - ay)))
    	ok = 1;	

    if (ok)
    	puts ("YES");
    else
    	puts ("NO");

	return 0;

}	