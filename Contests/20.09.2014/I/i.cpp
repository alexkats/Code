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

#define NAME "i"
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

int b;
int c, d;
int k, p;

int main ()
{
    //freopen (NAME".in", "r", stdin);
    //freopen (NAME".out", "w", stdout);

    scanf ("%d\n", &b);
    scanf ("%d %d\n", &c, &d);
    scanf ("%d %d\n", &k, &p);

    ll per = 100 + p;
    ll curr = c;
    ll ans1 = b * 100ll;
    ll ans2 = 0;

    rep0(i, k)
    {
        curr += d;
        ans1 += curr * 100ll;
        ans2 += curr * per;
    }

    if (ans1 == ans2)
    {
        puts ("Insurance");
        puts ("0.00");
        return 0;
    }

    if (ans1 < ans2)
    {
        puts ("Cash");
        ll ans = ans2 - ans1;
        double res = (ld) ans / 100.0;
        ll c = ans % 100;
        printf ("%d.", (int) floor (res));

        if (c < 10)
            printf ("0"lld"\n", c);
        else
            printf (lld"\n", c);
    }
    else
    {
        puts ("Insurance");
        ll ans = ans1 - ans2;
        double res = (ld) ans / 100.0;
        ll c = ans % 100;
        printf ("%d.", (int) floor (res));
        
        if (c < 10)
            printf ("0"lld"\n", c);
        else
            printf (lld"\n", c);
    }

    return 0;
}
