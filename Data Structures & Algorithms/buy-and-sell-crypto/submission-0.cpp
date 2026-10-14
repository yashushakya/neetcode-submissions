class Solution {
public:
    int maxProfit(vector<int>& prices) {
    
        int price = prices[0];
        int ans =0;
        for(int r=0;r<prices.size();r++){
            price = min(price,prices[r]);
            ans= max(ans, prices[r]-price);
        }
        return ans;
    }
};
