#include<iostream>
#include<fstream>//library for fstream objects
#include<string>//library for strings
using namespace std;
//function prototypes
void get_user_input(string&, string&, string&, string&, string&, string&, string&);
void error_message(ofstream&);
void create_webpage(ofstream&, string&, string&, string&, string&, string&, string&, string&);
//main function
int main()
{
    //declare ofstream object for writing data to a file
    ofstream outFile;
    //string variables to store user input
    string userName,
           userDescription,
           colorChoice,
           imageLink,
           personalFactOne,
           personalFactTwo,
           personalFactThree;
    //function call for input
    get_user_input(userName, userDescription, colorChoice, imageLink, personalFactOne, personalFactTwo, personalFactThree);
    //create html file to write data into
    outFile.open("yourWebPage.html");
    //function calls
    error_message(outFile);
    create_webpage(outFile, userName, userDescription, colorChoice, imageLink, personalFactOne, personalFactTwo, personalFactThree);
    //close html file
    outFile.close();
    //let user know the file creation was successful after all
    //functions have run
    cout << "Webpage created! Open yourWebPage.html in your computer files." << endl;
    return 0;
}
//function to get user input to later add to html file
void get_user_input(string& name, string& description, string& color, string& imgLink, string& factOne,
                    string& factTwo, string& factThree)
{
    int colorSel;
    char fontSel;
    cout << "Enter your name: ";
    getline(cin, name);//use getline to allow input with spaces
    cout << "Describe yourself: ";
    getline(cin, description);
    cout << "What are some fun facts about you?" << endl;
    cout << "Fact one: ";
    getline(cin, factOne);
    cout << "Fact two: ";
    getline(cin, factTwo);
    cout << "Fact three: ";
    getline(cin, factThree);
    cout << "Paste an image link: ";
    getline(cin, imgLink);
    cout << "_Color Menu_" << endl;
    cout << "1) Blue" << endl;
    cout << "2) Red" << endl;
    cout << "3) Pink" << endl;
    cout << "4) Purple" << endl;
    cout << "5) Green" << endl;
    cout << "Choose a background color: ";
    cin >> colorSel;
    if (colorSel == 1)
    {
        color = "blue";
    }
    if (colorSel == 2)
    {
        color = "red";
    }
    if (colorSel == 3)
    {
        color = "pink";
    }
    if (colorSel == 4)
    {
        color = "purple";
    }
    if (colorSel == 5)
    {
        color = "green";
    }
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
void create_webpage(ofstream& file, string& name, string& description, string& color, string& imgLink, string& factOne,
                    string& factTwo, string& factThree)
{
    file << "<style>" << endl;
    file << "body {" << endl;
    file << "background-color: " << color << ";" << endl;
    file << "}" << endl;
    file << "img {" << endl;
    file << "max-width: 80%;" << endl;
    file << "height: auto;" << endl;
    file << "display: block;" << endl;
    file << "margin-left: auto;" << endl;
    file << "margin-right: auto;" << endl;
    file << "}" << endl;
    file << "h2 {" << endl;
    file << "text-align: center;" << endl;
    file << "}" << endl;
    file << "</style>" << endl;
    file << "<html>" << endl;
    file << "<head>" << endl;
    file << "</head>" << endl;
    file << "<body>" << endl;
    file << "<center>" << endl;
    file << "<h1>" << name << "</h1>" << endl;//write user input into file
    file << "</center>" << endl;
    file << "<img class='img' src='" << imgLink << "'>" << endl;
    file << "<h2>" << description << "</h2>" << endl;
    file << "<h3>Some Fun Facts About Me</h3>" << endl;
    file << "<ul>" << endl;
    file << "<li>" << factOne << "</li>" << endl;
    file << "<li>" << factTwo << "</li>" << endl;
    file << "<li>" << factThree << "</li>" << endl;
    file << "</ul>" << endl;
    file << "</html>" << endl;
}
