//traidepluyenthuattoan - hngocuyen - [107]>> solutions
#include <bits/stdc++.h>
using namespace std;
typedef long long L;
typedef unsigned long long U;
L sq(L x){L r=sqrtl((long double)x);while(r*r>x)r--;while((r+1)*(r+1)<=x)r++;return r;}
U F(L A,L B,L N){
    U r=0;bool u=N<min(A,B);
    for(L s=2;A/s+B/s>=s;s++){
        L a=A/s,b=B/s;
        if(s*s*s<=A+B){
            for(L p=max(1LL,s-b),h=min(s-1,a);p<=h;p++){
                L v=min(a/p,b/(s-p));
                if(u)v=min(v,N/(p*(s-p)));
                r+=v;
            }
        }else{
            for(L m=1;;m++){
                L x=a/m,y=b/m;
                if(x+y<s)break;
                L l=max(1LL,s-y),h=min(s-1,x);
                if(l>h)continue;
                if(u){
                    L T=N/m;
                    if(4*T<s*s){
                        L k=(s-sq(s*s-4*T))/2;
                        while(k+1<=s/2&&(k+1)*(s-k-1)<=T)k++;
                        while(k>0&&k*(s-k)>T)k--;
                        L c=0,e=min(h,k),f=max(l,s-k);
                        if(e>=l)c+=e-l+1;
                        if(h>=f)c+=h-f+1;
                        r+=c;continue;
                    }
                }
                r+=h-l+1;
            }
        }
    }
    return r;
}
int main(){
    L n,a,b;cin>>n>>a>>b;
    L m=sq(max(a,b));
    vector<int> w(m+2,1),p;vector<char> c(m+2,0);
    for(L i=2;i<=m;i++){if(!c[i]){p.push_back(i);w[i]=-1;}for(int x:p){if(i*x>m)break;c[i*x]=1;if(i%x==0){w[i*x]=0;break;}w[i*x]=-w[i];}}
    U r=0;
    for(L d=1;d*d<=max(a,b);d++)if(w[d]){U f=F(a/(d*d),b/(d*d),n/(d*d));if(w[d]>0)r+=f;else r-=f;}
    cout<<r<<endl;
}
