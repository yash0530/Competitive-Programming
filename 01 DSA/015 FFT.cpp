namespace fft {
    typedef double dbl;
    struct num {
        dbl x, y;
        num() { x = y = 0; }
        num(dbl x_, dbl y_) : x(x_), y(y_) {}
    };
    inline num operator+(num a, num b) { return num(a.x + b.x, a.y + b.y); }
    inline num operator-(num a, num b) { return num(a.x - b.x, a.y - b.y); }
    inline num operator*(num a, num b) { return num(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x); }
    inline num conj(num a) { return num(a.x, -a.y); }
    int base = 1;
    vector<num> roots = {{0, 0}, {1, 0}};
    vector<int> rev = {0, 1};
    const dbl PI = static_cast<dbl>(acosl(-1.0));
    void ensure_base(int nbase) {
        if (nbase <= base) {
            return;
        }
        rev.resize(1 << nbase);
        for (int i = 0; i < (1 << nbase); i++) {
            rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (nbase - 1));
        }
        roots.resize(1 << nbase);
        while (base < nbase) {
            dbl angle = 2 * PI / (1 << (base + 1));
            for (int i = 1 << (base - 1); i < (1 << base); i++) {
                roots[i << 1] = roots[i];
                dbl angle_i = angle * (2 * i + 1 - (1 << base));
                roots[(i << 1) + 1] = num(cos(angle_i), sin(angle_i));
            }
            base++;
        }
    }

    void fft(vector<num> &a, int n = -1) {
        if (n == -1) {
            n = (int)a.size();
        }
        assert((n & (n - 1)) == 0);
        int zeros = __builtin_ctz(n);
        ensure_base(zeros);
        int shift = base - zeros;
        for (int i = 0; i < n; i++) {
            if (i < (rev[i] >> shift)) {
                swap(a[i], a[rev[i] >> shift]);
            }
        }
        for (int k = 1; k < n; k <<= 1) {
            for (int i = 0; i < n; i += 2 * k) {
                for (int j = 0; j < k; j++) {
                    num z = a[i + j + k] * roots[j + k];
                    a[i + j + k] = a[i + j] - z;
                    a[i + j] = a[i + j] + z;
                }
            }
        }
    }

    vector<num> fa, fb;
    vector<int> square(const vector<int> &a) {
        if (a.empty()) {
            return {};
        }
        int need = (int)a.size() + (int)a.size() - 1;
        int nbase = 1;
        while ((1 << nbase) < need)
            nbase++;
        ensure_base(nbase);
        int sz = 1 << nbase;
        if ((sz >> 1) > (int)fa.size()) {
            fa.resize(sz >> 1);
        }
        for (int i = 0; i < (sz >> 1); i++) {
            int x = (2 * i < (int)a.size() ? a[2 * i] : 0);
            int y = (2 * i + 1 < (int)a.size() ? a[2 * i + 1] : 0);
            fa[i] = num(x, y);
        }
        fft(fa, sz >> 1);
        num r(1.0 / (sz >> 1), 0.0);
        for (int i = 0; i <= (sz >> 2); i++) {
            int j = ((sz >> 1) - i) & ((sz >> 1) - 1);
            num fe = (fa[i] + conj(fa[j])) * num(0.5, 0);
            num fo = (fa[i] - conj(fa[j])) * num(0, -0.5);
            num aux = fe * fe + fo * fo * roots[(sz >> 1) + i] * roots[(sz >> 1) + i];
            num tmp = fe * fo;
            fa[i] = r * (conj(aux) + num(0, 2) * conj(tmp));
            fa[j] = r * (aux + num(0, 2) * tmp);
        }
        fft(fa, sz >> 1);
        vector<int> res(need);
        for (int i = 0; i < need; i++) {
            res[i] = llround(i % 2 == 0 ? fa[i >> 1].x : fa[i >> 1].y);
        }
        return res;
    }

    vector<int> multiply(const vector<int> &a, const vector<int> &b) {
        if (a.empty() || b.empty()) {
            return {};
        }
        if (a == b) {
            return square(a);
        }
        int need = (int)a.size() + (int)b.size() - 1;
        int nbase = 1;
        while ((1 << nbase) < need)
            nbase++;
        ensure_base(nbase);
        int sz = 1 << nbase;
        if (sz > (int)fa.size()) {
            fa.resize(sz);
        }
        for (int i = 0; i < sz; i++) {
            int x = (i < (int)a.size() ? a[i] : 0);
            int y = (i < (int)b.size() ? b[i] : 0);
            fa[i] = num(x, y);
        }
        fft(fa, sz);
        num r(0, -0.25 / (sz >> 1));
        for (int i = 0; i <= (sz >> 1); i++) {
            int j = (sz - i) & (sz - 1);
            num z = (fa[j] * fa[j] - conj(fa[i] * fa[i])) * r;
            fa[j] = (fa[i] * fa[i] - conj(fa[j] * fa[j])) * r;
            fa[i] = z;
        }
        for (int i = 0; i < (sz >> 1); i++) {
            num A0 = (fa[i] + fa[i + (sz >> 1)]) * num(0.5, 0);
            num A1 = (fa[i] - fa[i + (sz >> 1)]) * num(0.5, 0) * roots[(sz >> 1) + i];
            fa[i] = A0 + A1 * num(0, 1);
        }
        fft(fa, sz >> 1);
        vector<int> res(need);
        for (int i = 0; i < need; i++) {
            res[i] = llround(i % 2 == 0 ? fa[i >> 1].x : fa[i >> 1].y);
        }
        return res;
    }

    vector<int> multiply_mod(const vector<int> &a, const vector<int> &b, int m) {
        if (a.empty() || b.empty()) {
            return {};
        }
        int eq = (a.size() == b.size() && a == b);
        int need = (int)a.size() + (int)b.size() - 1;
        int nbase = 0;
        while ((1 << nbase) < need)
            nbase++;
        ensure_base(nbase);
        int sz = 1 << nbase;
        if (sz > (int)fa.size()) {
            fa.resize(sz);
        }
        for (int i = 0; i < (int)a.size(); i++) {
            int x = (a[i] % m + m) % m;
            fa[i] = num(x & ((1 << 15) - 1), x >> 15);
        }
        fill(fa.begin() + a.size(), fa.begin() + sz, num{0, 0});
        fft(fa, sz);
        if (sz > (int)fb.size()) {
            fb.resize(sz);
        }
        if (eq) {
            copy(fa.begin(), fa.begin() + sz, fb.begin());
        } else {
            for (int i = 0; i < (int)b.size(); i++) {
                int x = (b[i] % m + m) % m;
                fb[i] = num(x & ((1 << 15) - 1), x >> 15);
            }
            fill(fb.begin() + b.size(), fb.begin() + sz, num{0, 0});
            fft(fb, sz);
        }
        dbl ratio = 0.25 / sz;
        num r2(0, -1);
        num r3(ratio, 0);
        num r4(0, -ratio);
        num r5(0, 1);
        for (int i = 0; i <= (sz >> 1); i++) {
            int j = (sz - i) & (sz - 1);
            num a1 = (fa[i] + conj(fa[j]));
            num a2 = (fa[i] - conj(fa[j])) * r2;
            num b1 = (fb[i] + conj(fb[j])) * r3;
            num b2 = (fb[i] - conj(fb[j])) * r4;
            if (i != j) {
                num c1 = (fa[j] + conj(fa[i]));
                num c2 = (fa[j] - conj(fa[i])) * r2;
                num d1 = (fb[j] + conj(fb[i])) * r3;
                num d2 = (fb[j] - conj(fb[i])) * r4;
                fa[i] = c1 * d1 + c2 * d2 * r5;
                fb[i] = c1 * d2 + c2 * d1;
            }
            fa[j] = a1 * b1 + a2 * b2 * r5;
            fb[j] = a1 * b2 + a2 * b1;
        }
        fft(fa, sz);
        fft(fb, sz);
        vector<int> res(need);
        for (int i = 0; i < need; i++) {
            int aa = llround(fa[i].x);
            int bb = llround(fb[i].x);
            int cc = llround(fa[i].y);
            res[i] = static_cast<int>((aa + ((bb % m) << 15) + ((cc % m) << 30)) % m);
        }
        return res;
    }
}