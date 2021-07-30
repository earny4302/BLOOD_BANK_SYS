#include<iostream>
#include<conio.h>
#include<vector>
using namespace std;
class recipient;
int cal_A_pos()
{
    int a;
    
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
void donor::get_detail()
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
}
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
    void get_detail();
};

int check_criteria_donor()
{
    int age,weight,hemo,fit,STD;
    do{
        cout<<"\nIS YOUR AGE IS BETWEEN 18 YEARS AND 65 YEARS:-(1-YES,2-NO)\t";
        cin>>age;
    }while(age!=0&&age!=1);
    do{
        cout<<"\nIS YOUR WEIGHT MORE THAN 50 KG:-(1-YES,2-NO)\t";
        cin>>weight;
    }while(weight!=0&&weight!=1);
    do{
        cout<<"\nIS YOUR HEMOGLOBIN IS GREATER THAN 12 g/dl:-(1-YES,2-NO)\t";
        cin>>hemo;
    }while(hemo!=0&&hemo!=1);
    do{
        cout<<"\nARE YOU FIT:-(1-YES,2-NO)\t";
        cin>>fit;
    }while(fit!=0&&fit!=1);
    do{
        cout<<"\nEVER CONTRACTED ANY STD:-(1-YES,2-NO)\t";
        cin>>STD;
    }while(STD!=0&&STD!=1);
    if(age==1 && weight==1 && hemo==1 &&  fit==1 && STD==0)
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
    do
    {
        vector<donor*> don;
        system("CLS");
        dashboard();
        cout<<"\nHOW CAN WE HELP YOU?";
        cin>>choice;
        switch (choice)
        {
            case 1:
            int x=check_criteria_donor();
            if(x==1)
            {
                donor *d=new donor();
                d->get_detail();
                don.push_back(d);
            }
                
            break;
            case 2:

        
        default:
            cout<<"\nWRONG CHOICE";
            getch();
            break;
        }
        
    }while(choice!=4);
    return 0;
}
