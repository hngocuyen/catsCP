//traidepluyenthuattoan - hngocuyen - [117]>> solutions
#include <bits/stdc++.h>
using namespace std;
typedef long long L;
const L M=998244353;
L pw(L a,L e){L r=1;a%=M;if(a<0)a+=M;while(e){if(e&1)r=r*a%M;a=a*a%M;e>>=1;}return r;}
typedef unsigned U;
vector<U> R;
void ntt(vector<L>&A,bool iv){
    int n=A.size();
    if((int)R.size()<n){R.assign(n,0);for(int l=1;l<n;l<<=1){L w=pw(3,(M-1)/(2*l));L x=1;for(int j=0;j<l;j++){R[l+j]=x;x=x*w%M;}}}
    vector<U> a(A.begin(),A.end());
    for(int i=1,j=0;i<n;i++){int b=n>>1;for(;j&b;b>>=1)j^=b;j^=b;if(i<j)swap(a[i],a[j]);}
    for(int l=1;l<n;l<<=1)for(int i=0;i<n;i+=2*l)for(int j=0;j<l;j++){U u=a[i+j],v=(unsigned long long)a[i+j+l]*R[l+j]%M;a[i+j]=u+v>=M?u+v-M:u+v;a[i+j+l]=u>=v?u-v:u+M-v;}
    if(iv){reverse(a.begin()+1,a.end());L z=pw(n,M-2);for(int i=0;i<n;i++)A[i]=a[i]*z%M;}
    else for(int i=0;i<n;i++)A[i]=a[i];
}
vector<L> mul(vector<L> a,vector<L> b,int k){
    int s=1;while(s<(int)(a.size()+b.size()))s<<=1;
    a.resize(s);b.resize(s);ntt(a,0);ntt(b,0);
    for(int i=0;i<s;i++)a[i]=a[i]*b[i]%M;
    ntt(a,1);a.resize(k);return a;
}
vector<L> inv(const vector<L>&a,int k){
    vector<L> b={pw(a[0],M-2)};
    int c=1;
    while(c<k){
        c<<=1;
        vector<L> f(a.begin(),a.begin()+min((int)a.size(),c));
        vector<L> t=mul(f,b,c);
        for(auto&x:t)x=(M-x)%M;
        t[0]=(t[0]+2)%M;
        b=mul(b,t,c);
    }
    b.resize(k);return b;
}
void S(L m,int n,vector<L>&p){
    if(m<0)return;
    int d=m%2;
    L c=d?(m+1)/2%M:1;
    L N=(m+d)/2;
    for(;d<=n;d+=2){
        if(d>m)break;
        L k=(m-d)/2;
        p[d]=(p[d]+(k%2?M-c:c))%M;
        c=c*((N+1)%M)%M*((N-d)%M)%M*pw((L)(d+1)*(d+2)%M,M-2)%M;
        N++;
    }
}
int main(){
    int t;scanf("%d",&t);
    while(t--){
        L n,m;scanf("%lld %lld",&n,&m);
        vector<L> p(n+1,0);
        S(m,n,p);S(m-1,n,p);
        vector<L> d(n,0);
        for(int i=1;i<=n;i++)d[i-1]=p[i]*i%M;
        vector<L> q=inv(p,n);
        L a=0;
        for(int i=0;i<n;i++)a=(a+d[i]*q[n-1-i])%M;
        a=(M-a)%M;
        if(m%2&&n%2)a=(M-a)%M;
        printf("%lld\n",a);
    }
}
