#include <iostream>

using namespace std;

int main(){
    int n;
    cin>>n;

    for (int i = 0; i < n; i++)
    {
       for (int j  = 0; j < n ; j++)
       {
           if( n-j<=i+1){
               cout<<n-j<<" ";
           }
           else cout<<"  ";
           
       }
       for (int j  = 0; j < n ; j++)
       {   
           if( j<=i){
               if (j+1==1)
               {
                   continue;/* code */
               }
               
               cout<<j+1<<" ";
           }
           else cout<<"  ";
           
       }
       cout<<"\n";
    }
    
    
    return 0;
}