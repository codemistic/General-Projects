#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <iomanip>
using namespace std;

class UserReg
{
protected:
    string username, name, password, RegDate;

public:
    UserReg() {}
    UserReg(string usrname, string fname, string pass, string regtime)
    {
        username = usrname;
        name = fname;
        password = pass;
        RegDate = regtime;
    }
    string getUserName();
    void setUserName(string);

    string getName();
    void setName(string);

    string getPassword();
    void setPassword(string);

    string getRegDate();
    void setRegDate(string);

    friend ofstream &operator<<(ofstream &out, UserReg &usr);
};

string UserReg ::getUserName()
{
    return username;
}
string UserReg ::getName()
{
    return name;
}
string UserReg ::getPassword()
{
    return password;
}
string UserReg ::getRegDate()
{
    return RegDate;
}

void UserReg ::setUserName(string usrname)
{
    username = usrname;
}
void UserReg ::setName(string name)
{
    name = name;
}
void UserReg ::setPassword(string pss)
{
    password = pss;
}
void UserReg ::setRegDate(string date)
{
    RegDate = date;
}

ofstream &operator<<(ofstream &out, UserReg &usr)
{
    out << usr.username << endl;
    out << usr.name << endl;
    out << usr.password << endl;
    out << usr.RegDate;
    return out;
}

class UserLog : public UserReg
{
    string updname,updDate;
    int psslength = 0;
    string maskedpss;

public:
    UserLog() {}
    void wishUser();
    void changeDollar();
    void Passlength();
    void maskPass();
    string getUpdName() { return updname; };
    friend ifstream &operator>>(ifstream &in, UserLog &usr);
    friend void Profile(UserLog &user); 
    friend void Setting(UserLog &user); 
};

void Setting(UserLog &user){
    int ch;
    cout<<"\n\tWelcome to Settings!";
    cout<<"\n\tHere You can Update Your Profile";
    cout<<"\n\t1) Edit Profile";
    cout<<"\n\t2) View Profile";
    cout<<"\n\t3) Change Password";
    cout<<"\n\t4) Logout";
    cout<<"\n\tEnter Your Choice: ";
    cin>>ch;
    switch (ch)
    {
    case 1:
        Profile(user);
        break;
    
    default:
        break;
    }
}
void Profile(UserLog &user)
{
    system("cls");
    cout << "Settings > Profile";
    cout << "\n\n\tRegistered Username: " <<  user.getUserName();
    cout << "\n\n\tRegistered Name: " <<  user.updname;
    cout << "\n\n\tRegisteration Time: " <<  user.updDate<<endl;
}

void UserLog ::changeDollar()
{
    string name = getName();
    for (int i = 0; name[i] != '\0'; i++)
    {
        if (name[i] == 36)
            name[i] = 32;
    }
    updname = name;
    string date = getRegDate();
    for (int i = 0; date[i] != '\0'; i++)
    {
        if (date[i] == 36)
            date[i] = 32;
    }
    updDate = date;
}

void UserLog ::wishUser()
{
    cout << "Hello " << getUpdName() << endl;
}

void UserLog ::Passlength()
{
    string password = getPassword();
    for (int i = 0; password[i] != '\0'; i++)
    {
        psslength++;
        maskedpss += 149;
    }
}

ifstream &operator>>(ifstream &in, UserLog &usr)
{
    in >> usr.username;
    in >> usr.name;
    in >> usr.password;
    in >> usr.RegDate;
    return in;
}

//Convert Spaces into Dollars
string changeSpaces(string sr)
{
    for (int i = 0; sr[i] != '\0'; i++)
    {
        if (sr[i] == 32)
            sr[i] = 36;
    }
    return sr;
}

// bool checkPass(string password)
// {
//     if ((password.size() < 8) && (password.size() > 18))
//     {
//         cout << "\nPlease Choose Password (8 to 18 digit long)";
//         return false;
//     }
//     for (int i = 0; password[i] != '\0'; i++)
//     {
//         if (password[i] == 32)
//             cout << "Do not Use Spaces In Password!";
//         if (!((password[i] >= 48 && password[i] <= 57) ||
//               (password[i] >= 65 && password[i] <= 90) ||
//               (password[i] >= 97 && password[i] <= 122)))
//         {
//         }
//         else
//         {
//             cout << "Password Should contain any special character.\n";
//         }
//     }
//     return 0;
// }

int main()
{
    int n;
    bool chkps, loggedin;
    string username, name;
    string password;

    while (1)
    {
        ofstream ofs("UserData.txt", ios::app);
        system("cls");
        cout << "Press 1 for Registration Process\n";
        cout << "Press 2 for Login Process\n";
        cout << "Press 3 To Exit\n";
        cin >> n;
        if (n == 1)
        {
            cout << "Enter Username: ";
            cin >> username;
            cout << "Enter Name: ";
            fflush(stdin);
            getline(cin, name);
            name = changeSpaces(name);
            cout << "Create Password: ";
            getline(cin, password);

            time_t now = time(0);
            char *date_time = ctime(&now);
            string datetime = date_time;
            datetime= changeSpaces(datetime);

            UserReg user1(username, name, password, datetime);
            ofs << user1;
            cout << "Registered Successfully!!\n";
            ofs.close();
        }
        else if (n == 2)
        {
            string usrid, pss;
            UserLog user_new;
            fflush(stdin);
            cout << "Enter Userid: ";
            getline(cin, usrid);
            fflush(stdin);
            cout << "Enter Password: ";
            getline(cin, pss);
            ifstream ifst;
            ifst.open("UserData.txt");
            int counter = 0;
            while (!ifst.eof())
            {
                ifst >> user_new;
                if ((!usrid.compare(user_new.getUserName())) && (!pss.compare(user_new.getPassword())))
                {
                    counter++;
                    break;
                }
            }
            if (counter == 0)
                cout << "No record found\n";
            else
            {
                loggedin = 1;
                cout << "Logged In Successfully!!\n";
            }
            ifst.close();
            if (loggedin)
            {
                system("cls");
                user_new.changeDollar();
                user_new.wishUser();
                cout << "Welcome To the App!\n";
                Setting(user_new);
                Profile(user_new);
            }
        }
        else if (n == 3)
        {
            cout << "\nThank you for Using The App\n";
            exit(0);
        }
        else
        {
            cout << "Choose Valid Option!!";
        }
        cout<<"\nPress any key to Continue...";
        getchar();
    }
    return 0;
}