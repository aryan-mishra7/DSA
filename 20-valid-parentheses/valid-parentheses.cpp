class Solution {
private:
bool match(char ch,char br){
    if(ch=='{'&&br=='}')
    return true;
    if(ch=='['&&br==']')
    return true;
    if(ch=='('&&br==')')
    return true;
    return false;
}
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.length();i++){
            //agar opening bracket hai to stack mai psuh kro
            //agar closing braket hai to stack.top se compare caro or pop krdo
            char ch = s[i];
            if(ch=='{'||ch=='['||ch=='(')
            st.push(ch);
            else{
                if(!st.empty()){
                    if(match(st.top(),ch))
                    st.pop();
                    else{
                        return false;
                    }
                }
                //agar stack empty nahi hai or hame closing bracket mil gya to y unbalanced hai
                else
                return false;
            }
        }
        if(st.empty())
        return true;
        return false;
    }
};