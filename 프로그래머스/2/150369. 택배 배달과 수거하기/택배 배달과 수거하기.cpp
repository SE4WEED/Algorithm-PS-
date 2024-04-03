#include <string>
#include <vector>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    int nowd = n-1;
    int nowp = n-1;
    int sumd = 0;
    int sump = 0;
    int nowtr = 0;
    for(int i=n-1;i>=-1;i--){
        if(i==-1){
            nowd = -1;
        }
        if(deliveries[i]!=0){
            nowd = i;
            break;
        }
    }
    for(int i=n-1;i>=-1;i--){
        if(i==-1){
            nowp = -1;
        }
        if(pickups[i]!=0){
            nowp = i;
            break;
        }
    }
    while(nowd>=0||nowp>=0){
        answer += 2*(max(nowd,nowp)+1);
       // printf("%d  %d\n",nowd, nowp);
        sumd=0;
        sump=0;
        int nnd,nnp;
        nnd = nowd;
        nnp = nowp;
        for(int i=nnd;i>=-1;i--){
            if(i==-1){
                nowd = i;
                break;
            }
            if(deliveries[i]+sumd<cap){//다 넣어도되면
                sumd += deliveries[i];
                deliveries[i]=0;//넣어버려
            }else if(deliveries[i]+sumd==cap){//딱코
                sumd += deliveries[i];
                deliveries[i]=0;
                int j = i-1;
                for(;j>=0;j--){
                    if(deliveries[j]!=0){//0이아닌놈 -> 다음에 봐야되는놈
                        break;
                    }
                }
                nowd = j;
                break;
            }else{//넘친다
                int diff = cap - sumd;
                deliveries[i] -= diff;
                nowd = i;
                break;
            }
        }
        
        for(int i=nnp;i>=-1;i--){
            if(i==-1){
                nowp = i;
                break;
            }
            if(pickups[i]+sump<cap){//다 넣어도되면
                sump += pickups[i];
                pickups[i]=0;//넣어버려
            }else if(pickups[i]+sump==cap){//딱코
                sump += pickups[i];
                pickups[i]=0;
                int j = i-1;
                for(;j>=0;j--){
                    if(pickups[j]!=0){//0이아닌놈 -> 다음에 봐야되는놈
                        break;
                    }
                }
                nowp = j;
                break;
            }else{//넘친다
                int diff = cap - sump;
                pickups[i] -= diff;
                nowp = i;
                break;
            }
            
        }
        
        //printf("end   %d  %d\n",nowd, nowp);
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    //일단 시작할때 최대한 뒤에있는놈 ㅇㅇ
//     answer = 0;
//     while(nowd!=0||nowp!=0){//하나라도 할 게 있으면 해야됨
//         sumd=0;
//         sump=0;
//         answer += 2*max(nowd,nowp);
//         for(; nowd >=0; nowd--){
//             if(sumd+deliveries[nowd]<=cap){
//                 sumd += deliveries[nowd];
//             }else{
//                 break;
//             }
//         }
//         for(; nowp >=0; nowp--){
//             if(sump+pickups[nowp]<=cap){
//                 sump += pickups[nowp];
//             }else{
//                 break;
//             }
//         }
//     }
    
    
    
    
    
    return answer;
}
