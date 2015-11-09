#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
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

#define NAME "signal"
#define INF (int) 1e9 + 7
#define INFLONG (ll) 1e18 + 7
#define EPS 1e-9
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

vector <int> v [100005];
int n;
char used [100005];
int ans [100005];

void dfs (int x, int res)
{
    used [x] = 1;
    ans [x] = res++;

    rep0(i, (int) v [x].size ())
        if (!used [v [x][i]])
            dfs (v [x][i], res);
}

bool cmp (int a, int b)
{
    return a > b;
}

void dfs2 (int x, int res)
{
    used [x] = 1;
    ans [x] = res++;

    rep0(i, (int) v [x].size ())
        if (!used [v [x][i]])
            dfs2 (v [x][i], res++);
}

int main ()
{
    freopen (NAME".in", "r", stdin);
    freopen (NAME".out", "w", stdout);

    scanf ("%d", &n);

    rep0(i, n)
    {
        int x, y;
        scanf ("%d %d", &x, &y);
        v [--x].pb (--y);
        v [y].pb (x);
    }

    dfs (0, 0);
    int res = 0;
    int x = 0;

    rep0(i, n)
        if (ans [i] > res)
        {
            res = ans [i];
            x = i;
        }

    memset (used, 0, sizeof (used));
    dfs2 (x, 0);
    res = 0;

    rep0(i, n)
        res = max (res, ans [i]);

    printf ("%d\n", res);

    return 0;
}
