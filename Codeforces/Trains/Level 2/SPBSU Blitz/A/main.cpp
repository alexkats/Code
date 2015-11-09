#define NAME "lis"

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

const int INF = (int) 1e9 + 7;

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

int n;
vi a;

int main ()
{
    srand (time (0));

    freopen (NAME".in", "r", stdin);
    freopen (NAME".out", "w", stdout);

    scanf ("%d", &n);
    a.resize (n);

    for (int i = 0; i < n; i++)
        scanf ("%d", &a [i]);

    vi d (n + 1, INF);
    d [0] = -INF;

    for (int i = 0; i < n; i++)
    {
        int curr = int (upper_bound (d.begin (), d.end (), a [i] - 1) - d.begin ());

        if (a [i] >= d [curr - 1] && a [i] <= d [curr])
            d [curr] = a [i];
    }

    int ans = -INF;

    for (int i = 1; i <= n; i++)
        if (d [i] < INF && d [i + 1] == INF)
        {
            ans = i;
            break;
        }

    printf ("%d\n", ans);

    return 0;
}
