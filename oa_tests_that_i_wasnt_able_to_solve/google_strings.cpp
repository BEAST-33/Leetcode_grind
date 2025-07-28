//there is a coder who types fast and makes mistake by swapping consecutive letters of a string . if he does swap i and i+1 he cant swap i+1 and i+2 , he can however type correctly also no of unique strings he can make in total . how to do this in cpp. in less than 30 mins.
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <string>

 long solve(string& s){
    set<string> uniquestrings;
    helper(0,s,uniquestrings);
    return uniquestrings.size();
 }
 void helper(int idx, string& s, set<string>& uniquestrings){
    if (idx >= s.size()-1){
        return;
    }
    if ( idx +1 <=s.size()-1){
        char temp = s[idx+1];
        s[idx+1]=s[idx];
        s[idx]=temp;
        uniquestrings.insert(s);
        helper(idx+2,s,uniquestrings);
    }
    if ( idx +2 <=s.size()-1){
        char temp = s[idx+2];
        s[idx+2]=s[idx+1];
        s[idx+1]=temp;
        uniquestrings.insert(s);
        helper(idx+3,s,uniquestrings);
    }

 }

