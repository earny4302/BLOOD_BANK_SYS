#include<iostream>
#include<conio.h>
#include<bits/stdc++.h>

using namespace std;

class blood;
class patient
{
    char name[50];
    int mobile;
    int blt;
    int amount;
    public:
    friend class blood;
    void input(int,int);
};
void patient::input(int bt,int a)
{
    blt=bt;
    amount=a;
    cout<<"\nName:-\t";
    cin.ignore();
    cin.getline(name,50);
    cout<<"\nMobile Number:-\t";
    cin>>mobile;

}
class donor
{
    char name[50];
    long long mobile;
    int amount;
    int blt;
    public:
    friend class blood;
    void input();

};
void donor::input()
{
    cout<<"\nName:-\t";
    cin.ignore();
    cin.getline(name,50);
    cout<<"\nMobile Number:-\t";
    cin>>mobile;
    cout<<"\nBlood type(0-(A+),1-(A-),2-(B+),3-(B-),4-(AB+),5-(AB-),6-(O+),7-(O-)):-\t";
    cin>>blt;
    cout<<"\nAmount:-\t";
    cin>>amount;
}
class blood
{
    int bt[8]={0,0,0,0,0,0,0,0};
    public:
    void dashboard();
    void update_d(donor );
    void update_p(patient );
    int check(int,int);
};
int blood::check(int blt,int amount)
{
    
    if((blt>=0&&blt<8)&&bt[blt]>=amount)
    {
        return 1;
    }
    else 
        return 0;
}
void blood::update_p(patient p)
{
    bt[p.blt]-=p.amount;
}
void blood::update_d(donor d)
{

    bt[d.blt]+=d.amount;
    
}
void blood::dashboard()
{
    cout<<"\nDASHBOARD:-"<<endl;
    cout<<"A+:-\t"<<bt[0]<<endl;
    cout<<"A-:-\t"<<bt[1]<<endl;
    cout<<"O POS:-\t"<<bt[2]<<endl;
    cout<<"O NEG:-\t"<<bt[3]<<endl;
    cout<<"B POS:-\t"<<bt[4]<<endl;
    cout<<"B P:-\t"<<bt[5]<<endl;
    cout<<"AB NEG:-\t"<<bt[6]<<endl;
    cout<<"AB POS:-\t"<<bt[7]<<endl;
}
int eligibility()
{
    int age,weight,bi;
    cout<<"\n";
    cout<<"Enter your age:-"<<endl;
    cin>>age;
    cout<<"Enter your weight:-"<<endl;
    cin>>weight;
    cout<<"\nany blood infection(1-y/0-n):-"<<endl;
    cin>>bi;
    if((age>=18)&&(weight>40)&&(bi==0))
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}
int main()
{
    int choice;
    int x;
    int check;
    int bt;
    int amount;
    blood b;
    donor d[100];
    patient p[100];
    int i=0;
    int j=0;
    do
    {
        system("CLS");
        cout<<"\nHOW CAN WE HELP YOU?"<<endl;
        cout<<"1.REGISTER A DONOR:-"<<endl;
        cout<<"2.REGISTER A RECIEPTIENT:-"<<endl;
        cout<<"3.SHOW DASHBOARD:-"<<endl;
        cout<<"4.EXIT:-\t";
        cin>>choice;
        switch (choice)
        {
            case 1:
                x=eligibility();
                if(x==1)
                {
                    d[i].input();
                    b.update_d(d[i]);
                    i++;
                }
                else
                    cout<<"\nYou are not eligible for donation";
                    getch();
                break;

            case 2:
                cout<<"\nEnter your blood group(0-(A+),1-(A-),2-(B+),3-(B-),4-(AB+),5-(AB-),6-(O+),7-(O-)):-";
                cin>>bt;
                cout<<"\nEnter amount:-";
                cin>>amount;
                check=b.check(bt,amount);
                if(check==1)
                {
                    p[j].input(bt,amount);
                    b.update_p(p[j]);
                    j++;
                }
                else 
                    cout<<"\nNot Available";
                break;
            
            case 3:
                b.dashboard();
                getch();
                break;
            case 4:
                exit(0);
        
            default:
                cout<<"\nWRONG CHOICE";
                getch();
                break;
        }
    }while(choice!=4);

    return 0;
}