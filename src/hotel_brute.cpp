#include <bits/stdc++.h>
using namespace std;


// dbg
#ifdef LOCAL
    #include "dbg.h"
#else
    #define dbg(...)
#endif



// typedefs
using ll = long long;
#define int ll
const int inf = int(1e18);

using vi = vector<int>;
using vvi = vector<vi>;
using p2 = pair<int, int>;

#define rep(i, high) for (int i = 0; i < high; i++)
#define repp(i, low, high) for (int i = low; i < high; i++)
#define repe(i, container) for (auto& i : container)
#define per(i, high) for (int i = high-1; i >= 0; i--)
#define perr(i, high, low) for (int i = high-1; i >= low; i--)

#define clz(x) __builtin_clz(x)
#define popcount(x) __builtin_popcountll(x)

// fast io
inline void fast() { 
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 
}


#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define setcontains(set, x) (set.find(x) != set.end())
#define sz(container) ((int)container.size())
vector<p2> dirs = { {0,1},{0,-1},{1,0},{-1,0} };

// time and rng
auto Start = chrono::high_resolution_clock::now();
void resettimer() { Start = chrono::high_resolution_clock::now(); }
int elapsedmillis() { 
    return chrono::duration_cast<chrono::milliseconds>(
        chrono::high_resolution_clock::now() - Start
    ).count(); 
}
random_device rd;
mt19937 rng(rd());
template<typename T, typename U> inline int randint(T lo, U hi) { 
    return uniform_int_distribution<int>((int)lo, (int)hi)(rng); 
} // [lo,hi]
template<typename T> inline T randel(vector<T>& v) { 
    return v[uniform_int_distribution<int>(
        int(0), int(v.size()) - int(1))(rng)
    ]; 
} // [lo,hi]


// custom
vector<p2> deltas = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
#define beti(a, x, b) (a <= x && x <= b)

template <typename T, typename U> inline void 
operator+=(pair<T, U>& l, const pair<T, U>& r) { 
    l = { l.first + r.first,l.second + r.second }; 
}
template <typename T, typename U> inline pair<T, U> 
operator+(const pair<T, U> l, const pair<T, U> r) { 
    return { l.first + r.first, l.second + r.second }; 
}
template <typename T, typename U> inline pair<T, U> 
operator-(const pair<T, U> l, const pair<T, U> r) { 
    return { l.first - r.first, l.second - r.second }; 
}
template <typename T, typename U> inline pair<T, U> 
operator*(const pair<T, U> l, const int m) { 
    return { l.first * m, l.second * m }; 
}


const int MAL = 2000;

using bs = bitset<MAL>;

signed main() {
    // fast();
    
    int lo, hi;

    cout << "Enter a lowerbound: ";
    cin >> lo;
    cout << "\n";

    cout << "Enter an upperbound: ";
    cin >> hi;
    cout << "\n";

    assert(0 <= lo);
    assert(lo <= hi);
    assert(hi <= MAL);

    repp(l, lo, hi + 1) {
        resettimer();

        bs m;
        rep(i, l)
            m.set(i);
        // vector<bs> vis(1 << ML);

        unordered_map<bs, int> ans;
        unordered_map<bs, pair<bs, int>> prev;
        unordered_map<bs, bool> vis;

        queue<bs> s;

        bs st = m;

        s.push(st);

        vis[st] = 1;
        ans[st] = 0;


        // dbg(s);
       //  dbg(vis);

        while(!s.empty()) {
            bs v = s.front();
            s.pop();


            rep(i, l) {
                bs vv = v;

                if (!vv[i]) continue;
                
                vv.reset(i); 
               

                bs nv = 0;

                nv |= vv >> 1;
                nv |= vv << 1;
                nv &= m;


                if (vis[nv]) continue;
        
                /*
                dbg("------------");
                dbg(v);
                dbg(vv);
                dbg(nv);
                */

                vis[nv] = 1;
                prev[nv] = {v, i};
                ans[nv] = ans[v] + 1;

                // dbg(ans[nv]);
                s.push(nv);
            }
        }

        repe(i, ans) {
            // dbg(i);
        }

        repe(i, vis) {
            // dbg(i);
        }

        bs c = 0;
        while (c != m) {
            int t;
            tie(c, t) = prev[c];
            // dbg(t);
        }

        cout << l << " " << elapsedmillis() << '\n';

        if (l >= 3) assert(ans[0] = 2 * l - 4);
    }

}

