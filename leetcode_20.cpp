#include<iostream>
#include<stack>
using namespace std;

bool isValid(string s) {
    stack<char> ch_stk;
    for(auto ch : s){
        if(ch == '(' || ch == '[' || ch == '{')
            ch_stk.push(ch);
        else if(ch == ')'){
            if(ch_stk.empty())
                return false;
            if(ch_stk.top() != '(')
                return false;
            else ch_stk.pop();
        } else if(ch == ']'){
            if(ch_stk.empty())
                return false;
            if(ch_stk.top() != '[')
                return false;
            else ch_stk.pop();
        } else if(ch == '}'){
            if(ch_stk.empty())
                return false;
            if(ch_stk.top() != '{')
                return false;
            else ch_stk.pop();
        }
    }
    if(ch_stk.empty())
        return true;
    else
        return false;
}
int main(){
    cout << isValid("(") << endl;
    return 0;
}
