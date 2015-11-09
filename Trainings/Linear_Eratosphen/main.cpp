#define NAME "linear"

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
typedef vector <char> vc;

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

int n;
vi lp;
vi pr;

int main ()
{
    srand (time (0));

    freopen (NAME".in", "r", stdin);
    freopen (NAME".out", "w", stdout);

    scanf ("%d", &n);
    lp.resize (n + 1, 0);

    for (int i = 2; i <= n; i++)
    {
        if (!lp [i])
        {
            lp [i] = i;
            pr.pb (i);
        }

        for (int j = 0; j < (int) pr.size () && pr [j] <= lp [i] && i * 1ll * pr [j] <= n; j++)
            lp [i * pr [j]] = pr [j];
    }

    if (lp [n] == n)
    {
        puts ("YES");
        return 0;
    }

    puts ("NO");
    printf ("%d\n", lp [n]);

    return 0;
}
