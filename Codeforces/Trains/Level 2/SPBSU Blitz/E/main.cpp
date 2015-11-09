#define NAME "strings"

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

const int N = (int) 1e6 + 5;
const int p1 = 31;
const int p2 = 53;

string s, t;
char tmp [N];
ull prime1 [N];
ull prime2 [N];
ull hash [N][2][2];

void calc_hash (string s, int j)
{
    int n = (int) s.length ();
    hash [0][0][j] = (ull) (s [0] - 'A' + 1);
    
    for (int i = 0; i < n; i++)
    {
        hash [i][0][j] = hash [i - 1][0][j]

int main ()
{
    srand (time (0));

    freopen (NAME".in", "r", stdin);
    freopen (NAME".out", "w", stdout);

    scanf ("%s\n", tmp);
    s = (const char*) tmp;
    scanf ("%s\n", tmp);
    t = (const char*) tmp;
    ull res_hash = calc_hash (t);
    int n = (int) s.length ();
    prime1 [0] = 1;
    prime2 [0] = 1;

    for (int i = 1; i <= n; i++)
    {
        prime1 [i] = prime1 [i - 1] * p1;
        prime2 [i] = prime2 [i - 1] * p2;
    }



    return 0;
}
