//traidepluyenthuattoan - hngocuyen - [20]>> solutions
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int P[300005],G[300005],O;
ll C[300005];
priority_queue<ll> H[300005];
static char B[1<<25];
ll r(){while(B[O]<48)O++;ll x=0;while(B[O]>=48)x=x*10+B[O++]-48;return x;}
int main(){
    fread(B,1,sizeof B,stdin);
    int n=r(),m=r(),t=n+m;
    ll s=0;
    for(int i=2;i<=t;i++){P[i]=r();C[i]=r();G[P[i]]++;s+=C[i];}
    for(int i=t;i>=1;i--){
        auto&u=H[i];
        if(i>n){u.push(C[i]);u.push(C[i]);}
        else{
            int k=i==1?G[i]:G[i]-1;
            for(int j=0;j<k;j++)u.pop();
            if(i!=1){
                ll x=u.top();u.pop();
                ll y=u.top();u.pop();
                u.push(x+C[i]);u.push(y+C[i]);
            }
        }
        if(i==1){
            while(!u.empty()){s-=u.top();u.pop();}
            printf("%lld\n",s);
        }else{
            auto&v=H[P[i]];
            if(v.size()<u.size())swap(u,v);
            while(!u.empty()){v.push(u.top());u.pop();}
            priority_queue<ll>().swap(u);
        }
    }
}
