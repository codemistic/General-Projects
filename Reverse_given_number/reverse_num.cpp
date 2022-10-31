#include <iostream>
using namespace std;
#include <cmath>
int digits( int n){ int c=1;
    for ( int i=1; 5; i++)
    {
       if (n/pow(10,i)<1)
       {
         break;  
       }
       
     else   c++;
    }
return c;
}

int main()
{
    int n;
    cin >> n;
   cout<<digits(n)<<"\n";

    int rev = 0;
    for (int i = digits(n); n>=1; i--)
    {
        int x = n % 10;
        rev +=  x *(pow(10, i-1));
        n = n / 10;
    }
    cout << rev;                                    /* 
                                                    1234
                                                    4
                                                    4000
                                                    123
                                                    3
                                                    4300
                                                    4320
                                                    */

    return 0;
}
