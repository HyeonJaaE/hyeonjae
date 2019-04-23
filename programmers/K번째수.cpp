#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> v;

    for(int k = 0 ; k < commands.size() ; k++){
        for(int i = commands[k][0]-1 ; i < commands[k][1]; i++ ){
            if(v.size() == 0){
                v.push_back(array[i]);
            }
            else{
                for(int j = 0 ; j < v.size(); j++){
                    if(array[i] < v[j]){
                        v.insert(v.begin() + j, array[i]);
                    }
                }
            }
        }
        v.clear();
        answer.push_back(v[commands[k][2]-1]);
    }
    return answer;
}
