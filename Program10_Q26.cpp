#include<iostream>
#include<fstream>//library for fstream objects
#include<string>//library for strings
using namespace std;
//function prototypes
void get_user_input(string&, string&);
void error_message(ofstream&);
void create_webpage(ofstream&, string&, string&);
//main function
int main()
{
    //declare ofstream object for writing data to a file
    ofstream outFile;
    //string variables to store user input
    string userName,
           userDescription;
    //function call for input
    get_user_input(userName, userDescription);
    //create html file to write data into
    outFile.open("yourWebPage.html");
    //function calls
    error_message(outFile);
    create_webpage(outFile, userName, userDescription);
    //close html file
    outFile.close();
    //let user know the file creation was successful after all
    //functions have run
    cout << "Webpage created!" << endl;
    return 0;
}
//function to get user input to later add to html file
void get_user_input(string& name, string& description)
{
    cout << "Enter your name: ";
    getline(cin, name);//use getline to allow input with spaces
    cout << "Describe yourself: ";
    getline(cin, description);
}

void error_message(ofstream& file)
{
    if (file.fail())//determines if theres an error when creating the file
    {
        cout << "Error creating file." << endl;
        exit(1);//exits program if file cant be created
    }
}
//function to write data into the file that's been created
void create_webpage(ofstream& file, string& name, string& description)
{
    file << "<html>" << endl;
    file << "<head>" << endl;
    file << "</head>" << endl;
    file << "<body>" << endl;
    file << "<center>" << endl;
    file << "<h1>" << name << "</h1>" << endl;//write user input into file
    file << "</center>" << endl;
    file << "<hr />" << endl;
    file << description << endl;//write user input into file
    file << "<hr  />" << endl;
    file << "</body>" << endl;
    file << "</html>" << endl;
}