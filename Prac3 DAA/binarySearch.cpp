#include<bits/stdc++.h>
using namespace std;

int BinarSearch(vector<int>&v, int key){
        int s = 0;
        int e = v.size()-1;

        while(s<=e){
            int mid = s+(e-s)/2;

            if(key == v[mid])
            return mid;

            else if(v[mid]<key){
                e = mid-1;
            }
            else
            s=mid+1;
        }
}

int main()
{
    vector<int>v;
    int n;
    cin>>n;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }
    int key;
    cin>>key;
    
    cout<<"key found at index "<<BinarSearch(v,key);

return 0;
}