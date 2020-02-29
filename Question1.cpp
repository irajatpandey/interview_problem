/*Find pair with given sum in an array
 
Given an unsorted array of integers, find a pair with given sum in it.

 


For example,

Input:
 
arr = [8, 7, 2, 5, 3, 1]
sum = 10
 
Output:
 
Pair found at index 0 and 2 (8 + 2)
or
Pair found at index 1 and 4 (7 + 3)

 */

#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

/* Naive Solution */
/* The time complexity of above solution is O(n2) and auxiliary space used by the program is O(1). */

void pairSumNaiveSolution(vector<int> v, int size, int sum){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
           
            if(v[i] + v[j] == sum){
                cout << "pair (" << i << "," << j << ")" << endl;
                return;
            }
        }
    }
    cout << "Pair not found" << endl;
}



/* optimize solution */
/* The time complexity of above solution is O(nlogn) and auxiliary space used by the program is O(1). */


void pairSumOptimizedSolution(vector<int> v, int size, int sum){
    sort(v.begin(), v.end());


    int low = 0;
    int high = size - 1;
    while(low < high){
        if(v[low] + v[high] >= sum)
            low++;
        else if(v[low] + v[high] <= sum)    
            high--;
        else if(v[low] + v[high] == sum){
                cout << "pair (" << low << "," << high << ")" << endl;
                return;
            
        }    
    }


}

/* Best solution */
/* The time complexity of above solution is O(n) and auxiliary space used by the program is O(1). */
/*  using Hashing*/

void pairSumBestSolution(vector<int> v, int size, int sum){
    map<int, int> map;
    for(int i = 0; i < size; i++){
        if(map.find(sum - v[i]) != map.end()){
            cout << "Pair found at index " << map[sum - v[i]] << " and " << i;
            return;
        }
        else
            map[v[i]] = i;
    }
    cout << "Pair not found";

}




int main(){

    int size, sum;
    cout << "Enter the size of an Array";
    cin >> size;

    // Input in an array
    vector<int> v(size);
    for(int i = 0; i < size; i++)
        cin >> v[i];
    cout << "Enter the element" << endl;
    cin >> sum;
    pairSumNaiveSolution(v, size, sum);

    pairSumBestSolution(v, size, sum);
        

    return 0;
}