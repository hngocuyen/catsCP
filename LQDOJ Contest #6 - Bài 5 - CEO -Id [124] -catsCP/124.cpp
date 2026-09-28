//traidepluyenthuattoan - hngocuyen - [124]>> solutions
#include <bits/stdc++.h>
using namespace std;
int n,S;
vector<int> dp,tn,to,vd,mn;
vector<vector<int>> ls,fw;
void ac(int p){
    int d=vd[p];
    for(int i=p;i<=n;i+=i&-i){
        auto&v=ls[i];int j=lower_bound(v.begin(),v.end(),d)-v.begin()+1;
        for(auto&f=fw[i];j<(int)f.size();j+=j&-j)f[j]++;
    }
}
int qp(int p,int d){
    int r=0;
    for(int i=p;i>0;i-=i&-i){
        auto&v=ls[i];int j=upper_bound(v.begin(),v.end(),d)-v.begin();
        for(auto&f=fw[i];j>0;j-=j&-j)r+=f[j];
    }
    return r;
}
void st(int p,int v){p+=S;mn[p]=v;for(p>>=1;p;p>>=1)mn[p]=min(mn[2*p],mn[2*p+1]);}
void fd(int v,int lo,int hi,int l,int r,int d,vector<int>&o){
    if(hi<l||lo>r||mn[v]>d)return;
    if(lo==hi){o.push_back(lo);return;}
    int m=(lo+hi)/2;
    fd(2*v,lo,m,l,r,d,o);fd(2*v+1,m+1,hi,l,r,d,o);
}
int main(){
    if(fopen("CEO.INP","r")){freopen("CEO.INP","r",stdin);freopen("CEO.OUT","w",stdout);}
    scanf("%d",&n);
    vector<vector<int>> g(n+1);
    for(int i=1;i<n;i++){int x,y;scanf("%d %d",&x,&y);g[x].push_back(y);}
    dp.assign(n+1,0);tn.assign(n+1,0);to.assign(n+1,0);vd.assign(n+2,0);
    int c=0;
    vector<pair<int,int>> s={{1,0}};
    while(!s.empty()){
        auto&[v,i]=s.back();
        if(i==0){tn[v]=++c;vd[c]=dp[v];}
        if(i<(int)g[v].size()){int u=g[v][i++];dp[u]=dp[v]+1;s.push_back({u,0});}
        else{to[v]=c;s.pop_back();}
    }
    ls.assign(n+1,{});fw.assign(n+1,{});
    for(int i=1;i<=n;i++){
        for(int j=i-(i&-i)+1;j<=i;j++)ls[i].push_back(vd[j]);
        sort(ls[i].begin(),ls[i].end());
        fw[i].assign(ls[i].size()+1,0);
    }
    S=1;while(S<n+1)S<<=1;
    const int I=INT_MAX;
    mn.assign(2*S,I);
    vector<int> b(n+1);
    for(int i=1;i<=n;i++)scanf("%d",&b[i]);
    for(int v=1;v<=n;v++){if(b[v])ac(tn[v]);else mn[S+tn[v]]=vd[tn[v]];}
    for(int i=S-1;i>0;i--)mn[i]=min(mn[2*i],mn[2*i+1]);
    int q;scanf("%d",&q);
    vector<int> o;
    while(q--){
        int t,x,k;scanf("%d %d %d",&t,&x,&k);
        int d=dp[x]+k;
        if(t==1){
            o.clear();
            fd(1,0,S-1,tn[x],to[x],d,o);
            for(int p:o){st(p,I);ac(p);}
        }else printf("%d\n",qp(to[x],d)-qp(tn[x]-1,d));
    }
}
