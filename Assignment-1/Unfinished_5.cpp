#include <bits/stdc++.h>
using namespace std;
//Growing/Shrinking size sliding window two pointer technique
//Time complexity : O(n)
//Space complexity: O(n)

int ShortestSubstring(string phrase_1, string phrase_2){
    int start=0;
    int end=0;
    int longest;
    unordered_map<char>string;
    bool contains_all;
    for(char letter : phrase_2){
        if(string.count(letter)){
            string[letter]++;
        }
        else{ 
        string[letter]=1;}
    }
    if(phrase_2.size==1){
    for(char letter: phrase_1){
        if(letter==phrase_2){
            longest=1;
        }
    }}
    while(start!=end){
        for(int i=start;i<=end;i++){
           contains_all=phrase_2.count(phrase_1)
        }
    }
 
}

int main(){
  
 }
 //Time Spent on problem: 15 minutes
