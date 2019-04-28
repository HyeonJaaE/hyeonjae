#include <string>
#include <vector>
#include <algorithm>

using namespace std;
/*
    priorities = [1,1,9,1,1,1]
    힙 정렬 [1,1,1,1,1,9]
    최대값이 priorities[i] 와 동일하면 cnt++
    index가 location 일때 cnt++ 하면 해당 cnt 반환
*/

int solution(vector<int> priorities, int location) {
    vector<int> tmp = priorities;

    make_heap(tmp.begin(), tmp.end());
    sort_heap(tmp.begin(), tmp.end());

    int cnt = 0;
    int val = tmp.back();
    tmp.pop_back();
    int i = 0;
    while(i < priorities.size()){
        i = i % priorities.size();

        if( priorities[i] == val ){
            if(i == location){
                cnt++;
                return cnt;
            }
            cnt++;
            val = tmp.back();
            tmp.pop_back();
        }
        i++;
    }


}
