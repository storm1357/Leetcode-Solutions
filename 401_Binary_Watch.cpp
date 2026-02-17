class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> res;
        for(int h=0; h<12; h++){
            for(int m=0; m<60; m++){
                if(__builtin_popcount(h)+__builtin_popcount(m)==turnedOn){
                    string hour=to_string(h);
                    string min=(m<10?"0":"")+to_string(m);
                    res.push_back(hour+":"+min);
                }
            }
        }
        return res;
    }
};
