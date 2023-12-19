#include <iostream>
#include <string>
#include <fstream>     //File Management || Helps in File Management To Open Close Append IN The TXT File
#include <sstream>     //Call istringstream
#include <vector>      //Store Multiple Values of Same Type
#include <unistd.h>    //Used For Sleep & System function
#include <limits>      //Used to access the maximum representable value for streamsize, ensuring thorough cleanup of the input buffer
#include "studLogin.h"
#include "facultyInfo.h"
#include "library.h"

using namespace std;

int main()
{
    cout<<"\n";
    while (true) {
    start:
    system("CLS");
    cout<<"\n Welcome To JNCT Library Management System \n\n"<<endl;

    cout<<"             1.  STUDENT SIGNUP "<<endl;
    cout<<"             2.  STUDENT LOGIN  "<<endl;
    cout<<"             3.  FACULTY lOGIN  "<<endl;
    cout<<"             4.  EXIT           "<<endl;

    int opt;
    cout<<"\n Enter Your Choice (1-4) : ";
    cin >>opt;
    cout<<"\n";

    switch (opt) {
       case 1:{
            cout << " Registering User To The DataBase ::: \n" << endl;
            User sinfo;
            sinfo.clearUser();
            sinfo.DataIn();

            ifstream file("StudXData.txt");

            if (!file.is_open()) {
                sinfo.saveuser("StudXData.txt");
                cout<<"\n\n\t\t\t User Registered Successfully !! \n"<<endl;
                cout << "\n Press Enter to continue... ";
                cin.get();

            }else if (file.peek() == ifstream::traits_type::eof()){
                sinfo.saveuser("StudXData.txt");
                cout<<"\n\n\t\t\t User Registered Successfully !! \n"<<endl;
                cout << "\n Press Enter to continue... ";
                cin.get();

            }else {
                string filename = "StudXData.txt";
                string Enroll   = sinfo.getEnum();
                string finding  = sinfo.FindID(Enroll, filename);
                if (Enroll == finding ) {
                    cout<<"\n\n\t\t\t User is Already Registered !! Try Again !! \n"<<endl;
                    cout << "\n Press Enter to continue... ";
                    cin.get();
                }
                else {
                    sinfo.saveuser("StudXData.txt");
                    cout<<"\n\n\t\t\t User Registered Successfully !! \n"<<endl;
                    cout << "\n Press Enter to continue... ";
                    cin.get();
                }
            }
        }
        break;

        case 2:{
            cout << " Logging In The Registered User ::: \n" << endl;

            User sinfo;
            sinfo.DataIn();
            sinfo.loaduser("StudXData.txt");

            ifstream file("studXData.txt");
            if (!file.is_open()) {
                    cin.ignore();
                    break;
            }

            string filename = "StudXData.txt";
            string Enroll   = sinfo.getEnum();
            string finding  = sinfo.FindID(Enroll, filename);
            string UsName   = sinfo.getName();
            string UrFnding = sinfo.FindName(UsName, filename);
            string ReturnID = sinfo.FindNameID(UsName, filename);


            if (Enroll == finding && UsName == UrFnding && Enroll == ReturnID) {
                cout<<"\n Checking Credentials, Please Wait ........\n";
                sleep(6);
                while (true) {
                    system("CLS");
                    cout << "\n Welcome User : " << UsName << endl;
                    cout << "\n\n";
                    cout<<" 1.Show All The Books           "<< endl;
                    cout<<" 2.Searching Book by Title      "<< endl;
                    cout<<" 3.Searching Book by Author     "<< endl;
                    cout<<" 4.Searching Book by Department "<< endl;
                    cout<<" 5.Logout                       "<< endl;
                    cout<<" 6.Exit                         "<< endl;
                    cout<<"\n";
                    cout<<" Enter Your Choice (1-6) : ";
                    cin >> opt;
                    cout<< "\n";
                    Library lib;
                    switch (opt){
                        case 1:{
                            cout << " List Of all Books Data in Library ::: \n" << endl;
                            lib.loadFileStud("LibXData.txt");
                            cin.ignore();
                            cout << "\n\n Press Enter to continue... ";
                            cin.get();
                        }
                        break;

                        case 2: {
                            cout << " Searching BookData By Title in Library ::: \n" << endl;
                            ifstream file("LibXData.txt");
                            if (!file.is_open()) {
                                    cin.ignore();
                                    cout <<"\n\t\t\t File Is Empty !!! "<< endl;
                                    cout << "\n\n Press Enter to continue... ";
                                    cin.get();
                                    break;
                            }
                            string searchTitle;
                            lib.load("LibXData.txt");
                            cout << " Enter the Title to Search : ";
                            cin.ignore(); // To consume the newline character left by previous cin
                            getline(cin, searchTitle);

                            while (searchTitle[0] == ' ' || searchTitle[0] == '\t') { // Remove leading spaces
                                searchTitle.erase(0,1);
                            }
                            while (searchTitle.back() == ' ' || searchTitle.back() == '\t') { // Remove trailing spaces
                                searchTitle.pop_back();
                            }

                            for(int i=0;i<searchTitle.length();i++){ // Capitalizing searchTitle
                                if (searchTitle[i]>=65 && searchTitle[i]<=90)
                                    continue;
                                else if(searchTitle[i]==' ')
                                    continue;
                                else
                                    searchTitle[i]=toupper(searchTitle[i]);
                            }

                            lib.searching(searchTitle);
                            cout << "\n\n Press Enter to continue... ";
                            cin.get();
                        }
                        break;
                        case 3: {
                            cout << " Searching BookData By Author in Library ::: \n" << endl;
                            ifstream file("LibXData.txt");
                            if (!file.is_open()) {
                                    cin.ignore();
                                    cout <<"\n\t\t\t File Is Empty !!! "<< endl;
                                    cout << "\n\n Press Enter to continue... ";
                                    cin.get();
                                    break;
                            }
                            string searchAuthor;
                            lib.load("LibXData.txt");
                            cout << " Enter the Author Name to Search : ";
                            cin.ignore(); // To consume the newline character left by previous cin
                            getline(cin, searchAuthor);

                            while (searchAuthor[0] == ' ' || searchAuthor[0] == '\t') { // Remove leading spaces
                                searchAuthor.erase(0, 1);
                            }
                            while (searchAuthor.back() == ' ' || searchAuthor.back() == '\t') { // Remove trailing spaces
                                searchAuthor.pop_back();
                            }

                            for(int i=0;i<searchAuthor.length();i++){ // Capitalizing searchAuthor
                                if (searchAuthor[i]>=65 && searchAuthor[i]<=90)
                                    continue;
                                else if(searchAuthor[i]==' ')
                                    continue;
                                else
                                    searchAuthor[i]=toupper(searchAuthor[i]);
                            }

                            lib.FindAuthor(searchAuthor);
                            cout << "\n\n Press Enter to continue... ";
                            cin.get();
                        }
                        break;
                        case 4: {
                            cout << " Searching BookData By Department in Library ::: \n" << endl;
                            ifstream file("LibXData.txt");
                            if (!file.is_open()) {
                                    cin.ignore();
                                    cout <<"\n\t\t\t File Is Empty !!! "<< endl;
                                    cout << "\n\n Press Enter to continue... ";
                                    cin.get();
                                    break;
                            }
                            string dept;
                            lib.load("LibXData.txt");
                            cout<<" Enter The Department Code(CSE/MED/MBA) : ";
                            cin.ignore(); // To consume the newline character left by previous cin
                            getline(cin, dept);

                            while (dept[0] == ' ' || dept[0] == '\t') { // Remove leading spaces
                                dept.erase(0, 1);
                            }
                            while (dept.back() == ' ' || dept.back() == '\t') { // Remove trailing spaces
                                dept.pop_back();
                            }

                            for(int i=0;i<dept.length();i++){ // Capitalizing dept
                                if (dept[i]>=65 && dept[i]<=90)
                                    continue;
                                else if(dept[i]==' ')
                                    continue;
                                else
                                    dept[i]=toupper(dept[i]);
                            }

                            lib.SearchDeprt(dept);
                            cout << "\n\n Press Enter to continue... ";
                            cin.get();
                        }
                        break;
                        case 5: {
                            cout<<"\n\t\t\t LogOut Successfully !!! "<<endl;
                            cin.ignore();
                            cout << "\n\n Press Enter to continue... ";
                            cin.get();
                            goto start;

                        }
                        case 6:{
                            cout<<"\n\t\t---X---EXIT---X---\n"<<endl;
                            exit(0);
                        }
                        default :{
                            cout << "\n\t\t Invalid Choice !!\tTry Again !! ";
                            cout << "\n" << endl;

                            if (cin.fail() == true) { // It is true when there's an issue with the expected input type
                                cin.clear();         // Clear the error flag & allowing it to recover from the failed state
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard invalid input

                                //1. cin.ignore : used to skip or discard characters from the input stream
                                //2. numeric_limits<streamsize>::max() : This part specifies the maximum number of characters to ignore and here it is max
                                //3. '\n' :  This part indicates the delimiter character until which the characters should be ignored
                                //           In this case, it's the newline character (`'\n'`)

                                cout << "\n Press Enter to continue... ";
                                cin.get();

                            } else {
                                cin.ignore();
                                cout << "\n Press Enter to continue... ";
                                cin.get();
                            }
                            break;

                        }

                    }
                }

            } else {
                cout<<"\n Checking Credentials, Please Wait ........\n";
                sleep(6);
                cout << "\n\n\t\t Invalid Either ID or Enrollment Number \n" << endl;
                cout << "\n Press Enter to continue... ";
                cin.get();
                system("CLS");
            }

        }
        break;

        case 3:{
            cin.ignore();
            Librarian fuser;
            fuser.FacultyInput();

            bool Found =false;
            for (const auto& entry : FacultyData ){
                if(entry.second.first == fuser.getID() && entry.second.second==fuser.getpass()){
                Found=true;
                cout<<"\n Checking Credentials, Please Wait ........\n";
                sleep(6);
                while (true) {
                    system("CLS");
                    cout<<"\n\n Welcome Library Manager : "<<entry.first<<endl;
                    cout << "\n\n";
                    cout<<"  1.Add New Book To Library   "<<endl;
                    cout<<"  2.Show All The Books        "<<endl;
                    cout<<"  3.Search Book by Title      "<<endl;
                    cout<<"  4.Search Book by Author     "<<endl;
                    cout<<"  5.Search Book By Department "<<endl;
                    cout<<"  6.Issue Book                "<<endl;
                    cout<<"  7.Return Book               "<<endl;
                    cout<<"  8.Delete A Book             "<<endl;
                    cout<<"  9.Logout                    "<<endl;
                    cout<<" 10.Exit                      "<<endl;
                    cout<<"\n Enter Your Choice (1-10) : ";
                    cin>>opt;
                    cout<<"\n";
                    Library lib;
                    switch (opt){
                        case 1: {
                            lib.clearBooks();
                            re_enter:
                            cout << " Adding New Book Data to  Library  ::: \n" << endl;
                            lib.AddBook();

                            ifstream file("LibXData.txt");

                            if (!file.is_open()) {
                                lib.saveToFile("LibXData.txt");
                                cout << "\n\n Press Enter to continue... ";
                                cin.get();
                            }
                            else if (file.peek() == ifstream::traits_type::eof()){
                                lib.saveToFile("LibXData.txt");
                                cout << "\n\n Press Enter to continue... ";
                                cin.get();
                            }
                            else {
                                string filename = "LibXData.txt";
                                string SrchISBN = lib.getISBN();
                                string gfndISBN = lib.FindISBN(SrchISBN, filename);

                                if (SrchISBN == gfndISBN){
                                    cout<<"\n\n\t\t\t ISBN Number is Already Present !! Try Again !! \n"<<endl;
                                    cout << "\n Press Enter to continue... ";
                                    cin.get();

                                }
                                else{
                                    lib.saveToFile("LibXData.txt");
                                    cout << "\n\n Press Enter to continue... ";
                                    cin.get();
                                }
                            }
                        }
                        break;
                        case 2: {
                            cout << " List Of all Books Data in Library ::: \n" << endl;
                            lib.loadFromFile("LibXData.txt");
                            cin.ignore();
                            cout << "\n\n Press Enter to continue... ";
                            cin.get();
                        }
                        break;
                        case 3: {
                            cout << " Searching BookData By Title in Library ::: \n" << endl;
                            ifstream file("LibXData.txt");
                            if (!file.is_open()) {
                                    cin.ignore();
                                    cout <<"\n\t\t\t File Is Empty !!! "<< endl;
                                    cout << "\n\n Press Enter to continue... ";
                                    cin.get();
                                    break;
                            }
                            string searchTitle;
                            lib.load("LibXData.txt");
                            cout << " Enter the Title to Search : ";
                            cin.ignore(); // To consume the newline character left by previous cin
                            getline(cin, searchTitle);

                            while (searchTitle[0] == ' ' || searchTitle[0] == '\t') { // Remove leading spaces
                                searchTitle.erase(0, 1);
                            }
                            while (searchTitle.back() == ' ' || searchTitle.back() == '\t') { // Remove trailing spaces
                                searchTitle.pop_back();
                            }

                            for(int i=0;i<searchTitle.length();i++){ // Capitalizing searchTitle
                                if (searchTitle[i]>=65 && searchTitle[i]<=90)
                                    continue;
                                else if(searchTitle[i]==' ')
                                    continue;
                                else
                                    searchTitle[i]=toupper(searchTitle[i]);
                            }

                            lib.sTitle(searchTitle);
                            cout << "\n\n Press Enter to continue... ";
                            cin.get();
                        }
                        break;
                        case 4: {
                            cout << " Searching BookData By Author in Library ::: \n" << endl;
                            ifstream file("LibXData.txt");
                            if (!file.is_open()) {
                                    cin.ignore();
                                    cout <<"\n\t\t\t File Is Empty !!! "<< endl;
                                    cout << "\n\n Press Enter to continue... ";
                                    cin.get();
                                    break;
                            }
                            string searchAuthor;

                            lib.load("LibXData.txt");

                            cout << " Enter the Author Name to Search : ";
                            cin.ignore(); // To consume the newline character left by previous CIN
                            getline(cin, searchAuthor);

                            while (searchAuthor[0] == ' ' || searchAuthor[0] == '\t') { // Remove leading spaces
                                searchAuthor.erase(0, 1);
                            }
                            while (searchAuthor.back() == ' ' || searchAuthor.back() == '\t') { // Remove trailing spaces
                                searchAuthor.pop_back();
                            }

                            for (int i=0; i<searchAuthor.length(); i++){ // Capitalizing searchAuthor
                                if (searchAuthor[i]>=65 && searchAuthor[i]<=90)
                                    continue;
                                else if(searchAuthor[i]==' ')
                                    continue;
                                else
                                    searchAuthor[i]=toupper(searchAuthor[i]);
                            }

                            lib.sAuthor(searchAuthor);
                            cout << "\n\n Press Enter to continue... ";
                            cin.get();
                        }
                        break;
                        case 5: {
                            cout << " Searching BookData By Department In Library ::: \n" << endl;
                            ifstream file("LibXData.txt");
                            if (!file.is_open()) {
                                    cin.ignore();
                                    cout <<"\n\t\t\t File Is Empty !!! "<< endl;
                                    cout << "\n\n Press Enter to continue... ";
                                    cin.get();
                                    break;
                            }
                            string deprt;

                            lib.load("LibXData.txt");

                            cout<<" Enter The Department Code(CSE/MED/MBA) : ";
                            cin.ignore(); // To consume the newline character left by previous cin
                            getline(cin, deprt);

                            while (deprt[0] == ' ' || deprt[0] == '\t') { // Remove leading spaces
                                deprt.erase(0, 1);
                            }
                            while (deprt.back() == ' ' || deprt.back() == '\t') { // Remove trailing spaces
                                deprt.pop_back();
                            }

                            for(int i=0; i<deprt.length(); i++){ // Capitalizing deprt
                                if (deprt[i]>=65 && deprt[i]<=90)
                                    continue;
                                else if(deprt[i]==' ')
                                    continue;
                                else
                                    deprt[i]=toupper(deprt[i]);
                            }

                            lib.FindDepartment(deprt);
                            cout << "\n\n Press Enter to continue... ";
                            cin.get();
                        }
                        break;
                        case 6: {
                            cout<<" Issue Book To Student By Faculty From Library ::: \n";
                            ifstream file("LibXData.txt");
                            if (!file.is_open()) {
                                    cin.ignore();
                                    cout <<"\n\t\t\t File Is Empty !!! "<< endl;
                                    cout << "\n\n Press Enter to continue... ";
                                    cin.get();
                                    break;
                            }
                            string searchISBN;

                            lib.load("LibXData.txt");

                            cout<<"\n\n Enter The ISBN Number of Book : ";
                            cin.ignore();
                            getline(cin,searchISBN);

                            while (searchISBN[0] == ' ' || searchISBN[0] == '\t') { // Remove leading spaces
                                searchISBN.erase(0, 1);
                            }
                            while (searchISBN.back() == ' ' || searchISBN.back() == '\t') { // Remove trailing spaces
                                searchISBN.pop_back();
                            }

                            lib.issuebook(searchISBN);
                            cout << "\n\n Press Enter to continue... ";
                            cin.get();
                        }
                        break;
                        case 7: {
                            cout<<" Returning Book To Library By Student ::: \n";
                            ifstream file("LibXData.txt");
                            if (!file.is_open()) {
                                    cin.ignore();
                                    cout <<"\n\t\t\t File Is Empty !!! "<< endl;
                                    cout << "\n\n Press Enter to continue... ";
                                    cin.get();
                                    break;
                            }
                            string searchISBN;

                            lib.load("LibXData.txt");

                            cout<<"\n\n Enter The ISBN Number of Book : ";
                            cin.ignore();
                            getline(cin,searchISBN);

                            while (searchISBN[0] == ' ' || searchISBN[0] == '\t') { // Remove leading spaces
                                searchISBN.erase(0, 1);
                            }
                            while (searchISBN.back() == ' ' || searchISBN.back() == '\t') { // Remove trailing spaces
                                searchISBN.pop_back();
                            }

                            lib.returnbook(searchISBN);
                            cin.ignore();
                            cout << "\n\n Press Enter to continue... ";
                            cin.get();
                        }
                        break;
                        case 8: {
                            cout<<" Delete A Book & Its Data From Library ::: \n";
                            ifstream file("LibXData.txt");
                            if (!file.is_open()) {
                                    cin.ignore();
                                    cout <<"\n\t\t\t File Is Empty !!! "<< endl;
                                    cout << "\n\n Press Enter to continue... ";
                                    cin.get();
                                    break;
                            }
                            string searchISBN;

                            lib.load("LibXData.txt");

                            cout<<"\n\n Enter The ISBN Number of Book : ";
                            cin.ignore();
                            getline(cin,searchISBN);

                            while (searchISBN[0] == ' ' || searchISBN[0] == '\t') { // Remove leading spaces
                                searchISBN.erase(0, 1);
                            }
                            while (searchISBN.back() == ' ' || searchISBN.back() == '\t') { // Remove trailing spaces
                                searchISBN.pop_back();
                            }

                            lib.deletebook(searchISBN);
                            cin.ignore();
                            cout << "\n\n Press Enter to continue... ";
                            cin.get();
                        }
                        break;
                        case 9: {
                            cout<<"\n\t\t\t LogOut Successfully !!!\n"<<endl;
                            cin.ignore();
                            cout << "\n Press Enter to continue... ";
                            cin.get();
                            goto start;
                        }
                        break;
                        case 10: {
                            cout<<"\n\t\t---X---EXIT---X---\n"<<endl;
                            exit(0);
                        }
                        default : {
                            cout << "\n\t\t Invalid Choice !!\tTry Again !! ";
                            cout << "\n" << endl;

                            if (cin.fail() == true) { // It is true when there's an issue with the expected input type
                                cin.clear();         // Clear the error flag & allowing it to recover from the failed state
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard invalid input
                                //1. cin.ignore : used to skip or discard characters from the input stream
                                //2. numeric_limits<streamsize>::max() : This part specifies the maximum number of characters to ignore and here it is max
                                //3. '\n' :  This part indicates the delimiter character until which the characters should be ignored
                                //           In this case, it's the newline character (`'\n'`)
                                cout << "\n Press Enter to continue... ";
                                cin.get();

                            } else {
                                cin.ignore();
                                cout << "\n Press Enter to continue... ";
                                cin.get();
                            }
                            break;
                        }
                    }
                }
            }
        }
        if (Found==false){
            cout<<"\n Checking Credentials, Please Wait ........\n"<<endl;
            sleep(6);
            cout<<"\n\t\t Invalid UserID or Password !!!"<<endl;
            cout << "\n\n Press Enter to continue... ";
            cin.get();
            system("CLS");
            }
        }
        break;

        case 4:{
            cout<<"\n\t\t---X---EXIT---X---\n"<<endl;
            exit(0);
        }
        break;

        default : {
            cout << "\n\t\t Invalid Choice !!\tTry Again !! \n" << endl;

            if (cin.fail() == true) { // It is true when there's an issue with the expected input type
                cin.clear();         // Clear the error flag & allowing it to recover from the failed state
                cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard invalid input
                //1. cin.ignore : used to skip or discard characters from the input stream
                //2. numeric_limits<streamsize>::max() : This part specifies the maximum number of characters to ignore and here it is max
                //3. '\n' :  This part indicates the delimiter character until which the characters should be ignored
                //           In this case, it's the newline character (`'\n'`)
                cout << "\n Press Enter to continue... ";
                cin.get();

            } else {
                cin.ignore();
                cout << "\n Press Enter to continue... ";
                cin.get();
            }
            break;

        }
     }
  }

    return 0;
}
