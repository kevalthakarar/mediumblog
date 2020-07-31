#include<bits/stdc++.h>
using namespace std;
#define ff          first
#define ss          second
#define ll         	long long int
#define pb          push_back
#define ar 			array
#define mp 			make_pair
#define f(i,n)   	for(ll i =0;i<n;i++)
#define inf 		INT_MAX
#define pll 		pair<ll,ll>
const ll INF = 1e18;
void init(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE 
		freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif
}

bool checkp2(ll n){
	return n && (n-1);
}

ll power(ll x , ll n , ll mod){
	ll po = 1;
	while(n){
		if(n & 1){
			po = (po*x) % mod;
		}
		n = n>>1;
		x = (x * x) % mod;
	}
	return po;
}

bool isPrime(ll x){
	if(x < 2)
		return 0;
	for(ll y = 2; y * y <= x; y++){
		if(x % y == 0){
			return 0;
		}
	}
	return true;
}

const ll mxn = 3000;
const ll nxn = 5010;
ll n ,m;
vector<ar<ll , 3>> adj;
ll d[mxn];
vector<ll> ad[mxn] , ad2[mxn];
bool ans;
bool vis[mxn] , vis1[mxn];
void dfs1(ll u , ll p = -1){
	vis[u] = 1;
	for(ll v : ad[u]){
		if(v == p)
			continue;
		if(!vis[v])
			dfs1(v ,u);
	}

}
void dfs2(ll u , ll p = -1){
	vis1[u] = 1;
	for(ll v : ad2[u]){
		if(v == p)
			continue;
		if(!vis1[v])
			dfs2(v ,u);
	}

}

void solve(){

	cin>>n>>m;
	for(ll i =0;i<n;i++)
		d[i] = INF;
	d[0] = 0;


	for(ll i = 0;i<m;i++){
		ll a,b,c;
		cin>>a>>b>>c;
		--a , --b;
		adj.push_back({a,b,-c});
		ad[a].push_back(b);
		ad2[b].push_back(a);
	}	
	dfs1(0);
	dfs2(n-1);
	
	for(ll i = 0; i<n-1; i++){
		for(ll j = 0; j<m; j++){
			ar<ll ,3> k = adj[j];
			if(d[k[0]] + k[2] < d[k[1]])
				d[k[1]] = d[k[0]] + k[2];
		}
	}

	for(ll i = 0;i<m;i++){
		ar<ll,3> k = adj[i];
		if(d[k[0]] + k[2] < d[k[1]]){
			if(vis1[k[0]] && vis[k[0]]){
				cout<<"-1"<<endl;
				return;
			}
		}
	}
	if(n > 1){
		if(d[n-1] >= INF)
			cout<<"-1"<<endl;
		else 
			cout<< -d[n-1]<<endl;
	}
	else{
		cout<<"0"<<endl;
	}
	
}
int main(){
    //init();
	ll t = 1;
	//cin>>t;
	for(ll i=1;i<=t;i++){
		//cout<<"Case #"<<i<<": ";
		solve();
	}
}
