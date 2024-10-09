#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int maxWidth = 0, maxHeight = 0;
    for(int i = 0; i < sizes.size(); i++){
        if(sizes[i][0] < sizes[i][1]){
            int temp = sizes[i][1];
            sizes[i][1] = sizes[i][0];
            sizes[i][0] = temp;
        }
        maxWidth = max(sizes[i][0], maxWidth);
        maxHeight = max(sizes[i][1], maxHeight);
    }
    return maxWidth * maxHeight;
}