#include <bits/stdc++.h>

using namespace std;

int main() 
{ 
    queue<string> queueStr;
    vector<string> outStr;
    while(true){
        string Str;
        getline(cin, Str);
        if(Str == "#") break;
        else if(Str != "POP"){
            queueStr.push(Str);
        }
        else{
            if(queueStr.empty()){
                outStr.push_back("NULL");
            }
            else{
                char stringInt = queueStr.front().back();
                string myString(1, stringInt);
                outStr.push_back(myString);
                queueStr.pop();
            }
        }
    }

    for(string x : outStr){
        cout << x << endl;
    }

    return 0;
}
