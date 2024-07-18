#include <algorithm>
#include <numeric>
#include <iterator>
#include <iostream>
#include <cstring>
#include <bitset>
#include <deque>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <unordered_set>
using namespace std;
typedef long long ll;

std::bitset<100001> gates;

int main() {
    gates.flip();
    int G,P;
    cin >> G >> P;
    for (int i = 0; i < P; i++) {
        int inp;
        cin >> inp;
        int nextG = gates._Find_next(G-inp);
        if (G < nextG) {
            cout << i << "\n";
            return 0;
        }
        gates[nextG]=0;
    }
    cout << P << "\n";
}