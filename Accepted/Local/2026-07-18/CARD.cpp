#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>
#define VII vector<PII>
string s1[6],s2[6],s3[6];
map<char,int>mp;

// 同花顺 - 10
pair<int, vector<int>> ths(VII hand) { // 进来的时候A等于14
    vector<int> res(5);
    set<int> st;
    for (auto &i : hand) {
        st.insert(i.second);
    }
    
    if (st.size() > 1) return {-1, {}};
    ranges::sort(hand, greater<PII>());
    int ok = 1;
    for (int i = 1; i < 5; i++) {
        if (hand[i].first != hand[i - 1].first - 1) {
            ok = 0;
            break;
        }
    }
    
    if (ok) {
        for (int i = 0; i < 5; i++) res[i] = hand[i].first;
        return {10, res};
    }
    ok = 1;
    for (auto &i : hand) {
        if (i.first == 14) i.first = 1;
    }
    ranges::sort(hand, greater<PII>());
    for (int i = 1; i < 5; i++) {
        if (hand[i].first != hand[i - 1].first - 1) {
            ok = 0;
            break;
        }
    }
    if (ok) {
        for (int i = 0; i < 5; i++) res[i] = hand[i].first;
        return {10, res};
    }
    return {-1, {}};
}

// 四条 -9
pair<int, vector<int>> st(VII hand) {
    ranges::sort(hand, greater<PII>());
    map<int, int> cnt;
    for (auto &i : hand) {
        cnt[i.first]++;
    }
    if (cnt.size() > 2) return {-1, {}};
    for (auto &i : cnt) {
        if (i.second != 4 && i.second != 1) {
            return {-1, {}};
        }
    }

    int a = hand[1].first;
    int b;
    if (hand[0].first == a) b = hand[4].first;
    else b = hand[0].first;
    vector<int> res(5);
    for (int i = 0; i < 4; i++) res[i] = a;
    res[4] = b;
    return {9, res};
}

// 葫芦 -8
pair<int, vector<int>> hl(VII hand) {
    ranges::sort(hand, greater<PII>());
    map<int, int> cnt;
    for (auto &i : hand) {
        cnt[i.first]++;
    }
    if (cnt.size() > 2) return {-1, {}};
    for (auto &i : cnt) {
        if (i.second != 2 && i.second != 3) {
            return {-1, {}};
        }
    }
    int a = hand[2].first;
    int b;
    for (auto &i : cnt) {
        if (i.first != a) b = i.first;
    }
    vector<int> res(5);
    for (int i = 0; i < 3; i++) res[i] = a;
    for (int i = 3; i < 5; i++) res[i] = b;
    return {8, res};
}

// 同花 -7
pair<int, vector<int>> th(VII hand) {
    set<int> c;
    for (auto &i : hand) {
        c.insert(i.second);
    }
    if (c.size() > 1) return {-1, {}};
    ranges::sort(hand, greater<PII>());
    vector<int> res(5);
    for (int i = 0; i < 5; i++) res[i] = hand[i].first;
    return {7, res};
}

// 顺子 -6
pair<int, vector<int>> sz(VII hand) { // 进来的时候A等于14
    vector<int> res(5);
    ranges::sort(hand, greater<PII>());
    int ok = 1;
    for (int i = 1; i < 5; i++) {
        if (hand[i].first != hand[i - 1].first - 1) {
            ok = 0;
            break;
        }
    }
    
    if (ok) {
        for (int i = 0; i < 5; i++) res[i] = hand[i].first;
        return {10, res};
    }
    ok = 1;
    for (auto &i : hand) {
        if (i.first == 14) i.first = 1;
    }
    ranges::sort(hand, greater<PII>());
    for (int i = 1; i < 5; i++) {
        if (hand[i].first != hand[i - 1].first - 1) {
            ok = 0;
            break;
        }
    }
    if (ok) {
        for (int i = 0; i < 5; i++) res[i] = hand[i].first;
        return {10, res};
    }
    return {-1, {}};
}

// 三条 -5
pair<int, vector<int>> sanT(VII hand) {
    map<int, int> cnt;
    for (auto &i : hand) {
        cnt[i.first]++;
    }
    if (cnt.size() != 3) return {-1, {}};
    for (auto &i : cnt) {
        if (i.second != 1 && i.second != 3) return {-1, {}};
    }

    int a, b = 0, c = 0;
    for (auto &i : cnt) {
        if (i.second == 3) a = i.first;
        else {
            if (b == 0) b = i.first;
            else c = i.first;
        }
    }
    if (b < c) swap(b, c);

    vector<int> res(5);
    for (int i = 0; i < 3; i++) res[i] = a;
    res[3] = b;
    res[4] = c;
    return {5, res};
}

// 两对 -4
pair<int, vector<int>> ld(VII hand) {
    map<int, int> cnt;
    for (auto &i : hand) {
        cnt[i.first]++;
    }
    if (cnt.size() != 3) return {-1, {}};
    for (auto &i : cnt) {
        if (i.second != 2 && i.second != 1) return {-1, {}};
    }

    int a = 0, b = 0, c;
    for (auto &i : cnt) {
        if (i.second == 1) c = i.first;
        else {
            if (a == 0) a = i.first;
            else b = i.first;
        }
    }
    if (a < b) swap(a, b);
    vector<int> res(5);
    res[0] = res[1] = a;
    res[2] = res[3] = b;
    res[4] = c;
    return {4, res};
}

// 一对 -3
pair<int, vector<int>> yd(VII hand) {
    map<int, int> cnt;
    for (auto &i : hand) {
        cnt[i.first]++;
    }
    if (cnt.size() != 4) return {-1, {}};
    for (auto &i : cnt) {
        if (i.second != 2 && i.second != 1) return {-1, {}};
    }

    int a;
    vector<int> t;
    for (auto &i : cnt) {
        if (i.second == 2) a = i.first;
        else t.push_back(i.first);
    }
    ranges::sort(t, greater<int>());
    vector<int> res;
    res.push_back(a);
    res.push_back(a);
    for (auto &i : t) res.push_back(i);
    return {3, res};
}

// high card -2
pair<int, vector<int>> hc(VII hand) {
    vector<int> res;
    for (auto &i : hand) res.push_back(i.first);
    ranges::sort(res, greater<int>());
    return {2, res};
}

int cmp(vector<int> a, vector<int> b) {
    for (int i = 0; i < 5; i++) {
        if (a[i] > b[i]) return 1;
        else if (a[i] < b[i]) return 2;
    }
    return 0;
}

pair<int, vector<int>> choose(VII hand) {
    pair<int, vector<int>> res;
    res = ths(hand);
    if (res.first != -1) return res;
    res = st(hand);
    if (res.first != -1) return res;
    res = hl(hand);
    if (res.first != -1) return res;
    res = th(hand);
    if (res.first != -1) return res;
    res = sz(hand);
    if (res.first != -1) return res;
    res = sanT(hand);
    if (res.first != -1) return res;
    res = ld(hand);
    if (res.first != -1) return res;
    res = yd(hand);
    if (res.first != -1) return res;
    res = hc(hand);
    return res;
}

void solve(){
    vector<PII> A(5), B(5);
    for (int i = 0; i < 5; i++) {
        string s;cin >> s;
        A[i].first = mp[s[0]];
        if (s[1] == 'C') A[i].second = 1;
        if (s[1] == 'D') A[i].second = 2;
        if (s[1] == 'H') A[i].second = 3;
        if (s[1] == 'S') A[i].second = 4;
    }
    // for (int i = 0; i < 4; i++) {
    //     string s;cin >> s;
    //     B[i].first = mp[s[0]];
    //     if (s[1] == 'C') B[i].second = 1;
    //     if (s[1] == 'D') B[i].second = 2;
    //     if (s[1] == 'H') B[i].second = 3;
    //     if (s[1] == 'S') B[i].second = 4;
    // }

    auto [val, vec] = choose(A);
    cout << val << endl;
    for (auto &i : vec) cout << i << ' ';
}



void init()
{
    for(int i=2;i<=9;i++)
    mp['0'+i]=i;
    mp['T']=10;
    mp['J']=11;
    mp['Q']=12;
    mp['K']=13;
    mp['A']=14;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    init();
    int T = 1;cin >> T;
    while (T--) solve();
}
