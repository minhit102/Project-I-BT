#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() 
{ 
    stack<string> stackStr;
    vector<string> outStr;
    while(true){
        string Str;
        getline(cin, Str);
        if(Str == "#") break;
        else if(Str != "POP"){
            stackStr.push(Str);
        }
        else{
            if(stackStr.empty()){
                outStr.push_back("NULL");
            }
            else{
                char stringInt = stackStr.top().back();
                string myString(1, stringInt);
                outStr.push_back(myString);
                stackStr.pop();
            }
        }
    }

    for(string x : outStr){
        cout << x << endl;
    }

    return 0;
}
