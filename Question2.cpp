/*Check if subarray with 0 sum is exists or not
 
Given an array of integers, check if array contains a sub-array having 0 sum.*/



/*For example,

Input:  { 3, 4, -7, 3, 1, 3, 1, -4, -2, -2 }
 
Output: Subarray with 0 sum exists
 
The sub-arrays with 0 sum are:
 
{ 3, 4, -7 }
{ 4, -7, 3 }
{ -7, 3, 1, 3 }
{ 3, 1, -4 }
{ 3, 1, 3, 1, -4, -2, -2 }
{ 3, 4, -7, 3, 1, 3, 1, -4, -2, -2 }
*/

#include <bits/stdc++.h>
using namespace std;

/*The time complexity of proposed solution is O(n) and auxiliary space used by the program is O(n).*/
bool zeroSumSubArray(vector<int> v, int size){
    unordered_set<int> s;
    s.insert(0);
    int sum = 0;

    for(int i = 0; i < size; i++){
        sum += v[i];
        if(s.find(sum) != s.end())
            return true;
            
    }
    return false;
}
int main(){
    int size;
    cout << "Enter the size of an array" << endl;
    cin >> size;

    vector<int> v(size); 

    for(int i = 0; i < size; i++){
        cin >> v[i];
    }

    if(zeroSumSubArray(v, size))
        cout << "Subarray exists";
    else    
        cout << "Subarray do not exist";
  

}


 