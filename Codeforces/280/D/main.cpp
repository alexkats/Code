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

int n, x, y;
vi a;

int gcd (int a, int b)
{
    return b ? gcd (b, a % b) : a;
}

ll lcm (int a, int b)
{
    int g = gcd (a, b);
    return a * 1ll * b / (ll) g;
}

int main ()
{
    srand (time (0));

    //freopen (NAME".in", "r", stdin);
    //freopen (NAME".out", "w", stdout);

    scanf ("%d %d %d", &n, &x, &y);
    a.resize (n);

    for (int i = 0; i < n; i++)
        scanf ("%d", &a [i]);

    ll T = lcm (x, y);
    ll qT = T / (ll) x + T / (ll) y;

    for (int i = 0; i < n; i++)
    {
        int curr = a [i];

        if (curr % qT == 0 || (curr + 1) % qT == 0)
        {
            puts ("Both");
            continue;
        }

        curr = curr % qT;
        ll left = 0ll;
        ll right = T;

        while ((right - left) > 1)
        {
            ll middle = (left + right) / 2ll;
            ll have = middle / (ll) x + middle / (ll) y;

            if (have >= curr)
                right = middle;
            else
                left = middle;
        }

        ll have = left / (ll) x + left / (ll) y;

        if (have == curr)
        {
            if (left % x == 0)
                puts ("Vova");
            else
                puts ("Vanya");
        }
        else
        {
            if (right % x == 0)
                puts ("Vova");
            else
                puts ("Vanya");
        }
    }

    return 0;
}
