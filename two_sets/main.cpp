#include <iostream>

/*Your task is to divide the numbers 1,2,...,n into two sets of equal sum.
Input
The only input line contains an integer n.
Output
Print "YES", if the division is possible, and "NO" otherwise.
After this, if the division is possible, print an example of how to create the sets. 
First, print the number of elements in the first set followed by the elements themselves in a separate line,
and then, print the second set in a similar way.*/



// so the two sets can be of different sizes
// just as long as the sets sum up to the same number

// the sum of a arithmetic sequence is sum = (a1 + an)(n/2)

// notice the trick that the formula of the arithmetic sequence is telling us
// so lets say 7. 1 2 3 4 5 6 7 8
// 8+1 = 9
// 7+2 = 9
// 6+3 = 9
// 5+4 = 9

// so know that if we were to divide these additions into two sets, they would yield the same sum, being 36
// ie we can have 6 3 5 4  being one set and 8 1 7 2 being the other

// so when can we not be able to split them into 2 sets
// lets say 2. 1 2 
// we cant split this into sets of equal sums
// the same applis to 1
// can we do this for 4? 1 2 3 4 
// 4+1 = 5
// 3+2 = 5
// lets try 5. 1 2 3 4 5
// 1 + 5 = 6
// 2 + 5 = 6
// 3     = 3
// so notice this is an edge case where we would have to split the sets into 3 
// and there are no possible permutation of the sets for their sum to be equivalent
// that means that using our logic so far, we cannot form 2 sets of equal sum for some numbers
// lets take a look in our arithmetic sequence sum formula to see.
// so when n is even, the number of pairs is even ie we can split them into 2
// and when n is odd, the number of pairs is odd ie we cannot split them into 2
// 


// so basically:
//     if n % 2 == 0 print YES and generate the sets

// else print NO


// so now the next question becomes, how do we generate the sets?


// now thinking about it, there is no reason for us to focus on n
// we just need to see the what is the resulting sum will be
// for example, if the resulting sum is even, that means we can split it into 2 sets
// if the resulting sum is odd, there will be no way to for us to split the sum into 2 equal sets


// basically, find the sum from 1 to n and see if its even
// if sum % 2 == 0 print YES and generate sets
// if sum % 2 != 0 print NO
int main() {
    std::cout << "Hello world";

    return 0;
}