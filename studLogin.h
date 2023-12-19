#include <iostream>
#include <string>
using namespace std;

class User {
    private :
        struct Info { // Struct allows to group different variables together under a single name
                     // Encapsulation Due to Data Binding
            string Uname;
            string Enum;
        };
        vector<Info> Userdata; // It is used to store multiple instances of the Info structure
                              //  Here Info is Structure and all these structures can be stored in the Userdata vector.
                             //   Encapsulation as it encapsulates a collection of Info structures within the class

        Info Udata;         //    Here Udata is Member variable of Info
                           //     Encapsulation due to Member Variable declared in Private
    public :
        void DataIn () {
            cin.ignore();
            cout<<" Enter    Your    Name    : ";
            getline(cin,Udata.Uname);
            cout<<" Enter Your Enrollment No : ";
            getline(cin,Udata.Enum);

            // Remove leading spaces from Uname
            while (Udata.Uname[0] == ' ' || Udata.Uname[0] == '\t') {
                Udata.Uname.erase(0, 1);
            }
            // Remove trailing spaces from Uname
            while (Udata.Uname.back() == ' ' || Udata.Uname.back() == '\t') {
                Udata.Uname.pop_back();
            }

            // Remove leading spaces from Enum
            while (Udata.Enum[0] == ' ' || Udata.Enum[0] == '\t') {
                Udata.Enum.erase(0, 1);
            }
            // Remove trailing spaces from Enum
            while (Udata.Enum.back() == ' ' || Udata.Enum.back() == '\t') {
                Udata.Enum.pop_back();
            }

            //Capitalizing Uname
            for(int i=0;i<Udata.Uname.length();i++){
                if (Udata.Uname[i]>=65 && Udata.Uname[i]<=90)
                    continue;
                else if(Udata.Uname[i]==' ')
                    continue;
                else
                    Udata.Uname[i]=toupper(Udata.Uname[i]);
            }

            //Capitalizing Character in Enum
            for(int i=0;i<Udata.Enum.length();i++){
                if(Udata.Enum[i]>=65 && Udata.Enum[i]<=90)
                    continue;
                else if(Udata.Enum[i]>=48 && Udata.Enum[i]<=57)
                    continue;
                else if(Udata.Enum[i]==' ')
                    continue;
                else
                    Udata.Enum[i]=toupper(Udata.Enum[i]);
            }

            Userdata.push_back(Udata);
        }



        void clearUser() { // Useful in adding new user data without keeping prev
        Userdata.clear();
        }

        void saveuser(const string& Savefile) {
            ofstream file(Savefile, ios::out | ios::app);
            if (file.is_open()) {
                for (const auto& ud : Userdata) {
                    file << ud.Uname << ','<< ud.Enum << endl;
                }
                file.close();
            } else {
                cout << "\nUnable To Save To File " << endl;
            }
        }

        void loaduser(const string& Savefile) {
            ifstream file(Savefile, ios::in);
            if (!file.is_open()) {
                cout<<"\n Checking Credentials, Please Wait ........\n";
                sleep(6);
                cout << "\n\n\t\t\t User Is Not Registered" << endl;
                cout << "\n Press Enter to continue... ";
                return;
            }
            string split;
            while (getline(file, split)) {
                istringstream iss(split);
                Info splitdata;

                getline(iss, splitdata.Uname, ',');
                getline(iss, splitdata.Enum);

                Userdata.push_back(splitdata);
            }
            file.close();
        }

        string getEnum () const{
            return Udata.Enum;
        }

        string getName () const{
            return Udata.Uname;
        }

        string searchEnrollid(const string& searchEID){ //Search Enrollment and return Enrollment
            for (const auto& findEID : Userdata){
                if(findEID.Enum==searchEID){
                    return findEID.Enum;
                }
            }
            return "";
        }

        //Finding & Returning Enrollment Directly From File
        string FindID(const string& searchEID, const string& filename) const {
            ifstream file(filename);
            if (file.is_open()) {
                string line;
                while (getline(file, line)) {
                    istringstream split(line);
                    Info splitdata;

                    getline(split, splitdata.Uname, ',');
                    getline(split, splitdata.Enum);
                    if (splitdata.Enum == searchEID) {
                        file.close();
                        return splitdata.Enum; // Found: Return the enrollment ID
                    }
                }
                file.close();
            } else {
                cout << "Unable to open file " << endl;
            }

            return "";
        }

        //Finding & Returning User Name Directly From File
        string FindName(const string& searchName, const string& filename) const {
            ifstream file(filename);
            if (file.is_open()) {
                string line;
                while (getline(file, line)) {
                    istringstream split(line);
                    Info splitdata;

                    getline(split, splitdata.Uname, ',');
                    getline(split, splitdata.Enum);
                    if (splitdata.Uname == searchName) {
                        file.close();
                        return splitdata.Uname; // Found: Return the enrollment ID
                    }
                }
                file.close();
            } else {
                cout << "Unable to open file " << endl;
            }

            return "";
        }

        //Finding User Name & Returning Its Enrollment Directly From File
        string FindNameID(const string& searchName, const string& filename) const {
            ifstream file(filename);
            if (file.is_open()) {
                string line;
                while (getline(file, line)) {
                    istringstream split(line);
                    Info splitdata;

                    getline(split, splitdata.Uname, ',');
                    getline(split, splitdata.Enum);
                    if (splitdata.Uname == searchName) {
                        file.close();
                        return splitdata.Enum; // Found: Return the enrollment ID
                    }
                }
                file.close();
            } else {
                cout << "Unable to open file " << endl;
            }

            return "";
        }

};
