/*
#include <iostream>
#include<string>
using namespace std;


int solution(string s)
{
    bool finded;
    while(!s.empty()){
        finded = false;
        for(int i = 0; i < s.size() - 1; i++){
            if(s[i] == s[i+1]){
                s.erase(i, 2);
                finded = true;
                break;
            }
        }
        if(!finded){
            return 0;
        }
    }
    return 1;
}
*/
#include<vector>
#include<string>
using namespace std;


int solution(string s)
{
    vector<int> stack;
    for(int i = 0; i < s.size(); i++){
        if(stack.empty()){
            stack.push_back(s[i]);
            continue;
        }
        if(stack.back() == s[i]){
            stack.pop_back();
        } else{
            stack.push_back(s[i]);
        }
    }
    if(!stack.empty()){
        return 0;
    } else{
        return 1;
    }
}