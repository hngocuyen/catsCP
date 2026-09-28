//traidepluyenthuattoan - hngocuyen - [116]>> solutions
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll I=4e18;const int G=61;
int n,q,S;vector<int> T,o,c,nx,ex,fe,cs;vector<ll> fs;vector<ll> st;vector<vector<int>> up;vector<vector<ll>> sm;
ll ad(ll a,ll b){return a+b>=I?I:a+b;}
int id(int v,ll t){return o[v]+t%T[v];}
bool cl(int v,ll t,int L,int&u,ll&s){s=0;
    while(T[v]<L){int x=id(v,t);if(fe[x]<0)return 0;s+=fs[x];t+=fs[x];v=fe[x];}
    u=v;return 1;}
void fn(int x0){vector<int> P;int x=x0;while(cs[x]==0){cs[x]=1;P.push_back(x);if(nx[x]>=0)x=nx[x];else break;}
    int e;ll w;if(cs[x]==1&&nx[x]>=0){e=-1;w=0;}else if(cs[x]==2){e=fe[x];w=fs[x];}else{if(nx[x]==-1){e=ex[x];w=st[x];}else{e=-1;w=0;}cs[x]=2;fe[x]=e;fs[x]=w;P.pop_back();}
    while(!P.empty()){int y=P.back();P.pop_back();cs[y]=2;if(e>=0)w+=st[y];fe[y]=e;fs[y]=w;}}
ll rd(){ll r=0;int ch=getchar();while(ch<48)ch=getchar();while(ch>47){r=r*10+ch-48;ch=getchar();}return r;}
int main(){n=rd();q=rd();T.resize(n+1);o.resize(n+1);for(int i=1;i<=n;i++){T[i]=rd();o[i]=S;S+=T[i];}
    c.resize(S);for(int i=1;i<=n;i++)for(int j=0;j<T[i];j++)c[o[i]+j]=rd();
    nx.assign(S,-2);fe.assign(S,-1);cs.assign(S,0);fs.assign(S,0);ex.assign(S,0);st.assign(S,I);up.assign(G,vector<int>(S,-1));sm.assign(G,vector<ll>(S,I));
    vector<int> ord(n);iota(ord.begin(),ord.end(),1);sort(ord.begin(),ord.end(),[&](int a,int b){return T[a]<T[b];});
    for(int a=0;a<n;){int L=T[ord[a]],b=a;while(b<n&&T[ord[b]]==L)b++;
        for(int z=a;z<b;z++){int v=ord[z];for(int r=0;r<L;r++){int x=o[v]+r,w=c[x];
            if(T[w]>=L){st[x]=1;if(T[w]==L)nx[x]=id(w,r+1);else{nx[x]=-1;ex[x]=w;}}
            else{int u;ll s;if(!cl(w,r+1,L,u,s)){nx[x]=-2;continue;}st[x]=1+s;if(T[u]==L)nx[x]=id(u,r+1+s);else{nx[x]=-1;ex[x]=u;}}
            if(nx[x]>=0){up[0][x]=nx[x];sm[0][x]=st[x];}}}
        for(int z=a;z<b;z++){int v=ord[z];for(int r=0;r<L;r++)if(!cs[o[v]+r])fn(o[v]+r);}
        for(int k=1;k<G;k++)for(int z=a;z<b;z++){int v=ord[z];for(int r=0;r<L;r++){int x=o[v]+r,y=up[k-1][x];if(y>=0&&up[k-1][y]>=0){up[k][x]=up[k-1][y];sm[k][x]=ad(sm[k-1][x],sm[k-1][y]);}}}
        a=b;}
    while(q--){int v=rd();ll t=rd(),d=rd();
        while(d>0){int x=id(v,t);if(fe[x]>=0&&fs[x]<=d){d-=fs[x];t+=fs[x];v=fe[x];continue;}for(int k=63-__builtin_clzll(d);k>=0;k--)if(up[k][x]>=0&&sm[k][x]<=d){d-=sm[k][x];t+=sm[k][x];x=up[k][x];}
            v=0;int b=x;
            {int vv=upper_bound(o.begin()+1,o.end(),b)-o.begin()-1;v=vv;}
            if(d==0)break;
            if(nx[x]==-1&&st[x]<=d){d-=st[x];t+=st[x];v=ex[x];}
            else{v=c[x];t++;d--;}}
        printf("%d\n",v);}
}
