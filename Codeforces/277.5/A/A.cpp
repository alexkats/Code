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

    int n;
    cin >> n;
    vpii a (n);

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a [i] = mp (x, i);
    }

    sort (a.begin (), a.end ());
    set <pii> s;

    for (int i = 0; i < n; i++)
        s.insert (mp (min (a [i].snd, i), max (a [i].snd, i)));

    cout << s.size () << endl;

    while (!s.empty ())
    {
        int ans1 = s.begin () -> frs;
        int ans2 = s.begin () -> snd;
        s.erase (s.begin ());
        cout << ans1 << " " << ans2 << endl;
    }

    return 0;
}
