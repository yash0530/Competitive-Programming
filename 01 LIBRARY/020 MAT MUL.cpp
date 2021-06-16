#define Mat vector<vector<int>>
#define getMat(a, b) vector<vector<int>>(a, vector<int>(b, 0))

// matrix mul
Mat mat_mul(Mat a, Mat b) {

	Mat res = getMat(size(a), size(b[0]));
	for (int i = 0; i < size(a); i++) {
		for (int j = 0; j < size(b[0]); j++) {
			for (int k = 0; k < size(a[0]); k++) {
				res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % MOD;
			}
		}
	}

	return res;
}

// matrix expo
Mat mat_pow(Mat base, int pow) {
	Mat res = base; pow--;
	while (pow) {
		if (pow & 1) {
			res = mat_mul(res, base);
		}
		base = mat_mul(base, base);
		pow >>= 1;
	}
	return res;
}