#define NAME "e"

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

#define pb push_back
#define mp make_pair
#define frs first
#define snd second

#ifdef WIN32
    #define lld "%I64d"
#else
    #define lld "%lld"
#endif

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

using namespace std;

typedef vector <int> vi;
typedef vector <ll> vll;
typedef vector <vi> vvi;
typedef vector <vll> vvll;
typedef vector <char> vc;

typedef pair <int, int> pii;
typedef pair <int, ll> pil;
typedef pair <ll, int> pli;
typedef pair <ll, ll> pll;

typedef vector <pii> vpii;
typedef vector <pil> vpil;
typedef vector <pli> vpli;
typedef vector <pll> vpll;

template <typename T>
T sqr (T a)
{
    return a * a;
}

int n, m, dx, dy;
vpii a;
map <pii, int> s;

int gcd (int a, int b)
{
    return b ? gcd (b, a % b) : a;
}

int main ()
{
    srand (time (0));

    //freopen (NAME".in", "r", stdin);
    //freopen (NAME".out", "w", stdout);

    scanf ("%d %d %d %d", &n, &m, &dx, &dy);
    int g = gcd (dx, dy);
    dx /= g;
    dy /= g;

    for (int i = 0; i < m; i++)
    {
        int x, y;
        scanf ("%d %d", &x, &y);
        int q = 0;

        while ((q * 1ll * dx + x) % n != 0)
            q++;

        x = 0;
        y = ((ll) y + q * 1ll * dy) % n;
        a.pb (mp (x, y));
        s [mp (x, y)]++;
    }

    int res = 0;
    pii ans;

    for (int i = 0; i < m; i++)
    {
        int x = a [i].frs;
        int y = a [i].snd;
        int q = s [mp (x, y)];

        if (q > res)
        {
            res = q;
            ans = mp (x, y);
        }
    }

    printf ("%d %d\n", ans.frs, ans.snd);

    return 0;
}
