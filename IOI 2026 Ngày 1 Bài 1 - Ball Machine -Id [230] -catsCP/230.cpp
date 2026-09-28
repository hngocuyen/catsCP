//traidepluyenthuattoan - hngocuyen - [230]>> solutions
#include "ballmachine.h"
#include <bits/stdc++.h>
using namespace std;
struct A{int x=-1,p=-1,q=-1;vector<int>d;};
vector<int> find_structure(int m){
    vector<int>l(m),f(m,-1),g(m,-1);
    int n=0;
    for(int i=0;i<m;i++){
        while(insert(i,0))l[i]++;
        n+=l[i];
    }
    collect();
    for(int i=0;i<m;i++){
        if(l[i]==1)insert(i,0);
        else{
            insert(i,i/10+1);
            for(int j=2;j<l[i];j++)insert(i,31);
            insert(i,21+i%10);
        }
    }
    vector<int>s=collect();
    vector<A>a;
    int z=0;
    function<int(int,int)>h=[&](int p,int q){
        int r=a.size();
        a.push_back(A());
        a[r].p=p;
        a[r].q=q;
        int v=s[z++],x=v-1,y=0;
        while(1){
            int c=0;
            while(z<(int)s.size()&&s[z]<=20){
                c++;
                if(s[z]==0)z++;
                else h(r,y);
            }
            a[r].d.push_back(c);
            v=s[z++];
            y++;
            if(v>=21&&v<=30){
                a[r].x=x*10+v-21;
                a[r].d.push_back(0);
                break;
            }
        }
        return r;
    };
    h(-1,-1);
    vector<int>b(m,-1);
    vector<vector<int>>d(m);
    for(int i=0;i<(int)a.size();i++)b[a[i].x]=i;
    for(int i=0;i<(int)a.size();i++){
        int x=a[i].x;
        d[x]=a[i].d;
        if(a[i].p>=0){
            f[x]=a[a[i].p].x;
            g[x]=a[i].q;
        }
    }
    for(int t=0;t<m;t+=20){
        bool e=0;
        for(int i=t;i<min(m,t+20);i++)if(l[i]==1)e=1;
        if(!e)continue;
        for(int i=0;i<m;i++){
            if(l[i]==1)insert(i,i>=t&&i<t+20?i-t+10:30);
            else{
                insert(i,10+i/10);
                for(int j=1;j<l[i];j++)insert(i,i%10);
            }
        }
        s=collect();
        z=0;
        function<void(int,int)>u;
        function<void(int,int)>v=[&](int p,int q){
            int x=s[z];
            if(z+1==(int)s.size()||s[z+1]>=10){
                z++;
                if(x!=30){
                    int y=t+x-10;
                    if(y<m&&l[y]==1){
                        f[y]=p;
                        g[y]=q;
                    }
                }
            }else{
                int y=(x-10)*10+s[z+1];
                u(y,0);
            }
        };
        u=[&](int x,int p){
            z++;
            if(p+1<l[x])u(x,p+1);
            for(int i=0;i<d[x][p];i++)v(x,p);
        };
        u(0,0);
    }
    vector<vector<int>>q(m);
    int c=m;
    for(int i=0;i<m;i++){
        q[i].resize(l[i]);
        for(int j=0;j<l[i]-1;j++){
            if(i==0&&j==0)q[i][j]=n-1;
            else q[i][j]=c++;
        }
        q[i][l[i]-1]=i;
    }
    vector<int>r(n-1);
    for(int i=0;i<m;i++){
        if(i)r[q[i][0]]=q[f[i]][g[i]];
        for(int j=1;j<l[i];j++)r[q[i][j]]=q[i][j-1];
    }
    return r;
}
