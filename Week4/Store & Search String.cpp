#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

unordered_set<string> st;
vector<int> vt;

bool findStr(const string& str) {
    return st.find(str) != st.end();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string line;
    while (getline(cin, line) && line != "*") {
        st.insert(line);
    }

    string require, value;
    while (cin >> require && require != "***") {
        if (require == "find") {
            cin >> value;
            vt.push_back(findStr(value) ? 1 : 0);
        } else if (require == "insert") {
            cin >> value;
            if (!findStr(value)) {
                vt.push_back(1);
                st.insert(value);
            } else {
                vt.push_back(0);
            }
        }
    }

    for (int x : vt) {
        cout << x << endl;
    }

    return 0;
}

