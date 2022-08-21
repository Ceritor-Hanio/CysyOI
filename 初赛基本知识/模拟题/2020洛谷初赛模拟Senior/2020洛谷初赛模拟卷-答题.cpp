#include <string>
#include <iostream>
using namespace std;

int main() {
    string ans =
        "ABCBACABCBDBAAC"
        "FTTTBA"
        "FTTTAA"
        "FTFTCB"
        "CDDBC"
        "CBDCB";
    int no;
    cin >> no;
    cout << ans[no - 1];
    return 0;
}

// 86 pts