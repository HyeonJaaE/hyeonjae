#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;

    make_heap(citations.begin(), citations.end());
    sort_heap(citations.begin(), citations.end());

    for(int i = citations.size() -1 ; i >= 0 ; i--){
        if(citations.size() - i >= citations[i]){
            answer = citations[i];
            break;
        }
    }

    for(int i = citations.size() ; i >= 0 ; i--){
        int cnt = 0;
        for(int j = citations.size() - 1; j >= 0 ; j--){
            if(citations[j] >= i ) cnt++;
            if(cnt == i && i > answer){
                answer = i;
                return answer;
            }
        }
    }
    return answer;
}
