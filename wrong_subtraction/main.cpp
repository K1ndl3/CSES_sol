#include <iostream>
#include <string>
int main() {
    int n;
    int k;

    std::cin >> n >> k;

    while (k != 0)
    {
        if   ((n % 10) != 0) n = n -1;
        else                 n = n / 10;

        k--; // wow that is insane. Forgetting one line of code creates an infinite loop
    }

    std::cout << n;
    return 0;
}