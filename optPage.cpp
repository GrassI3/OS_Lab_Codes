#include<bits/stdc++.h>
using namespace std;

int main(){
    int f,n, faults=0;
    cout<<"Enter number of frames and number of pages: ";
    cin>>f>>n;
    int pages[n], frame[f];
    cout<<"Enter the page reference string: ";
    for(int i=0;i<n;i++) cin>>pages[i];
    for(int i=0;i<f;i++) frame[i]=-1;
    cout <<"Frames\n1   2   3 \n";
    for(int i=0;i<n;i++){
        bool hit=false;
        for(int j=0;j<f;j++){
            if(frame[j]==pages[i]){
                hit=true;
                break;
            }
        }
        if(!hit){
            int idx=-1, far=-1;
            for (int j = 0; j < f; j++) {
                int k;
                for (k = i + 1; k < n; k++)
                    if (frame[j] == pages[k]) break;
                if (k == n) { idx = j; break; }
                if (k > far) { far = k; idx = j; }
            }
            frame[idx] = pages[i];
            faults++;
        }
        for (int i=0;i<f;i++) cout<<frame[i]<<" ";
        if(hit) cout<<"Hit\n";
        else cout<<"Fault\n";
    }
    cout<<"Total Page Faults: "<<faults<<endl;
}