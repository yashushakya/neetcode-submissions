class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int,double>> pr;

        for(int i=0;i<n;i++){
            double time = (double)(target - position[i])/speed[i];
            pr.push_back({position[i], time});
        }
        sort(pr.rbegin(),pr.rend());
        double curtime = 0;
        int fleet = 0;

        for(auto &[pos,time]: pr){
            if(time>curtime){
                fleet++;
                curtime = time;
            }
        }

        return fleet;

    }
};
