class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int l=encodedText.length();
        int col=l/rows;
        string t;
        for(int i=0; i<col; i++){
            for(int j=i; j<l; j+=(col+1)){
                t+=encodedText[j];
            }
        }
        while(!t.empty() && t.back()==' '){
            t.pop_back();
        }
        return t;
    }
};
