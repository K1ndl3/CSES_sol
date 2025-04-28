#include <cstddef>
#include <iostream>

int main(){

    // for the input attcggga what do we do?
    // left = 0; right = 0; n.at(left) == a, n.at(right) == a
    // if (n.at(left) == n.at(right)) {right++; int current_window_size = right - left; window_max = std::max(window_max, current_window_size) }
    // else left = right


    // basically we are looping throughout the string
    // if we encounter consecitive letters, we calculate the window size
    // compare the current window size to the largest window we have encountered so far
    // if there is letter that breaks the window, we set the left side of the window to be the right's index.
    std::string n;
    std::cin >> n;

    std::size_t left = 0;
    std::size_t right = 0;

    std::size_t window_max = 0;

    if (n.empty())
    { 
    std::cout << 0;
    return 0;
    }

    while (right < n.size())
    {
        if (n.at(left) == n.at(right))
        {
            right++;
            std::size_t current_window = right - left;
            window_max = std::max(current_window, window_max);
        }
        else
        {
            left = right;
            right++;
        }
    }
    std::cout << window_max;

    //implement the sliding window approach and keep track of the largest window size
    return 0;
}