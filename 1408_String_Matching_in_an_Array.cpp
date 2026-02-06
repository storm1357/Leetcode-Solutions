class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        set<string>s;
        int n=words.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(words[i]!=words[j]){
                    if(words[j].find(words[i])!=string::npos)
                        s.insert(words[i]);
                }
            }
        }
        vector<string> res(s.begin(),s.end());
        return res;
    }
};
