#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1);
typedef complex<double> cpx;

// non-recursive. slower than recursive function :(
void fft(vector<cpx> &f, cpx w_1){
	int n = 1, l = 0;
	while (n < f.size()) n <<= 1, l++;
	vector<cpx> ws(l); ws[0] = w_1;
	for(int i = 1; i < l; i++) ws[i] = ws[i - 1] * ws[i - 1];
	for(int i = 1; i <= l; i++){
		vector<cpx> ff(n);
		int bias = n >> i;
		for(int j = 0; j < bias; j++){
			int n = 1 << i;
			cpx wp = 1, w = ws[l - i];
			for(int k = 0; k < (n >> 1); k++){
				int l = k * bias;
				ff[j + l] = f[j + l * 2] + wp * f[j + l * 2 + bias];
				ff[j + l + bias * (n >> 1)] = f[j + l * 2] - wp * f[j + l * 2 + bias];
				wp *= w;
			}
		}
		f.swap(ff);
	}
}

vector<cpx> mul_fft(vector<cpx> a, vector<cpx> b) {
	int n = 1;
	while (n <= a.size() || n <= b.size()) n <<= 1;
	n <<= 1;
	a.resize(n); b.resize(n); vector<cpx> c(n);
	cpx w(cos(2 * PI / n), sin(2 * PI / n));
	fft(a, w); fft(b, w);
	for (int i = 0; i < n; i++) c[i] = a[i] * b[i];
	fft(c, cpx(w.real(), -w.imag()));
	for (int i = 0; i < n; i++) {
		c[i] /= cpx(n, 0);
		c[i] = cpx(round(c[i].real()), round(c[i].imag()));
	}
	return c;
}


// recursive version
void fft(vector<cpx> &f, cpx w) {
	int n = f.size();
	if (n == 1) return;
	vector<cpx> even(n >> 1), odd(n >> 1);
	for (int i = 0; i < n; i++) { (i & 1 ? odd : even)[i / 2] = f[i]; }
	fft(even, w * w); fft(odd, w * w);
	cpx wp(1, 0);
	for (int i = 0; i < n / 2; i++) {
		f[i] = even[i] + wp * odd[i];
		f[i + n / 2] = even[i] - wp * odd[i];
		wp *= w;
	}
}