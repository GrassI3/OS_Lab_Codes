#include<iostream>
using namespace std;

string buffer[100];
int in=0, out=0, emptyVar=0, full=0, count=0, mutex=1;

void signal(int &s){
    s++;
}
void wait(int &s){
    if(s<=0) cout<<"Buffer full/empty, waiting...\n";
    else s--;
}
void produce(){
    wait(mutex);
    wait(emptyVar);
    cout<<"Enter item to produce: ";
    string item;
    cin>>item;
    buffer[in]=item;
    in=(in+1)%100;
    count++;
    signal(full);
    signal(mutex);
}
void consume(){
    if(count==0){
        cout<<"Buffer is empty, cannot consume.\n";
        return;
    }
    wait(mutex);
    wait(full);
    cout<<"Consuming item: "<<buffer[out]<<"\n";
    out=(out+1)%100;
    count--;
    signal(emptyVar);
    signal(mutex);
}

void display(){
    wait(mutex);
    if(count==0){
        cout<<"Buffer is empty\n";
    } else {
        cout<<"Buffer contents: ";
        for(int i=0; i<count; i++){
            cout<<buffer[(out+i)%100]<<" ";
        }
        cout<<"\n";
    }
    signal(mutex);
}
int main(){
    cout<<"Enter buffer size: ";
    int n;
    cin>>n;
    emptyVar=n;
    while(true){
        cout<<"1. Produce \n2. Consume \n3. Display \n4. Exit \n";
        int choice;
        cin>>choice;
        switch(choice){
            case 1: {
                produce();
                break;
            }
            case 2: {
                consume();
                break;
            }
            case 3: {
                display();
                break;
            }
            case 4: {
                cout<<"Exiting...\n";
                return 0;
            }
        }   
    }
}