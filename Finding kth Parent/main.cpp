#include <iostream>
using namespace std;

//finding k'th parent with linear approach O(n).

int main() {
    // your code goes here
    int parArr[100], n, child, par;

    for(int i=0;i<100;i++)
        parArr[i]=0;

    cin>>n;

    for(int i=0;i<n;i++){

        cin>>child>>par;
        parArr[child]=par;

    }

    int node, kPar, ans=-1;
    cin>>node>>kPar;

    ans=node;
    bool chk = false;

    while(kPar--){

        if(parArr[ans]!=ans)
            ans=parArr[ans];
            else chk=true;
    }
    if(ans==0)
        cout<<"The number is not in the tree\n";
    else if(chk)
        cout<<"The parent doesn't exist\n";
    else cout<<ans<<endl;

    return 0;

}

/*
10
40 40
76 40
12 40
38 76
26 76
15 12
21 12
41 26
37 26
5 37
5 7
*/
