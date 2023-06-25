/* #region header */

#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
// types
using ll = long long;
using ull = unsigned long long;
using ld = long double;
typedef pair<ll, ll> Pl;
typedef pair<int, int> Pi;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<char> vc;
template <typename T> using mat = vector<vector<T>>;
typedef vector<vector<int>> vvi;
typedef vector<vector<long long>> vvl;
typedef vector<vector<char>> vvc;
// abreviations
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rep_(i, a_, b_, a, b, ...) for (ll i = (a), max_i = (b); i < max_i; i++)
#define rep(i, ...) rep_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)
#define rrep_(i, a_, b_, a, b, ...) for (ll i = (b - 1), min_i = (a); i >= min_i; i--)
#define rrep(i, ...) rrep_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)
#define srep(i, a, b, c) for (ll i = (a), max_i = (b); i < max_i; i += c)
#define SZ(x) ((int)(x).size())
#define pb(x) push_back(x)
#define eb(x) emplace_back(x)
#define mp make_pair
//入出力
#define print(x) cout << x << endl
template <class T> ostream &operator<<(ostream &os, const vector<T> &v) {
    for (auto &e : v)
        cout << e << " ";
    cout << endl;
    return os;
}
void scan(int &a) {
    cin >> a;
}
void scan(long long &a) {
    cin >> a;
}
void scan(char &a) {
    cin >> a;
}
void scan(double &a) {
    cin >> a;
}
void scan(string &a) {
    cin >> a;
}
template <class T> void scan(vector<T> &a) {
    for (auto &i : a)
        scan(i);
}
#define vsum(x) accumulate(all(x), 0LL)
#define vmax(a) *max_element(all(a))
#define vmin(a) *min_element(all(a))
#define lb(c, x) distance((c).begin(), lower_bound(all(c), (x)))
#define ub(c, x) distance((c).begin(), upper_bound(all(c), (x)))
// functions
// gcd(0, x) fails.
ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}
ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}
ll safemod(ll a, ll b) {
    return (a % b + b) % b;
}
template <class T> bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T> bool chmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}
template <typename T> T mypow(T x, ll n) {
    T ret = 1;
    while (n > 0) {
        if (n & 1)
            (ret *= x);
        (x *= x);
        n >>= 1;
    }
    return ret;
}
ll modpow(ll x, ll n, const ll mod) {
    ll ret = 1;
    while (n > 0) {
        if (n & 1)
            (ret *= x);
        (x *= x);
        n >>= 1;
        x %= mod;
        ret %= mod;
    }
    return ret;
}

uint64_t my_rand(void) {
    static uint64_t x = 88172645463325252ULL;
    x = x ^ (x << 13);
    x = x ^ (x >> 7);
    return x = x ^ (x << 17);
}
int popcnt(ull x) {
    return __builtin_popcountll(x);
}
template <typename T> vector<int> IOTA(vector<T> a) {
    int n = a.size();
    vector<int> id(n);
    iota(all(id), 0);
    sort(all(id), [&](int i, int j) { return a[i] < a[j]; });
    return id;
}
struct Timer {
    clock_t start_time;
    void start() {
        start_time = clock();
    }
    int lap() {
        // return x ms.
        return (clock() - start_time) * 1000 / CLOCKS_PER_SEC;
    }
};
template <int Mod> struct modint {
    int x;

    modint() : x(0) {
    }

    modint(long long y) : x(y >= 0 ? y % Mod : (Mod - (-y) % Mod) % Mod) {
    }

    modint &operator+=(const modint &p) {
        if ((x += p.x) >= Mod)
            x -= Mod;
        return *this;
    }

    modint &operator-=(const modint &p) {
        if ((x += Mod - p.x) >= Mod)
            x -= Mod;
        return *this;
    }

    modint &operator*=(const modint &p) {
        x = (int)(1LL * x * p.x % Mod);
        return *this;
    }

    modint &operator/=(const modint &p) {
        *this *= p.inverse();
        return *this;
    }

    modint operator-() const {
        return modint(-x);
    }

    modint operator+(const modint &p) const {
        return modint(*this) += p;
    }

    modint operator-(const modint &p) const {
        return modint(*this) -= p;
    }

    modint operator*(const modint &p) const {
        return modint(*this) *= p;
    }

    modint operator/(const modint &p) const {
        return modint(*this) /= p;
    }

    bool operator==(const modint &p) const {
        return x == p.x;
    }

    bool operator!=(const modint &p) const {
        return x != p.x;
    }

    modint inverse() const {
        int a = x, b = Mod, u = 1, v = 0, t;
        while (b > 0) {
            t = a / b;
            swap(a -= t * b, b);
            swap(u -= t * v, v);
        }
        return modint(u);
    }

    modint pow(int64_t n) const {
        modint ret(1), mul(x);
        while (n > 0) {
            if (n & 1)
                ret *= mul;
            mul *= mul;
            n >>= 1;
        }
        return ret;
    }

    friend ostream &operator<<(ostream &os, const modint &p) {
        return os << p.x;
    }

    friend istream &operator>>(istream &is, modint &a) {
        long long t;
        is >> t;
        a = modint<Mod>(t);
        return (is);
    }

    static int get_mod() {
        return Mod;
    }

    constexpr int get() const {
        return x;
    }
};
template <typename T = int> struct Edge {
    int from, to;
    T cost;
    int idx;

    Edge() = default;

    Edge(int from, int to, T cost = 1, int idx = -1) : from(from), to(to), cost(cost), idx(idx) {
    }

    operator int() const {
        return to;
    }
};

template <typename T = int> struct Graph {
    vector<vector<Edge<T>>> g;
    int es;

    Graph() = default;

    explicit Graph(int n) : g(n), es(0) {
    }

    size_t size() const {
        return g.size();
    }

    void add_directed_edge(int from, int to, T cost = 1) {
        g[from].emplace_back(from, to, cost, es++);
    }

    void add_edge(int from, int to, T cost = 1) {
        g[from].emplace_back(from, to, cost, es);
        g[to].emplace_back(to, from, cost, es++);
    }

    void read(int M, int padding = -1, bool weighted = false, bool directed = false) {
        for (int i = 0; i < M; i++) {
            int a, b;
            cin >> a >> b;
            a += padding;
            b += padding;
            T c = T(1);
            if (weighted)
                cin >> c;
            if (directed)
                add_directed_edge(a, b, c);
            else
                add_edge(a, b, c);
        }
    }
};

/* #endregion*/
// constant
#define inf 1000000000ll
#define INF 4000000004000000000LL
#define mod 998244353ll
const long double eps = 0.000000000000001;
const long double PI = 3.141592653589793;
using mint = modint<mod>;
using vmint = vector<mint>;


long long xor64(long long range) {
    static uint64_t x = 88172645463325252ULL;
    x ^= x << 13;
    x ^= x >> 7;
    return (x ^= x << 17) % range;
}

int n = 30;
int max_swap = 10000;
int N = n * (n + 1) / 2;
mat<int> b(n, vi(n));
vi x_inv = vi(N);
vi y_inv = vi(N);

void swap_ball(int x1, int y1, int x2, int y2){
    int tmp = b[x1][y1];
    b[x1][y1] = b[x2][y2];
    b[x2][y2] = tmp;
    x_inv[b[x1][y1]] = x1;
    y_inv[b[x1][y1]] = y1;
    x_inv[b[x2][y2]] = x2;
    y_inv[b[x2][y2]] = y2;
}

bool is_inside(int x, int y){
    return !(x < 0 || x >= n || y < 0 || y > x);
}

void calc_cost(int x1, int y1, int ball, mat<int>& dp, int depth = 1){
    if(dp[x1][y1] != inf) return;
    int x2 = x1 - 1;
    int y2 = y1;
    int x3 = x1 - 1;
    int y3 = y1 - 1;
    bool right = is_inside(x2, y2) && b[x2][y2] > ball;
    bool left = is_inside(x3, y3) && b[x3][y3] > ball;
    if((!right && !left) || depth == 0){
        dp[x1][y1] = -b[x1][y1];
        return;
    }
    if(right){
        calc_cost(x2, y2, ball, dp, depth-1);
        chmin(dp[x1][y1], dp[x2][y2] + 5000 - b[x1][y1]);
    }
    if(left){
        calc_cost(x3, y3, ball, dp, depth-1);
        chmin(dp[x1][y1], dp[x3][y3] + 5000 - b[x1][y1]);
    }
    return ;
}

double value(int x1, int y1, mat<int>& dp, int swap_count){
    return -dp[x1][y1];
}

int main(int argc, char *argv[]) {
    int max_depth = 5;
    if (argc == 2) {
        max_depth = stod(argv[1]);
    }
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << setprecision(30) << fixed;

    rep(i, n) rep(j, i+1) {
        cin >> b[i][j];
    }
    rep(i, n) rep(j, i+1) {
        x_inv[b[i][j]] = i;
        y_inv[b[i][j]] = j;
    }

    int swap_count = 0;
    vector<tuple<int, int, int, int>> swap_hist;
    rep(i, N){
        while(true){
            if (swap_count >= max_swap) break;

            int x1 = x_inv[i];
            int y1 = y_inv[i];
            int x2 = x1 - 1;
            int y2 = y1;
            int x3 = x1 - 1;
            int y3 = y1 - 1;
            int ball = b[x1][y1];
            mat<int> dp(n, vi(n, inf));
            calc_cost(x1, y1, ball, dp, max_depth);

            // x2とx3のどっちを優先するか
            if(is_inside(x2, y2) && is_inside(x3, y3) && value(x2, y2, dp, swap_count) < value(x3, y3, dp, swap_count)){
                swap(x2, x3);
                swap(y2, y3);
            }

            if(is_inside(x2, y2) && b[x2][y2] > b[x1][y1]){
                swap_ball(x1, y1, x2, y2);
                swap_count++;
                swap_hist.emplace_back(x1, y1, x2, y2);
            }else if(is_inside(x3, y3) && b[x3][y3] > b[x1][y1]){
                swap_ball(x1, y1, x3, y3);
                swap_count++;
                swap_hist.emplace_back(x1, y1, x3, y3);
            }else{
                break;
            }
        }
    }

    print(swap_count);
    cerr << swap_count << endl;
    rep(i, swap_count){
        int x1, y1, x2, y2;
        tie(x1, y1, x2, y2) = swap_hist[i];
        cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
    }
}