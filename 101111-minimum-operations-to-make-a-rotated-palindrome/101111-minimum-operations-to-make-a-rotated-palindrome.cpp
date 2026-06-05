class Solution {
public:
    using cd = complex<double>;
    const double PI = acos(-1.0);

    void fft(vector<cd>& a, bool invert) {
        int n = a.size();

        for (int i = 1, j = 0; i < n; i++) {
            int bit = n >> 1;
            for (; j & bit; bit >>= 1) j ^= bit;
            j ^= bit;
            if (i < j) swap(a[i], a[j]);
        }

        for (int len = 2; len <= n; len <<= 1) {
            double ang = 2 * PI / len * (invert ? -1 : 1);
            cd wlen(cos(ang), sin(ang));

            for (int i = 0; i < n; i += len) {
                cd w(1);
                for (int j = 0; j < len / 2; j++) {
                    cd u = a[i + j];
                    cd v = a[i + j + len / 2] * w;

                    a[i + j] = u + v;
                    a[i + j + len / 2] = u - v;

                    w *= wlen;
                }
            }
        }

        if (invert) {
            for (auto& x : a) x /= n;
        }
    }

    vector<cd> multiply(vector<cd> a, vector<cd> b) {
        int n = 1;
        while (n < a.size() + b.size() - 1) n <<= 1;

        a.resize(n);
        b.resize(n);

        fft(a, false);
        fft(b, false);

        for (int i = 0; i < n; i++) a[i] *= b[i];

        fft(a, true);
        return a;
    }

    int minOperations(string s) {
        int n = s.size();

        vector<cd> total(n);

        for (int f = 0; f < 26; f++) {
            cd lambda(0);

            for (int d = 0; d < 26; d++) {
                double cost = min(d, 26 - d);
                double ang = -2 * PI * f * d / 26.0;
                lambda += cd(cos(ang), sin(ang)) * cost;
            }

            lambda /= 26.0;

            vector<cd> a(n), b(n);

            for (int i = 0; i < n; i++) {
                int x = s[i] - 'a';

                double ang1 = -2 * PI * f * x / 26.0;
                double ang2 = 2 * PI * f * x / 26.0;

                a[i] = cd(cos(ang1), sin(ang1));
                b[i] = cd(cos(ang2), sin(ang2));
            }

            vector<cd> conv = multiply(a, b);

            for (int t = 0; t < n; t++) {
                cd cur = conv[t];
                if (t + n < conv.size()) cur += conv[t + n];
                total[t] += lambda * cur;
            }
        }

        long long res = LLONG_MAX;

        for (int r = 0; r < n; r++) {
            int t = (2 * r - 1 + n) % n;
            long long palindromeCost = llround(total[t].real() / 2.0);
            res = min(res, palindromeCost + r);
        }

        return res;
    }
};