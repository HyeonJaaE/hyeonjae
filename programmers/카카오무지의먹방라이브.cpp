#include <string>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

//pair(value, idx)
vector<pair<long long, int>> _food_times;

bool compare(const pair<long long, int>& a, const pair<long long, int>& b){
    return a.second < b.second;
}

int solution(vector<int> food_times, long long k) {
    int answer = 0;
    long long N = food_times.size();

    for(int i = 0 ; i < N; i++)
        _food_times.push_back(make_pair(food_times[i], i+1));

    sort(_food_times.begin(), _food_times.end());

    long long i;
    long long tmp = _food_times[0].first;

    for(i = 0; i < N ;i++){
        if( i > 0 ) tmp = _food_times[i].first - _food_times[i-1].first;
        //젤 작은 숫자 * N 이 k 보다 작으면 한바꾸 다 못 돔
        if(k - (tmp * ( N - i )) < 0 ) break;
        k -= tmp * ( N - i );
    }

    if(i == N) return -1;

    sort(_food_times.begin() + i, _food_times.end(), compare);
    answer = _food_times[i + k % ( N - i )].second;
    return answer;
}
