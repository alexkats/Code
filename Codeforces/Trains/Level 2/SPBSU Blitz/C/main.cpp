#define NAME "bfs"

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

int n, s, f;
vvi g;

int main ()
{
    srand (time (0));

    freopen (NAME".in", "r", stdin);
    freopen (NAME".out", "w", stdout);

    scanf ("%d %d %d", &n, &s, &f);
    g.resize (n + 1);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            int x;
            scanf ("%d", &x);

            if (x)
                g [i + 1].pb (j + 1);
        }

    queue <int> q;
    q.push (s);
    vi d (n + 1, -1);
    d [s] = 0;

    while (!q.empty ())
    {
        int v = q.front ();
        q.pop ();

        for (int i = 0; i < (int) g [v].size (); i++)
            if (d [g [v][i]] == -1)
            {
               d [g [v][i]] = d [v] + 1;
               q.push (g [v][i]);
            }
    }

    if (d [f] == -1)
        puts ("0");
    else
        printf ("%d\n", d [f]);

    return 0;
}
