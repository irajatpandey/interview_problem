// Sort Binary Array in Linear Time
 
// Given a binary array, sort it in linear time and constant space. Output should print contain all zeroes followed by all ones.

// For example,


// Input: { 1, 0, 1, 0, 1, 0, 0, 1 }
 
// Output:{ 0, 0, 0, 0, 1, 1, 1, 1 }

 
#include <iostream>
#include <vector>
using namespace std;
int main(){
        vector<int> v(10);
        v = {0, 1, 0, 1, 0, 0 , 0 , 1, 0, 1};
        int count = 0;
        int j = -1;
        for(int i = 0; i < v.size(); i++){
            if(v[i] < 1)
                swap(v[i], v[++j]);
    }


    for( auto i : v)
        cout << i << " ";

    return 0;
} 