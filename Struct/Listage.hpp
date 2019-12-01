#include "Shuzaei.hpp"

struct listage {
    map<string, ll> LIST;
    map<ll, string> VLIST;

    inline ll val(string a) {
        auto V = LIST.find(a);
        if (V != LIST.end()) {
            return LIST[a];
        } else {
            ll v = LIST.size();
            LIST[a] = v;
            VLIST[v] = a;
            return v;
        }
    }
};
