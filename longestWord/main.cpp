#include <iostream>
#include <string>
#include <cctype>


int main() {
    int n;
    std::cin >> n;
    while (n--)
    {
        std::string input;
        std::cin >> input;
        if (input.size() > 10)
        {
            std::cout << input[0] << input.size() - 2 << input[input.size() - 1] << '\n';
        } 
        else
        {
            std::cout << input << '\n';
        }
    }
    return 0;
}