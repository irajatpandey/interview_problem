/* Find duplicate element in a limited range array
 
Given a limited range array of size n where array contains elements between 1 to n-1 with one element repeating, find the duplicate number in it.

For example,

Input:   { 1, 2, 3, 4, 4 }
Output: The duplicate element is 4
 
Input:   { 1, 2, 3, 4, 2 }
Output: The duplicate element is 2     

 */

#include <bits/stdc++.h>
using namespace std;


// Time Complexity O(n ^ 2)
int naive_duplicate(vector<int> v){
     for(int i = 0; i < v.size(); i++){
         for(int j = i + 1; j < v.size(); j++){
             if(v[i] == v[j])
                return v[i];
         }
     }
     return -1; // all element are unique

}

/* The time complexity of this solution is O(n) and auxiliary space used by the program is O(n). */
int hashing_duplicate(vector<int> v){
     set<int> s;

     for(int i = 0; i < v.size(); i++){
         if(s.find(v[i]) != s.end())
             return v[i];
         else
            s.insert(v[i]);    
     }
     return -1; // all element are unique
}



// This approach will print all the duplicate elements in an array 
void absoluteIndex_duplicate(vector<int> v){
   
    cout << "All the duplicate elements are : "; 
    for(int i = 0; i < v.size(); i++){
        if(v[abs(v[i])]  >= 0)
            v[abs(v[i])] = -v[abs(v[i])];
        else
            cout << abs(v[i]) << " ";
        
    }


}

/* There is a problem in the above approach. It prints the repeated number more than once. For example: {1, 6, 3, 1, 3, 6, 6} 
it will give output as : 1 3 6 6. In below set, another approach is discussed that prints repeating elements only once. */


void xorSolution_duplicate(vector<int> v){

}


int main(){

    vector<int> v { 1, 2, 3, 3, 4, 4};
    cout << naive_duplicate(v) << endl;
    cout << hashing_duplicate(v) << endl;

    absoluteIndex_duplicate(v);

    return 0;
}