#include<iostream>
#include<conio.h>
#include<vector>
using namespace std;
class recipient;
int cal_A_pos()
{
    int a;
    for(int i=0)
}
int cal_A_neg()
{

}
int cal_B_pos()
{

}
int cal_B_neg()
{

}
int cal_AB_pos()
{

}
int cal_AB_neg()
{

}
int cal_O_pos()
{

}
int cal_O_neg()
{

}


void dashboard()
{
    int A_pos,A_neg,B_pos,B_neg,AB_pos,AB_neg,O_pos,O_neg;
    A_pos=cal_A_pos();
    A_neg=cal_A_neg();
    B_pos=cal_B_pos();
    B_neg=cal_B_neg();
    AB_pos=cal_AB_pos();
    AB_neg=cal_AB_neg();
    O_pos=cal_O_pos();
    O_neg=cal_O_neg();



}
class donor
{
    int no;
    string name;
    string address;
    long int mobile_no;
    long int addhar;
    int day;
    int month;
    int year;
    string blood_type;
    int amount_ml;
    public:
    friend void dashboard();
    void get_detail();
};
class recipient
{
    int no;
    string name;
    string address;
    long int mobile_no;
    long int addhar;
    int day;
    int month;
    int year;
    string blood_type;
    int amount_ml;
    public:
    friend void dashboard();
};

int check_criteria()
{

}
int main()
{
    int choice;
    do
    {
        system("CLS");
        dashboard();
        cout<<"\nHOW CAN WE HELP YOU?";
        cin>>choice;
        switch (choice)
        {
            case 1:
            int x= check_criteria();
            if(x==1)
                
            break;
        
        default:
            break;
        }
        
    }while(choice!=4);
    return 0;
}
