#include <bits/stdc++.h>
using namespace std;
//
//Time complexity : O(n)
//Space complexity: O(n)

int ShortestSubstring(string phrase_1, string phrase_2){
    int start=0;
    int end=0;
    int shortest;
    unordered_map<char, int>string;
    bool contains_all;
    for(char letter : phrase_2){
        if(string.count(letter)){
            string[letter]++;
        }
        else{ 
        string[letter]=1;}
    }
    
   while(start!=end){
        for(auto letter:string){
            contains_all= count(phrase_1.begin()+start, phrase_1.begin()+end, letter)==string[letter.first];
                
            
        }
        if(contains_all==true){
            int count=(end-start)+1;
            if(count<shortest){
                longest=count;
            };
        }
       start++;
       if(start==end){
           start=0;
           end--;
       }
    }
    return longest;
 
}

int main(){
   return 0;
  
 }
 //Time Spent on problem: 40+ minutes. I wasn't able to complete the problem before within the time limit.
