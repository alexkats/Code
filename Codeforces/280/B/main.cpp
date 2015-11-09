#define NAME "b"

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

char good (double x, int l, int n, vi a)
{
    double left = (double) l;
    double right = 0.0;

    for (int i = 0; i < n; i++)
    {
        left = min (left, a [i] - x);
        right = max (right, a [i] + x);
    }

    if (left <= 0.0 && right >= l)
        return 1;

    return 0;
}

int main ()
{
    srand (time (0));

    int n, l;
    cin >> n >> l;
    vi a (n);

    for (int i = 0; i < n; i++)
        cin >> a [i];

    sort (a.begin (), a.end ());
    double ans = 0.0;

    for (int i = 1; i < n; i++)
        ans = max (ans, (a [i] - a [i - 1]) / 2.0);

    ans = max (ans, (double) a [0] - 0.0);
    ans = max (ans, (double) l - (double) a [n - 1]);

    printf ("%.9lf\n", ans);

    return 0;
}
