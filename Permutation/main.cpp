#include <iostream>
/*
A permutation of integers 1,2,...,n is called beautiful if there are no adjacent elements whose difference is 1.
Given n, construct a beautiful permutation if such a permutation exists.
Input
The only input line contains an integer n.
Output
Print a beautiful permutation of integers 1,2,...,n. If there are several solutions, you may print any of them. 
If there are no solutions, print "NO SOLUTION".
*/

// so the trick here is to place the odd first and then even 
// 1 3 5 2 4 6
// this would be considered beautiful
// the question becomes what are the edge cases where our arrangements cannot work
// 2 would not work because 1 2 are adjacents with diff of 1
// 1 3 2 would not work because 3 and 2 fails

// can we conclude that if n <= 3, there are no beatiful arrangement?
int main() {
    int n;
    std::cin >> n;

    if (n == 1) {
        std::cout << "1";
        return 0;
    }

    if (n <= 3 && n != 1) 
    {
        std::cout << "NO SOLUTION"; 
        return 0;
    }

    
    for ( int j = 2; j <= n; j++) {
        if (j % 2 == 0) std::cout << j << " ";
    }

    for (int i = 1; i <= n; i++) {
        if (i % 2 != 0) std::cout << i << " ";
    }
    return 0;
}