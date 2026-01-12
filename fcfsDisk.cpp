#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, head, total=0;
    cout<<"Enter number of cylinders and head position: ";
    cin>>n>>head;
    int cylinders[n];
    cout<<"Enter the cylinder positions: ";
    for(int i=0;i<n;i++) cin>>cylinders[i];
    for(int i=0;i<n;i++){
        total += abs(cylinders[i]-head);
        head = cylinders[i];
    }
    cout<<"Total Head Movement: "<<total<<endl;
}