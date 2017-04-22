#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

enum Section_Type
{
    General = 0,
    Cash
};

class Section
{
public:
    string Section_Name;
    string Section_Description;
    int Monthly_Income;
    int Job_Seats;
    Section_Type Type;
    Section() {}
    Section(string Name, string Desc, int Income, int Seats, Section_Type Sec_Type)
    {
        Section_Name = Name;
        Section_Description = Desc;
        Monthly_Income = Income;
        Job_Seats = Seats;
        Type = Sec_Type;
    }
};

class User
{
    public:
        string Name;
        int ID;
        string Password;
        int Total_Money;
    User() {}
    User(string User_Name, string Pass, int Account_ID, int Money)
    {
        Name = User_Name;
        Password = Pass;
        Total_Money = Money;
        ID = Account_ID;
    }
};

int Bank_Total_Money;

int main()
{
    Bank_Total_Money = 100000;
    int Running = 1;
    int Choice;

    ///////////////////////
    vector<Section> Sections;

    Sections.push_back(Section("Pension", "Description", 10000,10, Cash));
    Sections.push_back(Section("Bima", "Description", 1000,10, Cash));
    ////////////////////////
    vector<User> Users;

    Users.push_back(User("Sharmi", "Password", 102040, 2000));
    ////////////////////////
    int Continue_1;
    int Continue_2;
    string Name;
    string Password;
    while (Running)
    {
        cout << "Banking Management" << endl;
        cout << "1. New corner" << endl;
        cout << "2. Banker" << endl;
        cout << "3. User" << endl;
        cin >> Choice;
        switch(Choice)
        {
            case 1:

            /////////////////////////////////////////////////////////
            //New Corner
            int I;
            for (I = 0; I < Sections.size(); I++)
            {
                cout << I+1 << ". " << Sections[I].Section_Name << endl;
            }

            int Choice_2;
            cin >> Choice_2;

            cout << endl;
            cout << "Section Name : " << Sections[Choice_2-1].Section_Name << endl;
            cout << "Section Description : " << Sections[Choice_2-1].Section_Description << endl;
            cout << "Section Monthly Income : " << Sections[Choice_2-1].Monthly_Income << endl;
            cout << "Section Job Seats : " << Sections[Choice_2-1].Job_Seats << endl;
            cout << endl;

            ///////////////////////////////////////////////////////

            break;
            case 2:

            ///////////////////////////////////////////////////////
            //Banker
            Continue_1 = 1;
            while (Continue_1) {
            cout << endl;
            cout << "For Banker : " << endl;
            cout << "1. Diposit" << endl;
            cout << "2. Withdraw" << endl;
            cout << "3. Back" << endl;

            int Choice_3;
            cin >> Choice_3;
            int Money;

            switch (Choice_3)
            {
                case 1:
                    ////////////////////////////////
                    //Deposit

                    cout << endl << "How much money to you want to deposit ?" << endl;
                    cin >> Money;
                    Bank_Total_Money = Bank_Total_Money + Money;
                    cout << Money << " money deposited successfully." << endl;
                    cout << "Currently bank has : " << Bank_Total_Money << endl;
                break;
                case 2:
                    ////////////////////////////////
                    //Withdraw

                    cout << endl << "How much money to you want to withdraw ?" << endl;
                    cin >> Money;
                    Bank_Total_Money = Bank_Total_Money - Money;
                    cout << Money << " money withdrawn successfully." << endl;
                    cout << "Currently bank has : " << Bank_Total_Money << endl;
                break;
                default:
                    Continue_1 = 0;

            }
            }
            break;
            case 3:

            /////////////////////////////////////////////////////
            //User
            Continue_2 = 1;
            while (Continue_2)
            {
            cout << endl << "Choose user options : " << endl;
            cout << "1. Create Account" << endl;
            cout << "2. Sign In" << endl;
            cout << "3. Back" << endl;
            int Choice_4;
            int Account_No;
            int Money;
            cin >> Choice_4;
            switch(Choice_4)
            {
                case 1:

                //Create Account
                cout << endl << "Enter User Name : " << endl;
                cin >> Name;
                Account_No = rand() % 10000;
                cout << "Your given account No. : " << Account_No << endl;
                cout << "Enter password : " << endl;
                cin >> Password;
                cout << "Enter the money you want to keep : " << endl;
                cin >> Money;
                Users.push_back(User(Name, Password, Account_No, Money));
                cout << "Account created successfully" << endl;

                break;
                case 2:

                //Sign In
                cout << endl << "User Log In" << endl;
                cout << "-----------------------------------" << endl;
                cout << "Enter your name : ";
                cin >> Name;
                cout << "Enter your password : ";
                cin >> Password;

                int I;

                for (I = 0; I < Users.size(); I++)
                {
                    if (Users[I].Name == Name)
                    {
                        if (Users[I].Password == Password)
                        {

                            //User
                            cout << endl ;

                        }
                        else
                        {
                            cout << "Password wrong" << endl;
                            break;
                        }
                    }
                    else
                    {
                        cout << "User not found" << endl;
                        break;
                    }
                }

                break;
                default:
                Continue_2 = 0;
                break;
            }
            }
            ////////////////////////////////////////////////////

            break;
            default:
            break;
        }
    }


    return 0;
}
