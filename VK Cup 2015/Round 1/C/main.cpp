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

int n, k, q;
set <int> s;
vi a;

char check (int q, int needed)
{
    for (int i = 0; i < n; i++)
    {
        int curr = a [i];

        for (int p = 1; p <= q; p++)
        {
            int r = needed - p * curr;

            if (q == p && r == 0)
                return 1;

            if (q == p)
                break;

            if (r % (q - p) != 0)
                continue;

            int curr2 = r / (q - p);

            if (s.find (curr2) == s.end ())
                continue;
            else
                return 1;
        }
    }

    return 0;
}

int main ()
{
    //freopen (NAME".in", "r", stdin);
    //freopen (NAME".out", "w", stdout);

    scanf ("%d %d", &n, &k);

    for (int i = 0; i < n; i++)
    {
        int x;
        scanf ("%d", &x);
        s.insert (x);
        a.pb (x);
    }

    scanf ("%d", &q);
    vi ans;

    for (int i = 0; i < q; i++)
    {
        int x;
        scanf ("%d", &x);
        int res = -1;

        for (int m = k; m > 0; m--)
            if (check (m, x))
                res = m;

        ans.pb (res);
    }

    for (int i = 0; i < q; i++)
        printf ("%d\n", ans [i]);

    return 0;
}
