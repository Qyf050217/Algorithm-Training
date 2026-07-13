#include<bits/stdc++.h>
using namespace std;

vector<int> a,b;

int kth(vector<int> x,vector<int> y,int k){
    if(x.size()>y.size()) return kth(y,x,k);
    if(x.empty()) return y[k-1];
    if(k==1) return min(x[0],y[0]);
    
    int mi=min((int)x.size(),k/2);
    int mj=min((int)y.size(),k/2);
    if(x[mi-1]<y[mj-1])
        return kth(vector<int>(x.begin()+mi,x.end()),y,k-mi);
    else
        return kth(x,vector<int>(y.begin()+mj,y.end()),k-mj);
}

int main(){
    int n,m;
    cin>>n>>m;
    a.resize(n),b.resize(m);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<m;i++) cin>>b[i];
    int tot=n+m;
    double ans;
    if(tot&1) ans=kth(a,b,tot/2+1);
    else ans=(kth(a,b,tot/2)+kth(a,b,tot/2+1))/2.0;
    printf("%.1lf\n",ans);
    return 0;
}