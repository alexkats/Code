#define NAME "d"

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

int n, l, x, y;
int a [100005];
set <int> s;
set <int> good_x;
vi good_y;

int main ()
{
    srand (time (0));

    freopen (NAME".in", "r", stdin);
    freopen (NAME".out", "w", stdout);

    scanf ("%d %d %d %d", &n, &l, &x, &y);

    for (int i = 0; i < n; i++)
    {
        scanf ("%d", &a [i]);
        s.insert (a [i]);
    }

    if (s.find (x) != s.end () && s.find (y) != s.end ())
    {
        puts ("0");
        return 0;
    }

    int curr = 1;

    for (int i = 1; i < n; i++)
        if (a [i] <= x)
            curr++;

    good_x.insert (x);
    vi checking_x;
    checking_x.pb (x);

    for (int i = curr; i < n; i++)
    {
        checking_x.pb (a [i] - x);
        good_x.insert (a [i] - x);
    }

    curr = 1;

    for (int i = 1; i < n; i++)
        if (a [i] <= y)
            curr++;

    good_y.pb (y);

    for (int i = curr; i < n; i++)
        good_y.pb (a [i] - y);

    char ok1 = 0;
    char ok2 = 0;

    for (int i = 0; i < (int) checking_x.size (); i++)
        if (s.find (checking_x [i]) != s.end ())
        {
            ok1 = 1;
            break;
        }

    for (int i = 0; i < (int) good_y.size (); i++)
        if (s.find (good_y [i]) != s.end ())
        {
            ok2 = 1;
            break;
        }

    if (ok1 && ok2)
    {
        puts ("0");
        return 0;
    }

    if (ok1)
    {
        printf ("%d\n%d\n", 1, y);
        return 0;
    }

    if (ok2)
    {
        printf ("%d\n%d\n", 1, x);
        return 0;
    }

    for (int i = 0; i < (int) good_y.size (); i++)
    {
        if (good_x.find (good_y [i]) != good_x.end ())
        {
            printf ("%d\n%d\n", 1, good_y [i]);
            return 0;
        }
    }

    printf ("%d\n%d %d\n", 2, x, y);

    return 0;
}
