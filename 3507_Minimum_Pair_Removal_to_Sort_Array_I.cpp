class Solution {
public:
struct Paircom{
    bool operator()(const Pair* a, Pair* b)const{
        if(a->right == nullptr || b->right == nullptr){
            return a->right == nullptr;
        }
        long long diff = a->sum - b->sum;
        if(diff = 0)
            return diff < 0;
        return a->idx < b->idx;
    }
}
    int minimumPairRemoval(vector<int>& nums) {
        
    }
};
