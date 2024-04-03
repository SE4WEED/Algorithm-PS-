#include <string>
#include <string.h>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    int yyyy=0,mm=0,dd=0;
    string tmp = "";
    for (auto c : today){
        if(c!='.'){
            tmp += c;
        }else{
            if(yyyy==0){
                yyyy = stoi(tmp);
                tmp = "";
            }else if(mm==0){
                mm = stoi(tmp);
                tmp = "";
            }
        }
    }
    dd = stoi(tmp);
    
    char jong[101];
    int gigan[101];
    for(int i=0;i<terms.size();i++){
        jong[i] = terms[i][0];
        gigan[i] = stoi(terms[i].substr(2));
    }
    vector<int> answer;  
    
    char now;
    int nowy, nowd, nowm;
    int nowgigan;
    for(int i=0;i<privacies.size();i++){
        now = privacies[i][11];
        nowy = stoi(privacies[i].substr(0,4));
        nowm = stoi(privacies[i].substr(5,2));
        nowd = stoi(privacies[i].substr(8,2));
        for(int k=0;k<terms.size();k++){
            if(terms[k][0]==now){
                nowgigan = gigan[k];
                //printf("%d\n",nowgigan);
                break;
            }
        }
        nowm += nowgigan;
        if(nowm>12){
            nowy += nowm/12;
            nowm %= 12;
            if(nowm==0){
                nowm = 12;
                nowy -=1;
            }
        }
        if(yyyy>nowy){//오늘이 지금거 끝나는 년도보다 미래면 상관 없네 이미 끝난거네
            answer.push_back(i+1);
        }else if(yyyy==nowy){
            if(mm>nowm){
                answer.push_back(i+1);
            }else if(mm==nowm){
                if(dd>nowd){
                    answer.push_back(i+1);
                }else if(dd==nowd){
                    answer.push_back(i+1);
                }
            }
        }
    }
    
    return answer;
}