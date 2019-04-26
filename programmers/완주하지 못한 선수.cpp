#include <string>
#include <vector>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";

    vector<string> hash[600];
    while(!completion.empty()){
        string s = completion.back();

        int tmp = 0;
        for(int i = 0 ; i < s.size(); i++) tmp += (s[i] - 96);

        hash[tmp].push_back(s);
        completion.pop_back();
    }

    while(!participant.empty()){
        string s = participant.back();

        int tmp = 0;
        for(int i = 0 ; i < s.size(); i++) tmp+= (s[i] - 96);

        if(hash[tmp].size() == 0) answer = s;
        else{
            int exist = 1;
            for(int i = 0 ; i < hash[tmp].size() ; i++){
                if(hash[tmp][i] == s){
                    exist = 0;
                    hash[tmp].erase(hash[tmp].begin() + i);
                    break;
                }
            }
            if( exist == 1) answer = s;
        }
        participant.pop_back();
    }

    return answer;
}
