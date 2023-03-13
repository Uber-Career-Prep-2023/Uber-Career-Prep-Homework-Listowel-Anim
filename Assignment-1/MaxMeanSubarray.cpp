#include <bits/stdc++.h>
using namespace std;
//Sliding window two pointer technique
//Time complexity : O(n)
//Space complexity: O(n)

double MaxMeanSubArray(vector<int>array, int k){
    int start=0;
    int end=k-1;
    double max_mean=0;
    while(end<array.size()){
        double sum=0;
        for(int i=start;i<=end;i++){
          sum+=array[i];
        }
        double mean=sum/k;
        if(mean>max_mean){
            max_mean=mean;
        }
        start++;
        end++;
    }
    return max_mean;
}

int main(){
  vector<int>numbers={4, 5, -3, 2, 6, 1};
  vector<int>numbers_={};
  cout<<MaxMeanSubArray(numbers,2)<<"\n";//subarray of size 2
  cout<<MaxMeanSubArray(numbers,3)<<"\n";//subarray of size 3
  cout<<MaxMeanSubArray(numbers_,2)<<"\n";//edgecase of an empty array
  cout<<MaxMeanSubArray(numbers,0)<<"\n";//edgecase using a subarray size of 0
  return 0;
  
}
