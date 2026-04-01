class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
         int n=positions.size();
        vector<vector<int>>vect;
        for(int i=0;i<n;i++)
            vect.push_back({positions[i],healths[i],directions[i]=='R' ? 1 : -1,i});
        sort(vect.begin(),vect.end());
        stack<vector<int>>st;
        for(int i=0;i<n;i++){
            if(st.empty())
                st.push(vect[i]);
            else if(vect[i][2]==1){
                st.push(vect[i]);
            }
            else{
                int val=vect[i][1];
                while(!st.empty() && st.top()[2]>0 && vect[i][2]<0){
                    int x=st.top()[1];
                    int y=vect[i][1];
                    if(x==y){
                        val=0;
                        st.pop();
                        break;
                    } 
                    if(x > y){
                        val=0;
                        st.top()[1]--;
                        break;
                    }else{
                        st.pop();
                        vect[i][1]--;
                        val=vect[i][1];
                    }
                }
                if(val)
                    st.push(vect[i]);
            }  
        }
        vector<int>ans;
        map<int,int>res;
        while(!st.empty()){
            res[st.top()[3]] = st.top()[1];
            st.pop();
        }
        for(auto it=res.begin();it!=res.end();it++)
            ans.push_back(it->second);
        
        return ans;
    }
};
