vector<ll> pn;
bool arr[MAX];

void eratos() {
	pn.push_back(2);
	rep(i, 3, MAX) {
		if (arr[i]) continue;
		pn.push_back(i);
		for (ll j = i * i; j < MAX; j += i) arr[j] = 1;
	}
}