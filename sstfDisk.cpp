#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, head, total=0;
    cout<<"Enter number of cylinders and head position: ";
    cin>>n>>head;
    int cylinders[n];
    cout<<"Enter the cylinder positions: ";
    for(int i=0;i<n;i++) cin>>cylinders[i];
    bool visited[n]={false};
    for(int i=0;i<n;i++){
        int min_dist=INT_MAX, idx=-1;
        for(int j=0;j<n;j++){
            if(!visited[j]){
                int dist=abs(head-cylinders[j]);
                if(dist<min_dist){
                    min_dist=dist;
                    idx=j;
                }
            }
        }
        visited[idx]=true;
        total+=min_dist;
        head=cylinders[idx];
    }
    cout<<"\nTotal Movement : "<<total<<endl;
}