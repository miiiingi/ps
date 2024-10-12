#include <string>
#include <set>
#include <vector>
using namespace std;

/*
1. set을 이용해서 방문한 곳을 찾는 알고리즘 까지는 맞았는데, 디테일한 부분이 부족했다.
2. prev, cur를 나눈 것과 그리고 양방향을 다 고려해주어야한다는 것까지 고려를 했어야함.
*/

int answer = 0;
pair<int, int>move(pair<int, int> curP, char d, set<pair<pair<int, int>, pair<int, int>>>&visited){
    pair<int, int>prevP = curP;
    
    if(d == 'U' && curP.second + 1 <= 5){
        curP.second++;
    } else if(d == 'L' && curP.first - 1 >= -5){
        curP.first--;
    } else if(d == 'R' && curP.first + 1 <= 5){
        curP.first++;
    } else if(d == 'D' && curP.second -1 >= -5){
        curP.second--;
    }
    
    if(prevP != curP){
        pair<int, int> path1 = {prevP.first, prevP.second};
        pair<int, int> path2 = {curP.first, curP.second};
        if(visited.find({path1, path2}) == visited.end() && visited.find({path2, path1}) == visited.end()){
            visited.insert({path1, path2});
            visited.insert({path2, path1});
            answer++;
        }
    }
    return curP;
}

int solution(string dirs) {
    pair<int, int> curP = {0, 0};
    set<pair<pair<int, int>, pair<int, int>>> visited;
    for(char d: dirs){
        curP = move(curP, d, visited);
    }
    return answer;
}