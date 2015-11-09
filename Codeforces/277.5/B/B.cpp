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

int main ()
{
    srand (time (0));

    //freopen (NAME".in", "r", stdin);
    //freopen (NAME".out", "w", stdout);

    int n, m;
    vi a, b;

    scanf ("%d", &n);
    a.resize (n);

    for (int i = 0; i < n; i++)
        scanf ("%d", &a [i]);

    scanf ("%d", &m);
    b.resize (m);

    for (int i = 0; i < m; i++)
        scanf ("%d", &b [i]);


    sort (a.begin (), a.end ());
    sort (b.begin (), b.end ());

    int ans = 0;
    int i = 0;
    int j = 0;
    vc used (m, 0);

    while (i < n)
    {
        if (j == m)
        {
            i++;
            j = 0;
            continue;
        }

        if (abs (a [i] - b [j]) > 1 || used [j])
        {
            j++;
            continue;
        }

        ans++;
        i++;
        used [j] = 1;
        j = 0;
    }

    printf ("%d\n", ans);

    return 0;
}
