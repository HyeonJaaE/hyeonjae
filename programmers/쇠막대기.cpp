#include <string>
#include <vector>

using namespace std;

int solution(string arrangement) {
    int answer = 0;
    for(int i = 0 ; i < arrangement.size() ; i++){
        if(arrangement[i+1] == ')'){
            i++;
        } // 레이저만 있을 때 = 필요없음
        else if(arrangement[i] == '(' && arrangement[i+1] == '('){
            int bracket = 1;
            int laser = 0;
            for(int j = i + 1 ; j < arrangement.size() ; j++ ){
                if(arrangement[j] == '(' && arrangement[j + 1] == ')') {
                    laser++;
                    j++;
                }
                else if(arrangement[j] == '(' && arrangement[j + 1] == '('){
                    bracket++;
                }
                else bracket--;

                if(bracket == 0){
                    laser++;
                    answer += laser;
                    laser = 0;
                    break;
                }
            }
        }
    }
    return answer;
}
