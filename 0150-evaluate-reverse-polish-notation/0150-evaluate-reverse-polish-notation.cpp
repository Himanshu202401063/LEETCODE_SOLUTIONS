class Solution {
public:
    int evalRPN(vector<string>& tokens) {
         stack<int>s;
         for(auto&i:tokens){
            if(i!="+"  &&i!="-" &&i!="*"&&i!="/"){
                s.push(stoi(i));
            }
            else if(i=="+"){
                int x = s.top();
                s.pop();
                int y = s.top();
                s.pop();
                 s.push(x+y);
            }
            else if(i=="-") {
                 int x = s.top();
                s.pop();
                int y = s.top();
                s.pop();
                 s.push(-x+y);

            }
            else if(i=="*"){
                 int x = s.top();
                s.pop();
                int y = s.top();
                s.pop();
                 s.push(x*y);
            }
            else {
                 int x = s.top();
                s.pop();
                int y = s.top();
                s.pop();
                 s.push(y/x);
            }
         }
          return s.top();
    }
};