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

const int N = 1005;

vvi g;
vc used;
char found;
int num [N][N];
int n, m;

void dfs (int v, vi &ans)
{
    if (used [v])
    {
        found = 1;
        ans.pb (v);
        return;
    }

    used [v] = 1;

    for (int i = 0; i < (int) g [v].size (); i++)
    {
        dfs (g [v][i], ans);

        if (found)
        {
            ans.pb (v);
            break;
        }
    }
}

int main ()
{
    srand (time (0));

    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    scanf ("%d %d", &n, &m);
    g.resize (n + 1);
    used.resize (n + 1, 0);

    for (int i = 0; i < m; i++)
    {
        int x, y;
        scanf ("%d %d", &x, &y);
        g [x].pb (y);
        num [x][y] = i + 1;
    }

    int st;
    scanf ("%d", &st);
    vi ans;
    found = 0;
    dfs (st, ans);

    if ((int) ans.size () == 0)
    {
        puts ("-1");
        return 0;
    }

    reverse (ans.begin (), ans.end ());
    ans.pop_back ();
    printf ("%d\n", (int) ans.size ());

    for (int i = 0; i < (int) ans.size (); i++)
        printf ("%d%c", ans [i], " \n" [i == (int) ans.size () - 1]);

    return 0;
}
