// Microsoft
class Solution {
public:

    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        unordered_map<string,function<int (int,int)>> mp = {
            {"+",[](int a,int b) {return a+b;} },
            {"-",[](int a,int b) {return a-b;} },
            {"*",[](int a,int b) {return (long)a*(long)b;} },
            {"/",[](int a,int b) {return a/b;} }
        };

         

        for(string &token : tokens){ // for each token in tokens
            if(token == "+" || token == "-" || token == "*" || token == "/"){
                // top 2 elements ko pop karke operate karlo
                // then push back eveluated in the stack

                int b =  st.top();  // stack ke top wala
                st.pop();
                
                int a =  st.top();  // jo hai top pe wo
                st.pop();

                // operate karne ke liye Operate name ka funtion

                int result = mp[token](a,b);
                st.push(result);

            }
            else 
            {
                st.push(stoi(token)); // if operator does not come any string would come so convert it in number
            }
        }
        return st.top();
    }
};