#include <iostream>
using namespace std;

int main() {
    string time;
    cin >> time;

    if (time.size() != 8 || time[2] != ':' || time[5] != ':') {
        cout << "INCORRECT" << endl;
        return 0;
    }

    int hour, minute, second;
    if (sscanf(time.c_str(), "%d:%d:%d", &hour, &minute, &second) != 3) {
        cout << "INCORRECT" << endl;
        return 0;
    }

    if (hour < 0 || hour > 23 || minute < 0 || minute > 59 || second < 0 || second > 59) {
        cout << "INCORRECT" << endl;
        return 0;
    }

    int result = hour * 3600 + minute * 60 + second;
    cout <<  result << endl;

    return 0;
}

