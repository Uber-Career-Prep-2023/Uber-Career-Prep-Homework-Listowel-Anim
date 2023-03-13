#include <bits/stdc++.h>
using namespace std;
//Forward Backward two pointer technique
//Time complexity : O(n)
//Space complexity: O(n)

int ZeroSumSubArrays(vector<int>integers){
    int count=0;
    int start=0;
    int end=0;
    for(int num:integers){
        if(num==0){
            count++;
        }
    }
    while(end<integers.size()){
        int sum=0;
        for(int i=start;i<=end;i++){
            sum+=integers[i];
        }
        if(sum==0){
            count++;
        }
        end++;
    }
    start=1;
    while(start<end){
        int sum_=0;
        for(int i=start;i<end;i++){
            sum_+=integers[i];
        }
        if(sum_==0){
            count++;
        }
        start++;
    }
 return count;
}

int main(){
    vector<int>numbers={8, -5, 0, -2, 3, -4};
    vector<int>numbers_={4, 5, 2, -1, -3, -3, 4, 6, -7};
    vector<int>numbers_1={1, 8, 7, 3, 11, 9};
    cout<<ZeroSumSubArrays(numbers);
    cout<<ZeroSumSubArrays(numbers_);
    cout<<ZeroSumSubArrays(numbers_1);
 return 0;
 }
 //Time Spent on problem: 19 minutes
