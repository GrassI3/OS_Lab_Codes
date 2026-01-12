#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, head, prev, total=0;
    cout<<"Enter number of cylinders, head position and previous head position: ";
    cin>>n>>head>>prev;
    int cylinders[n];
    cout<<"Enter the cylinder positions: ";
    for(int i=0;i<n;i++) cin>>cylinders[i];
    sort(cylinders, cylinders+n);

    vector<int> left, right;
    for(int i=0;i<n;i++){
        if(cylinders[i] < head) left.push_back(cylinders[i]);
        else right.push_back(cylinders[i]);
    }
    if(head > prev){
        for(int i=0;i<right.size();i++){
            total += abs(head - right[i]);
            head = right[i];
        }
        for(int i=0;i<left.size();i++){
            total += abs(head - left[i]);
            head = left[i];
        }
    }
    else{
        for(int i=left.size()-1;i>=0;i--){
            total += abs(head - left[i]);
            head = left[i];
        }
        for(int i=right.size()-1;i>=0;i--){
            total += abs(head - right[i]);
            head = right[i];
        }
    }
    cout<<"Total Head Movement: "<<total<<endl;
}
