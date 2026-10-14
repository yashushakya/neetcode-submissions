class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int hash[256] ={0};
        int l=0;
        int ans = 0;

        for(int r=0;r<s.size();r++){
            hash[s[r]]++;
            while(hash[s[r]]>1){
                hash[s[l]]--;
                l++;
            }
            ans= max(ans,r-l+1);
        }

        return ans;
        
    }
};
