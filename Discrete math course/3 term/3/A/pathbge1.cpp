#define NAME "pathbge1"

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

const static int N = 30005;

int n, m;
vi g [N];
char used [N];
int d [N];
queue <int> q;

void bfs (int v)
{
    d [v] = 0;
    q.push (v);
    used [v] = 1;

    while (!q.empty ())
    {
        v = q.front ();
        q.pop ();

        for (int i = 0; i < (int) g [v].size (); i++)
            if (!used [g [v][i]])
            {
                used [g [v][i]] = 1;
                d [g [v][i]] = d [v] + 1;
                q.push (g [v][i]);
            }
    }
}

int main ()
{
    srand (time (0));

    freopen (NAME".in", "r", stdin);
    freopen (NAME".out", "w", stdout);
    memset (used, 0, sizeof (used));
    memset (d, -1, sizeof (d));

    scanf ("%d %d", &n, &m);

    for (int i = 0; i < m; i++)
    {
        int x, y;
        scanf ("%d %d", &x, &y);
        g [x].pb (y);
        g [y].pb (x);
    }

    bfs (1);

    for (int i = 1; i <= n; i++)
        printf ("%d ", d [i]);

    puts ("");

    return 0;
}
