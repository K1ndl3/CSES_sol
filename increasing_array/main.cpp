#include <iostream>
#include <string>
#include <vector>
#include <cmath>
/*

You are given an array of n integers. You want to modify the array so that it is increasing, i.e., every element is at least as large as the previous element.
On each move, you may increase the value of any element by one. What is the minimum number of moves required?
Input
The first input line contains an integer n: the size of the array.
Then, the second line contains n integers x_1,x_2,\ldots,x_n: the contents of the array.
Output
Print the minimum number of moves.


*/

int main(){
    // so we start at the beginning of the array of course
    // we make sure that the n-1 <= n 
    // since we find the min of moves, if (n - 1 > n) the amount of moves we can do to follow the rule is arr[(n-1)] - arr[n]
    // if n-1 < n, we can continue to the next index
    // this time comparing the n and the n + 1 element
    // this seems to me like a two pointers approach
    // where the left will be at n and right will be at n+1
    // that means that our right pointer has to be indexable from 1 to arr.size() - 1
    long long n;
    std::cin >> n;
    std::vector<long long> arr(n);
    for (int i = 0; i < n; i++) {
       std::cin >> arr.at(i);
    }


    long long num_moves = 0;
    long long index = 0;
    while (index < arr.size() - 1)
    {
        if (arr.at(index) > arr.at(index + 1))
        {
            num_moves += arr.at(index) - arr.at(index + 1);
            arr.at(index + 1) = arr.at(index);
            index++;
        }
        else
        {
            index++;
        }
    }

    std::cout << num_moves;
    return 0;
}