class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        priority_queue<pair<int,vector<int>>> pq;

        for(auto &vec: points){
            int x = vec[0]; int y = vec[1];
            int distance = x*x + y*y;
            pq.push({distance,vec});
            if(pq.size()>k) pq.pop();
        }

        vector<vector<int>> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second); pq.pop();
        }
        return ans;
        
    }
};
