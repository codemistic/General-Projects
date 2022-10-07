//Generate the power set of a given set
#include <iostream>
#include <vector>
using namespace std;
 
// Function to print a given set
void printSet(vector<int> const &input)
{
    cout << "[";
    int n = input.size();
    for (int i: input) {
        cout << i;
        if (--n) {
            cout << ", ";
        }
    }
    cout << "]\n";
}
 
// Function to generate power set of a given set `S`
void printPowerSet(vector<int> const &S, vector<int> &set, int n)
{
    // if we have considered all elements
    if (n == 0)
    {
        printSet(set);
        return;
    }
 
    // consider the n'th element
    set.push_back(S[n - 1]);
    printPowerSet(S, set, n - 1);
 
    set.pop_back();                    // backtrack
 
    // or don't consider the n'th element
    printPowerSet(S, set, n - 1);
}
 
// Wrapper over `printPowerSet()` function
void findPowerSet(vector<int> const &S)        // no-ref, no-const
{
    // create an empty vector to store elements of a subset
    vector<int> set;
    printPowerSet(S, set, S.size());
}
 
int main()
{
    vector<int> S = { 1, 2, 3 };
 
    findPowerSet(S);
 
    return 0;
}


// Output:

// [3, 2, 1]
// [3, 2]
// [3, 1]
// [3]
// [2, 1]
// [2]
// [1]
// []
