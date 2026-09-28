//traidepluyenthuattoan - hngocuyen - [67]>> solutions
#include <bits/stdc++.h>
using namespace std;
typedef long long L;typedef unsigned long long U;
const L P=1000000007;
int n,T;L M,K;vector<L> p,q,c,v0[2];vector<int> tt[2],ek,ed,ez;vector<L> an;
vector<vector<U>> B;
L pw(L a,L e){L r=1;a%=P;while(e){if(e&1)r=r*a%P;a=a*a%P;e>>=1;}return r;}
L fl(L a,L b){L d=a/b;if((a%b!=0)&&((a<0)!=(b<0)))d--;return d;}
void ap(int k,int l,int dp,L&o,L&s){
    L a=(v0[0][k]+(tt[0][k]<l))%n,b=(v0[1][k]+(tt[1][k]<l))%n;
    if(p[k]==0){o=(o+a)%n;return;}
    if(q[k]==0){o=(o+b)%n;return;}
    int t=(b-a+n)%n;U*x=B[dp].data();static vector<U> y;y.assign(x,x+n);U w=c[k];
    for(int u=0;u<t;u++)x[u]=(y[u]+w*y[u-t+n])%P;
    for(int u=t;u<n;u++)x[u]=(y[u]+w*y[u-t])%P;
    s=s*q[k]%P;o=(o+a)%n;
}
void go(int l,int r,int dp,vector<int>&A,L o,L s){
    if(r-l==1){
        int k=ek[l],d=ed[l];L w=(n-v0[d][k]%n)%n;L z=(w-o+n)%n;
        an[ez[l]]=(an[ez[l]]+B[dp][z]*s%P*(d?p[k]:q[k]))%P;return;
    }
    int m=(l+r)/2;
    for(int h=0;h<2;h++){
        int a=h?m:l,b=h?r:m;
        copy(B[dp].begin(),B[dp].begin()+n,B[dp+1].begin());
        vector<int> C;L oo=o,ss=s;
        for(int k:A){
            bool in=(tt[0][k]>=a&&tt[0][k]<b)||(tt[1][k]>=a&&tt[1][k]<b);
            if(in)C.push_back(k);else ap(k,a,dp+1,oo,ss);
        }
        go(a,b,dp+1,C,oo,ss);
    }
}
int main(){
    int t;scanf("%d",&t);
    while(t--){
        scanf("%d %lld %lld",&n,&M,&K);
        p.assign(n,0);q.assign(n,0);c.assign(n,0);
        for(int i=0;i<n;i++){scanf("%lld",&p[i]);q[i]=(1-p[i]+P)%P;if(q[i])c[i]=p[i]*pw(q[i],P-2)%P;}
        vector<L> x(n);for(auto&e:x)scanf("%lld",&e);
        vector<array<L,3>> E;
        for(int d=0;d<2;d++){v0[d].assign(n,0);tt[d].assign(n,0);}
        for(int i=0;i<n;i++){
            L e1=x[i]-K,e2=x[i]+K;
            L f1=fl(e1,M),f2=fl(e2,M);
            v0[0][i]=((-f1)%n+n)%n;v0[1][i]=((-f2)%n+n)%n;
            E.push_back({e1-f1*M,i,0});E.push_back({e2-f2*M,i,1});
        }
        sort(E.begin(),E.end());
        int m=2*n;ek.assign(m,0);ed.assign(m,0);ez.assign(m,0);
        for(int i=0;i<m;i++){ez[i]=E[i][0];ek[i]=E[i][1];ed[i]=E[i][2];tt[ed[i]][ek[i]]=i;}
        int D=2;while((1<<(D-2))<m)D++;
        B.assign(D+2,vector<U>(n,0));B[0][0]=1;
        an.assign(M,0);
        vector<int> A(n);iota(A.begin(),A.end(),0);
        go(0,m,0,A,0,1);
        string S;S.reserve(M*11);char bf[24];
        for(L i=0;i<M;i++){int len=snprintf(bf,24,"%lld",an[i]);S.append(bf,len);S.push_back(i+1<M?' ':'\n');}
        fputs(S.c_str(),stdout);
    }
}
