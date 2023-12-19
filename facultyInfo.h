#include <iostream>
#include <string>
#include <unordered_map> //is a container in C++ that stores Key-Value pairs in an unordered manner
using namespace std;

class Librarian {
    private:
        string FID;
        string pass;

    public:

        void FacultyInput(){
            cout<<" Enter Your Faculty ID : ";
            getline(cin,FID);

            while (FID[0] == ' ' || FID[0] == '\t') { // Remove leading spaces
                FID.erase(0, 1);
            }
            while (FID.back() == ' ' || FID.back() == '\t') { // Remove trailing spaces
                FID.pop_back();
            }

            cout<<" Enter Your  Password  : ";
            getline(cin,pass);

            while (pass[0] == ' ' || pass[0] == '\t' ) { // Remove leading spaces
                pass.erase(0, 1);
            }
            while (pass.back() == ' ' || pass.back() == '\t' ) { // Remove trailing spaces
                pass.pop_back();
            }

        }

        string getID() const{
        return FID;
        }
        string getpass() const{
        return pass;
        }
};

unordered_map <string, pair<string, string>> FacultyData = {
    {"VIVEK DUBEY", {"01VD31", "VIVEK001"}},
    {"VIKASH SHARMA", {"01VS31", "VIKASH001"}},
    {"PANKAJ PANDEY", {"01PP31", "PANKAJ001"}},
    {"B.M. SHARMA",{"01BM31","BM001"}}
};

