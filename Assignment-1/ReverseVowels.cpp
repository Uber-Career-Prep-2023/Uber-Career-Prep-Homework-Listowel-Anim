#include <bits/stdc++.h>
using namespace std;
//Forward Backward two pointer technique
//Time complexity : O(n)
//Space complexity: O(n)

string ReverseVowels(string phrase){
     
  unordered_map<char, int>vowels({{'a',1},
                                  {'e',2},
                                  {'i',3},
                                  {'o',4}, 
                                  {'u',5}
                                          });
  int start=0;
  int end=phrase.size()-1;
  while(start!=end){
      if(vowels.count(tolower(phrase[start]))){
        int first=start; 
        if(vowels.count(tolower(phrase[end]))){
            int second=end;
            char temp=phrase[first];
            phrase[first]=phrase[second];
            phrase[second]=temp;
            start++;
            end--;
        }
        else{
            end--;
        }
      }
      else{
         start++; 
      }
      
  } 
    return phrase;
}

int main(){
 
 string word="Uber Career Prep";
 string word_="xyz";
 string word_1="flamingo";
 string word_2="";
 string word_3="sdfd";
 cout<<ReverseVowels(word)<<"\n";
 cout<<ReverseVowels(word_)<<"\n";
 cout<<ReverseVowels(word_1)<<"\n";
 cout<<ReverseVowels(word_2)<<"\n";//testing an edgecase of an empty string
 cout<<ReverseVowels(word_3)<<"\n";//testing an edgecase of an input string with no vowels 
 return 0;
 }
 //Time Spent on problem: 13 minutes
