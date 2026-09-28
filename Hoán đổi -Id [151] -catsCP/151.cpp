//traidepluyenthuattoan - hngocuyen - [151]>> solutions
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k;
    cin>>n>>k;
    int z=1;
    while(z<n)z<<=1;
    vector<pair<int,int>>s(z*2,{-1,-1});
    for(int i=0,x;i<n;i++){
        cin>>x;
        s[z+i]={x,i};
    }
    for(int i=z-1;i;i--)s[i]=max(s[i*2],s[i*2+1]);
    auto q=[&](int l,int r){
        pair<int,int>x={-1,-1};
        for(l+=z,r+=z;l<r;l>>=1,r>>=1){
            if(l&1)x=max(x,s[l++]);
            if(r&1)x=max(x,s[--r]);
        }
        return x;
    };
    auto u=[&](int p){
        s[z+p]={-1,p};
        for(int i=(z+p)>>1;i;i>>=1)s[i]=max(s[i*2],s[i*2+1]);
    };
    priority_queue<int>h;
    int b=(n+k-1)/k;
    auto a=[&](int c){
        if(c<0||c>=b)return;
        auto x=q(c*k,min(n,(c+1)*k));
        if(x.first<0)return;
        int p=x.second;
        if(q(max(0,p-k+1),min(n,p+k)).first==x.first)h.push(p);
    };
    for(int i=0;i<b;i++)a(i);
    vector<int>r(n);
    for(int x=n;x;x--){
        int p;
        while(1){
            p=h.top();
            h.pop();
            if(s[z+p].first>=0&&q(max(0,p-k+1),min(n,p+k)).second==p)break;
        }
        r[p]=x;
        u(p);
        int c=p/k;
        a(c-1);
        a(c);
        a(c+1);
    }
    for(int x:r)cout<<x<<'\n';
}
