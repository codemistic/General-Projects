// Brian Kernighan’s Algorithm to count set bits in an integer
#include <iostream>
#include <bitset>
using namespace std;
 
// Function to count the total number of set bits in `n`
int countSetBits(int n)
{
    // `count` stores the total bits set in `n`
    int count = 0;
 
    while (n)
    {
        n = n & (n - 1);    // clear the least significant bit set
        count++;
    }
 
    return count;
}
 
int main()
{
    int n = -1;
 
    cout << n << " in binary is " << bitset<32>(n) << endl;
    cout << "The total number of set bits in " << n << " is "
         << countSetBits(n) << endl;
 
    return 0;
}

// Output:

// -1 in binary is 11111111111111111111111111111111
// The total number of set bits in -1 is 32