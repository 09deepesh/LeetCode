class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> st;

        for(int i = 0; i < tokens.size() ; i++)
        {
            if(tokens[i] == "+" || tokens[i] == "/" || tokens[i] == "-"||tokens[i] == "*")
            {
                long long b = st.top(); st.pop();
                long long a = st.top() ;st.pop();

                long long res = 0;

                if(tokens[i] == "+") res = a+b;
                else if(tokens[i] == "*") res = a*b;
                else  if(tokens[i] == "/") res = a/b;
                else  if(tokens[i] == "-") res = a-b;

                st.push(res);
            }
            else {
    st.push(stoll(tokens[i]));
}

        }

        return (int)st.top();
    }
};