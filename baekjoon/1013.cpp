#include <iostream>
#include <string>
#include <regex>

using namespace std;

string removePattern(const string& str) {
    string result;
    regex pattern1("100+1");
    result = regex_replace(str, pattern1, "");
    regex pattern2("01");
    result = regex_replace(result, pattern2, "");
    return result;
}
int main() {
    int T;
    string str;
    cin >> T;
    while(T--){
        cin >> str;
        str = removePattern(str);
        if (!str.empty())
        {
            for (auto c : str)
            {
                if (c == '0')
                {
                    cout << "NO";
                    break;
                }
                
            }
            cout << "YES";
        } else
        {
            cout << "YES";
        }
        cout << "\n";
    }
    return 0;
}