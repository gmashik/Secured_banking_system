#include<iostream>
#include "header.h"
#include<fstream>
#include<cstdlib>
#include<iosfwd>
#include<cstdio>
using namespace std;

void account::read_input()
{
	cout<<"------------------------------------------\n";
    cout<<"\n Please Enter Your Account Number: ";
    cin>>account_number;
    cout<<"\nEnter The Given Name: ";
    cin.get(firstName,20);
    cout<<"\nEnter The Family(Last) Name: ";
    cin>>lastName;
    cout<<"\nEnter telephone Number: ";
    cin>>tel;
    cout<<"\nEnter Balance (in $CAD): ";
    cin>>total_Balance;
    cout<<endl;
    cout<<"------------------------------------------\n";
}
void account::record_read()
{
    ifstream in;
    in.open("data", ios::in | ios::binary);
    if(!in)
    {
        cout<<"Error 404 in Opening! File Not Found!!"<<endl;
        return;
    }
    cout<<"\n****Data from file****"<<endl;
    while(!in.eof())
    {
        if(in.read(reinterpret_cast<char*>(this), sizeof(*this))>0)
        {
            show_info();
        }
    }
    in.close();
}
void account::show_info()
{
	cout<<"===================================================================="<<endl;
    cout<<" Account Number is : "<<account_number<<endl;
    cout<<" Name of the account holder : "<<firstName<<"  "<<lastName<<endl;
    cout<<" Telephone Number is : "<<tel<<endl;
    cout<<" Current Balance: $Cad  "<<total_Balance<<endl;
    cout<<"===================================================================="<<endl;
}

void account::record_search()
{
    int n;
    ifstream infile;
    infile.open("data", ios::binary);
    if(!infile)
    {
        cout<<"\nError 404! File Not Found!!"<<endl;
        return;
    }
    infile.seekg(0,ios::end);
    int count = infile.tellg()/sizeof(*this);
    cout<<"\n There are "<<count<<" record in the file";
    cout<<"\n Please Enter Record Number to Search: ";
    cin>>n;
    infile.seekg((n-1)*sizeof(*this));
    infile.read(reinterpret_cast<char*>(this), sizeof(*this));
    show_info();
}
void account::info_write()
{
    ofstream out;
    out.open("data", ios::binary|ios::app);
    read_input();
    out.write(reinterpret_cast<char *>(this), sizeof(*this));
    out.close();
}
void account::record_mod()
{
    int n;
    fstream inoout;
    inoout.open("data", ios::in|ios::binary);
    if(!inoout)
    {
        cout<<"\nError in opening! File Not Found!!"<<endl;
        return;
    }
    inoout.seekg(0, ios::end);
    int count = inoout.tellg()/sizeof(*this);
    
    cout<<"\n Which record you want to modify: ";
    cin>>n;
    inoout.seekg((n-1)*sizeof(*this));
    inoout.read(reinterpret_cast<char*>(this), sizeof(*this));
    cout<<"Record "<<n<<" has following data"<<endl;
    show_info();
    inoout.close();
    inoout.open("data", ios::out|ios::in|ios::binary);
    inoout.seekp((n-1)*sizeof(*this));
    cout<<"\nEnter data to Modify "<<endl;
    read_input();
    inoout.write(reinterpret_cast<char*>(this), sizeof(*this));
}
void account::rec_delete()
{
    int n;
    ifstream in;
    in.open("data", ios::binary);
    if(!in)
    {
        cout<<"\nError in opening! File Not Found!!"<<endl;
        return;
    }
    in.seekg(0,ios::end);
    int count = in.tellg()/sizeof(*this);
    cout<<"\n There are "<<count<<" record in the file";
    cout<<"\n Enter Record Number to Delete: ";
    cin>>n;
    fstream tmp;
    tmp.open("tmpdata", ios::out|ios::binary);
    in.seekg(0);
    for(int i=0; i<count; i++)
    {
        in.read(reinterpret_cast<char*>(this),sizeof(*this));
        if(i==(n-1))
            continue;
        tmp.write(reinterpret_cast<char*>(this), sizeof(*this));
    }
    in.close();
    tmp.close();
    remove("data");
    rename("tmpdata", "data");
}
