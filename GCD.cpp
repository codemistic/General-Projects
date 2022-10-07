 #include <iostream>
 using namespace std;

// 1. Naive Approach
// int gcd(int a,int b){
//     int res=min(a,b);
//     while(res>0){
//         if(a%res==0 && b%res==0){
//             break;
//         }
//         res--;
//     }
//     return res;
// }

// 2. Euclidean Algorith for GCD
// int gcd(int a,int b){
//     while(a!=b){
//         if(a>b){
//             a=a-b;
//         }
//         else{
//             b=b-a;
//         }
//     }
//     return a;
// }

// 3. Optimized Euclidean Algorithm 
int gcd(int a,int b){
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
}


 int main(){
     int x=gcd(12,15);
     cout<<x;
     
     return 0;
 }
