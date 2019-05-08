#include <string>
#include <vector>

using namespace std;

int cnt = 0;

void DFS(vector<int> &numbers, int sum, int &target, int distance){
    if(distance >= numbers.size()){
        if(sum == target) cnt++;
        return;
    }

    DFS(numbers, sum + numbers[distance] , target , distance+1);
    DFS(numbers, sum - numbers[distance] , target , distance+1);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;

    DFS(numbers, numbers[0],  target, 1);
    DFS(numbers, -numbers[0], target, 1);

    answer = cnt;
    return answer;
}
