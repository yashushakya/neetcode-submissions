class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        int prev1 = 0;
        int prev = 0;
        for(string s: operations){            
            if(s=="C"){
                if(!st.empty()) st.pop();
            }
            else if(s=="D"){
                st.push(st.empty()?0:2*st.top());
            }
            else if(s=="+"){
                int prev1 = st.empty()?0:st.top();st.pop();
                int prev2 = st.empty()?0:st.top();st.pop();
                st.push(prev2);st.push(prev1);
                st.push(prev1+prev2);
            }
            else{
                st.push(stoi(s));
            }
        }

        int ans = 0;
        while(!st.empty()){
            ans+=st.top();st.pop();
        }
        return ans;
        
    }
};