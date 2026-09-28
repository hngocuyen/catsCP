//traidepluyenthuattoan - hngocuyen - [24]>> solutions
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;ll w,h,X[100005],Y[100005],T[100005];int D[100005],P[600005],Q[600005];
int F[6]={0,3,0,3,0,1},G[6]={2,1,1,2,3,2};
vector<int> K[4],A,B;
priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> E;
void z(int g,int a,int b){
    if(D[a]!=F[g]||D[b]!=G[g])return;
    ll t=g==0?X[b]-X[a]:g==1?Y[b]-Y[a]:2*(X[b]-X[a]);
    A.push_back(a);B.push_back(b);E.push({t,(int)A.size()-1});
}
vector<array<ll,3>> m(vector<array<ll,3>> L){
    sort(L.begin(),L.end());
    vector<array<ll,3>> O;
    for(auto&v:L){
        if(O.size()&&O.back()[0]==v[0]&&v[1]<=O.back()[2]+1)O.back()[2]=max(O.back()[2],v[2]);
        else O.push_back(v);
    }
    return O;
}
int main(){
    scanf("%lld %lld %d",&w,&h,&n);
    for(int i=0;i<n;i++)scanf("%lld %lld %d",&X[i],&Y[i],&D[i]);
    memset(P,-1,sizeof P);memset(Q,-1,sizeof Q);
    vector<ll> C(n),O(n);
    for(int g=0;g<6;g++){
        K[F[g]].push_back(g);K[G[g]].push_back(g);
        vector<int> L;
        for(int i=0;i<n;i++)if(D[i]==F[g]||D[i]==G[g])L.push_back(i);
        for(int i=0;i<n;i++){C[i]=g==0?Y[i]:g==1?X[i]:g<4?X[i]-Y[i]:X[i]+Y[i];O[i]=g==1?Y[i]:X[i];}
        sort(L.begin(),L.end(),[&](int a,int b){return C[a]!=C[b]?C[a]<C[b]:O[a]<O[b];});
        for(size_t j=0;j+1<L.size();j++){
            int a=L[j],b=L[j+1];
            if(C[a]==C[b]){Q[g*n+a]=b;P[g*n+b]=a;z(g,a,b);}
        }
    }
    const ll I=1LL<<62;
    for(int i=0;i<n;i++)T[i]=I;
    while(!E.empty()){
        ll t=E.top().first;
        vector<int> J,U;
        while(!E.empty()&&E.top().first==t){J.push_back(E.top().second);E.pop();}
        for(int j:J){
            int a=A[j],b=B[j];
            if(T[a]>=t&&T[b]>=t){
                if(T[a]==I){T[a]=t;U.push_back(a);}
                if(T[b]==I){T[b]=t;U.push_back(b);}
            }
        }
        for(int c:U)for(int g:K[D[c]]){
            int p=P[g*n+c],q=Q[g*n+c];
            if(p>=0)Q[g*n+p]=q;
            if(q>=0)P[g*n+q]=p;
            if(p>=0&&q>=0&&T[p]==I&&T[q]==I)z(g,p,q);
        }
    }
    vector<array<ll,3>> R,V;
    for(int i=0;i<n;i++){
        ll f=T[i]/2;int d=D[i];
        if(d==0)R.push_back({Y[i],X[i],min(w,X[i]+f)});
        else if(d==2)R.push_back({Y[i],max(1LL,X[i]-f),X[i]});
        else if(d==1)V.push_back({X[i],max(1LL,Y[i]-f),Y[i]});
        else V.push_back({X[i],Y[i],min(h,Y[i]+f)});
    }
    R=m(R);V=m(V);
    ll s=0;
    for(auto&v:R)s+=v[2]-v[1]+1;
    for(auto&v:V)s+=v[2]-v[1]+1;
    vector<ll> Uy;
    for(auto&v:R)Uy.push_back(v[0]);
    sort(Uy.begin(),Uy.end());Uy.erase(unique(Uy.begin(),Uy.end()),Uy.end());
    int k=Uy.size();
    vector<ll> N(k+1,0);
    vector<array<ll,3>> Z;
    for(auto&v:R){
        ll j=lower_bound(Uy.begin(),Uy.end(),v[0])-Uy.begin()+1;
        Z.push_back({v[1],j,1});Z.push_back({v[2]+1,j,-1});
    }
    sort(Z.begin(),Z.end());
    size_t j=0;
    for(auto&v:V){
        while(j<Z.size()&&Z[j][0]<=v[0]){
            for(ll o=Z[j][1];o<=k;o+=o&-o)N[o]+=Z[j][2];
            j++;
        }
        ll a=upper_bound(Uy.begin(),Uy.end(),v[2])-Uy.begin(),b=lower_bound(Uy.begin(),Uy.end(),v[1])-Uy.begin();
        for(;a>0;a-=a&-a)s-=N[a];
        for(;b>0;b-=b&-b)s+=N[b];
    }
    printf("%lld\n",s);
}
