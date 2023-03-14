#include <bits/stdc++.h>
using namespace std;
//Hash the elements
//Time complexity : O(n)
//Space complexity: O(n)

string DedupArray(vector<int>integers){
   int first=0;
   int second=0;
   while(second<integers.size()-1){
       second++;
       
       if(integers[first]==integers[second]){
           integers.erase(integers.begin()+first);
           second--;
    
       }
       else{
           first++; 
       }
   }
   for(int num:integers){
       cout<<num<<" ";
   }
 
   return "";
}

int main(){
 cout<<DedupArray({1, 2, 2, 3, 3, 3, 4, 4, 4, 4})<<"\n";
 cout<<DedupArray({0, 0, 1, 4, 5, 5, 5, 8, 9, 9, 10, 11, 15, 15})<<"\n";
 cout<<DedupArray({1, 3, 4, 8, 10, 12})<<"\n";
 
 return 0;
 }
 //Time Spent on problem: 29 minutes
