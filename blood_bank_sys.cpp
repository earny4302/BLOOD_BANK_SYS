#include<iostream>
#include<conio.h>
#include<vector>
#include<fstream>
using namespace std;
class recipient;
class blood_bank;
class transaction;
class donor
{
    string name;
    string address;
    long long mobile_no;
    long long addhar;
    int day;
    int month;
    int year;
    
    int amount_ml;
    public:
    char blood_type;
    char rh;
    friend class blood_bank;
    friend class transaction;
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
    string name;
    string address;
    long long mobile_no;
    long long addhar;
    int day;
    int month;
    int year;
    
    int amount_ml;
    public:
    char blood_type;
    char rh;
    friend class blood_bank;
    friend class transaction;
    
    void get_detail(char,char,int);
};
void recipient::get_detail(char bg,char rhe,int amount)
{
    blood_type=bg;
    rh=rhe;
    amount_ml=amount;
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
    
    
}
class blood_bank
{
    int A_pos,A_neg,B_pos,B_neg,AB_pos,AB_neg,O_pos,O_neg;
    
    public:
    void calculate(vector<donor*> d,vector<recipient*>r);
    friend void dashboard(blood_bank);
    int check(char,char,int);
}d;
int blood_bank::check(char bg, char rhe, int amount)
{
    int blood_g;
        if(bg=='A'&&rhe=='+')
        {
           blood_g=A_pos;
       }
       if(bg=='B'&&rhe=='+')
       {
           blood_g=B_pos;
       }
       if(bg=='AB'&&rhe=='+')
       {
           blood_g=AB_pos;
       }
       if(bg=='A'&&rhe=='-')
       {
           blood_g=A_neg;
       }
       if(bg=='B'&&rhe=='-')
       {
           blood_g=B_neg;
       }
       if(bg=='AB'&&rhe=='-')
       {
           blood_g=AB_neg;
       }
       if(bg=='O'&&rhe=='+')
       {
           blood_g=O_pos;
       }
       if(bg=='O'&&rhe=='-')
       {
           blood_g=O_neg;
       }
       if(blood_g>=amount)
       {
           return 1;
       }
       else
        return 0;
}
void dashboard(blood_bank d)
{   
    cout<<"\nA_pos"<<d.A_pos;
    cout<<"\nA_neg"<<d.A_neg;
    cout<<"\nB_pos"<<d.B_pos;
    cout<<"\nB_neg"<<d.B_neg;
    cout<<"\nAB_pos"<<d.AB_pos;
    cout<<"\nAB_neg"<<d.AB_neg;
    cout<<"\nO_pos"<<d.O_pos;
    cout<<"\nO_neg"<<d.O_neg;
}
class transaction
{
    string type;
    string name;
    string address;
    long long mobile_no;
    long long addhar;
    int day;
    int month;
    int year;
    
    int amount_ml;
    public:
    char blood_type;
    char rh;
    transaction(int i,donor* d)
    {
        if(i==0)
        {
            type="DONOR";
        }
        name=d->name;
        address=d->address;
        mobile_no=d->mobile_no;
        addhar=d->addhar;
        day=d->day;
        month=d->month;
        year=d->year;
        amount_ml=d->amount_ml;
        blood_type=d->blood_type;
        rh=d->rh;
    }
    transaction(int i,recipient* r)
    {
        if(i==1)
        {
            type="RECIEPIENT";
        }
        name=r->name;
        address=r->address;
        mobile_no=r->mobile_no;
        addhar=r->addhar;
        day=r->day;
        month=r->month;
        year=r->year;
        amount_ml=r->amount_ml;
        blood_type=r->blood_type;
        rh=r->rh;
    }
    void show_details();
    void insert();
};
void transaction::insert()
{
    
    system("cls");
    fstream file;
  
    file.open("transaction.txt", ios::app | ios::out);
    file << " " << name << " " << blood_type << " " << rh<< " " << amount_ml<< address << "\n";
    file.close();

}
void transaction::show_details()
{
    
    cout<<"\n"<<type;
    cout<<"\nNAME:-"<<name;
    cout<<"\nADDRESS:-"<<address;
    cout<<"\nMOBILE NO.:-"<<mobile_no;
    cout<<"\nADDHAR:- "<<addhar;
    cout<<"\nDATE:-"<<day<<" "<<month<<" "<<year;
    cout<<"\nBLOOD DONATED:-(in ml)"<<amount_ml;
    cout<<"\nBLOOD TYPE:-"<<blood_type<<rh;

}
void blood_bank::calculate(vector<donor*> d,vector<recipient*>r)
{
    A_pos=0,A_neg=0,B_pos=0,B_neg=0,AB_pos=0,AB_neg=0,O_pos=0,O_neg=0;
   
    for (auto& it : d) 
    {
       if(it->blood_type=='A'&&it->rh=='+')
       {
           A_pos+=it->amount_ml;
       }
       if(it->blood_type=='B'&&it->rh=='+')
       {
           B_pos+=it->amount_ml;
       }
       if(it->blood_type=='AB'&&it->rh=='+')
       {
           AB_pos+=it->amount_ml;
       }
       if(it->blood_type=='A'&&it->rh=='-')
       {
           A_neg+=it->amount_ml;
       }
       if(it->blood_type=='B'&&it->rh=='-')
       {
           B_neg+=it->amount_ml;
       }
       if(it->blood_type=='AB'&&it->rh=='-')
       {
           AB_neg+=it->amount_ml;
       }
       if(it->blood_type=='O'&&it->rh=='+')
       {
           O_pos+=it->amount_ml;
       }
       if(it->blood_type=='O'&&it->rh=='-')
       {
           O_neg+=it->amount_ml;
       }
    }
    for (auto& it : r) 
    {
       if(it->blood_type=='A'&&it->rh=='+')
       {
           A_pos-=it->amount_ml;
       }
       if(it->blood_type=='B'&&it->rh=='+')
       {
           B_pos-=it->amount_ml;
       }
       if(it->blood_type=='AB'&&it->rh=='+')
       {
           AB_pos-=it->amount_ml;
       }
       if(it->blood_type=='A'&&it->rh=='-')
       {
           A_neg-=it->amount_ml;
       }
       if(it->blood_type=='B'&&it->rh=='-')
       {
           B_neg-=it->amount_ml;
       }
       if(it->blood_type=='AB'&&it->rh=='-')
       {
           AB_neg-=it->amount_ml;
       }
       if(it->blood_type=='O'&&it->rh=='+')
       {
           O_pos-=it->amount_ml;
       }
       if(it->blood_type=='O'&&it->rh=='-')
       {
           O_neg-=it->amount_ml;
       }
    }
   
}

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
    int check_re;
    vector<donor*> don;
    vector<recipient*> recep;
    vector<transaction*>trans;
    do
    {
        
        system("CLS");
        d.calculate(don,recep);
        dashboard(d);
        cout<<"\nHOW CAN WE HELP YOU?";
        cout<<"\n1.REGISTER A DONOR:-\t";
        cout<<"\n2.REGISTER A RECIEPTIENT:-\t";
        cout<<"\n3.TRANSACTION:-\t";
        cout<<"\n4.EXIT:-\t";
        cin>>choice;
        switch (choice)
        {
            case 1:
                x=check_criteria_donor();
                if(x==1)
                {
                    donor *d=new donor();
                    d->get_detail();
                    transaction *t=new transaction(0,d);
                    trans.push_back(t);
                    don.push_back(d);
                }
                else
                    cout<<"\n not fit";
                break;

            case 2:
                char bg,rhe;
                int amount;
                cout<<"\nWhich blood group(A,B,O,AB):-";
                cin>>bg;
                cout<<"\nWhich rhesus(+,-):-";
                cin>>rhe;
                cout<<"\namount of blood needed:-";
                cin>>amount;
                check_re=d.check(bg,rhe,amount);
                if(check_re==1)
                {
                    recipient *receip=new recipient();
                    receip->get_detail(bg,rhe,amount);
                    transaction *t=new transaction(1,receip);
                    trans.push_back(t);
                    recep.push_back(receip);
                }
                else 
                    cout<<"\nNot Available";
                break;
            
            case 3:
                for (auto& it : trans) 
                {
                    cout<<it<<endl;
                    it->show_details();
                    
                }
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
    don.clear();
    recep.clear();
    return 0;
}
