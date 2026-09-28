//traidepluyenthuattoan - hngocuyen - [86]>> solutions
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;vector<vector<pair<int,int>>> G;vector<int> E,ea,sa;vector<ll> C;
ll cc(int s){auto&g=G[s];ll r=0;for(size_t i=0;i<g.size();i++){ll a=g[i].first,b=(i+1<g.size()?g[i+1].first:E[s])-1;r+=(ll)g[i].second*(b-a+1)-(a+b)*(b-a+1)/2;}return r;}
bool lv(int s){return G[s].size()>1||G[s][0].second!=E[s];}
int main(){
    scanf("%d",&n);vector<int> a(n);for(auto&x:a)scanf("%d",&x);
    vector<int> o(n);iota(o.begin(),o.end(),0);sort(o.begin(),o.end(),[&](int x,int y){return a[x]<a[y];});
    G.assign(n+1,{});E.assign(n+1,0);C.assign(n+1,0);ea.assign(n+2,-1);sa.assign(n+2,-1);
    ll T=(ll)n*(n+1)/2,c=0,s=0;int v=a[o[0]],p=0;s=(ll)v*T;
    set<int> L;
    while(1){
        vector<int> rm;
        for(int b:L){auto&g=G[b];int k=g.size(),j=0;vector<pair<int,int>> h;
            for(int i=0;i<k;i++){int r=g[i].second,q;if(r==E[b])q=r;else{while(j+1<k&&g[j+1].first<=r)j++;q=g[j].second;}
                if(!h.empty()&&h.back().second==q)continue;h.push_back({g[i].first,q});}
            g.swap(h);c-=C[b];C[b]=cc(b);c+=C[b];if(!lv(b))rm.push_back(b);}
        for(int b:rm)L.erase(b);
        while(p<n&&a[o[p]]==v){int x=o[p++];int b=x;G[b]={{x,x+1}};E[b]=x+1;C[b]=1;c+=1;
            if(ea[x]>=0){int l=ea[x];ea[x]=-1;sa[x]=-1;L.erase(l);for(auto&z:G[b])G[l].push_back(z);vector<pair<int,int>>().swap(G[b]);E[l]=E[b];C[l]+=C[b];b=l;}
            if(sa[x+1]>=0){int r=sa[x+1];sa[x+1]=-1;ea[E[b]]=-1;L.erase(r);for(auto&z:G[r])G[b].push_back(z);vector<pair<int,int>>().swap(G[r]);E[b]=E[r];C[b]+=C[r];}
            sa[b]=b;ea[E[b]]=b;if(lv(b))L.insert(b);}
        s+=T-c;if(c==T)break;
        if(L.empty()){int w=a[o[p]];s+=(ll)(w-v-1)*(T-c);v=w;}else v++;
    }
    printf("%lld\n",s);
}
