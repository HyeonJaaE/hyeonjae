#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;

    int arrA[] = {1,2,3,4,5};
    int arrB[] = {2,1,2,3,2,4,2,5};
    int arrC[] = {3,3,1,1,2,2,4,4,5,5};

    vector<int> cnt;
    for(int i = 0 ; i < 3; i ++){
        cnt.push_back(0);
    }

    for(int i = 0 ; i < answers.size() ; i++){
        int tmp = i % 5;
        if(answers[i] == arrA[tmp]) cnt[0]++;
    }

    for(int i = 0 ; i < answers.size() ; i++){
        int tmp = i % 8;
        if(answers[i] == arrB[tmp]) cnt[1]++;
    }

    for(int i = 0 ; i < answers.size() ; i++){
        int tmp = i % 10;
        if(answers[i] == arrC[tmp]) cnt[2]++;
    }

    int max = cnt[0];
    for(int i = 1 ; i < 3 ; i++){
        if(cnt[i] > max) max = cnt[i];
    }

    for(int i = 0 ; i < 3 ; i++){
        if(cnt[i] == max) answer.push_back(i+1);
    }


    return answer;
}
