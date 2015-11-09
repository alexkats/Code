#define NAME "a"

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
#include <climits>
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
typedef vector <string> vs;

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

int m, k;

int main ()
{
    //freopen (NAME".in", "r", stdin);
    //freopen (NAME".out", "w", stdout);

    scanf ("%d %d", &m, &k);
    map <int, vi> g;
    map <int, vi> ans;
    set <int> s;

    for (int i = 0; i < m; i++)
    {
        int x, y;
        scanf ("%d %d", &x, &y);
        g [x].pb (y);
        g [y].pb (x);
        s.insert (x);
        s.insert (y);
    }

    for (set <int> :: iterator i = s.begin (); i != s.end (); i++)
        sort (g [*i].begin (), g [*i].end ());

    for (set <int> :: iterator i = s.begin (); i != s.end (); i++)
    {
        for (set <int> :: iterator j = s.begin (); j != s.end (); j++)
        {
            if (*i == *j)
                continue;

            char next = 0;

            for (int t = 0; t < (int) g [*i].size (); t++)
                if (g [*i][t] == *j)
                {
                    next = 1;
                    break;
                }

            if (next)
                continue;

            int q = 0;
            int r = 0;
            int res = 0;

            while (q < (int) g [*i].size () && r < (int) g [*j].size ())
            {
                if (g [*i][q] == g [*j][r])
                {
                    res++;
                    q++;
                    r++;
                    continue;
                }

                if (g [*i][q] < g [*j][r])
                    q++;
                else
                    r++;
            }

            if (res * 100 >= (int) (g [*i].size ()) * k)
                ans [*i].pb (*j);
        }
    }

    for (set <int> :: iterator i = s.begin (); i != s.end (); i++)
    {
        printf ("%d: %d", *i, (int) ans [*i].size ());

        for (int j = 0; j < (int) ans [*i].size (); j++)
            printf (" %d", ans [*i][j]);

        puts ("");
    }

    return 0;
}
