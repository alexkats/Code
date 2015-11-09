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

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

typedef vector <int> vi;
typedef vector <ll> vll;
typedef vector <vi> vvi;
typedef vector <vll> vvll;
typedef vector <bool> vb;

typedef pair <int, int> pii;
typedef pair <int, ll> pil;
typedef pair <ll, int> pli;
typedef pair <ll, ll> pll;

typedef vector <pii> vpii;
typedef vector <pil> vpil;
typedef vector <pli> vpli;
typedef vector <pll> vpll;

#ifdef WIN32
    #define lld "%I64d"
#else
    #define lld "%lld"
#endif

template <typename T>
T sqr (T a)
{
    return a * a;
}

bool cmp (pii a, pii b)
{
    return a.frs < b.frs;
}

int n, k;
vpii a;
vpii ans;

int main ()
{
    srand (time (0));

    //freopen (NAME".in", "r", stdin);
    //freopen (NAME".out", "w", stdout);

    scanf ("%d %d", &n, &k);

    for (int i = 0; i < n; i++)
    {
        int x;
        scanf ("%d", &x);
        a.pb (mp (x, i + 1));
    }

    sort (a.begin (), a.end (), cmp);
    int curr = a [n - 1].frs - a [0].frs;

    while (curr > 1 && k > 0)
    {
        a [n - 1].frs--;
        a [0].frs++;
        ans.pb (mp (a [n - 1].snd, a [0].snd));
        k--;
        sort (a.begin (), a.end (), cmp);
        curr = a [n - 1].frs - a [0].frs;
    }

    printf ("%d %d\n", curr, (int) ans.size ());

    for (int i = 0; i < (int) ans.size (); i++)
        printf ("%d %d\n", ans [i].frs, ans [i].snd);

    return 0;
}
