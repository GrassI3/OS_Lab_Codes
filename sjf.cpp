#include<bits/stdc++.h>
using namespace std;
struct process {
    int BT,AT,WT,TAT,CT,ID;
};
bool compare(process a, process b){
    return a.AT<b.AT;
}
int main() {
    int n;
    float atat=0, awt=0;
    cout<<"Enter number of processes: ";
    cin>>n;
    vector<process> p(n);
    cout<<"Enter AT and BT for process: ";
    for(int i=0; i<n;i++){
        cin>>p[i].AT>>p[i].BT;;
        p[i].ID = i+1;
    }
    sort(p.begin(), p.end(),compare);
    int currentTime = p[0].AT;
    for(int i=0; i<n; i++){
        int idx = -1;
        int minBT = INT_MAX;
        for(int j=0; j<n; j++){
            if(p[j].AT <= currentTime && p[j].BT < minBT && p[j].CT == 0){
                minBT = p[j].BT;
                idx = j;
            }
        }
        if(idx == -1){
            currentTime++;
            i--;
            continue;
        }
        currentTime += p[idx].BT;
        p[idx].CT = currentTime;
        p[idx].TAT = p[idx].CT - p[idx].AT;
        p[idx].WT = p[idx].TAT - p[idx].BT;
        atat += p[idx].TAT;
        awt += p[idx].WT;
    }
    cout<<"PID\tAT\tBT\tCT\tTAT\tWT\n";
    for(int i=0; i<n; i++){
        cout<<p[i].ID<<"\t"<<p[i].AT<<"\t"<<p[i].BT<<"\t"<<p[i].CT<<"\t"<<p[i].TAT<<"\t"<<p[i].WT<<"\n";
    }
    cout<<"Average TAT: "<<atat/n<<endl;
    cout<<"Average WT: "<<awt/n<<endl;
}