
#include <bits/stdc++.h>

using namespace std;



/*
 * Complete the 'getPalindromesCount' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

int getPalindromesCount(string s) {
int n = s.size();
vector<int> zl (n,0);
vector<int> zr (n,0);
vector<int> onel (n,0);
vector<int> oner (n,0);
for ( int i =0 ; i<n;i++){
    if ( i==0){
        if ((s[i]) == '0' ){zl[i]++;} 
        else {
            onel[i]++;
            } 
    }
    else {
        if ((s[i]) == '0' ){zl[i]= zl[i-1]+1;
             onel[i] = onel[i-1];
        }
        // forgot to update the other array ,bull shit mistake!!!!! 
        else {
            zl[i]= zl[i-1];
            onel[i] = onel[i-1]+1;
    }
}
}
for ( int i =n-1 ; i>=0;i--){
    if ( i==n-1){
        if ((s[i]) == '0' ){zr[i]++;} 
        else {oner[i]++;} 
    }
    else {
        if ((s[i]) == '0' ){zr[i] = zr[i+1]+1;
        oner[i] = oner[i+1];}
        else {oner[i] = oner[i+1]+1;
            zr[i] = zr[i+1];
    
    }
}
}
vector<int> onezerol (n,0);
vector<int> onezeror (n,0);
vector<int> zeroonel (n,0);
vector<int> zerooner (n,0);
for ( int i =1 ; i<n;i++){
    if ( s[i]=='1'){
        zeroonel[i]= zl[i-1] + zeroonel[i-1];
        onezerol[i] = onezerol[i-1];
        
    }
    else if  ( s[i]=='0'){
        onezerol[i]= onel[i-1] + onezerol[i-1];
        zeroonel[i] = zeroonel[i-1];
    }
}
for ( int i =n-2 ; i>=0;i--){
    if ( s[i]=='0'){
        zerooner[i]= oner[i+1] + zerooner[i+1];
        onezeror[i] = onezeror[i+1];
    }
    else if  ( s[i]=='1'){
        onezeror[i]= zr[i+1] + onezeror[i+1];
        zerooner[i] = zerooner[i+1];
    }
}
long long int  ans;
ans =0;
for ( int i =2 ; i<n-2;i++){
    ans+=((zl[i-1]*(zl[i-1]-1))/2)*((zr[i+1]*(zr[i+1]-1))/2)%1000000007;
    ans+=((onel[i-1]*(onel[i-1]-1))/2)*((oner[i+1]*(oner[i+1]-1))/2)%1000000007;
    ans+=((zeroonel[i-1])*(onezeror[i+1]))%1000000007;
    ans+=((onezerol[i-1])*(zerooner[i+1]))%1000000007;
}

return ans;
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    int result = getPalindromesCount(s);

    fout << result << "\n";

    fout.close();
string s ="";
s.
    return 0;
}