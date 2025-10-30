#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>v={2,6,7,17,22,30};
    vector<int>ans;
     int start=0,end=1;
    while(start<end){
        if(v[end]-v[start]==15){
        ans.push_back(v[start]);
        ans.push_back(v[end]);
        break;
        }
        else {
           if(v[end]-v[start]<15){
            end++;
           }
            else{
                start++;

            }
            }
        }
        cout << ans[0];
        cout << endl;
        cout << ans[1];
        
}