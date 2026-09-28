//traidepluyenthuattoan - hngocuyen - [120]>> solutions
#include "magiccity.h"
#include <bits/stdc++.h>
using namespace std;
pair<vector<int>,vector<pair<int,int>>> construct(int K){
    if(K==1)return {{0,1},{{0,1}}};
    int v=2*K-1,n=2*K;
    vector<vector<int>> B;
    vector<int> o;
    if(K==2)B={{0,1},{0,2},{1,2}};
    else if(K==3)B={{0,1,2},{0,3,4},{1,3,4},{2,3,4}},o={1};
    else if(K==4)B={{0,1,3,4},{1,4,5,6},{0,3,5,6},{2,3,4,5},{0,1,2,6}},o={1,2,3};
    else if(K==5)B={{0,4,5,6,8},{3,4,5,7,8},{0,1,3,6,7},{0,2,3,6,7},{1,2,4,5,8}},o={1,2,3,5};
    else{
        vector<vector<int>> g(4);
        for(int i=0;i<v;i++)g[i%4].push_back(i);
        for(int i=0;i<4;i++)for(int j=i+1;j<4;j++){vector<int> b=g[i];b.insert(b.end(),g[j].begin(),g[j].end());B.push_back(b);}
    }
    int b=B.size();
    vector<int> m(v,0);
    for(auto&x:B)for(int y:x)m[y]++;
    int h=*max_element(m.begin(),m.end());
    vector<int> T(n*b);
    vector<vector<int>> F(n,vector<int>(v));
    for(int t=0;t<n;t++){
        vector<int> a,c;
        vector<char> w(n,0);
        if(o.empty())for(int u=0;u<n;u++)w[u]=u!=t;
        else for(int d:o){w[(t+d)%n]=1;w[(t-d+n)%n]=1;}
        for(int u=0;u<n;u++)if(u!=t)(w[u]?a:c).push_back(u);
        int x=0,y=0;
        for(int p=0;p<v;p++)F[t][p]=m[p]==h?a[x++]:c[y++];
        for(int i=0;i<b;i++)T[t*b+i]=t;
    }
    vector<vector<vector<int>>> L(n,vector<vector<int>>(n));
    for(int t=0;t<n;t++)for(int i=0;i<b;i++)for(int p:B[i])L[t][F[t][p]].push_back(t*b+i);
    vector<pair<int,int>> E;
    for(int t=0;t<n;t++)for(int u=t+1;u<n;u++)for(size_t i=0;i<L[t][u].size();i++)E.push_back({L[t][u][i],L[u][t][i]});
    return {T,E};
}
