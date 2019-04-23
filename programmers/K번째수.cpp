#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> v;

    while(!commands.empty()){
        for(int i = commands[0][0] - 1 ; i < commands[0][1] ; i++){
            v.push_back(array[i]);
        }
        make_heap(v.begin(), v.end());
        sort_heap(v.begin(), v.end());


        answer.push_back(v[commands[0][2] -1]);
        commands.erase(commands.begin());
        v.clear();
    }
    return answer;
}
