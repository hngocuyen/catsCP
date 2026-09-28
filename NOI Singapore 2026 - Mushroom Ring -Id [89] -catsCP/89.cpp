//traidepluyenthuattoan - hngocuyen - [89]>> solutions
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int X=150005;
int f[X],c[X][2],z[X],w[X],e[X],t[X];
bool ir(int x){return !f[x]||(c[f[x]][0]!=x&&c[f[x]][1]!=x);}
void up(int x){z[x]=z[c[x][0]]+z[c[x][1]]+1+w[x];}
void rt(int x){int y=f[x],q=f[y],k=c[y][1]==x;if(!ir(y))c[q][c[q][1]==y]=x;f[x]=q;c[y][k]=c[x][!k];if(c[x][!k])f[c[x][!k]]=y;c[x][!k]=y;f[y]=x;up(y);up(x);}
void sp(int x){while(!ir(x)){int y=f[x];if(!ir(y))rt((c[y][1]==x)==(c[f[y]][1]==y)?y:x);rt(x);}}
void ac(int x){for(int y=0;x;y=x,x=f[x]){sp(x);w[x]+=z[c[x][1]]-z[y];c[x][1]=y;up(x);}}
int fr(int x){ac(x);sp(x);while(c[x][0])x=c[x][0];sp(x);return x;}
int sz(int r){ac(r);sp(r);return z[r];}
void lk(int u,int v){ac(u);sp(u);ac(v);sp(v);f[u]=v;w[v]+=z[u];up(v);}
void ct(int u){ac(u);sp(u);int l=c[u][0];c[u][0]=0;f[l]=0;up(u);}
ll C1[X],C2[X];int D;
void fl(int r){int s=sz(r);(e[r]?C2:C1)[s]+=D-t[r];}
int main(){int n,m;ll k;scanf("%d %d %lld",&n,&m,&k);
    vector<vector<array<int,2>>> A(n+2),R(n+2);
    for(int i=0;i<m;i++){int u,v,a,b;scanf("%d %d %d %d",&u,&v,&a,&b);A[a].push_back({u,v});R[b+1].push_back({u,v});}
    for(int i=1;i<=n;i++){z[i]=1;t[i]=1;}
    ll B=0;
    for(D=1;D<=n;D++){
        for(auto&[u,v]:R[D]){
            if(e[u]==v){fl(u);e[u]=0;t[u]=D;continue;}
            int r=fr(u);fl(r);ct(u);
            if(e[r]&&fr(e[r])==u){lk(r,e[r]);e[r]=0;}
            t[u]=D;t[fr(v)]=D;
        }
        for(auto&[u,v]:A[D]){
            int r=fr(v);
            if(r==u){fl(u);e[u]=v;t[u]=D;}
            else{fl(u);fl(r);lk(u,v);t[r]=D;}
        }
        int s=sz(D);B+=s;C1[s]--;
    }
    for(int i=1;i<=n;i++)if(fr(i)==i)fl(i);
    vector<pair<ll,ll>> P,Q;
    for(int s=n;s>=1;s--){if(C1[s])P.push_back({s,C1[s]});if(C2[s])Q.push_back({s,C2[s]});}
    auto g=[&](vector<pair<ll,ll>>&V,ll x){ll r=0;for(auto&[s,q]:V){if(x<=0)break;ll y=min(x,q);r+=y*s;x-=y;}return r;};
    ll T2=0;for(auto&p:Q)T2+=p.second;
    ll hi=min(T2,k/2),lo=0;
    auto F=[&](ll j){return g(Q,j)+g(P,k-2*j);};
    while(lo<hi){ll md=(lo+hi+1)/2;if(F(md)-F(md-1)>0)lo=md;else hi=md-1;}
    printf("%lld\n",B+F(lo));
}
