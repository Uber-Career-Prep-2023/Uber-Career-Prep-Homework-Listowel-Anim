#include <bits/stdc++.h>
using namespace std;
//Increment or decrement count hash technique
//Time complexity : O(n)
//Space complexity: O(n)

bool KAnagrams(string first, string second, int k){
    unordered_map<char, int>characters;
    int count=0;
    if(first.size()!=second.size()){
        return false;
    }
    else{
       for(char letter : first){
          if (characters.count(letter)){
              characters[letter]++;
          }
          else{
              characters[letter]=1;
          }
       } 
       
       for(char letter : second){
           if(characters.count(letter)){
               characters[letter]--;
           }
       }
       for(auto character:characters){
          if(character.second==1){
              count++;
          } 
       }
       return k==count;
    }
}

int main(){
 cout<<KAnagrams("apple", "peach",1)<<"\n";
 cout<<KAnagrams("apple", "peach", 2)<<"\n";
 cout<<KAnagrams("cat", "dog", 3)<<"\n";
 cout<<KAnagrams( "debit curd", "bad credit",1)<<"\n";
 cout<<KAnagrams( "baseball", "basketball", 2)<<"\n";
 cout<<KAnagrams("", "k",1)<<"\n";//Testing out an edgecase involvoing an empty string
 }
 //Time Spent on problem: 24 minutes
