#include "AnimalList.cpp"
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

//Function to get data from data set
//Puts that data into the variables in struct AnimalList
Animal getAnimalData(istream &File);
//Function to reset the data set after the program is finished
void ResetList(istream &File);
//Function to get response from user 
char getResponse();

//object to use struct AnimalList in main cpp
AnimalList myAnimal(1);

int main() {
  //Variable for the data set
  ifstream Species;
  //Open data set and insert into variable 
  Species.open("species_revised.csv", ios_base::in);
  string column_name;
  getline(Species, column_name);

  //Load 100 items from data set into AnimalList
  //Group task 1
  //Devin Johnson & Tychicus Johnson
  for (int i = 0; i < 100; i++) {
    myAnimal.insert(getAnimalData(Species));
  }

  //myAnimal.printScientific();

  char option = '\0';
  do {
    int choice;
    // create menu
    cout << "************************************************" << endl;
    cout << "|                    Menu                      |" << endl;
    cout << "|**********************************************|" << endl;
    cout << "|           1. Display Animal List             |" << endl;
    cout << "|**********************************************|" << endl;
    cout << "|          2. Delete a Random Animal           |" << endl;
    cout << "|**********************************************|" << endl;
    cout << "|             3. Sort by Occurence             |" << endl;
    cout << "|**********************************************|" << endl;
    cout << "|         4. Search Conservation Status        |" << endl;
    cout << "|**********************************************|" << endl;
    cout << "|             5. Nativeness Check              |" << endl;
    cout << "|**********************************************|" << endl;
    cout << "|              6. Search by Order              |" << endl;
    cout << "|**********************************************|" << endl;
    cout << "|         7. Scientific to Common Swap         |" << endl;
    cout << "|**********************************************|" << endl;   
    cout << "|         8. Check if abundunce or not         |" << endl;
    cout << "|**********************************************|" << endl;     
    cout << "|              0. Exit Application             |" << endl;
    cout << "************************************************" << endl;
    cout << "Choose a task to complete, choose 0 to exit application: ";
    cin >> choice;
    while (choice < 0 || choice > 8) {
      cout << "Invalid Operation. Enter a number from 0-8: ";
      cin >> choice;
    }

    cout << "\n";
    cin.ignore();

    switch (choice) {
      case 1: {
        //Group task 2
        //Devin Johnson & Tychicus Johnson
        myAnimal.Display();
        break;
      }
      case 2: {
        //Group task 3
        //Devin Johnson
        //Variable for yes/no input
        char input;
        //Select a random number
        srand(time(NULL));
        int rand_index = rand() % 100;
        //Time complexity analysis
        clock_t t1 = clock();
        myAnimal.deleteElement(rand_index);
        clock_t t2 = clock();
        cout << "Deletion took: " << t2 - t1 << " ticks" << endl;
        cout << "Index Deleted: " << rand_index + 1 << endl;
        cout << "Would you like to see the new list? (Y/N) ";
        cin >> input;
        //Allow user to see the new list
        input = toupper(input);
        if(input == 'Y'){
          myAnimal.Display();
        }
        break;
      }
      case 3: {
        //Group task 4
        //Devin Johnson

        char input;
        //Time complexity analysis
        clock_t t1 = clock();
        myAnimal.SortSwap();
        clock_t t2 = clock();
        cout << "Sort took: " << t2 - t1 << " ticks" << endl;
        cout << "Would you like to see the new list? (Y/N) ";
        cin >> input;
        //Allow user to see the sorted list
        input = toupper(input);
        if(input == 'Y'){
          myAnimal.Display();
        } 
        break;
      }
      case 4: {
        //Group tast 5
        //Devin Johnson

        //print common names with species ID
        myAnimal.IDcname();
        cout << "\n";
        string input;
        cout << "Enter Species ID: ";
        cin >> input;
        //Time complexity analysis
        clock_t t1 = clock();
        myAnimal.SearchCS(input);
        clock_t t2 = clock();
        cout << "Search took: " << t2 - t1 << " ticks" << endl;
        break;
      }
      case 5: {
        //Solo task 1
        //Devin Johnson

        //print common names with species ID
        myAnimal.IDcname();
        cout << "\n";
        string isNative;
        cout << "Enter Species ID: ";
        cin >> isNative;
        //Time complexity analysis
        clock_t t1 = clock();
        myAnimal.isNative(isNative);
        clock_t t2 = clock();
        cout << "Search took: " << t2 - t1 << " ticks" << endl;
        break;
      }
      case 6: {
        //Solo task 2
        //Devin Johnson

        //print all orders
        myAnimal.printOrder();
        cout << "\n";
        string order;
        cout << "Enter Order: ";
        cin >> order;
        //time complexity analysis
        clock_t t1 = clock();
        myAnimal.OrderSearch(order);
        clock_t t2 = clock();
        cout << "\n";
        cout << "Search took: " << t2 - t1 << " ticks" << endl;
        break;
      }
      case 7:{
        //Extra task
        //Devin Johnson

        //print scientific names with species ID
        myAnimal.IDsname();
        cout << "\n";
        string input;
        cout <<"Enter Species ID: ";
        cin >> input;
        //time complexity analysis
        clock_t t1 = clock();
        myAnimal.SntoCn(input);
        clock_t t2 = clock();
        cout << "\n";
        cout << "Operation took: " << t2 - t1 << " ticks" << endl;
        break;
      }
      case 8:{
      //Extra task
      // Tychicus Johnson
        
      // Check if the animal is abundant or not
      myAnimal.PrintAbundant();
        cout << "\n";
        string abundance;
        cout << "Enter Abundant, Casional, Common, Uncommon, Occasional, Rare, or Unknown:  ";
        cin >> abundance;
        //time complexity analysis
        clock_t t1 = clock();
        myAnimal.AbundantSearch(abundance);
        clock_t t2 = clock();
        cout << "\n";
        cout << "Operation took: " << t2 - t1 << " ticks" << endl;
        break;
        }
      case 0: {
        cout << "Application Closed" << endl;
        return 0;;
      }
    }
    //auto capitalized the user input
    if (choice != 0) {
      option = getResponse();
      toupper(option);
      if (option != 'Y')
        cout << "Application Closed" << endl;
      else
        ResetList(Species);
    }

  } while (option == 'Y');
  return 0;
}

//get data function
Animal getAnimalData(istream &File) {
  Animal myAnimal;

  getline(File, myAnimal.Species_ID, ',');

  getline(File, myAnimal.Park_Name, ',');
  getline(File, myAnimal.Category, ',');
  getline(File, myAnimal.Order, ',');
  getline(File, myAnimal.Family, ',');
  getline(File, myAnimal.Scientific_Name, ',');
  getline(File, myAnimal.Common_Name, ',');

  getline(File, myAnimal.Record_Status, ',');
  getline(File, myAnimal.Occurence, ',');
  
  getline(File, myAnimal.Nativeness, ',');
  getline(File, myAnimal.Abundance, ',');
  getline(File, myAnimal.Seasonality, ',');
  getline(File, myAnimal.Conservation_Status);

  return myAnimal;
}

//reset the data set
void ResetList(istream &File) {
  File.clear();
  File.seekg(0);
}

//automated user response function
char getResponse() {
  // initialize return variable
  char response = '\0';
  // Get Response
  cout << "\nTask completed. Would you like to choose another task?(Y/N) ";
  cin >> response;
  response = toupper(response);
  return response;
}
