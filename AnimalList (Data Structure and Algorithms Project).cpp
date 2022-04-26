#include<iostream>
#include <string>
#include <fstream>
#include<iomanip>
#include<ctime>
using namespace std;

//Define Animal struct
//Each struct will be 1 element in the dynamic array
//Each variable will how the information in a column
struct Animal
{
  string Species_ID;
  string Park_Name;
  string Category;
  string Order;
  string Family;
  string Scientific_Name;
  string Common_Name;
  string Record_Status;
  string Occurence;
  string Nativeness;
  string Abundance;
  string Seasonality;
  string Conservation_Status;
};

//Create dynamic array AnimalList 
class AnimalList
{
  private:
    Animal *array;
    int maxSize;
    int endOfArray = -1;
        
  public:
    AnimalList(int size)
    {
      array = new Animal[size];
      maxSize = size;
      endOfArray = -1;
    }
      
    bool isEmpty()
    {
      if(endOfArray == -1)
      {
        return true;
      }
      return false;
    }
      
      
    void resize(int s)
    {
      Animal *tempArray = array;
      array = new Animal[s];
      for(int i = 0; i < min(s, endOfArray + 1); i++)
      {
        array[i] = tempArray[i];
      }
      maxSize = s;
    }
    
    void insert(Animal data)
    {
      if(endOfArray == maxSize - 1)
      {
        resize(2*maxSize);
      }
      array[++endOfArray] = data;
    }
    
    void InsertAtIndex(int insertIndex, Animal data)
    {
      if(insertIndex > endOfArray + 1)
      {
        insertIndex = endOfArray + 1;
      }
      if(insertIndex == maxSize - 1)
      {
        resize(2*maxSize);
      }

      for(int index = endOfArray; index >= insertIndex; index--)
      {
        array[index + 1] = array[index];
      }
      array[insertIndex] = data;
      endOfArray++;
    }
    
    Animal read(int index)
    {
      return array[index];
    }
    
    void modifyElement(int index, Animal data)
    {
      array[index] = data;
    }
    
    void deleteElement(int deleteIndex)
    {
      for(int index = deleteIndex; index < endOfArray; index++)
      {
        array[index] = array[index + 1];
      }
        
      endOfArray--;
    }
    
    int countList()
    {
      int count = 0;
      for(int index = 0; index < endOfArray; index++)
      {
        count++;
      }
        
      return count;
    }
    
    /*void print()
    {
      for(int index = 0; index <= endOfArray; index++)
      {
        cout << array[index] << " ";
      }
        
      cout << endl;
    }*/

    void Display(){
      cout<<"\t Species ID "
      <<"\t\t\t\t Park Name "<<setw(16)
      <<"Category"<<setw(16)
      <<"Order"<<setw(16)
      <<" \t Family "<<setw(16)
      <<" \t\t Scientific Name "<<setw(16)
      <<" \t\t\t\t\t Common Name "<<setw(16)
      <<" \t\t\t\t\t Record Status "<<setw(16)
      <<" \t\t Occurence "<<setw(16)
      <<" \t\t Nativeness "<<setw(16)
      <<" \t\t Abundance "<<setw(16)
      <<" \t\t Seasonality "<<setw(16)
      <<" \t\t Conservation Status "<< endl; 
    cout<<endl;
    for(int i = 0; i <= endOfArray; i++)
      cout<<setw(3)<<i+1<<". "
      <<" "<<array[i].Species_ID
      <<" \t\t\t\t\t"<<array[i].Park_Name
      <<" \t\t\t\t\t"<<array[i].Category
      <<" \t"<<array[i].Order
      <<" \t  "<<array[i].Family
      <<"\t\t\t\t\t"<<array[i].Scientific_Name
      <<" \t\t\t\t"<<array[i].Common_Name
      <<" \t\t"<<array[i].Record_Status
      <<" \t\t"<<array[i].Occurence
      <<" \t\t"<<array[i].Nativeness
      <<" \t\t"<<array[i].Abundance
      <<" \t\t"<<array[i].Seasonality
      <<" \t\t"<<array[i].Conservation_Status<<endl;
    }
    
    void SortSwap()
    {
      int i, j = 0;
      int length = endOfArray;
      Animal temp;
      bool isSorted;
      do
      {
        isSorted = false;
        for(i = 0; i < length; i++)
        {
          j = i + 1;
          /*if(array[i].Common_Name.length() >  array[j].Common_Name.length())
          {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            isSorted = true;
          }*/


          /*if(array[i].Abundance == "Abundant" && array[j].Abundance != "Abundant")
          {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            isSorted = true;
          }*/


          if(array[i].Occurence == "Present" && array[j].Occurence != "Present")
          {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            isSorted = true;
          }
          
        }
      }while(isSorted);
    }
    
    void SearchCS(string name)
    {
      for(int i = 0; i < endOfArray; i++)
      {
        if(name == array[i].Species_ID)
        {
          if(array[i].Conservation_Status == ","){
            cout << "Conservation Status: N/A" << endl;
          }
          else
            cout << "Conservation Status: " << array[i].Conservation_Status << endl;
        }
      }
    }

//Devin Johnson
    void isNative(string name)
    {
      for(int i = 0; i < endOfArray; i++){
        if(name == array[i].Species_ID)
        {
          cout << "Nativeness: " << array[i].Nativeness << endl; 
        }
      }
    }

//Devin Johnson
    void OrderSearch(string search)
    {
      for(int i = 0; i < endOfArray; i++)
      {
        if(search == array[i].Order)
        {
          cout << array[i].Common_Name << "\t";
        }
      }
    }

//Devin Johnson
    void printCommon_Name()
    {
      for(int i = 0; i < endOfArray; i++)
      {
        cout << array[i].Common_Name << "\t";
      }
    }

//Devin Johnson
    void printOrder()
    {
      for(int i = 0; i < endOfArray; i++)
      {
        cout << array[i].Order << "\t";
      }
    }

//Devin Johnson
    void IDcname(){
      for(int i = 0; i < endOfArray; i++){
        cout << array[i].Species_ID << ": " << array[i].Common_Name << "\t";
      }
    }

//Devin Johnson
    void IDsname(){
      for(int i = 0; i < endOfArray; i++){
        cout << array[i].Species_ID << ": " << array[i].Scientific_Name << "\t";
      }
    }

//Devin Johnson
    void SntoCn(string science){
      for(int i = 0; i < endOfArray; i++){
        if(science == array[i].Species_ID){
          cout << "Common Name: " << array[i].Common_Name << endl;
        }
      }
    }

//Tychicus Johnson
    void AbundantSearch(string Abundance)
    {
       for(int i = 0; i < endOfArray; i++)
      {
        if(Abundance == array[i].Abundance)
        {
          cout << array[i].Common_Name << "\t";
        }
      }
    }

//Tychicus Johnson
    void PrintAbundant()
    {
      for(int i = 0; i < endOfArray; i++)
      {
        cout << array[i].Abundance << "\t";
      }
    }

    void printScientific(){
      for(int i = 0; i < endOfArray; i++){
        cout << array[i].Scientific_Name << "\t";
      }
    }

};