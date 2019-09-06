#include <bits/stdc++.h>

using namespace std;

int main()
{
    int bs, ps;
    cout<<"Enter the block size and process size: ";
    cin>>bs>>ps;

    vector<int> block(bs), process(ps), allocated(ps,-1);

    cout<<"Enter block: ";
    for(int i=0; i<bs; i++)cin>>block[i];
    cout<<"Enter process: ";
    for(int i=0; i<ps; i++) cin>>process[i];

    for(int i=0; i<ps; i++){
        for(int j=0; j<bs; j++){
            if(process[i] <= block[j]){
                block[j]-=process[i];
                allocated[i] = j+1;
                break;
            }
        }
    }

    for(int i=0; i<ps; i++) cout<<allocated[i]<<" ";

}
