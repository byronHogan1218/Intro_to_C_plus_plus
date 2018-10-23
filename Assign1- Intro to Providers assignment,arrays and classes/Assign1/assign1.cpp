/********************************************************
CSCI 241 - Assignment 1 - Fall 2017 

Programmer: Kevin Kang
Z-ID: z1837081
Section: 4
TA: Abdul Syed
DATE DUE:   Thursday, 9/14/2017 by 11:59 pm

Purpose: This program reads a .csv file and processes it
into an array of objects, and then outputs the information
for each object with formatting. 
********************************************************/

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

class Provider {
  // Data Members
  private:

    // C Strings
    char pNumber[7]{};
    char specialty[41]{};
    char name[41]{};
    char address1[41]{};
    char address2[31]{};
    char city[21]{};
    char state[3]{};
    char zip[6]{};
    char phoneNum[15]{};

  public:
    //Class Method Initialization
    Provider();
    void set_values (char *, char *, char *, 
                     char *, char *, char *,
                     char *, char *, char *);
    void print() const;
    Provider test();
};

/*********************************************************
Provider

Use: this is the constructor for class Provider but the 
information was all initialized at declaration so this is
very small. Needed for when compiler calls this method

Params: none

Returns: nothing
*********************************************************/
Provider::Provider() {}
Provider Provider::test() {Provider provider(); return provider;}
/*********************************************************
set_values

Use: takes in 9 strings and sets all the data values of a
Provider to those cstrings.

Params: 9 char arrays representing different information
for a Provider: name, address, etc.

Returns: nothing
*********************************************************/
void Provider::set_values(char *newNum, 
           char *newSpec, char *newName, char *newAddress1, 
           char *newAddress2, char *newCity, char *newState, 
           char *newZip, char *newPhoneNum) {
  
  strcpy(pNumber, newNum);
  strcpy(specialty, newSpec);
  strcpy(name, newName);
  strcpy(address1, newAddress1);
  strcpy(address2, newAddress2);
  strcpy(city, newCity);
  strcpy(state, newState);
  strcpy(zip, newZip);
  strcpy(phoneNum, newPhoneNum);
}

/*********************************************************
print

Use: Outputs the data for a Provider in a formatted template
using cout

Params: none

Retruns: nothing 
*********************************************************/
void Provider::print() const {
  cout << "#" << pNumber << endl << name << endl << specialty <<
  endl << address1 << endl << address2 << endl << city << ", " <<
  state << ' ' << zip << endl << phoneNum << endl << endl;
}

int main() {
  //Variables
  int numProviders = 0;         //for counting providers in array, in while loop
  char temp[41],                //temporary storage for read data
       fullName[41];            //for building provider full name with strcat()
  char strHolder [9][41];       //holds all the info for a provider until final dump
  
  Provider providers[40];       //stores all the providers

  //sets up file stream
  ifstream inputFile;
  inputFile.open( "providers.csv" );

  //checks to see if file stream opens correctly
  if (!inputFile.good())
    cout << "Error: There seems to be a problem opening the CSV" << endl;

  //while loop that continuously reads file until it hits the end of file
  while (inputFile.good()) {
    //temporarily gets data from file and copies it to the strHolder
    inputFile.getline(temp, 7, ',');
    strcpy(strHolder[0], temp);

    inputFile.getline(temp, 41, ',');
    strcpy(strHolder[1], temp);

    inputFile.getline(temp, 41, ',');
    strcpy(fullName, strcat(temp, ", "));

    //starts building the full name of provider
    inputFile.getline(temp, 41, ',');
    strcat(fullName, temp);

    inputFile.getline(temp, 41, ',');
    
    //checks for middle name and adds it if there is
    if (temp[0] != 0) {
      strcat(strcat(fullName, " "), temp);
    }
    strcat(fullName, ", ");

    inputFile.getline(temp, 41, ',');
    strcat(fullName, temp);

    strcpy(strHolder[2], fullName);

    inputFile.getline(temp, 41, ',');
    strcpy(strHolder[3], temp);

    inputFile.getline(temp, 31, ',');
    strcpy(strHolder[4], temp);

    inputFile.getline(temp, 21, ',');
    strcpy(strHolder[5], temp);

    inputFile.getline(temp, 3, ',');
    strcpy(strHolder[6], temp);

    inputFile.getline(temp, 6, ',');
    strcpy(strHolder[7], temp);

    inputFile.getline(temp, 15);
    strcpy(strHolder[8], temp);
    
    //dumps all of a providers data into the Object using set_values
    providers[numProviders].set_values(
      strHolder[0], strHolder[1], strHolder[2],
      strHolder[3], strHolder[4], strHolder[5],
      strHolder[6], strHolder[7], strHolder[8]);

    numProviders++;
  }

  inputFile.close();

  //iterates through providers array calling each of their print()s
  for (int i = 0; i < numProviders - 1; i++) { 
    providers[i].print();
  }

  return 0;
}
