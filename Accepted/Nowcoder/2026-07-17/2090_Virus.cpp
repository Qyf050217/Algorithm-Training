#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    map<char,int>mp;
    string s;
    cin>>s;
    mp['a']=1;
    mp['e']=1;
    mp['i']=1;
    mp['o']=1;
    mp['u']=1;
    if(s.size()!=8)
    {
        cout<<"Well-Being\n";
        return;
    }
    for(int i=0;i<8;i++)
    {
        if(i%2)
        {
            if(mp[s[i]]==0)
            {
                cout<<"Well-Being\n";
                return;
            }
        }
        else
        {
            if(mp[s[i]]==1)
            {
                cout<<"Well-Being\n";
                return;
            }
        }
        
    }
    cout<<"Suspected Virus\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
