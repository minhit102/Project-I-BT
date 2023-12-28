#include <bits/stdc++.h> 
using namespace std;

bool check(string str){
    stack <char> st;
    for(char t : str){
        if(t =='(' || t =='{' || t =='['){
            st.push(t);
        }
        else if(st.empty()){
            return false;
        }
        else if((t == ')' && st.top() == '(') || (t == '}' && st.top() == '{') || (t == ']' && st.top() == '[')){
            st.pop();
        }
        else {
            return false;
        }
    }
    return st.empty();
}

int main() 
{
    string str;
    cin >> str;
    if(check(str)){
        cout <<  1;
    }
    else cout << 0;

    return 0;
}
