class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string,vector<string>> mp;
        vector<vector<string>> vec;

        for(auto &str:strs){
            string key = str;
            sort(key.begin(),key.end());
            mp[key].push_back(str);
           
        }

        for(auto &x: mp){
            vec.push_back(x.second);
        }

        return vec;
        
    }
};
