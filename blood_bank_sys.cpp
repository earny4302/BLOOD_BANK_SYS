#include<iostream>
#include<conio.h>
#include<vector>
using namespace std;
class recipient;


void dashboard()
{
    int A_pos,A_neg,B_pos,B_neg,AB_pos,AB_neg,O_pos,O_neg;
    
    
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
    
    int amount_ml;
    public:
    char blood_type;
    char rh;
    friend void dashboard();
    void get_detail();
};
void donor::get_detail()
{
    cout<<"\nENTER NAME:-\t";
    cin.clear();
    cin.sync();
    getline(cin,name);
    cout<<"\nENTER ADDRESS:-\t";
    cin.clear();
    cin.sync();
    getline(cin,address);
    cout<<"\nENTER YOUR ADDHAR:-\t";
    cin>>addhar;
    cout<<"\nENTER YOUR MOBILE NO.:-\t";
    cin>>mobile_no;
    cout<<"\nENTER YOUR BLOOD TYPE(A,B,AB,O):-\t";
    cin>>blood_type;
    cout<<"\nENTER YOUR RHESUS(+,-):-\t";
    cin>>rh;
    cout<<"\nENTER AMOUNT BLOOD DONATED(IN ML):-\t";
    cin>>amount_ml;
}
class recipient
{
    int no;
    string name;
    string address;
    long long mobile_no;
    long long addhar;
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
    int x;
    vector<donor*> don;
    do
    {
        
        system("CLS");
        dashboard();
        cout<<"\nHOW CAN WE HELP YOU?";
        cin>>choice;
        switch (choice)
        {
            case 1:
             x=check_criteria_donor();
            if(x==1)
            {
                donor *d=new donor();
                d->get_detail();
                don.push_back(d);
            }
            break;

            case 2:
              for (auto& it : don) {
  
        
                    cout << it->blood_type<<" "<<it->rh<<endl;
                 }
                 getch();
            break;


        
        default:
            cout<<"\nWRONG CHOICE";
            getch();
            break;
        }
        
    }while(choice!=4);
    don.clear();
    return 0;
}
