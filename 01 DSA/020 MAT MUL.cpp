// matrix mul
vector<vector<int>> mat_mul(vector<vector<int>> a, vector<vector<int>> b) {
	getMat(res, size(a), size(b[0]), 0);
	for (int i = 0; i < size(a); i++) {
		for (int j = 0; j < size(b[0]); j++) {
			for (int k = 0; k < size(a[0]); k++) {
				res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % HELL;
			}
		}
	}
	return res;
}

// matrix expo
vector<vector<int>> mat_pow(vector<vector<int>> base, int pow) {
	vector<vector<int>> res = base; pow--;
	while (pow) {
		if (pow & 1) {
			res = mat_mul(res, base);
		}
		base = mat_mul(base, base);
		pow >>= 1;
	}
	return res;
}