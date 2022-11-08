class dsu {
private:
	vector<ll> parent,rank,size;
public:
	dsu(ll n) {
		parent.resize(n);
		for (ll i=0;i<=n;i++) {
			parent[i]=i;
		}
		rank.resize(n+1,0);
		size.resize(n+1,1);
	}
	ll findParent(ll x) {
		if (parent[x]==x) return x;
		return parent[x]=findParent(parent[x]);
	}
	void unionbyrank(ll u,ll v) {
		ll pu=findParent(u),pv=findParent(v);
		if (pu==pv) return;
		if (rank[pu]<rank[pv]) {
			parent[pu]=pv;
		}
		else if (rank[pv]<rank[pu]) {
			parent[pv]=pu;
		}
		else {
			parent[pv]=pu;
			rank[pu]++;
		}
	}
	void unionbysize(ll u,ll v) {
		ll pu=findParent(u),pv=findParent(v);
		if (pu==pv) return;
		if (size[pu]<sizep[pv]) {
			parent[pu]=pv;
			size[pv]+=size[pu];
		}
		else {
			parent[pv]=pu;
			size[pu]+=size[pv];
		}
	}
};
