#include <bits/stdc++.h>
using namespace std;

static long long final_position(int D, long long n) {
    long long pos = 1;
    for (int level = 1; level < D; ++level) {
        if (n & 1LL) {           // odd -> go left
            pos = pos * 2;
            n = (n + 1) / 2;
        } else {                 // even -> go right
            pos = pos * 2 + 1;
            n /= 2;
        }
    }
    return pos;
}

static void distribute(int depth, int D, long long balls, vector<int>& leaves, int l, int r) {
    if (balls == 0) return;
    if (depth == D) {
        leaves[l] = int(balls & 1LL); // parity (1=open if odd)
        return;
    }
    long long left_balls = (balls + 1) / 2; // sequence L,R,L,R,...
    long long right_balls = balls / 2;
    int mid = (l + r) >> 1;
    distribute(depth + 1, D, left_balls, leaves, l, mid);
    distribute(depth + 1, D, right_balls, leaves, mid + 1, r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int D; long long n;
    if (!(cin >> D >> n)) return 0;

    long long pos = final_position(D, n);
    cout << pos << "\n";

    int L = 1 << (D - 1); // number of leaves
    vector<int> leaves(L, 0);
    distribute(1, D, n, leaves, 0, L - 1);

    for (int i = 0; i < L; ++i) {
        if (i) cout << ' ';
        cout << leaves[i];
    }
    cout << "\n";
    return 0;
}
