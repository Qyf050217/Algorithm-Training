#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>
vector<vector<int>> weight(7, vector<int>(2));
int d1[6][3] = {{}};
int d2[6][3] = {};
int ans = 0;
void cjp(int id,int a[],int b[])
{
    if(id==2)
    {
        if(max(a[0],a[1])<b[id]||max(a[2],a[3])<b[id])
        {
            ans+=weight[3][1];
        }
        else
        {
            ans+=weight[3][0];
        }
    }
    if(id==0)
    {
        ans+=weight[1][0];
    }
    else if(id==1)
    {
        ans+=weight[2][0];
    }
    else if(id==3)
    {
        ans+=weight[4][1];
    }
}
void solve(){
    
    weight[1][0] = 6;   // 1面
    weight[2][0] = 11;  // 2 面相邻的
    weight[2][1] = 7;   // 2 面相对的
    weight[3][0] = 15;  // 3 面在角落
    weight[3][1] = 13;  // 3 面边相连
    weight[4][0] = 14;  // 4 面剩余相对
    weight[4][1] = 18;  // 4 面剩相连
    weight[5][0] = 20;  // 5 面
    weight[6][0] = 21;  // 6 面

    int n, m;cin >> n >> m;
    vector<vector<int>> arr(n + 2, vector<int>(m + 2));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) cin >> arr[i][j];
    }
    ans = 0;
    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= m; j++) {
            cout<<ans<<'\n';
            // int cnt = 0;
            // vector<int> hs, empty;
            // // 把下标填进数组

            // // 
            // if (cnt == 1) {
            //     ans += 6;
            // } else if (cnt == 5) ans += 20;
            // else if (cnt == 6) ans += 21;
            // else if (cnt == 2) {

            // } else if (cnt == 3) {

            // } else if (cnt == 4) {

            // }
            if(arr[i][j]==0) continue;
            int a[4]={arr[i-1][j],arr[i+1][j],arr[i][j-1],arr[i][j+1]};
            int b[4]={arr[i-1][j],arr[i+1][j],arr[i][j-1],arr[i][j+1]};
            sort(b,b+4);
            int x=0,id=0;
            while(id<=3&&b[id]==x)
            {
                id++;
            }
            if(arr[i][j]==1)
            {
                if(id==0)
                {
                    ans+=weight[2][1];
                }
                else if(id==1)
                {
                    ans+=weight[3][1];
                }
                else if(id==2)
                {
                    if(max(a[0],a[1])<b[id]||max(a[2],a[3])<b[id])
                    ans+=weight[4][0];
                    else
                    {
                        ans+=weight[4][1];
                    }
                }
                else
                {
                    ans+=weight[id+2][0];
                }
                continue;
            }
            cjp(id,a,b);
            
            if(id==4)
            {
                ans+=weight[4][0]*(arr[i][j]-2);
                ans+=weight[5][0];
                continue;
            }

            x=b[id];
            int y=1;
            while(id<=3&&b[id]==x)
            {
                id++;
            }
            
            if(b[id-1]>=arr[i][j])
            {
                if(id==3)
                {
                    ans+=weight[id][1]*(arr[i][j]-1-y); 
                }
                else
                {
                    ans+=weight[id][0]*(arr[i][j]-1-y);              
                }
                cjp(id,a,b);
                continue;
            }
            if(id==4)
            {
                ans+=weight[4][0]*(arr[i][j]-1-y);
                ans+=weight[5][0];
                continue;
            }
            if(id==3)
            {
                ans+=weight[id][1]*(b[id-1]-y); 
            }
            else
            {
                ans+=weight[id][0]*(b[id-1]-y);              
            }
            y=b[id-1];    

            while(id<=3&&b[id]==x)
            {
                id++;
            }
            if(b[id-1]>=arr[i][j])
            {
                if(id==3)
                {
                    ans+=weight[id][1]*(arr[i][j]-1-y); 
                }
                else
                {
                    ans+=weight[id][0]*(arr[i][j]-1-y);              
                }
                cjp(id,a,b);
                continue;
            }
            if(id==4)
            {
                ans+=weight[4][0]*(arr[i][j]-1-y);
                ans+=weight[5][0];
                continue;
            }
            if(id==3)
            {
                ans+=weight[id][1]*(b[id-1]-y); 
            }
            else
            {
                ans+=weight[id][0]*(b[id-1]-y);              
            }
            y=b[id-1];



            while(id<=3&&b[id]==x)
            {
                id++;
            }
            if(b[id-1]>=arr[i][j])
            {
                if(id==3)
                {
                    ans+=weight[id][1]*(arr[i][j]-1-y); 
                }
                else
                {
                    ans+=weight[id][0]*(arr[i][j]-1-y);              
                }
                cjp(id,a,b);
                continue;
            }
            if(id==4)
            {
                ans+=weight[4][0]*(arr[i][j]-1-y);
                ans+=weight[5][0];
                continue;
            }
            if(id==3)
            {
                ans+=weight[id][1]*(b[id-1]-y); 
            }
            else
            {
                ans+=weight[id][0]*(b[id-1]-y);              
            }
            y=b[id-1];


            while(id<=3&&b[id]==x)
            {
                id++;
            }
            if(b[id-1]>=arr[i][j])
            {
                if(id==3)
                {
                    ans+=weight[id][1]*(arr[i][j]-1-y); 
                }
                else
                {
                    ans+=weight[id][0]*(arr[i][j]-1-y);              
                }
                cjp(id,a,b);
                continue;
            }
            if(id==4)
            {
                ans+=weight[4][0]*(arr[i][j]-1-y);
                ans+=weight[5][0];
                continue;
            }
            if(id==3)
            {
                ans+=weight[id][1]*(b[id-1]-y); 
            }
            else
            {
                ans+=weight[id][0]*(b[id-1]-y);              
            }
            y=b[id-1];
        }
    }


    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
    return 0;
}