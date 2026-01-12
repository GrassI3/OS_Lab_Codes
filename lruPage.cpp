#include<bits/stdc++.h>
using namespace std;

int main(){
    int f,n, faults=0, idx=0;
    cout<<"Enter number of frames and number of pages: ";
    cin>>f>>n;
    int pages[n], frame[f], time[f];
    cout<<"Enter the page reference string: ";
    for(int i=0;i<n;i++) cin>>pages[i];
    for(int i=0;i<f;i++) frame[i]=-1;
    cout <<"Frames\n1   2   3 \n";
    for(int i=0;i<n;i++){
        bool hit=false;
        for(int j=0;j<f;j++){
            if(frame[j]==pages[i]){
                hit=true;
                time[j] = ++idx;
                break;
            }
        }
        if(!hit){
            int lru = 0;
            for(int j=1;j<f;j++){
                if(time[j]<time[lru]) lru=j;
            }
            frame[lru] = pages[i];
            time[lru] = ++idx;
            faults++;
        }
        for (int i=0;i<f;i++) cout<<frame[i]<<" ";
        if(hit) cout<<"Hit\n";
        else cout<<"Fault\n";
    }
    cout<<"Total Page Faults: "<<faults<<endl;
}