#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end());
    for(int i = 0; i < phone_book.size() - 1; i++){
        int size = phone_book[i].size();
        if(phone_book[i+1].substr(0, size) == phone_book[i]){
            return false;
        }
    }
    return true;
}