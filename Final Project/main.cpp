//Name: Kristine Vergara
//CWID: 886992213 
//Email: kvergara@csu.fullerton.edu

#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::ofstream;
using std::ifstream;
using std::vector;

//const double EULERS_NUMBER = 2.71828;
//global constant

int main()
{
  const string FILE = "out.txt";
  remove (FILE.c_str ());
  //removing/emptying file "out.txt"
  int n_items;    //creating variable to hold number of items of data
  double item;    //creating variable to hold data item
  
  double sum = 0; 
    //creating variable of the sum of all coverted data items
  const double Y = (pow(M_E,(2*item))-1)/(pow(M_E,(2*item))+1) ;
    //writing equation of constants, displaying final value
  
  cout << "How many items of data do you wish to enter? " << endl;
  //asking user how many items of data they want to create
  cin >> n_items;
  //collecting the number of items to create
  
  if (n_items <= 0)
  {
    cout << "Invalid number. Now quitting! " << endl;
    //if user enters a number < or = 0 the program will quit
  }
  else 
  { 
    ofstream outputFile;
    //getting ready to write data into "out.txt"
    outputFile.open (FILE, std::ios_base::app);
    //opening file "out.txt"  
    
    cout << "Ok! Will receive " << n_items << " data items. " << endl; 
    //telling user the program will recieve n_items of data
    
    
    vector <double> trans_i(n_items);
    
    for (item = 0; item <= n_items; item++)
      {
        cout << "Please enter the next data item. " << endl;
        //asking user to enter the data item
        cin >> item;
        //revieving item variable
        cout << "Recieved " << item << " and converted to ==> " << endl;
        cout << trans_i[item] << endl;
        sum += trans_i[item];
      }
    
    cout << "Thank you for entering your data. " << endl;
    //thanking user for entering data and closing the file "out.txt"
    
    outputFile.close ();
    //no more input to be collecting so closing "out.txt" 
    ifstream inputFile;
    //getting ready to display the enterted data from "out.txt"
    inputFile.open (FILE);
    //opening file to display data in file "out.txt"

       //sum += trans_i[item];
       //adding all the convereted items together to get a sum 
    cout << "Lowest converted value: " << trans_i[item] << "" << endl;
    //displaying lowest converted item
    cout << "Highest converted value: " << trans_i[item] << "" << endl;
    //displaying highest converted item
    cout << "Sum of all converted values: " << sum << "" << endl;
      //sum of all converted items
   
   }
  
  return 0;
}
