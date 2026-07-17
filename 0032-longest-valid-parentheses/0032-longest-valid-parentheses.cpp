class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);

        int ans = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                st.pop();

                if (st.empty()) {
                    st.push(i);
                } else {
                    ans = max(ans, i - st.top());
                }
            }
        }

        // int mx =0;
        // int ans =0;
        // for(int i=0;i<s.size();i++){
        //     if(s[i]=='('){
        //         st.push(s[i]);
        //     }
        //     else {
        //         if(st.empty()) ans =0;
        //         if( !st.empty() && st.top()=='(') {
                    
        //             ans += 2;
        //             st.pop();
        //         }
        //         else ans =0;
            
        //     }
        //      mx = max(mx,ans);
        // }

        // return mx;
         return ans;
    }
};