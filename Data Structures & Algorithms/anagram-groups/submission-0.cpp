class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string,vector<string>> mp;
        vector<vector<string>> vec;

        for(auto &str:strs){
            string og = str;
            sort(str.begin(),str.end());
            if(mp.count(str)){
                mp[str].push_back(og);
            }
            else{
                mp[str] = {og};
            }
        }

        for(auto &x: mp){
            vec.push_back(x.second);
        }

        return vec;
        
    }
};
