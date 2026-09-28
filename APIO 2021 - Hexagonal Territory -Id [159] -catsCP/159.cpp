//traidepluyenthuattoan - hngocuyen - [159]>> solutions
#include "hexagon.h"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M=1000000007;
static ll A_,B_,X2;
struct E{ll x,y,s;int b;};
static vector<E> e;
static ll vl(int i,ll X){return 2*e[i].y+e[i].s*(X-2*e[i].x);}
struct Cp{bool operator()(int a,int b)const{return vl(a,X2)<vl(b,X2);}};
struct S{ll m,p,q;};
static ll tri(ll n){return (ll)((__int128)n*(n+1)/2%M);}
static ll cs(S s,ll b,ll t){ll r=(t-b+1)%M*((A_+B_*(s.m%M))%M)%M;return (r+B_*((tri(s.p-b)+tri(t-s.q))%M))%M;}
static S tR(S s,ll B,ll T,ll b,ll t){ll lo=max(B,b),hi=min(T+1,t),p=max(s.p,lo),q=min(s.q+1,hi);if(lo>hi)throw 1;if(p<=q)return {s.m+1,p,q};if(s.q+1<lo)return {s.m+lo-s.q,lo,lo};return {s.m+1+s.p-hi,hi,hi};}
static S tL(S s,ll B,ll T,ll b,ll t){S r=tR({s.m,-s.q,-s.p},-T,-B,-t,-b);return {r.m,-r.q,-r.p};}
static S pc(S s,ll b0,ll t0,ll cb,ll ct,ll K,ll&sm){
    auto F=[&](ll k){ll b=b0+cb*k,t=t0+ct*k;return cs({s.m+k,max(s.p,b),min(s.q+k,t)},b,t);};
    vector<ll> c={0,K};
    if(cb){ll k=s.p-b0+1;if(k>0&&k<K)c.push_back(k);}
    if(!ct){ll k=t0-s.q+1;if(k>0&&k<K)c.push_back(k);}
    sort(c.begin(),c.end());
    for(size_t i=0;i+1<c.size();i++){ll a=c[i],n=c[i+1]-a;if(n<=0)continue;
        if(n<=3){for(ll k=a;k<a+n;k++)sm=(sm+F(k))%M;continue;}
        ll f0=F(a),f1=F(a+1),f2=F(a+2),d1=(f1-f0+M)%M,d2=((f2-2*f1+f0)%M+2*M)%M;
        ll c2=(ll)((__int128)n*(n-1)/2%M),c3=(ll)((__int128)n*(n-1)*(n-2)/6%M);
        sm=(sm+n%M*f0+c2*d1%M+c3*d2)%M;}
    ll k=K-1,b=b0+cb*k,t=t0+ct*k;return {s.m+k,max(s.p,b),min(s.q+k,t)};
}
int dx[7]={0,0,1,1,0,-1,-1},dy[7]={0,1,1,0,-1,-1,0};
static int od(int x,int y){if(x==1)return y;if(x==0)return y>0?2:5;return y<0?4:3;}
int draw_territory(int N,int A,int B,vector<int> D,vector<int> L){
    A_=A;B_=B;
    vector<ll> X(N+1),Y(N+1);
    auto bd=[&](){for(int i=0;i<N;i++)X[i+1]=X[i]+dx[D[i]]*(ll)L[i],Y[i+1]=Y[i]+dy[D[i]]*(ll)L[i];};
    bd();
    __int128 ar=0;for(int i=0;i<N;i++)ar+=(__int128)X[i]*Y[i+1]-(__int128)X[i+1]*Y[i];
    if(ar<0){reverse(D.begin(),D.end());reverse(L.begin(),L.end());for(auto&d:D)d=(d+2)%6+1;bd();}
    e.assign(N+1,{0,0,0,0});
    vector<int> lv(N,-1),rv(N,-1);
    for(int i=0;i<N;i++){int a=dx[D[i]],b=dy[D[i]];if(!a)continue;
        if(a>0){e[i]={X[i],Y[i],b,1};lv[i]=i;rv[i]=(i+1)%N;}else{e[i]={X[i+1],Y[i+1],-b,0};lv[i]=(i+1)%N;rv[i]=i;}}
    auto st=[&](int v,int d){int j=(v+N-1)%N,w=od(dx[D[v]],dy[D[v]]),u=od(-dx[D[j]],-dy[D[j]]);if(d==w||d==u)return 2;return (d-w+6)%6<(u-w+6)%6?1:0;};
    vector<int> vs(N);iota(vs.begin(),vs.end(),0);
    sort(vs.begin(),vs.end(),[&](int a,int b){return X[a]!=X[b]?X[a]<X[b]:Y[a]<Y[b];});
    set<int,Cp> T;vector<set<int,Cp>::iterator> it(N);
    vector<ll> ps(N);vector<int> pn(N);
    vector<ll> xl,xr,bl,tl,br,tr,sb,sT;vector<vector<int>> g;
    auto nn=[&](ll a,ll b,ll c,ll d,ll f,ll h,ll p,ll q){xl.push_back(a);xr.push_back(b);bl.push_back(c);tl.push_back(d);br.push_back(f);tr.push_back(h);sb.push_back(p);sT.push_back(q);g.push_back({});return (int)xl.size()-1;};
    auto lk=[&](int a,int b){g[a].push_back(b);g[b].push_back(a);};
    int Q=N,rt=-1;
    for(int i=0;i<N;){
        int j=i;ll x=X[vs[i]];while(j<N&&X[vs[j]]==x)j++;
        X2=2*x;
        vector<array<ll,3>> sg;
        for(int k=i;k<j;){
            int v=vs[k];ll lo,hi;
            if(st(v,5)==1){e[Q].y=Y[v];auto t=T.lower_bound(Q);if(t==T.begin())throw 2;--t;lo=vl(*t,X2)/2;}else lo=Y[v];
            int nd=xl.size();
            while(1){v=vs[k];if(v==0)rt=nd;int s=st(v,2);k++;
                if(s==0){hi=Y[v];break;}
                if(s==2)continue;
                e[Q].y=Y[v];auto t=T.upper_bound(Q);ll ny=k<j?Y[vs[k]]:LLONG_MAX;
                if(t!=T.end()&&vl(*t,X2)/2<ny){hi=vl(*t,X2)/2;break;}
                if(k>=j)throw 3;}
            nn(x,x,lo,hi,lo,hi,0,0);sg.push_back({lo,hi,nd});
        }
        for(auto&z:sg){e[Q].y=z[0];vector<int> w;for(auto t=T.lower_bound(Q);t!=T.end()&&vl(*t,X2)<=2*z[1];t++)w.push_back(*t);
            for(size_t k=0;k+1<w.size();k++)if(e[w[k]].b){int a=w[k],b=w[k+1];ll s=ps[a];
                if(s<=x-1){int p=nn(s,x-1,vl(a,2*s)/2,vl(b,2*s)/2,vl(a,2*x-2)/2,vl(b,2*x-2)/2,e[a].s,e[b].s);lk(pn[a],p);lk(p,z[2]);}else lk(pn[a],z[2]);}}
        for(int k=i;k<j;k++){int v=vs[k];for(int ed:{(v+N-1)%N,v})if(lv[ed]>=0&&rv[ed]==v)T.erase(it[ed]);}
        X2=2*x+1;
        for(int k=i;k<j;k++){int v=vs[k];for(int ed:{(v+N-1)%N,v})if(lv[ed]==v)it[ed]=T.insert(ed).first;}
        X2=2*x;
        for(auto&z:sg){e[Q].y=z[0];vector<int> w;for(auto t=T.lower_bound(Q);t!=T.end()&&vl(*t,X2)<=2*z[1];t++)w.push_back(*t);
            for(size_t k=0;k+1<w.size();k++)if(e[w[k]].b){ps[w[k]]=x+1;pn[w[k]]=z[2];}}
        i=j;
    }
    int n=xl.size();vector<S> sl(n),sr(n);vector<char> vz(n,0);
    ll an=0;vector<int> q={rt};vz[rt]=1;sl[rt]=sr[rt]={0,0,0};an=cs(sl[rt],bl[rt],tl[rt]);
    for(size_t h=0;h<q.size();h++){int u=q[h];
        for(int w:g[u]){if(vz[w])continue;vz[w]=1;q.push_back(w);ll K=xr[w]-xl[w]+1;
            if(xl[w]==xr[u]+1){sl[w]=tR(sr[u],br[u],tr[u],bl[w],tl[w]);if(K==1){sr[w]=sl[w];an=(an+cs(sl[w],bl[w],tl[w]))%M;}else sr[w]=pc(sl[w],bl[w],tl[w],sb[w],sT[w],K,an);}
            else if(xr[w]==xl[u]-1){sr[w]=tL(sl[u],bl[u],tl[u],br[w],tr[w]);if(K==1){sl[w]=sr[w];an=(an+cs(sl[w],bl[w],tl[w]))%M;}else{S r=pc({sr[w].m,-sr[w].q,-sr[w].p},-tr[w],-br[w],sT[w],sb[w],K,an);sl[w]={r.m,-r.q,-r.p};}}
            else throw 4;}}
    if((int)q.size()!=n)throw 5;
    return (int)an;
}
