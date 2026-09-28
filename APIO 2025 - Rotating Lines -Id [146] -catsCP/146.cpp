//traidepluyenthuattoan - hngocuyen - [146]>> solutions
#include "rotate.h"
#include <bits/stdc++.h>
using namespace std;
void energy(int n,vector<int> v){vector<int> o(n);iota(o.begin(),o.end(),0);sort(o.begin(),o.end(),[&](int a,int b){return v[a]<v[b];});int h=n/2;for(int i=0;i<h;i++){int a=o[i],b=o[i+h];int x=((v[b]+25000-v[a])%50000+50000)%50000;if(x)rotate({a},x);}}
