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
        if(currentTime<p[i].AT){
            currentTime = p[i].AT;
        }
        currentTime += p[i].BT;
        p[i].CT = currentTime;
        p[i].TAT = p[i].CT -p[i].AT;
        p[i].WT = p[i].TAT - p[i].BT;
        atat += p[i].TAT;
        awt += p[i].WT;
    }
    cout<<"PID\tAT\tBT\tCT\tTAT\tWT\n";
    for(int i=0; i<n; i++){
        cout<<p[i].ID<<"\t"<<p[i].AT<<"\t"<<p[i].BT<<"\t"<<p[i].CT<<"\t"<<p[i].TAT<<"\t"<<p[i].WT<<"\n";
    }
    cout<<"Average TAT: "<<atat/n<<endl;
    cout<<"Average WT: "<<awt/n<<endl;
}