class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char,char> closeopen ={
            {')', '('}, {'}', '{'} , { ']' , '['}
        };
        
        for(const char& c:s){
            if(!st.empty()){
                if(c=='(' || c=='{' || c=='[') st.push(c);
                else if(st.top()=='{' && c=='}') st.pop();
                else if(st.top()=='(' && c==')') st.pop();
                else if(st.top()=='[' && c==']') st.pop();
                else return false;
            }
            else{
                if(c=='}' || c==')' || c==']') return false;
                else st.push(c);
            }    
        }

        return st.empty();
    }
};
