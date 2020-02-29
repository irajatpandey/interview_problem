/*
Print all sub-arrays with 0 sum
 
Given an array of integers, print all sub-arrays with 0 sum.

For example,

Input:  { 4, 2, -3, -1, 0, 4 }
 
Sub-arrays with 0 sum are
 
{ -3, -1, 0, 4 }
{ 0 }
 
 
Input:  { 3, 4, -7, 3, 1, 3, 1, -4, -2, -2 }
 
Sub-arrays with 0 sum are
 
{ 3, 4, -7 }
{ 4, -7, 3 }
{ -7, 3, 1, 3 }
{ 3, 1, -4 }
{ 3, 1, 3, 1, -4, -2, -2 }
{ 3, 4, -7, 3, 1, 3, 1, -4, -2, -2 }        

*/

#include <bits/stdc++.h>
using namespace std;

void check_subArray_zero(vector<int> v){
     multimap<int, int> map;

     map.insert(make_pair(0, -1));
     
     int sum = 0;
     for(int i = 0; i < v.size(); i++){
         sum += v[i];
         if(map.find(sum) != map.end()){
             auto it = map.find(sum);

             while(it != map.end() and it -> first == sum){
                 cout << "Sub Array [ " << it -> second + 1 << "... " << i << " ]" << endl;
                 it++;
             }
         }
         map.insert(make_pair(sum, i));
     }
}
int main(){

    vector<int> v(10);

    v = { 3, 4, -7, 3, 1, 3, 1, -4, -2, -2 };

    check_subArray_zero(v);

    return 0;
}