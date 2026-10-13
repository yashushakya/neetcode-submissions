class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        set<int> st(nums.begin(),nums.end());
        int ans = 0;

        for(const int &x:st){
            int num = x;
            if(!st.count(num-1)){
                int cnt = 1;
                while(st.count(num+1)){
                    cnt++;
                    num++;
                }
                ans=max(ans,cnt);
            }
        }

        return ans;
        
    }
};
