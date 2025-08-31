class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string ch;
        stringstream ss(path);
       while(getline(ss, ch, '/'))
       {
          if(ch == "" || ch ==".") continue;

          if(ch == "..")
          {
            if(!st.empty()) {
                st.pop();
            }
          }
          else{
          st.push(ch);

          }
       }

       string res ="";
       while(!st.empty())
       {
        res = "/"+st.top()+res;
        st.pop();
       }

       return res.empty() ? "/":res;


    }
};