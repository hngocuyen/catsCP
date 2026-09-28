//traidepluyenthuattoan - hngocuyen - [138]>> solutions
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;const ll P=1e9+7;const int K=17;
int pr[K]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59};
struct V{int e[K];};
V fc(int x){V v;for(int i=0;i<K;i++){v.e[i]=0;while(x%pr[i]==0){x/=pr[i];v.e[i]++;}}return v;}
ll pw(ll b,ll e){ll r=1;b%=P;while(e){if(e&1)r=r*b%P;b=b*b%P;e>>=1;}return r;}
ll pm(ll b,ll e,ll m){ll r=1%m;b%=m;while(e){if(e&1)r=r*b%m;b=b*b%m;e>>=1;}return r;}
int main(){
    vector<int> tk;int x;while(scanf("%d",&x)==1)tk.push_back(x);
    size_t p=0;vector<int> L,R,cl,cr;vector<int> st,fl;
    auto nw=[&](int a,int b){L.push_back(a);R.push_back(b);cl.push_back(-1);cr.push_back(-1);return (int)L.size()-1;};
    int rt=-1;
    auto att=[&](int v){if(st.empty()){rt=v;return;}int u=st.back();if(cl[u]<0)cl[u]=v;else{cr[u]=v;}};
    while(1){
        int t=tk[p++];int v;
        if(t==0){v=nw(0,0);att(v);}
        else{int r=tk[p++];v=nw(t,r);att(v);st.push_back(v);continue;}
        while(!st.empty()&&cr[st.back()]>=0){st.pop_back();}
        if(st.empty())break;
    }
    int n=L.size();vector<V> W(n),X(n),Y(n);
    vector<int> ord;{vector<int> s={rt};while(!s.empty()){int u=s.back();s.pop_back();ord.push_back(u);if(L[u]){s.push_back(cl[u]);s.push_back(cr[u]);}}}
    for(int k=n-1;k>=0;k--){int u=ord[k];if(!L[u]){for(int i=0;i<K;i++)W[u].e[i]=0;continue;}
        V a=fc(L[u]),b=fc(R[u]),c=fc(L[u]+R[u]);V&wl=W[cl[u]],&wr=W[cr[u]];
        for(int i=0;i<K;i++){int t=max(wl.e[i]+a.e[i],wr.e[i]+b.e[i]);X[u].e[i]=t-wl.e[i]-a.e[i];Y[u].e[i]=t-wr.e[i]-b.e[i];W[u].e[i]=t+c.e[i]-a.e[i]-b.e[i];}}
    int m=tk[p++];set<int> br;for(int i=0;i<m;i++)br.insert(tk[p++]);
    vector<V> A;{vector<pair<int,V>> s;V z;for(int i=0;i<K;i++)z.e[i]=0;s.push_back({rt,z});
        while(!s.empty()){auto [u,v]=s.back();s.pop_back();if(!L[u]){A.push_back(v);continue;}V a=v,b=v;for(int i=0;i<K;i++){a.e[i]+=X[u].e[i];b.e[i]+=Y[u].e[i];}s.push_back({cr[u],b});s.push_back({cl[u],a});}}
    ll ans=1;
    for(int h:br){V&v=A[h-1];vector<int> q;for(int i=0;i<K;i++)if(v.e[i])q.push_back(i);
        int z=q.size();ll f=0;vector<ll> G(z),H(z);
        for(int j=0;j<z;j++){G[j]=pm(pr[q[j]],v.e[q[j]],P-1);H[j]=pm(pr[q[j]],v.e[q[j]]-1,P-1);}
        function<void(int,ll,int)> go=[&](int j,ll r,int c){if(j==z){ll t=pw(2,(r-1+(P-1))%(P-1));f=(f+(c&1?P-t:t))%P;return;}go(j+1,r*G[j]%(P-1),c);go(j+1,r*H[j]%(P-1),c+1);};
        go(0,1,0);
        ans=ans*f%P;}
    printf("%lld\n",ans);
}
