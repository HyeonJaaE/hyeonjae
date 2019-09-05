#include <vector>

using namespace std;

int M , N, size;
vector<vector<int>> V;
int a[100][100];
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.

void search(int num, int r, int c){
    if( r - 1 >= 0 && V[r][c] == V[r-1][c] && a[r-1][c] == 0){
        size += 1;
        a[r-1][c] = num;
        search( num, r-1, c);
    }
    if( r + 1 < M && V[r][c] == V[r+1][c] && a[r+1][c] == 0){
        size += 1;
        a[r+1][c] = num;
        search( num, r+1, c);
    }
    if( c - 1 >= 0 && V[r][c] == V[r][c-1] && a[r][c-1] == 0){
        size += 1;
        a[r][c-1] = num;
        search( num, r, c-1);
    }
    if( c + 1 < N && V[r][c] == V[r][c+1] && a[r][c+1] == 0){
        size += 1;
        a[r][c+1] = num;
        search( num, r, c+1);
    }
    return;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    M = m;
    N = n;
    V = picture;
    for(int i = 0 ; i < 100 ; i++){
        for(int j = 0 ; j < 100 ; j++){
            a[i][j] = 0;
        }
    }

    for(int r = 0 ; r < m ; r++){
        for(int c = 0 ; c < n ; c++){
            if(V[r][c] != 0 && a[r][c] == 0){
                number_of_area += 1;
                a[r][c] = number_of_area;
                size = 1;
                search(number_of_area, r, c);
                if ( size >= max_size_of_one_area ) max_size_of_one_area = size;
            }
        }
    }

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}

/*
input
[
[0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0],
[0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0],
[0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0],
[0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0],
[0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0],
[0,1,1,1,1,2,1,1,1,1,2,1,1,1,1,0],
[0,1,1,1,2,1,2,1,1,2,1,2,1,1,1,0],
[0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0],
[0,1,3,3,3,1,1,1,1,1,1,3,3,3,1,0],
[0,1,1,1,1,1,2,1,1,2,1,1,1,1,1,0],
[0,0,1,1,1,1,1,2,2,1,1,1,1,1,0,0],
[0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0],
[0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0]
]
*/
