#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

int main()
{
    int N;
    cin >> N;
    cin.ignore();
    vector<string> arr(N);
    set<char> abbr;
    vector<string> words;

    for (int i = 0; i < N; i++)
    {
        bool flag = false;
        words.clear();
        string in;
        getline(cin, in);
        string temp = "";
        for (auto &c : in)
        {
            if (c == ' ')
            {
                words.push_back(temp);
                temp = "";
                continue;
            }
            temp += c;
        }
        words.push_back(temp);
        string out = "";
        for (size_t i = 0; i < words.size(); i++)
        {
            string word = words[i];
            for (size_t j = 0; j < word.size(); j++)
            {
                if (j == 0 && abbr.find(toupper(word[j])) == abbr.end() && !flag)
                {
                    abbr.insert(toupper(word[j]));
                    out += '[';
                    out += word[j];
                    out += ']';
                    flag = true;
                }
                else
                {
                    out += word[j];
                }
            }
            if (words.size() > 1)
            {
                out += " ";
            }
        }
        if (!flag)
        {
            out = "";
            for (size_t i = 0; i < words.size(); i++)
            {
                string word = words[i];
                for (size_t j = 0; j < word.size(); j++)
                {
                    if (abbr.find(toupper(word[j])) == abbr.end() && !flag)
                    {
                        abbr.insert(toupper(word[j]));
                        out += '[';
                        out += word[j];
                        out += ']';
                        flag = true;
                    }
                    else
                    {
                        out += word[j];
                    }
                }
                if (words.size() > 1)
                {
                    out += " ";
                }
            }
            cout << out;
        }
        else
        {
            cout << out;
        }

        cout << "\n";
    }

    return 0;
}