//Program:    Assignment 1
//Class:      CSCI 241
//Teacher:    Amy Byrnes
//Programmer: Byron Hogan
//ZID:        Z1825194


#include <iostream>
#include<fstream>
#include<string>
using namespace std;
//the class is declared here
class provider
{
	private:
		string providerNum;
		string specialty;
		string last;
		string first;
		string middle;
		string title;
		string addressP1;
		string addressP2;
		string city;
		string state;
		string zip;
		string phoneNum;
	public:
		provider();
		void readFile(ifstream&);
		void printFile();
};
//The constructor initializes all the string to error
// in case something is used incorrectly
provider::provider(){
		providerNum="error";
		specialty="error";
		last="error";
		first="error";
		middle="error";
		title="error";
		addressP1="error";
		addressP2="error";
		city=="error";
		state="error";
		zip="error";
		phoneNum="error";
}
//This method is to read data from a file
void provider::readFile(ifstream& fin)
{
  getline(fin,providerNum,',');//priming read from file to ensure there is something in it
//loops through to get data in the strings
       if(fin){
 	    getline(fin, specialty,',');
            getline(fin, last,',');
            getline(fin, first,',');
            getline(fin, middle,',');
            getline(fin, title,',');
            getline(fin, addressP1,',');
            getline(fin, addressP2,',');
	    getline(fin, city,',');
            getline(fin, state,',');
            getline(fin, zip,',');
            getline(fin, phoneNum,'\n');
	}
}


//organizes and prints the data to the screen
void provider::printFile(){
cout << "#" << providerNum<< endl;
cout << last << ","<< first;
//Decides  whether to print the middle name or not
if (middle != " "){
	cout << ", " << middle<<", "<< title<< endl;
}
else{
	cout << title<< endl;
}
cout << specialty << endl;
cout << addressP1<< endl;
cout << addressP2<< endl;
cout << city << ", "<< state<< zip<< endl;
cout << phoneNum << endl << endl;

}

int main() {
	ifstream fin;//file input stream declaration
	fin.open("providers.csv");
	int i=0;
	provider provider[35];//creates an array of objects from the provider class
	for (i=0; i<35;++i){
		provider[i].readFile(fin);//calls the function to read the file
	}
        for (i=0; i<35;++i){
        	provider[i].printFile();//calls the function to print the file
        }
	fin.close();
	return 0;
}
