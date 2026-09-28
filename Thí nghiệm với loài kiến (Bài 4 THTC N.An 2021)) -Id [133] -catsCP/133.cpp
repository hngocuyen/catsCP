//traidepluyenthuattoan - hngocuyen - [133]>> solutions
#include <bits/stdc++.h>
using namespace std;
typedef long long L;const L P=1e9+7;int m;
typedef vector<int> S;map<S,int> id;vector<S> st;
S nm(S a){map<int,int> r;int c=0;for(int&x:a)if(x){if(!r.count(x))r[x]=++c;x=r[x];}return a;}
int gi(const S&a){auto it=id.find(a);if(it!=id.end())return it->second;int k=st.size();id[a]=k;st.push_back(a);return k;}
int f[20];int fd(int x){return f[x]==x?x:f[x]=fd(f[x]);}
typedef vector<vector<L>> M;
M mul(const M&a,const M&b){int n=a.size();M c(n,vector<L>(n,0));for(int i=0;i<n;i++)for(int k=0;k<n;k++)if(a[i][k])for(int j=0;j<n;j++)c[i][j]=(c[i][j]+a[i][k]*b[k][j])%P;return c;}
int main(){
    L n;cin>>m>>n;
    vector<int> s0;
    for(int b=1;b<(1<<m);b++){S a(m,0);int c=0;for(int i=0;i<m;i++)if(b>>i&1){if(!(i&&(b>>(i-1)&1)))c++;a[i]=c;}s0.push_back(gi(a));}
    vector<vector<pair<int,int>>> e;
    for(size_t q=0;q<st.size();q++){
        S a=st[q];e.push_back({});map<int,int> cnt;
        for(int b=1;b<(1<<m);b++){
            for(int i=0;i<20;i++)f[i]=i;
            S c(m,0);for(int i=0;i<m;i++)if(b>>i&1)c[i]=(i&&(b>>(i-1)&1))?c[i-1]:10+i;
            bool ok=1;
            for(int i=0;i<m;i++)if(a[i]&&c[i])f[fd(a[i])]=fd(c[i]);
            for(int i=0;i<m;i++)if(a[i]&&fd(a[i])<10)ok=0;
            if(!ok)continue;
            S d(m,0);for(int i=0;i<m;i++)if(c[i])d[i]=fd(c[i]);
            int t=gi(nm(d));cnt[t]++;
        }
        for(auto&p:cnt)e[q].push_back(p);
    }
    int z=st.size();M T(z+1,vector<L>(z+1,0));
    for(int q=0;q<z;q++){for(auto&p:e[q])T[q][p.first]=p.second;bool o=1;for(int x:st[q])if(x>1)o=0;if(o)T[q][z]=1;}
    T[z][z]=1;
    M R(z+1,vector<L>(z+1,0));for(int i=0;i<=z;i++)R[i][i]=1;
    while(n){if(n&1)R=mul(R,T);T=mul(T,T);n>>=1;}
    L r=0;for(int x:s0)r+=R[x][z];cout<<r%P<<endl;
}
