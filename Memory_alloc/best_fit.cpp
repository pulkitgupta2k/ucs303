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
        int minimum=-1;

        for (int j=0; j<bs; j++){
            minimum = block[j]-process[i];
            if(minimum > 0) break;
        }

        if(minimum < 0) break;

        for(int j=0; j<bs; j++){
            if(process[i] <= block[j]){
                minimum=min(minimum,block[j]-process[i]);
                //block[j]-=process[i];
                //allocated[i] = j+1;
            }
        }
        for(int j=0; j<bs; j++){
            if(block[j]-process[i] == minimum){
                block[j]-=process[i];
                allocated[i] = j+1;
            }
        }

    }

    for(int i=0; i<ps; i++) cout<<allocated[i]<<" ";

}
