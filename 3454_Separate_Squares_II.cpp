class Solution {
public:

    struct Event {
        double y;
        int type; // +1 = add, -1 = remove
        double x1, x2;
    };

    struct SegTree {
        int n;
        vector<int> cover;
        vector<double> len;
        vector<double> xs;

        SegTree(int n, vector<double>& xs) : n(n), xs(xs) {
            cover.assign(4 * n, 0);
            len.assign(4 * n, 0.0);
        }

        void pushUp(int node, int l, int r) {
            if (cover[node] > 0) {
                len[node] = xs[r] - xs[l];
            } else if (l + 1 == r) {
                len[node] = 0;
            } else {
                len[node] = len[node * 2] + len[node * 2 + 1];
            }
        }

        void update(int node, int l, int r, int ql, int qr, int val) {
            if (qr <= l || r <= ql) return;
            if (ql <= l && r <= qr) {
                cover[node] += val;
                pushUp(node, l, r);
                return;
            }
            int mid = (l + r) / 2;
            update(node * 2, l, mid, ql, qr, val);
            update(node * 2 + 1, mid, r, ql, qr, val);
            pushUp(node, l, r);
        }
    };

    double separateSquares(vector<vector<int>>& squares) {
        vector<Event> events;
        vector<double> xs;

        for (auto& s : squares) {
            double x = s[0], y = s[1], len = s[2];
            events.push_back({y, +1, x, x + len});
            events.push_back({y + len, -1, x, x + len});
            xs.push_back(x);
            xs.push_back(x + len);
        }

        sort(events.begin(), events.end(),
             [](auto& a, auto& b) { return a.y < b.y; });

        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());

        SegTree st(xs.size() - 1, xs);

        auto idx = [&](double x) {
            return lower_bound(xs.begin(), xs.end(), x) - xs.begin();
        };

        // First pass: compute total area
        double totalArea = 0;
        for (int i = 0; i + 1 < events.size(); i++) {
            int l = idx(events[i].x1);
            int r = idx(events[i].x2);
            st.update(1, 0, st.n, l, r, events[i].type);
            double dy = events[i + 1].y - events[i].y;
            totalArea += st.len[1] * dy;
        }

        double target = totalArea / 2.0;

        // Second pass: find split
        SegTree st2(xs.size() - 1, xs);
        double acc = 0;

        for (int i = 0; i + 1 < events.size(); i++) {
            int l = idx(events[i].x1);
            int r = idx(events[i].x2);
            st2.update(1, 0, st2.n, l, r, events[i].type);
            double dy = events[i + 1].y - events[i].y;
            double slab = st2.len[1] * dy;

            if (acc + slab >= target) {
                return events[i].y + (target - acc) / st2.len[1];
            }
            acc += slab;
        }

        return events.back().y;
    }
};
