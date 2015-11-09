#define NAME "f"

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

#ifdef WIN32
    #define lld "%I64d"
#else
    #define lld "%lld"
#endif

#define pb push_back
#define mp make_pair
#define frs first
#define snd second

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

char check (char a, char b)
{
    if (a == b)
        return 1;



void calc (string s, vi &z)
{
    int n = (int) s.length ();
    z.resize (n, 0);
    int left = 0;
    int right = 0;

    for (int i = 1; i < n; i++)
    {
        if (i <= right)
            z [i] = min (z [i - left], right - i + 1);

        while ((z [i] + i) < n && check (s [z [i]], s [z [i] + i]))
            z [i]++;

        if ((z [i] + i - 1) > right)
        {
            left = i;
            right = i + z [i] - 1;
        }
    }
}

string text, s, t;

int main ()
{
    srand (time (0));

    freopen (NAME".in", "r", stdin);
    freopen (NAME".out", "w", stdout);

    int ss, tt;
    cin >> ss >> tt;
    cin >> s;
    cin >> t;
    text = s + "#" + t;
    int n = ss + tt + 1;
    vi ans;
    calc (text, ans);

    return 0;
}
