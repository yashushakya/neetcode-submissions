class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char,char> closeopen ={
            {')', '('}, {'}', '{'} , { ']' , '['}
        };
        
        for(const char& c:s){
            if(closeopen.count(c)){
                if(!st.empty() && st.top()==closeopen[c]){
                    st.pop();
                }
                else return false;
            }   
            else{
                st.push(c);
            }         
        }

        return st.empty();
    }
};
