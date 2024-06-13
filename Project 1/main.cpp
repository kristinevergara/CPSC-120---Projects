/*
*Name: Dahlia Sukaik
*Email: dahliasukaik@csu.fullerton.edu
*Name: Kristine Vergara
*Email: kvergara@csu.fullerton.edu
*Name: Elizabeth Mazuca
*Email: elizbethmazuca@csu.fullerton.edu
*/
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cctype>

using std::cout;
using std::endl;
using std::ofstream;
using std::ifstream;
using std::cin;
using std::string;
using std::left;
using std::right;
using std::fixed;
using std::setw;
using std::setprecision;


int main () {

  const string FILE = "words.db";
  //creating string for file 'words.db'
  string clear_database_input;
  //creating string to clear data in 'words.db'
  cout << "Welcome to the Word Association Game!\n" << endl;
  //welcome statement to user
  cout << "You will get to choose the number of entries you want to complete. " << endl;
  cout << "To play, you must enter one word and another word you associate with it. " << endl;
  cout << "Next, you will give this association a number to score it. " << endl;
  cout << "This will go on for however many entries you choose. " << endl;
  cout << "In the end, a summary of all your entries will be printed for you to see." << endl;
  cout << "Let's get started!\n" << endl;
  //explaining how the program will work/run and what it will ask of the user
  cout << "Would you like to clear the database? "  << endl;
  cout << "Please enter a y or yes. Otherwise, press any other character to continue: ";
  //asking user if they want to delete previous data inside 'words.db'
  cin >> clear_database_input;
  //getting user input if data base should be cleared

  for (string::iterator y = clear_database_input.begin (); y < clear_database_input.end (); y++) {
      *y = tolower (*y);
  //making a string case sensitive for clearning data base
  }

  if (clear_database_input == "yes" || clear_database_input == "y") {
      remove (FILE.c_str ());
      cout << "\n *Database cleared* \n" << endl;
  //letting user know that their command to clear the data base is complete
  }
  else {
      cout << "\n *continuing* \n" << endl;
  //letting user know that their command is continuing to run with a non-cleared database
  }

  ofstream outputFile;
  //getting ready to input/write data into 'words.db'
  outputFile.open (FILE, std::ios_base::app);
  //opening file 'words.db'
  int number_of_records;
  //declaring variable to hold the number of records the user wants
  cout << "How many records would you like to add? ==> ";
  //asking user how many records they would like to complete
  cin >> number_of_records;
  //getting numer of records user would like to complete
  
  string word1;
  //declaring variable to hold all of the first entered word of each record
  string word2;
  //declaring variable to hold all of the second entered word of each record
  int score;
  //creating variable to hold user inputted score of each record
  
  if (number_of_records > 0) {
    for (int num = 1; num <= number_of_records; num++) {
    //making questions reoccur based on number of records user typed
    	  cout << "\nCreating new record " << num << " of " << number_of_records << ".\n" << endl;
      //telling user what number record is being created
	  cout << "Note: Please only use single words; " << endl;
	  cout << "Don't input any words with spaces or non alpha-numeric characters. \n" << endl;
	  //asking user to enter one word containing no whitespaces
	  cout << "Please enter the first word: ";
	  //asking user to enter first word of each record
	  cin >> word1;
	  //storing first word of user inputs in 'words.db'
	  cout << "Please enter the second word: ";
	  //asking user to enter second word of each record
	  cin >> word2;
	  //storing second word of user inputs in 'words.db'
	  cout << "Please enter the score for this word association: ";
	  //asking user for a score of the words of the record they are on
	  cin >> score;
	  //storing the user inputted scores in 'words.db'
	  outputFile << word1 << " " << word2 << " " << score << endl;
	  //inputing the words and scores into 'words.db'
	}

    cout << "\nFinished adding new records.\n" << endl;
    // telling user words and score enteries are finished and thanking them

    outputFile.close ();
    //no more input to be collecting so closing 'words.db' 

    ifstream inputFile;
    //getting ready to display the enterted data from 'words.db'
    inputFile.open (FILE);
    //re-opening 'words.db'
    double sum = 0;
    //creating variable to hold the sum of all the inputed scores
    int total_records = 0;
    //creating variable to display all records from inside the previous loop
    cout << "\nYou have completed all of your entries. Thank you for your input! \n" << endl;
    //telling user that they have completed all of the records and thanking them
    cout << "Printing all recorded data: \n" << endl;
    //telling user that the program will display the recorded entries

   
    while (!inputFile.fail() && inputFile >> word1 >> word2 >> score ) {
    // gathering the words and scores for 'words.db' 
	  cout << left << setw (20) << word1;
	  //displaying word1 left justified 
	  cout << left << setw (20) << word2;
	  //displaying word2 left justified 20 spaces away from word 1 
	  cout << right << setw (10) << score << endl;
	  //diplaying score right justified 10 spaces away from word 2
	  sum += score;
	  //adding all the scores together to get a sum
	  total_records ++;
	  //will display all other inputs following this format 
    } 

        cout << "\nPrinting final summary of your input from the database: \n" << endl;
      //displaying the final and completed summary of all input and scores in the correct format
	cout << "Total word count: " << (total_records * 2) << endl;
      //displaying the total words (multiplying the total records by 2(2 words per entry))
	cout << "Total records: " << total_records << endl;
      //displaying total records the user completed
	cout << "Average score: " << fixed << setprecision (2) << (sum / total_records) << endl;
      //displaying the average score by getting the summ and dividing it by the total completed entry
	cout << "\nThank you for playing this game! We hope you had fun :) " << endl;
      //Thanking user for using our program
	
	inputFile.close ();
      //closing 'words.db' until program is ran again
    }
    
  else {
    cout << "Invalid input! Please run the program another time and " << endl;
    cout << "enter an integer greater than 0 for the number of records. Goodbye :(" << endl;
    //if the user inputs a 0 for the number of records they wish to input
  }

  return 0;
}
