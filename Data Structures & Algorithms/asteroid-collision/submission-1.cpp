class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        
        stack<int> st;
        for(int i=0;i<arr.size();i++){
            bool destroyed = false;
            if(st.empty() || arr[i]>0 || st.top()<0){
                st.push(arr[i]);
            }
            else{
                // here: st.top()>0 and arr[i]<0 (the only real collision)
                while(!st.empty() && st.top()>0 && st.top()<abs(arr[i])){
                    st.pop();
                }
                if(!st.empty() && st.top()==abs(arr[i])){
                    st.pop();
                    destroyed = true;
                }
                else if(!st.empty() && st.top()>abs(arr[i])) destroyed = true;

                if(!destroyed) st.push(arr[i]);
            }
        }

        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};