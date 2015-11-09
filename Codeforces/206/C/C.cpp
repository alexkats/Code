#include <climits>
#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>

#define REP(i, n) for (size_t i = 0; i < n; i++)

using namespace std;


int main() {
    
    int N, L, R, Ql, Qr;
    cin >> N >> L >> R >> Ql >> Qr;
    
    int w[N];
    long long countLeft[N+1];
    long long count = 0;
    
    REP(i, N) { 
    	cin >> w[i];
        countLeft[i] = count;
    	count += w[i];
    }
    countLeft[N] = count;
    
    int bestI = -1;
    long long bestValue = LONG_LONG_MAX;
    REP(i, N + 1) {
    	long long myVal = countLeft[i] * L + (countLeft[N] - countLeft[i]) * R;
    	int diff = (N - i) - i;
        if(diff > 1)
            myVal += (diff - 1) * Qr;
        if (diff < -1)
            myVal += (-diff - 1) * Ql;
    	bestValue = min(bestValue, myVal);
    }
    
    
    cout << bestValue << endl;
    
    
}