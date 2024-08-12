#include <iostream>
#include <string>
#include <regex>

using namespace std;

bool removePattern(const string& str) {
    string result;
    regex pattern1("(100+1+|01)+");
    return regex_match(str, pattern1);
}
int main() {
    int T;
    string str;
    cin >> T;
    while(T--){
        cin >> str;
        if (!removePattern(str))
        {
            cout << "NO\n";
        } else
        {
            cout << "YES\n";
        }
    }
    return 0;
}