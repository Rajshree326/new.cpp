#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
using namespace std;
int main(){
    ll n,m;
    cin>>n>>m;
    vector<pair<ll,ll>>adj[n];
    for(ll i=0;i<m;i++){
       ll a,b,wt;
       cin>>a>>b>>wt;
       adj[a].pb(mp(b,wt));
       adj[b].pb(mp(a,wt));
    }
    ll parent[n],key[n];
    bool mst[n];

    //initialize
    for(ll i=0;i<n;i++){
      key[i]=INT_MAX;
      mst[i]=false;
    }
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
    key[0]=0;
    parent[0]=-1;
    pq.push(mp(0,0));
    for(ll i=0;i<n-1;i++){
        ll u=pq.top().second;
        pq.pop();
        mst[u]=true;
        for(auto it:adj[u]){
            ll v=it.first,weight=it.second;
            if(mst[v]==false && weight<key[v]){
                parent[v]=u;
                pq.push(mp(key[v],v));
                key[v]=weight;
            }
        }
    }
    for(ll i=0;i<n;i++){
        cout<<parent[i]<<"-"<<i<<endl;
    }
    return 0;
}