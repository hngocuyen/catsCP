//traidepluyenthuattoan - hngocuyen - [91]>> solutions
#include <bits/stdc++.h>
using namespace std;
typedef long long L;
int main(){
    int t;scanf("%d",&t);
    while(t--){
        int n,m;scanf("%d %d",&n,&m);
        vector<vector<int>> g(n+1);
        for(int i=0;i<m;i++){int x,y;scanf("%d %d",&x,&y);g[x].push_back(y);if(x!=y)g[y].push_back(x);}
        const int I=INT_MAX;
        vector<array<int,2>> d(n+1,{I,I});
        deque<pair<int,int>> q;
        d[1][0]=0;q.push_back({1,0});
        while(!q.empty()){
            auto [v,p]=q.front();q.pop_front();
            for(int u:g[v])if(d[u][p^1]==I){d[u][p^1]=d[v][p]+1;q.push_back({u,p^1});}
        }
        if(d[1][1]==I){printf("%d\n",n-1);continue;}
        map<pair<int,int>,int> c,r;
        for(int v=1;v<=n;v++){int x=min(d[v][0],d[v][1]),y=max(d[v][0],d[v][1]);c[{x,y}]++;}
        vector<pair<int,int>> k;
        for(auto&e:c)k.push_back(e.first);
        sort(k.begin(),k.end(),[](const pair<int,int>&a,const pair<int,int>&b){int s=a.first+a.second,h=b.first+b.second;return s!=h?s<h:a.first<b.first;});
        auto H=[&](int x,int y){return c.count({x,y})>0;};
        L a=0;
        for(auto [x,y]:k){
            int z=c[{x,y}];
            bool sp=(y==x+1);
            if(x==0){r[{x,y}]=1;if(sp)a+=1;continue;}
            int pd=H(x-1,y+1)?r[{x-1,y+1}]:0;
            int w=H(x-1,y-1)?min(pd,z):z;
            if(!sp&&!H(x+1,y-1))w=0;
            a+=(z-w)+max(pd,w)+(sp?(w+1)/2:0);
            r[{x,y}]=w;
        }
        printf("%lld\n",a);
    }
}
