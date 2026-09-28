//traidepluyenthuattoan - hngocuyen - [87]>> solutions
#include <bits/stdc++.h>
using namespace std;
typedef long long L;
typedef __int128 W;
int n;
vector<L> p;
W fl(W a,W b){if(b<0)a=-a,b=-b;W q=a/b;if(q*b>a)q--;return q;}
W ce(W a,W b){return -fl(-a,b);}
bool ok(W s){
    W lo=0,hi=s;
    for(int i=0;i<n;i++){
        W d=2*i-n+1,r=(W)p[i]-s*(n-1-i);
        if(d>0)lo=max(lo,ce(r,d));
        else if(d<0)hi=min(hi,fl(r,d));
        else if(r>0)return 0;
    }
    return lo<=hi;
}
vector<W> K;vector<L> Z;vector<int> T;
vector<W> BN;vector<L> BD;
int dr;
W vn(int i,int x){return dr>0?K[i]-i+x:K[i]+i-x;}
bool lt(int i,int j,int x){return vn(i,x)*Z[j]<vn(j,x)*Z[i];}
void ins(int v,int l,int r,int i){
    if(T[v]<0){T[v]=i;return;}
    int m=(l+r)/2;
    if(lt(i,T[v],m))swap(i,T[v]);
    if(l==r)return;
    if(lt(i,T[v],l))ins(2*v,l,m,i);
    else if(lt(i,T[v],r))ins(2*v+1,m+1,r,i);
}
void qr(int v,int l,int r,int x,W&a,L&b){
    if(T[v]<0)return;
    W c=vn(T[v],x);
    if(b==0||c*b<a*Z[T[v]])a=c,b=Z[T[v]];
    if(l==r)return;
    int m=(l+r)/2;
    if(x<=m)qr(2*v,l,m,x,a,b);else qr(2*v+1,m+1,r,x,a,b);
}
vector<W> mv(vector<int>&u){
    vector<W> R(n);
    vector<W> an(n);vector<L> bd(n,0);
    vector<char> in(n,0);
    for(int i:u)in[i]=1;
    for(int e=0;e<2;e++){
        dr=e?-1:1;
        T.assign(4*n,-1);
        for(int k=0;k<n;k++){
            int x=e?n-1-k:k;
            if(in[x])ins(1,0,n-1,x);
            W a=0;L b=0;
            qr(1,0,n-1,x,a,b);
            if(b&&(bd[x]==0||a*bd[x]<an[x]*b))an[x]=a,bd[x]=b;
        }
    }
    W I=(W)1<<120;
    for(int x=0;x<n;x++)R[x]=bd[x]?fl(an[x],bd[x]):I;
    return R;
}
int main(){
    int t;scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        p.assign(n,0);
        for(auto&x:p)scanf("%lld",&x);
        L mx=*max_element(p.begin(),p.end());
        W lo=0,hi=2*((mx+n-2)/(n-1))+2;
        while(lo<hi){W m=(lo+hi)/2;if(ok(m))hi=m;else lo=m+1;}
        W S=lo,A=S;
        if(S>=2){
            W s=S-2;
            K.assign(n,0);Z.assign(n,1);
            vector<int> u1,u2;
            int md=-1;W mr=0;
            for(int i=0;i<n;i++){
                W d=2*i-n+1;
                if(d<0)K[i]=s*(n-1-i)-p[i],Z[i]=-d,u1.push_back(i);
                else if(d>0)K[i]=s*(n-1-i)-p[i],Z[i]=d,u2.push_back(i);
                else md=i,mr=(W)p[i]-s*(n-1-i);
            }
            vector<W> U=mv(u1),V=mv(u2);
            for(int x=0;x<n;x++){
                W h=min(s,U[x]),l=max((W)0,-V[x]);
                if(md>=0&&abs(md-x)<mr)continue;
                if(l<=h){A=S-1;break;}
            }
        }
        printf("%lld\n",(L)A);
    }
}
