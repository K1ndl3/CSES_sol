#include <iostream>
#include <vector>
#include <utility>
#include <fstream>


void dutchFlag(std::vector<int>& nums) {
    int low = 0;
    int mid = 0;
    int high = nums.size() - 1;
    int top = nums.size() - 1;
    while (mid <= high) {
        if (nums[mid] == 0) {
            std::swap(nums[low], nums[mid]);
            low++;
            mid++;
        } else if (nums[mid] == 1) {
            mid++;
        } else if (nums[mid] == 2) {
            std::swap(nums[mid], nums[high]);
            high--;
        } else {
            std::swap(nums[mid], nums[top]);
            top--;
            if (high > top) high = top;
        }
    }
}


int main() {
    std::ifstream infile("input.txt");
   char n;
   std::string sampleString = "";
   while (infile >> n) {
    sampleString.push_back(n);
    std::cout << n << '\n';
   }
   std::cout << '\n';
   std::cout << "after reading the string is: " << sampleString;
    return 0;
}