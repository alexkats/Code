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

#define NAME "shadow"
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

struct tree
{
    int x, h;
    tree () {}

    tree (int X, int H)
    {
        x = X;
        h = H;
    }
};

int n;
vector <tree> t;
int W, H;

bool cmp (tree a, tree b)
{
    return a.x < b.x;
}

int main ()
{
    freopen (NAME".in", "r", stdin);
    freopen (NAME".out", "w", stdout);

    scanf ("%d", &n);

    rep0(i, n)
    {
        int X, H;
        scanf ("%d %d", &X, &H);
        t.pb (tree (X, H));
    }

    t.pb (tree ((INF) * 2, 0));

    sort (t.begin (), t.end (), cmp);

    scanf ("%d %d", &W, &H);

    int curr = 0;

    rep0(i, n)
    {
        if (H >= t [i].h && curr == 0)
            continue;

        int max_l = t [i].x;
        int max_r = t [i].x + t [i].h - H;
        curr = max (curr, max_r);
        max_r = curr;

        if ((max_r - max_l) < W)
        {
            curr = 0;
            continue;
        }

        if (t [i + 1].x > max_r)
        {
            puts ("YES");
            return 0;
        }
    }

    puts ("NO");

    return 0;
}
