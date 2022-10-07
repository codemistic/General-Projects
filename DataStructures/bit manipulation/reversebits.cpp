//Reverse bits of an integer
#include <iostream>
#include <bitset>
using namespace std;
 
// A macro that defines the size of an integer
#define INT_SIZE sizeof(int) * 8
 
// Function to reverse bits of a given integer
int reverseBits(int n)
{
    int pos = INT_SIZE - 1;     // maintains shift
 
    // store reversed bits of `n`. Initially, all bits are set to 0
    int reverse = 0;
 
    // do till all bits are processed
    while (pos >= 0 && n)
    {
        // if the current bit is 1, then set the corresponding bit in the result
        if (n & 1) {
            reverse = reverse | (1 << pos);
        }
 
        n >>= 1;                // drop current bit (divide by 2)
        pos--;                  // decrement shift by 1
    }
 
    return reverse;
}
 
int main()
{
    int n = -100;
 
    cout << n << " in binary is " << bitset<32>(n) << endl;
    cout << "On reversing bits " << bitset<32>(reverseBits(n));
 
    return 0;
}


// Output:

// -100 in binary is 11111111111111111111111110011100
// On reversing bits 00111001111111111111111111111111