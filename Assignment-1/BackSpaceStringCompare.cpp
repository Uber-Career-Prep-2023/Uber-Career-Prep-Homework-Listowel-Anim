#include <bits/stdc++.h>
using namespace std;
//Simultaneous iteration two pointer technique
//Time complexity : O(n)
//Space complexity: O(n)

bool BackSpaceStringCompare(string phrase_1, string phrase_2){
    int first=0;
    int second=0;
    bool is_equal=false;
    while(count(phrase_1.begin(),phrase_1.end(),'#')){
        for(int i=0;i<phrase_1.size();i++){
            if(phrase_1[i]=='#'){
                phrase_1.erase(i-1,2);
            }
        }
    }
    
    
    while(count(phrase_2.begin(),phrase_2.end(),'#')){
          for(int i=0;i<phrase_2.size();i++){
            if(phrase_2[i]=='#'){
                phrase_2.erase(i-1,2);
            }
        }
    }
    
   if(phrase_1.size()!=phrase_2.size()){
        return is_equal;
    }
    else{
   while(first<phrase_1.size()&&second<phrase_2.size()){
        is_equal=phrase_1[first]==phrase_2[second];
        first++;
        second++;
    }
     return is_equal;   
    }
    

}

int main(){
   
   cout<<BackSpaceStringCompare("abcdef###xyz", "abcw#xyz")<<"\n";
   cout<<BackSpaceStringCompare("Uber Career Prep", "u#Uber Careee#r Prep")<<"\n";
   cout<<BackSpaceStringCompare("abcde", "abcde")<<"\n";
   cout<<BackSpaceStringCompare("abcdef###xyz", "abcdefxyz###")<<"\n";
   cout<<BackSpaceStringCompare("a","abcd###");//My assumption is that two empty strings aren't equal
   cout<<""=="";
   return 0;
  
 }
 //Time Spent on problem: 28 minutes
