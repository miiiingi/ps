#include<string>
#include<vector>

using namespace std;
bool judge(char temp1, char temp2){
    if(temp1 == '(' && temp2 == ')'){
        return true;
    } else{
        return false;
    }
}

bool solution(string s)
{
    vector<char> stack;
    for(int i = 0; i < s.size(); i++){
        if(stack.empty()){
            stack.push_back(s[i]);
        } else {
            if(judge(stack.back(), s[i])){
                stack.pop_back();
            } else{
                stack.push_back(s[i]);
            }
        }
    }
    if(stack.empty()){
        return true;
    } else{
        return false;
    }
}