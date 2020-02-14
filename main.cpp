//Programmer Names: Angelique Lopez, Alvin Beltran
//DUE DATE:02/13/2020
//CLASS: CIS-17A
//PROFESSOR: DR. NGUYEN
//FINAL PROJECT C++ FOR SMALL BUSINESS
//A+ BOWLS
//This is a simple restaurant ordering program that lets user
//Choose between protein, beans, rice, and topping options.
//the program repeats your order at the end along with customers total cost

//preprocessor directives 
#include<iostream>
#include<string>
#include<iomanip> 
#include<fstream>
#include"Order.h"
using namespace std; 

  
int main() 
{
  //variable definition statements 
  
  double totalCost;
  int userChoice[4];
  Order menu;
  char name[20];
  
  cout<<"******************************************"<<endl;
  cout<<"         Welcome to A+ Bowls       "<<endl; 
  cout<<"******************************************"<<endl<<endl;
   
   cout<<"Here you will build your own unique burrito bowl!"<<endl; 
  cout<<"Please follow the following prompts on your screen"<<endl<<endl; 

  cout<<"******************************************"<<endl<<endl;
  //asking user for name 
  cout << "Please Enter Your First Name: ";
  cin.getline(name, 20);
  //display user name 
  cout << "Hello " << name << ".."<< endl<< endl; 


  cout<<"*****Protein Options*****"<<endl<<endl;
 for( int i = 0; i< 5; i++)
  {
  cout<<i<<" "<<menu.getProteinOptions(i)<< "\t $"<<menu.getProteinPrice(i)<<endl;
  }
  //get protien option from user 
 cout<<"Please Select a Protein Option (0-4): ";
 cin>>userChoice[0];
//display user choice and price 

 cout<<menu.getProteinOptions(userChoice[0])<<endl<<endl;


cout<<"*****Bean Options*****"<<endl<<endl;

 for ( int i =0; i<2; i++)
 {
  cout<<i<<" "<<menu.getBeanOptions(i)<< "\t $"<<menu.getBeanPrice(i)<<endl; 
 }

 //get bean option from user 

 cout<<"Please Select a Bean option (0-1): ";
 cin>>userChoice[1];
//display user option 
 cout<<menu.getBeanOptions(userChoice[1])<<endl<<endl;


cout<<"*****Rice Options*****"<<endl<<endl;

 for( int i = 0; i <3; i++)
 //display rice menu options 
 {
 cout<<i<<" "<<menu.getRiceOptions(i)<< "\t $"<<menu.getRicePrice(i)<<endl;
 }
 //user rice option 
 cout<<"Please Select a Rice Option (0-2): ";
 cin>>userChoice[2];

//display user choice 
 cout<<menu.getRiceOptions(userChoice[2])<<endl<<endl; 

cout<<"*****Topping Options*****"<<endl<<endl;

 for ( int i =0; i<7; i++)
 {
  cout<<i<<" "<<menu.getTopOption(i)<< "\t $"<<menu.getTopPrice(i)<<endl; 
 }
 //user topping option 
 cout<<"Please Select a Topping Option (0-6): ";
 cin>>userChoice[3];
 
 cout<<menu.getTopOption(userChoice[3])<<endl<<endl;
//display order 
 cout<< name << "'s order is a "<<menu.getProteinOptions(userChoice[0])<<" bowl with "
 <<menu.getBeanOptions(userChoice[1])<<", "
 <<menu.getRiceOptions(userChoice[2])<<" and "
 <<menu.getTopOption(userChoice[3])<<endl;



  //additon of prices of items 
  totalCost = menu.getProteinPrice(userChoice[0]) + 
  menu.getBeanPrice(userChoice[1])+
  menu.getRicePrice(userChoice[2]) + 
  menu.getTopPrice(userChoice[3]);
  //display pricing of items 
  cout<< name <<"'s total cost is: $ "<< totalCost << endl;
  //receipt text file 
  {
    fstream dataFile;
    dataFile.open("Receipt.txt",ios::out);

    dataFile <<"******************************************" << endl;
    dataFile <<"************ A+ Bowls Receipt ************"<<endl; 
    dataFile <<"****************************************** \n\n"<< endl;
    dataFile << name << "'s order is a "<<menu.getProteinOptions(userChoice[0])<<" bowl with \n"
    <<menu.getBeanOptions(userChoice[1])<<", "
    <<menu.getRiceOptions(userChoice[2])<<" and "
    <<menu.getTopOption(userChoice[3])<< "\n\n"<< endl;

    dataFile << "Total amount paid is $" << totalCost << "\n\n"<< endl;
 
    dataFile << "******************************************\n\n" << endl;
    dataFile.close();
  

  }


}
