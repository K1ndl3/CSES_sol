#include <iostream>
#include <vector>
/*A number spiral is an infinite grid whose upper-left square has number 1. Here are the first five layers of the spiral:

Your task is to find out the number in row y and column x.
Input
The first input line contains an integer t: the number of tests.
After this, there are t lines, each containing integers y and x.
Output
For each test, print the number in row y and column x.*/


// so we know how to generate the the numbers in the diagonal
// if a number is in the diagonal, its rows and columns are the same ie r == c
// so then:
//       if r == c we do r^2 minus the offset index from the very left 
// ex) diag num for the 6th row and column would be (6*6) - 5
// and the numbers on the left side and right of the diag seems to be converging from or diverging from it
// so on the left the diagonal, where row is always greater than the column, 
//      if r > c
//          if r is even, r^2 minus (c-1)
//          else diag at row r minus (r-c)
// so on the right of the diagonal, where the column is always greater than the row
//      if r < c
//          if c is even, diag at column c - (c-r)
//          else c^2 minus (r-1)

long long solve(long long row, long long col){ // here is an idea, we could have pass in a ostream object, and just extract from that ostream object instead of doing return
    
    if (row == col) // means that the number lie on the diag
    {
        return (row * row) - (row  - 1);
    }
    if (row > col) // lower half of the diagonal
    {
        if (row % 2 == 0)  // if row is an even number
        {
            return (row * row) - (col - 1);
        }
        else // if row is an odd number
        {
            return ((row * row) - (row  - 1)) - (row - col);
        }
    }   
    else // upper half of the diagonal
    {
        if (col % 2 == 0) // if col is an even number
        {
            return ((col * col) - (col  - 1)) - (col - row);
        }
        else // if col is an odd number
        {
            return (col * col) - (row - 1);
        }
    }
}

int main() {
    long long t;
    std::cin >> t;
    std::vector<long long> answer(t);

    for (int i = 0; i < t; i++){
        long long x;
        long long y;
        std::cin >> x >> y;
        answer.at(i) = solve(x,y);
    }
    
    for (auto num : answer){
        std::cout << num << '\n';
    }

    return 0;
}

