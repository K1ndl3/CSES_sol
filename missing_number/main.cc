#include <iostream>
#include <set>

int main(){

   // since the number from 1 to n adds up to an expected number
   // expected sum = (n (n + 1)) / 2
   // iterate through the list and find the actual sum
   // the missing number is will be the expected sum - actual sum 

   // or we could have also used a associative container for the find() function to check if i and i+1 exists
   int n;
   std::cin >> n;

   long long mult = n * (n + 1);

   long long actSum = 0;
   long long expSum = mult / 2;

   for (int i = 1; i < n; i++)
   {
        int num;
        std::cin >> num;
        actSum += num;
   }
   long long answer = expSum - actSum; 
   std::cout << answer;
    
    return 0;
}