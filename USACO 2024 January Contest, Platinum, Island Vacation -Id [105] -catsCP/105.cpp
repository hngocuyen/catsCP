//traidepluyenthuattoan - hngocuyen - [105]>> solutions
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll P=1e9+7;
ll pw(ll a,ll b){ll r=1;a%=P;while(b){if(b&1)r=r*a%P;a=a*a%P;b>>=1;}return r;}
int n,m;vector<vector<int>> g;vector<int> par,dep,ord,pc,vis;vector<vector<int>> cy,bc,cc;vector<int> tp;
void dfs(int u){
    vis[u]=1;ord.push_back(u);
    for(int v:g[u]){
        if(v==par[u])continue;
        if(!vis[v]){par[v]=u;dep[v]=dep[u]+1;dfs(v);}
        else if(dep[v]<dep[u]){
            int id=cy.size();vector<int> c;int x=u;
            while(x!=v){c.push_back(x);pc[x]=id;x=par[x];}
            reverse(c.begin(),c.end());cy.push_back(c);tp.push_back(v);cc[v].push_back(id);
        }
    }
}
int main(){
    int T;scanf("%d",&T);
    vector<ll> iv(40005);for(int i=1;i<40005;i++)iv[i]=pw(i,P-2);
    while(T--){
        scanf("%d %d",&n,&m);
        vector<ll> p(n+1);for(int i=1;i<=n;i++)scanf("%lld",&p[i]);
        g.assign(n+1,{});for(int i=0;i<m;i++){int a,b;scanf("%d %d",&a,&b);g[a].push_back(b);g[b].push_back(a);}
        par.assign(n+1,0);dep.assign(n+1,0);ord.clear();pc.assign(n+1,-1);vis.assign(n+1,0);cy.clear();tp.clear();cc.assign(n+1,{});bc.assign(n+1,{});
        dfs(1);
        for(int v=2;v<=n;v++)if(pc[v]<0)bc[par[v]].push_back(v);
        vector<ll> r(cy.size()),q(n+1),ps(n+1),pb(n+1);vector<vector<ll>> py(n+1);
        for(int z=n-1;z>=0;z--){
            int u=ord[z];
            int b=bc[u].size(),c=cc[u].size(),f=u!=1&&pc[u]>=0;
            int D=b+2*c+f;
            ll o=(1-p[u]%P+P)%P;
            vector<ll> e(c+1,0);e[0]=1;
            for(int i=0;i<c;i++){ll x=r[cc[u][i]];for(int k=i+1;k>=1;k--)e[k]=(e[k]+e[k-1]*x)%P;}
            vector<ll> A(c+1);A[0]=1;
            for(int k=0;k<c;k++)A[k+1]=A[k]*(k+1)%P*o%P*2%P*iv[D-2*k]%P;
            vector<ll> t(c+1);
            for(int k=0;k<=c;k++)t[k]=D-2*k>0?o*iv[D-2*k]%P:0;
            ll s=0,w=0;
            for(int k=0;k<=c;k++){s=(s+A[k]*e[k]%P*(D-2*k==0?1:p[u]%P))%P;w=(w+A[k]*e[k]%P*t[k])%P;}
            ps[u]=s;pb[u]=w;q[u]=f?w:0;
            py[u].assign(c,0);
            for(int i=0;i<c;i++){
                ll x=r[cc[u][i]];ll h=0,y=0;
                for(int k=0;k<c;k++){y=(e[k]-(k?y*x%P:0)+P)%P;h=(h+A[k]*y%P*t[k])%P;}
                py[u][i]=h;
            }
            if(pc[u]>=0&&cy[pc[u]][0]==u){
                int id=pc[u];ll x=1;for(int v:cy[id])x=x*q[v]%P;r[id]=x;
            }
        }
        vector<ll> M(n+1,0),E(n+1,0);M[1]=1;
        for(int u:ord){
            E[u]=M[u]*ps[u]%P;
            for(int v:bc[u])M[v]=(M[v]+M[u]*pb[u])%P;
            for(int i=0;i<(int)cc[u].size();i++){
                ll e=M[u]*py[u][i]%P;auto&C=cy[cc[u][i]];
                ll x=e;for(int v:C){M[v]=(M[v]+x)%P;x=x*q[v]%P;}
                x=e;for(int j=C.size()-1;j>=0;j--){M[C[j]]=(M[C[j]]+x)%P;x=x*q[C[j]]%P;}
            }
        }
        for(int i=1;i<=n;i++)printf("%lld%c",E[i],i==n?'\n':' ');
    }
}
