//traidepluyenthuattoan - hngocuyen - [233]>> solutions
#include <bits/stdc++.h>
using namespace std;
long long setN(int);
vector<pair<int,int>> Alice(){
    long long x=setN(5000)-1,c[11]{};
    for(int i=0;i<11;i++){c[i]=x%61;x/=61;}
    vector<pair<int,int>> e;
    for(int i=2;i<=61;i++)e.push_back({1,i});
    for(int i=0;i<4939;i++){
        long long z=i%60,y=0,p=1;
        for(int j=0;j<11;j++){y=(y+c[j]*p)%61;p=p*z%61;}
        e.push_back({62+i,1+(int)y});
    }
    return e;
}
long long Bob(vector<pair<int,int>> v){
    int y[60],h[60]{};
    for(auto e:v){
        int a=e.first,b=e.second;
        if(a>b)swap(a,b);
        if(a<=61&&b>=62){int x=(b-62)%60;y[x]=a-1;h[x]=1;}
    }
    vector<int>x,z;
    for(int i=0;i<60&&x.size()<11;i++)if(h[i])x.push_back(i),z.push_back(y[i]);
    long long c[11]{};
    auto pw=[](long long a,int b){long long r=1;while(b){if(b&1)r=r*a%61;a=a*a%61;b>>=1;}return r;};
    for(int i=0;i<11;i++){
        long long q[12]{};q[0]=1;int d=0;long long w=1;
        for(int j=0;j<11;j++)if(i!=j){
            for(int k=d+1;k>=1;k--)q[k]=(q[k-1]-q[k]*x[j])%61;
            q[0]=-q[0]*x[j]%61;d++;w=w*(x[i]-x[j])%61;
        }
        w=(w%61+61)%61;w=z[i]*pw(w,59)%61;
        for(int k=0;k<11;k++)c[k]=(c[k]+q[k]*w)%61;
    }
    __int128 r=0,p=1;
    for(int i=0;i<11;i++){c[i]=(c[i]%61+61)%61;r+=p*c[i];p*=61;}
    return (long long)r+1;
}
