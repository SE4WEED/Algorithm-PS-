#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <map>
#include <algorithm>
using namespace std;
int solution(vector<string> friends, vector<string> gifts) {
    int dp[55][55]={0,};
    int giff[55]={0,};
    map<string,int> m1;
    for(int i=0;i<friends.size();i++){
        m1[friends[i]] = i;
    }
    
    for(auto g : gifts){
        stringstream s(g);
        string ju, bad;
        s >> ju >> bad;
        int j, b;
        j = m1[ju];
        b = m1[bad];
        dp[j][b]++;    
        giff[j]++;
        giff[b]--;
    }
    int ansarr[55]={0,};
    for(int i=0;i<friends.size();i++){
        for(int j=i+1;j<friends.size();j++){
            if(dp[i][j]<dp[j][i]){
                ansarr[j]++;
            }else if(dp[i][j]>dp[j][i]){
                ansarr[i]++;
            }else{
                if(giff[i]>giff[j]){
                    ansarr[i]++;
                }else if(giff[i]<giff[j]){
                    ansarr[j]++;
                }else{
                    continue;
                }
            }
        }
    }
    int answer = 0;
    for(int i=0;i<friends.size();i++){
        answer = max(answer,ansarr[i]);
    }
    return answer;
}