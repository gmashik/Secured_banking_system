#include <iostream>
#include "header.h"
#include<fstream>
#include<cstdlib>
#include<iosfwd>
#include<cstdio>
#include<cmath>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	account ac;
    int num,apass,epass,c,lc;
    cout<<"===================================================================================================\n";
    cout<<"                               Welcome to the secured banking system                                  \n";
    cout<<"====================================================================================================\n";
    start:cout<<"Please Select an option below \n";
    			cout<<"***Note that only admin can add or delete acount*****\n";
           		cout<<"Please Select an option below \n";
        		cout<<"		Press 1 to Add account record \n";
        		cout<<"		Press 2 to Show record from the server\n";
        		cout<<"		Press 3 to Search Record from server\n";
       			cout<<"		Press 4 to Modify existing Record\n";
       			cout<<"		Press 5 to Delete an existing Record\n";
        		cout<<"		Press 6 to Quit\n";
        		cout<<"		\n Please enter your choice: ";
        		cin>>num;
        		switch(num)
        		{
        			case 1:
        				cout<<"Please Enter admin password :";
        				cin>>apass;
            			if(apass==1234){
            				ac.info_write();
           					break;
						}else{
				        	cout<<"Wrong Password please press 1 to retry and 0 to exit :";
							cin>>c;
							if(c==1) {
							goto start;
							}else{
								exit(0);
							}
						}
	
        			case 2:
            			cout<<"Please Enter your password :";
        				cin>>epass;
            			if(epass==1234 || epass==4567){
            				ac.read_input();
           					break;
						}else{
				        	cout<<"Wrong Password please press 1 to retry and 0 to exit :";
							cin>>c;
							if(c==1) {
							goto start;
							}else{
								exit(0);
							}
						}
        			case 3:
            			cout<<"Please Enter your password :";
        				cin>>epass;
            			if(epass==1234|| epass==4567){
            				ac.record_search();
           					break;
						}else{
				        	cout<<"Wrong Password please press 1 to retry and 0 to exit :";
							cin>>c;
							if(c==1) {
							goto start;
							}else{
								exit(0);
							}
						}
        			case 4:
            			cout<<"Please Enter your password :";
        				cin>>epass;
            			if(epass==1234|| epass==4567){
            				ac.record_mod();
           					break;
						}else{
				        	cout<<"Wrong Password please press 1 to retry and 0 to exit :";
							cin>>c;
							if(c==1) {
							goto start;
							}else{
								exit(0);
							}
						}
        			case 5:
            			cout<<"Please Enter admin password :";
        				cin>>apass;
            			if(apass==1234){
            				ac.rec_delete();
           					break;
						}else{
				        	cout<<"Wrong Password please press 1 to retry and 0 to exit :";
							cin>>c;
							if(c==1) {
							goto start;
							}else{
								exit(0);
							}
						}
       				case 6:
            			exit(0);
           				break;
        			default:
            			cout<<"\nEnter corret choice";
            			exit(0);
        		}
    		system("pause");
			
	return 0;
}
