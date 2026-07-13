#include<bits/stdc++.h>
using namespace std;

const int maxN = 1e5 + 7;
vector<int> arr(maxN);

int part(int l, int r) {
    int x = arr[r];
    int i = l - 1;
    for (int j = l; j < r; j++) {
        if (arr[j] <= x) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[r]);
    return i + 1;
}

void qs(int l, int r) {
    if (l < r) {
        int mid = part(l, r);
        qs(l, mid - 1);
        qs(mid+1, r);
    }
}

int main() {
    int n;cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    qs(1, n);
    for (int i = 1; i <= n; i++) cout << arr[i] << " \n"[i == n];
}