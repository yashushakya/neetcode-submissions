class Solution {
public:

    string encode(vector<string>& strs) {

        if(strs.size()==0) return "";
        string s = "";

        for(auto &ch: strs){
            int size = ch.size();
            s+= to_string(size);
            s+="#";
            s+=ch;
        }
        return s;
    }

    vector<string> decode(string s) {
        if(s=="") return {};
        vector<string> ans;
        string temp = "";
        int num = 0;
        bool brk = false;
        for(char &c:s){
            if(!brk){ //read length
                if(isdigit(c) && brk ==false){
                    num = num *10 + (c-'0');
                }
                else if(c=='#'){
                    brk =true;
                    if(num==0){
                        ans.push_back("");
                        brk = false;
                    }
                }
            }
            else{
                //read content
                temp+=c;
                num--;
                if(num==0){
                    ans.push_back(temp);
                    temp="";
                    brk =false;
                }                
            }           
            
        }

        return ans;

    }
};
