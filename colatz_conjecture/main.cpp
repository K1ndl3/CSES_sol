// if n is even divides n by 2
// if n is odd multiply n by 3 and plus 1

#include <iostream>


int main()  {

// can only think of iterative approach right now
    long long n;
    std::cin >> n;

    while (n != 1)
    {
        std::cout << n << ' ';

        if (n % 2 == 0) n = n / 2;
        else 
        {
            n = (n * 3) + 1;
        }
    }
    std::cout << n;
    return 0;
}