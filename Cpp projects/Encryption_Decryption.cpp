#include <iostream>
#include <string.h>
using namespace std;

void encryptfunc()
{
    char text[100];
    char temp;
    int i , key;

    cout<<"Enter a message to encrypt: "<<endl;
    cin>>text;
    cout <<"Enter key: "<<endl;
    cin>>key;

    for(i =0; text[i] != '\0';i++){
        temp = text[i];
        if(temp >='a' && temp <= 'z'){
            temp = temp + key;
            if(temp > 'z'){
                temp = temp - 'z' + 'a' -1;
            }
            text[i] = temp;
        }
        else if( temp >= 'A' && temp <= 'Z'){
            temp = temp + key;
            if(temp > 'Z'){
                temp = temp - 'Z' + 'A' -1;
            }
            text[i] = temp;
        }
    }
    cout <<"Encrypted message:"<<text<<endl;
}

void decryptfunc()
{
    char text[100];
    char temp; int i , key;

    cout <<"Enter a message to decrypt: "<<endl;
    cin>>text;
    cout <<"Enter key:" <<endl;
    cin>>key;
    for(int i =0; text[i] != '\0'; ++i){
        temp = text[i];
        if(temp >= 'a' && temp <='z'){
            temp = temp - key;
            if(temp <'a'){
                temp = temp + 'z' - 'a' +1;
            }
            text[i] = temp;
        }
        else if(temp >= 'A' && temp <= 'Z'){
            temp = temp - key;
            if(temp < 'A'){
                temp = temp + 'Z' - 'A' + 1;
            }
            text[i] = temp;
        } 
    }
    cout <<"Decrypted message: "<<text<<endl;

}

int main()
{
    int choice;
    cout <<"Choose any one !"<<endl;
    cout <<"1.Encryption \t 2.Decryption"<<endl;
    cin >>choice;
    switch(choice)
    {
        case 1: encryptfunc();
        break;
        case 2: decryptfunc();
        break;
        default: cout <<"Please select valid option";
        break;
    }
    return 0;
}