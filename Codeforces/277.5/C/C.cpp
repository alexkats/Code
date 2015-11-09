#define NAME "c"

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

int find_sum (vi a)
{
    int res = 0;

    for (int i = 0; i < (int) a.size (); i++)
        res += a [i];

    return res;
}

char bad (vi a)
{
    for (int i = 0; i < (int) a.size (); i++)
        if (a [i] != 9)
            return 0;

    return 1;
}

char badd (vi a)
{
    if (a [0] != 1)
        return 0;

    for (int i = 1; i < (int) a.size (); i++)
        if (a [i] != 0)
            return 0;

    return 1;
}

vi find_next (vi a)
{
    int n = (int) a.size ();
    int curr = n - 1;

    while (a [curr] == 9)
        curr--;

    a [curr]++;

    for (int i = curr + 1; i < n; i++)
        a [i] = 0;

    return a;
}

vi find_prev (vi a)
{
    int n = (int) a.size ();
    int curr = n - 1;

    while (a [curr] == 0)
        curr--;

    a [curr]--;

    for (int i = curr + 1; i < n; i++)
        a [i] = 9;

    return a;
}

int main ()
{
    srand (time (0));

    freopen (NAME".in", "r", stdin);
    freopen (NAME".out", "w", stdout);

    int m, s;
    scanf ("%d %d", &m, &s);

    if (m == 1 && s < 10)
    {
        printf ("%d %d\n", s, s);
        return 0;
    }

    if (s == 0)
    {
        puts("-1 -1");
        return 0;
    }

    vi a (m, 0);
    a [0] = 1;
    int res = find_sum (a);

    if (res > s)
    {
        puts ("-1 -1");
        return 0;
    }
    
    for (int i = 0; i < m; i++)
        a [i] = 9;

    res = find_sum (a);

    if (res < s)
    {
        puts ("-1 -1");
        return 0;
    }

    vi ans1 (m);
    vi ans2 (m);

    for (int i = 1; i < m; i++)
        a [i] = 0;

    a [0] = 1;

    while (1)
    {
        res = find_sum (a);
        vi tmp = a;
        
        if (!bad (a))
            a = find_next (a);

        if (res == s)
        {
            ans1 = tmp;
            break;
        }
    }


    for (int i = 0; i < m; i++)
        a [i] = 9;

    while (1)
    {
        res = find_sum (a);
        vi tmp = a;

        if (!badd (a))
            a = find_prev (a);

        if (res == s)
        {
            ans2 = tmp;
            break;
        }
    }

    for (int i = 0; i < m; i++)
        printf ("%d", ans1 [i]);

    printf (" ");

    for (int i = 0; i < m; i++)
        printf ("%d", ans2 [i]);

    puts ("");

    return 0;
}
