#define NAME ""

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

const int INF = (int) 1e9 + 7;
const ll INFLONG = (ll) 1e18 + 7;
const double EPS = 1e-9;

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

    int n;
    cin >> n;
    vi a (n);

    for (int i = 0; i < n; i++)
        cin >> a [i];

    int ans = 1;
    int curr = a [2] - a [0];

    for (int i = 1; i < (n - 1); i++)
        if (a [i + 1] - a [i - 1] < curr)
        {
            curr = a [i + 1] - a [i - 1];
            ans = i;
        }

    swap (a [ans], a [n - 1]);
    sort (a.begin (), a.end () - 1);
    ans = 0;

    for (int i = 0; i < n - 2; i++)
        ans = max (ans, a [i + 1] - a [i]);

    cout << ans << endl;

    return 0;
}
