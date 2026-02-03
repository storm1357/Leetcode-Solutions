class Solution {
public:
    struct Node {
        long long val;
        int id;
        Node *prev, *next;
        bool alive = true;
        Node(long long v, int i): val(v), id(i), prev(nullptr), next(nullptr) {}
    };

    struct Pair {
        long long sum;
        Node* left;
        Node* right;
    };

    struct Cmp {
        bool operator()(const Pair& a, const Pair& b) const {
            if (a.sum != b.sum) return a.sum > b.sum;
            return a.left->id > b.left->id; // leftmost
        }
    };

    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        vector<Node*> nodes;
        for (int i = 0; i < n; i++) {
            nodes.push_back(new Node(nums[i], i));
            if (i > 0) {
                nodes[i-1]->next = nodes[i];
                nodes[i]->prev = nodes[i-1];
            }
        }

        // count initial violations
        int bad = 0;
        for (int i = 0; i + 1 < n; i++) {
            if (nums[i] > nums[i+1]) bad++;
        }

        priority_queue<Pair, vector<Pair>, Cmp> pq;
        for (int i = 0; i + 1 < n; i++) {
            pq.push({nodes[i]->val + nodes[i+1]->val, nodes[i], nodes[i+1]});
        }

        int ops = 0;

        while (bad > 0) {
            Pair p;
            do {
                p = pq.top(); pq.pop();
            } while (!p.left->alive || !p.right->alive || p.left->next != p.right);

            Node* L = p.left;
            Node* R = p.right;

            // remove old violations
            if (L->prev && L->prev->val > L->val) bad--;
            if (L->val > R->val) bad--;
            if (R->next && R->val > R->next->val) bad--;

            Node* merged = new Node(L->val + R->val, L->id);
            merged->prev = L->prev;
            merged->next = R->next;

            if (L->prev) L->prev->next = merged;
            if (R->next) R->next->prev = merged;

            L->alive = R->alive = false;

            // add new violations
            if (merged->prev && merged->prev->val > merged->val) bad++;
            if (merged->next && merged->val > merged->next->val) bad++;

            if (merged->prev)
                pq.push({merged->prev->val + merged->val, merged->prev, merged});
            if (merged->next)
                pq.push({merged->val + merged->next->val, merged, merged->next});

            ops++;
        }

        return ops;
    }
};
