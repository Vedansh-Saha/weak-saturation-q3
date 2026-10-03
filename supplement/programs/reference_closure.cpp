#include <bits/stdc++.h>
using namespace std;
using U=uint64_t;
struct Edge{int a,b;};
static int pc(U x){return __builtin_popcountll(x);}

int main(int argc,char**argv){
    if(argc!=3){cerr<<"usage: reference_closure n reps_file\n";return 2;}
    int n=stoi(argv[1]); string path=argv[2];
    int totalE=n*(n-1)/2; vector<Edge>E; int eid[12][12]; memset(eid,-1,sizeof(eid));
    for(int a=0,k=0;a<n;a++)for(int b=a+1;b<n;b++){eid[a][b]=k++;E.push_back({a,b});}
    vector<Edge> q;for(int v=0;v<8;v++)for(int bit:{1,2,4}){int w=v^bit;if(v<w)q.push_back({v,w});}
    U core=0;for(auto [a,b]:q)core|=1ULL<<eid[a][b];
    vector<int> outs;int oi[66];fill(oi,oi+66,-1);for(int e=0;e<totalE;e++)if(!(core>>e&1)){oi[e]=outs.size();outs.push_back(e);}int m=outs.size();
    vector<Edge> local;int leid[8][8];memset(leid,-1,sizeof(leid));for(int a=0,k=0;a<8;a++)for(int b=a+1;b<8;b++){leid[a][b]=k++;local.push_back({a,b});}
    unordered_set<U> base;base.reserve(1000);vector<int> p(8);iota(p.begin(),p.end(),0);do{U x=0;for(auto[a,b]:q){int u=min(p[a],p[b]),v=max(p[a],p[b]);x|=1ULL<<leid[u][v];}base.insert(x);}while(next_permutation(p.begin(),p.end()));
    unordered_set<U> masks;masks.reserve(150000);
    for(int sm=0;sm<(1<<n);sm++)if(pc((U)sm)==8){vector<int>S;for(int i=0;i<n;i++)if(sm>>i&1)S.push_back(i);for(U bm:base){U om=0;for(auto[a,b]:local)if(bm>>leid[a][b]&1){int u=min(S[a],S[b]),v=max(S[a],S[b]);int e=eid[u][v];if(oi[e]>=0)om|=1ULL<<oi[e];}masks.insert(om);}}
    vector<vector<int>> rev(m);vector<int> need,target;
    size_t ruleCount=0;for(U om:masks){vector<int>b;U x=om;while(x){int i=__builtin_ctzll(x);b.push_back(i);x&=x-1;}for(int t:b){int r=need.size();need.push_back((int)b.size()-1);target.push_back(t);for(int f:b)if(f!=t)rev[f].push_back(r);}}
    ifstream in(path,ios::binary);if(!in){cerr<<"cannot open reps file\n";return 2;}uint64_t nr=0;in.read((char*)&nr,sizeof(nr));vector<U> reps(nr);in.read((char*)reps.data(),reps.size()*sizeof(U));if(!in){cerr<<"invalid reps file\n";return 2;}
    vector<int> state(m),rstamp(need.size()),cnt(need.size());int stamp=0;int maxc=0;uint64_t full=0;map<int,uint64_t> hist;
    auto closure=[&](U seed){++stamp;vector<int>qv;qv.reserve(m);U x=seed;int sz=0;while(x){int i=__builtin_ctzll(x);x&=x-1;if(state[i]!=stamp){state[i]=stamp;qv.push_back(i);sz++;}}for(size_t h=0;h<qv.size();h++){int f=qv[h];for(int r:rev[f]){if(rstamp[r]!=stamp){rstamp[r]=stamp;cnt[r]=0;}if(++cnt[r]==need[r]){int t=target[r];if(state[t]!=stamp){state[t]=stamp;qv.push_back(t);sz++;}}}}return sz;};
    for(U s:reps){int c=closure(s);hist[c]++;maxc=max(maxc,c);if(c==m)full++;}
    cout<<"n="<<n<<" masks="<<masks.size()<<" rules="<<need.size()<<" reps="<<reps.size()<<" percolating="<<full<<" max_closure="<<maxc<<"\n";for(auto [k,v]:hist)cout<<k<<":"<<v<<" ";cout<<"\n";if(full)return 1;cout<<"PASS: reference closure engine finds no percolating representative.\n";
}
