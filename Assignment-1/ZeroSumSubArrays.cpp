#include <bits/stdc++.h>
using namespace std;
//Growing/Shrinking size sliding window two pointer technique
//Time complexity : O(n)
//Space complexity: O(n)

int ZeroSumSubArrays(vector<int>integers){
    int count=0;
    int start=0;
    int end=integers.size()-1;
    for(int num:integers){
        if(num==0){
            count++;
        }
    }
    while(end!=0){
        int sum=0;
        for(int i=start;i<=end;i++){
            sum+=integers[i];
        }
        if(sum==0){
            count++;
        }
        start++;
        if(start==end){
            start=0;
            end--;
        }
    }
    return count;
 
}

int main(){
    vector<int>numbers={8, -5, 0, -2, 3, -4};
    vector<int>numbers_={4, 5, 2, -1, -3, -3, 4, 6, -7};
    vector<int>numbers_1={1, 8, 7, 3, 11, 9};
    vector<int>numbers_2={};
    cout<<ZeroSumSubArrays(numbers)<<"\n";
    cout<<ZeroSumSubArrays(numbers_)<<"\n";
    cout<<ZeroSumSubArrays(numbers_1)<<"\n";
    cout<<ZeroSumSubArrays(numbers_2);//testing an edgecase of an empty array of numbers
 return 0;
 }
 //Time Spent on problem: 15 minutes

