#include <bits/stdc++.h>
using namespace std;
//Hash the elements
//Time complexity : O(n)
//Space complexity: O(n)

int TwoSum(vector<int>integers, int k){
    unordered_map<int, int>integer_count;
    int count=0;
    for(int i =0;i<integers.size();i++){
        if(integer_count.count(integers[i])){
            integer_count[integers[i]]++;
            
        }
        else{
            integer_count[integers[i]]=1;
        }
    }
    
    
    for(int i=0;i<integers.size();i++){
        int k_diff=k-integers[i];
        if(integer_count.count(k_diff) && integers[i]!=k_diff){
            count+=(integer_count[k_diff]*integer_count[integers[i]]);
            integer_count.erase(k_diff);
            integer_count.erase(integers[i]);
            
        }
        
        else if(integer_count.count(k_diff)&& integers[i]==k_diff){
            while(integer_count[k_diff]!=0){
                integer_count[k_diff]--;
                count+=integer_count[k_diff];
            }
        }
        
            
        
    }
    
   return count;
    
    
}

int main(){
 cout<<TwoSum({1, 10, 8, 3, 2, 5, 7, 2, -2, -1},10)<<"\n";
 cout<<TwoSum({1, 10, 8, 3, 2, 5, 7, 2, -2, -1},9)<<"\n";
 cout<<TwoSum({4, 3, 3, 5, 7, 0, 2, 3, 8, 6},1)<<"\n";
 cout<<TwoSum({4, 3, 3, 5, 7, 0, 2, 3, 8, 6},6)<<"\n";
 return 0;
 }
 //Time Spent on problem: 29 minutes
