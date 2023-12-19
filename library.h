#include <iostream>
#include <iomanip> // for setw
using namespace std;

// Library
class Library {
    private:
        struct Book {
            string Title;
            string Author;
            string checkout = "Yes";
            string ISBN;
            string SID = "None";
            string Department;
        };

        vector<Book> books;
        Book bookdata;

    public:
        // Adding Book Data To The Library
        void AddBook() { // For Faculty
            cin.ignore();
            cout << " Enter  Title of Book   : ";
            getline(cin, bookdata.Title);
            cout << " Enter  Author of Book  : ";
            getline(cin, bookdata.Author);
            cout << " Enter  ISBN  of  Book  : ";
            getline(cin, bookdata.ISBN);
            cout << " Enter Department (CSE/MED/MBA) : ";
            getline(cin,bookdata.Department);


            //Capitalizing Title
            for(int i=0;i<bookdata.Title.length();i++){
                if (bookdata.Title[i]>=65 && bookdata.Title[i]<=90)
                    continue;
                else if(bookdata.Title[i]==' ')
                    continue;
                else
                    bookdata.Title[i]=toupper(bookdata.Title[i]);
            }

            //Capitalizing Author
            for(int i=0;i<bookdata.Author.length();i++){
                if (bookdata.Author[i]>=65 && bookdata.Author[i]<=90)
                    continue;
                else if(bookdata.Author[i]==' ')
                    continue;
                else
                    bookdata.Author[i]=toupper(bookdata.Author[i]);
            }

            //Capitalizing Department
            for(int i=0;i<bookdata.Department.length();i++){
                if (bookdata.Department[i]>=65 && bookdata.Department[i]<=90)
                    continue;
                else if(bookdata.Department[i]==' ')
                    continue;
                else
                    bookdata.Department[i]=toupper(bookdata.Department[i]);
            }


            books.push_back(bookdata);
        }

        //Used For Adding New Book Without Keeping Previous One
        void clearBooks() { //For Faculty
            books.clear();
        }

        // Loading Files From The TXT File & To Display In Output
        void loadFileStud(const string& filename) {  //For Student Only
            ifstream File(filename, ios::in);
            if (!File.is_open()) {
                cout <<"\n\t\t\t File Is Empty !!! \n"<< endl;
                //cin.ignore();
                return;
            }
            books.clear();
            string aData;
            while (getline(File, aData)) {
                istringstream split(aData); // istringstream read values from the string
                Book Newbook;

                getline(split, Newbook.Title, ',');   //Read from the istringstream until a comma & store result in Newbook.Title
                getline(split, Newbook.Author, ',');
                getline(split, Newbook.Department, ',');
                getline(split, Newbook.ISBN, ',');
                getline(split, Newbook.SID,',');
                getline(split, Newbook.checkout);

                books.push_back(Newbook);
            }
            File.close();
            int i=1;
            // Display the loaded data
            cout << "  " << setfill('_') << setw(2) << "" << setw(6) << "" << setw(1) << "" << setw(25) << "" << setw(3) << "" << setw(25) << "" << setw(3) << "" << setw(15) << "" << setfill(' ') << endl;
            cout << " " << setfill(' ') << setw(1) << "|" << setw(6) << "" << setw(1) << "|" << setw(25) << "" << setw(3) << "  |" << setw(25) << "" << setw(3) << "  |" << setw(15) << "" << setfill(' ') << "  |" << endl;
            cout << " " <<  setw(1) << "| " << setw(5) << left << "S.No" << setw(3) << "|" << setw(25) << left << "Title" << setw(3) << "|" << setw(25)  << left << "Author" << setw(3) << "|" << setw(15) << left << "Department" << "|" << endl;
            cout << " " << setfill('_') << setw(2) << "|" << setw(5) << "" << setw(3) << "|" << setw(25) << "" << setw(3) << "|" << setw(25) << "" << setw(3) << "|" << setw(15) << "" << setfill(' ') << "|" << endl;
            cout << " " << setfill(' ') << setw(1) << "|" << setw(6) << "" << setw(1) << "|" << setw(25) << "" << setw(3) << "  |" << setw(25) << "" << setw(3) << "  |" << setw(15) << "" << setfill(' ') << "  |" << endl;
            for (const auto& book : books) {
                cout << " " << setw(2) << "|" << setw(1) << left << i << setw(4) << "." << setw(3) << "|" << setw(25) << left << book.Title << setw(3) << "|" << setw(25) << left << book.Author << setw(3) << "|" << setw(15) << left << book.Department << "|" << endl;
                cout << " " << setw(2) << "|" << setw(5) << "" << setw(1) << "|" << setw(25) << "" << setw(3) << "  |" << setw(25) << "" << setw(3) << "  |" << setw(15) << "" << "  |" << endl;
                i++;
            }
            cout << " " << setfill('_') << setw(2) << "|" << setw(5) << "" << setw(3) << "|" << setw(25) << "" << setw(3) << "|" << setw(25) << "" << setw(3) << "|" << setw(15) << "" << setfill(' ') << "|" << endl;


        }

        // Searching For Title In The TXT File
        void searching(const string& searchTitle) {  // For Student Only
        bool found = false;
        sleep(2);
        int i=1;
        for (const auto& book : books) {

            if (book.Title.find(searchTitle) != string::npos) { //string::npos` is a constant static member representing the largest `size_t` value.
                                                               // size_t is an unsigned integer type used for representing sizes or indices
                                                              // "find" method finds the first occurrence index of substring in the main string
                if (!found){
                        cout << "  "<< setfill('_') << setw(2) << "" << setw(6) << "" << setw(1) << "" << setw(25) << "" << setw(3) << "" << setw(25) << "" << setw(3) << "" << setw(15) << "" << setfill(' ') << endl;
                        cout << " " << setfill(' ') << setw(1) << "|" << setw(6) << "" << setw(1) << "|" << setw(25) << "" << setw(3) << "  |" << setw(25) << "" << setw(3) << "  |" << setw(15) << "" << setfill(' ') << "  |" << endl;
                        cout << " " <<  setw(1) << "| " << setw(5) << left << "S.No" << setw(3) << "|" << setw(25) << left << "Title" << setw(3) << "|" << setw(25)  << left << "Author" << setw(3) << "|" << setw(15) << left << "Department" << "|" << endl;
                        cout << " " << setfill('_') << setw(2) << "|" << setw(5) << "" << setw(3) << "|" << setw(25) << "" << setw(3) << "|" << setw(25) << "" << setw(3) << "|" << setw(15) << "" << setfill(' ') << "|" << endl;
                        cout << " " << setfill(' ') << setw(1) << "|" << setw(6) << "" << setw(1) << "|" << setw(25) << "" << setw(3) << "  |" << setw(25) << "" << setw(3) << "  |" << setw(15) << "" << setfill(' ') << "  |" << endl;
                    }
                    cout << " " << setw(2) << "|" << setw(1) << left << i << setw(4) << "." << setw(3) << "|" << setw(25) << left << book.Title << setw(3) << "|" << setw(25) << left << book.Author << setw(3) << "|" << setw(15) << left << book.Department << "|" << endl;
                    cout << " " << setw(2) << "|" << setfill(' ') << setw(5) << "" << setw(1) << "|" << setw(25) << "" << setw(3) << "  |" << setw(25) << "" << setw(3) << "  |" << setw(15) << "" << setfill(' ') << "  |" <<endl;
                    found = true;
                    i++;
            }

        }
        if (found==true){
            cout << " " << setfill('_') << setw(2) << "|" << setw(5) << "" << setw(3) << "|" << setw(25) << "" << setw(3) << "|" << setw(25) << "" << setw(3) << "|" << setw(15) << "" << setfill(' ') << "|" << endl;
        }
        if (!found) {
            cout << "\n\n\t\t\t\t Book not found !!!" << endl;
            }
        }

        // Searching For Author In The TXT File
        void FindAuthor(const string& searchAuthor) { // For Student Only
        bool found = false;
        sleep(2);
        int i=1;
        for (const auto& book : books) {

            if (book.Author.find(searchAuthor) != string::npos) { //string::npos` is a constant static member representing the largest `size_t` value.
                                                               // size_t is an unsigned integer type used for representing sizes or indices
                                                              // "find" method finds the first occurrence index of substring in the main string
                if (!found){
                        cout << "  "<< setfill('_') << setw(2) << "" << setw(6) << "" << setw(1) << "" << setw(25) << "" << setw(3) << "" << setw(25) << "" << setw(3) << "" << setw(15) << "" << setfill(' ') << endl;
                        cout << " " << setfill(' ') << setw(1) << "|" << setw(6) << "" << setw(1) << "|" << setw(25) << "" << setw(3) << "  |" << setw(25) << "" << setw(3) << "  |" << setw(15) << "" << setfill(' ') << "  |" << endl;
                        cout << " " <<  setw(1) << "| " << setw(5) << left << "S.No" << setw(3) << "|" << setw(25) << left << "Title" << setw(3) << "|" << setw(25)  << left << "Author" << setw(3) << "|" << setw(15) << left << "Department" << "|" << endl;
                        cout << " " << setfill('_') << setw(2) << "|" << setw(5) << "" << setw(3) << "|" << setw(25) << "" << setw(3) << "|" << setw(25) << "" << setw(3) << "|" << setw(15) << "" << setfill(' ') << "|" << endl;
                        cout << " " << setfill(' ') << setw(1) << "|" << setw(6) << "" << setw(1) << "|" << setw(25) << "" << setw(3) << "  |" << setw(25) << "" << setw(3) << "  |" << setw(15) << "" << setfill(' ') << "  |" << endl;
                    }
                    cout << " " << setw(2) << "|" << setw(1) << left << i << setw(4) << "." << setw(3) << "|" << setw(25) << left << book.Title << setw(3) << "|" << setw(25) << left << book.Author << setw(3) << "|" << setw(15) << left << book.Department << "|" << endl;
                    cout << " " << setw(2) << "|" << setfill(' ') << setw(5) << "" << setw(1) << "|" << setw(25) << "" << setw(3) << "  |" << setw(25) << "" << setw(3) << "  |" << setw(15) << "" << setfill(' ') << "  |" <<endl;
                    found = true;
                    i++;
            }

        }
        if (found==true){
            cout << " " << setfill('_') << setw(2) << "|" << setw(5) << "" << setw(3) << "|" << setw(25) << "" << setw(3) << "|" << setw(25) << "" << setw(3) << "|" << setw(15) << "" << setfill(' ') << "|" << endl;
        }

        if (!found) {
            cout << "\n\n\t\t\t\t Book not found !!!" << endl;
            }
        }

        // Searching Books By Department
        void SearchDeprt (const string& Sdeprt ){  // For Student Only
            bool found=false;
            sleep(2);
            int i=1;
            for (const auto& book : books) {

            if (book.Department.find(Sdeprt) != string::npos) { //string::npos` is a constant static member representing the largest `size_t` value.
                                                               // size_t is an unsigned integer type used for representing sizes or indices
                                                              // "find" method finds the first occurrence index of substring in the main string
                if (!found){
                        cout << "  "<< setfill('_') << setw(2) << "" << setw(6) << "" << setw(1) << "" << setw(25) << "" << setw(3) << "" << setw(25) << "" << setw(3) << "" << setw(15) << "" << setfill(' ') << endl;
                        cout << " " << setfill(' ') << setw(1) << "|" << setw(6) << "" << setw(1) << "|" << setw(25) << "" << setw(3) << "  |" << setw(25) << "" << setw(3) << "  |" << setw(15) << "" << setfill(' ') << "  |" << endl;
                        cout << " " <<  setw(1) << "| " << setw(5) << left << "S.No" << setw(3) << "|" << setw(25) << left << "Title" << setw(3) << "|" << setw(25)  << left << "Author" << setw(3) << "|" << setw(15) << left << "Department" << "|" << endl;
                        cout << " " << setfill('_') << setw(2) << "|" << setw(5) << "" << setw(3) << "|" << setw(25) << "" << setw(3) << "|" << setw(25) << "" << setw(3) << "|" << setw(15) << "" << setfill(' ') << "|" << endl;
                        cout << " " << setfill(' ') << setw(1) << "|" << setw(6) << "" << setw(1) << "|" << setw(25) << "" << setw(3) << "  |" << setw(25) << "" << setw(3) << "  |" << setw(15) << "" << setfill(' ') << "  |" << endl;
                    }
                    cout << " " << setw(2) << "|" << setw(1) << left << i << setw(4) << "." << setw(3) << "|" << setw(25) << left << book.Title << setw(3) << "|" << setw(25) << left << book.Author << setw(3) << "|" << setw(15) << left << book.Department << "|" << endl;
                    cout << " " << setw(2) << "|" << setfill(' ') << setw(5) << "" << setw(1) << "|" << setw(25) << "" << setw(3) << "  |" << setw(25) << "" << setw(3) << "  |" << setw(15) << "" << setfill(' ') << "  |" <<endl;
                    found = true;
                    i++;
            }

        }
        if (found==true){
            cout << " " << setfill('_') << setw(2) << "|" << setw(5) << "" << setw(3) << "|" << setw(25) << "" << setw(3) << "|" << setw(25) << "" << setw(3) << "|" << setw(15) << "" << setfill(' ') << "|" << endl;
        }

        if (!found) {
            cout << "\n\n\t\t\t\t Book not Found !!!" << endl;
            }
        }


        // Used To Just Load File Without Printing
        void load(const string& filename) {          // Used By Both Student and Faculty
        ifstream File(filename, ios::in);

        if (!File.is_open()) {
            cout << "\n\n\t\t\t File Is Empty !!!"<< endl;
            return;
        }

        books.clear();

        string aData;
        while (getline(File, aData)) {
            istringstream cut(aData);  // istringstream read values from the string
            Book Newbook;

            getline(cut, Newbook.Title, ',');
            getline(cut, Newbook.Author, ',');
            getline(cut, Newbook.Department, ',');
            getline(cut, Newbook.ISBN, ',');
            getline(cut, Newbook.SID,',');
            getline(cut, Newbook.checkout);

            books.push_back(Newbook);
        }

        File.close();
    }

        // Saving The Data To The TXT File By Appending Previous Data
        void saveToFile(const string& filename) {   // For Faculty
        ofstream File(filename, ios::app | ios::out);

        if (File.is_open()) {
            for (const auto& book : books) {
                File << book.Title << ',' << book.Author << ',' << book.Department << ',' << book.ISBN << ',' << book.SID<< ',' << book.checkout << endl;
                cout<<"\n\n\t\t\t\t Book Data Is Saved Successfully To The Library "<<endl;
            }
            File.close();
        } else {
            cout << "\n\n\t\t\t\t Unable To Save Data To File "<< endl;
            }
        }

        // Loading Files From The TXT File & To Display In Output
        void loadFromFile(const string& filename) { // For Faculty
            ifstream File(filename, ios::in);
            if (!File.is_open()) {
                cout << "\n\n\t\t\t File Is Empty !!! "<< endl;
                cin.ignore();
                return;
            }
            books.clear();
            string aData;
            while (getline(File, aData)) {
                istringstream split(aData); // istringstream read values from the string
                Book Newbook;

                getline(split, Newbook.Title, ',');   // Read from the istringstream until a comma & store result in Newbook.Title
                getline(split, Newbook.Author, ',');
                getline(split,Newbook.Department, ',');
                getline(split, Newbook.ISBN, ',');
                getline(split, Newbook.SID,',');
                getline(split, Newbook.checkout);

                books.push_back(Newbook);
            }
            File.close();
            int i=1;
            // Display the loaded data
            cout << "  " << setfill('_') << setw(2) << "" << setw(6) << "" << setw(1) << "" << setw(25) << "" << setw(3) << "" << setw(25) << "" << setw(3) << "" << setw(15) << "" << setw(3) << ""
                 << setw(20) << "" << setw(3) << "" << setw(20) << "" << setw(3) << "" << setw(20) << "" << setfill(' ') << endl;

            cout << " " << setfill(' ') << setw(1) << "|" << setw(6) << "" << setw(1) << "|" << setw(25) << "" << setw(3) << "  |" << setw(25) << "" << setw(3) << "  |" << setw(15) << "" << setw(3) << "  |"
                 << setw(20) << "" << setw(3) << "  |" << setw(20) << "" << setw(3) << "  |" << setw(20) << "" << setfill(' ') << "  |" << endl;

            cout << " " <<  setw(1) << "| " << setw(5) << left << "S.No" << setw(3) << "|" << setw(25) << left << "Title" << setw(3) << "|" << setw(25)  << left << "Author" << setw(3) << "|" << setw(15) << left
                 << "Department" << setw(3) << "|" << setw(20) << left << "ISBN" << setw(3) << "|" << setw(20) << left << "Distribute To" << setw(3) << "|" << setw(20) << left << "Available" << "|" << endl;

            cout << " " << setfill('_') << setw(2) << "|" << setw(5) << "" << setw(3) << "|" << setw(25) << "" << setw(3) << "|" << setw(25) << "" << setw(3) << "|" << setw(15) << "" << setw(3) << "|"
                 << setw(20) << "" << setw(3) << "|" << setw(20) << "" << setw(3) << "|" << setw(20) << "" << setfill(' ') << "|" << endl;

            cout << " " << setfill(' ') << setw(1) << "|" << setw(6) << "" << setw(1) << "|" << setw(25) << "" << setw(3) << "  |" << setw(25) << "" << setw(3) << "  |" << setw(15) << "" << setw(3) << "  |"
                 << setw(20) << "" << setw(3) << "  |" << setw(20) << "" << setw(3) << "  |" << setw(20) << "" << setfill(' ') << "  |" << endl;

            for (const auto& book : books) {
                cout << " " << setw(2) << "|" << setw(1) << left << i << setw(4) << "." << setw(3) << "|" << setw(25) << left << book.Title << setw(3) << "|" << setw(25) << left << book.Author << setw(3) << "|"
                     << setw(15) << left << book.Department << setw(3) << "|" << setw(20) << left << book.ISBN << setw(3) << "|" << setw(20) << left << book.SID << setw(3) << "|" << setw(20) << left << book.checkout << "|" << endl;

                cout << " " << setw(2) << "|" << setw(5) << "" << setw(1) << "|" << setw(25) << "" << setw(3) << "  |" << setw(25) << "" << setw(3) << "  |" << setw(15) << "" << setw(3) << "  |" << setw(20) << ""
                     << setw(3) << "  |" << setw(20) << "" << setw(3) << "  |" << setw(20) << "" << "  |" << endl;

                i++;
            }
            cout << " " << setfill('_') << setw(2) << "|" << setw(5) << "" << setw(3) << "|" << setw(25) << "" << setw(3) << "|" << setw(25) << "" << setw(3) << "|" << setw(15) << "" << setw(3) << "|" << setw(20) << "" << setw(3) << "|"
                 << setw(20) << "" << setw(3) << "|" << setw(20) << "" << setfill(' ') << "|" << endl;

        }

        //Searching For Title In The TXT File
        void sTitle(const string& searchTitle) {  // For Faculty
        bool found = false;
        sleep(2);
        int i=1;
        for (const auto& book : books) {
            if (book.Title.find(searchTitle) != string::npos) {
                if (!found){
                    cout << "\n  " << setfill('_') << setw(2) << "" << setw(6) << "" << setw(1) << "" << setw(25) << "" << setw(3) << "" << setw(25) << "" << setw(3) << "" << setw(15) << "" << setw(3) << ""
                         << setw(20) << "" << setw(3) << "" << setw(20) << "" << setw(3) << "" << setw(20) << "" << setfill(' ') << endl;

                    cout << " " << setfill(' ') << setw(1) << "|" << setw(6) << "" << setw(1) << "|" << setw(25) << "" << setw(3) << "  |" << setw(25) << "" << setw(3) << "  |" << setw(15) << "" << setw(3) << "  |"
                         << setw(20) << "" << setw(3) << "  |" << setw(20) << "" << setw(3) << "  |" << setw(20) << "" << setfill(' ') << "  |" << endl;

                    cout << " " <<  setw(1) << "| " << setw(5) << left << "S.No" << setw(3) << "|" << setw(25) << left << "Title" << setw(3) << "|" << setw(25)  << left << "Author" << setw(3) << "|" << setw(15) << left
                         << "Department" << setw(3) << "|" << setw(20) << left << "ISBN" << setw(3) << "|" << setw(20) << left << "Distribute To" << setw(3) << "|" << setw(20) << left << "Available" << "|" << endl;

                    cout << " " << setfill('_') << setw(2) << "|" << setw(5) << "" << setw(3) << "|" << setw(25) << "" << setw(3) << "|" << setw(25) << "" << setw(3) << "|" << setw(15) << "" << setw(3) << "|"
                         << setw(20) << "" << setw(3) << "|" << setw(20) << "" << setw(3) << "|" << setw(20) << "" << setfill(' ') << "|" << endl;

                    cout << " " << setfill(' ') << setw(1) << "|" << setw(6) << "" << setw(1) << "|" << setw(25) << "" << setw(3) << "  |" << setw(25) << "" << setw(3) << "  |" << setw(15) << "" << setw(3) << "  |"
                         << setw(20) << "" << setw(3) << "  |" << setw(20) << "" << setw(3) << "  |" << setw(20) << "" << setfill(' ') << "  |" << endl;

                }
                cout << " " << setw(2) << "|" << setw(1) << left << i << setw(4) << "." << setw(3) << "|" << setw(25) << left << book.Title << setw(3) << "|" << setw(25) << left << book.Author << setw(3) << "|"
                     << setw(15) << left << book.Department << setw(3) << "|" << setw(20) << left << book.ISBN << setw(3) << "|" << setw(20) << left << book.SID << setw(3) << "|" << setw(20) << left << book.checkout << "|" << endl;

                cout << " " << setw(2) << "|" << setw(5) << "" << setw(1) << "|" << setw(25) << "" << setw(3) << "  |" << setw(25) << "" << setw(3) << "  |" << setw(15) << "" << setw(3) << "  |" << setw(20) << ""
                     << setw(3) << "  |" << setw(20) << "" << setw(3) << "  |" << setw(20) << "" << "  |" << endl;

                found = true;
                i++;
            }
        }
        if (found==true){
            cout << " " << setfill('_') << setw(2) << "|" << setw(5) << "" << setw(3) << "|" << setw(25) << "" << setw(3) << "|" << setw(25) << "" << setw(3) << "|" << setw(15) << "" << setw(3) << "|" << setw(20) << "" << setw(3) << "|"
                 << setw(20) << "" << setw(3) << "|" << setw(20) << "" << setfill(' ') << "|" << endl;
        }
        if (!found) {
            cout << "\n\n\t\t\t\t Book Data Does Not Found !!!" << endl;
            }
        }

        //Searching For Author In The TXT File
        void sAuthor(const string& searchAuthor) { // For Faculty
        bool found = false;
        sleep(2);
        int i=1;
        for (const auto& book : books) {
            if (book.Author.find(searchAuthor) != string::npos) {
                if (!found){
                    cout << "\n  " << setfill('_') << setw(2) << "" << setw(6) << "" << setw(1) << "" << setw(25) << "" << setw(3) << "" << setw(25) << "" << setw(3) << "" << setw(15) << "" << setw(3) << ""
                         << setw(20) << "" << setw(3) << "" << setw(20) << "" << setw(3) << "" << setw(20) << "" << setfill(' ') << endl;

                    cout << " " << setfill(' ') << setw(1) << "|" << setw(6) << "" << setw(1) << "|" << setw(25) << "" << setw(3) << "  |" << setw(25) << "" << setw(3) << "  |" << setw(15) << "" << setw(3) << "  |"
                         << setw(20) << "" << setw(3) << "  |" << setw(20) << "" << setw(3) << "  |" << setw(20) << "" << setfill(' ') << "  |" << endl;

                    cout << " " <<  setw(1) << "| " << setw(5) << left << "S.No" << setw(3) << "|" << setw(25) << left << "Title" << setw(3) << "|" << setw(25)  << left << "Author" << setw(3) << "|" << setw(15) << left
                         << "Department" << setw(3) << "|" << setw(20) << left << "ISBN" << setw(3) << "|" << setw(20) << left << "Distribute To" << setw(3) << "|" << setw(20) << left << "Available" << "|" << endl;

                    cout << " " << setfill('_') << setw(2) << "|" << setw(5) << "" << setw(3) << "|" << setw(25) << "" << setw(3) << "|" << setw(25) << "" << setw(3) << "|" << setw(15) << "" << setw(3) << "|"
                         << setw(20) << "" << setw(3) << "|" << setw(20) << "" << setw(3) << "|" << setw(20) << "" << setfill(' ') << "|" << endl;

                    cout << " " << setfill(' ') << setw(1) << "|" << setw(6) << "" << setw(1) << "|" << setw(25) << "" << setw(3) << "  |" << setw(25) << "" << setw(3) << "  |" << setw(15) << "" << setw(3) << "  |"
                         << setw(20) << "" << setw(3) << "  |" << setw(20) << "" << setw(3) << "  |" << setw(20) << "" << setfill(' ') << "  |" << endl;

                }
                cout << " " << setw(2) << "|" << setw(1) << left << i << setw(4) << "." << setw(3) << "|" << setw(25) << left << book.Title << setw(3) << "|" << setw(25) << left << book.Author << setw(3) << "|"
                     << setw(15) << left << book.Department << setw(3) << "|" << setw(20) << left << book.ISBN << setw(3) << "|" << setw(20) << left << book.SID << setw(3) << "|" << setw(20) << left << book.checkout << "|" << endl;

                cout << " " << setw(2) << "|" << setw(5) << "" << setw(1) << "|" << setw(25) << "" << setw(3) << "  |" << setw(25) << "" << setw(3) << "  |" << setw(15) << "" << setw(3) << "  |" << setw(20) << ""
                     << setw(3) << "  |" << setw(20) << "" << setw(3) << "  |" << setw(20) << "" << "  |" << endl;

                found = true;
                i++;
            }
        }
        if (found==true){
            cout << " " << setfill('_') << setw(2) << "|" << setw(5) << "" << setw(3) << "|" << setw(25) << "" << setw(3) << "|" << setw(25) << "" << setw(3) << "|" << setw(15) << "" << setw(3) << "|" << setw(20) << "" << setw(3) << "|"
                 << setw(20) << "" << setw(3) << "|" << setw(20) << "" << setfill(' ') << "|" << endl;
        }
        if (!found) {
            cout << "\n\n\t\t\t\t Book Data Does Not Found !!!" << endl;
            }
        }

        //Searching For Department In the TXT File
        void FindDepartment(const string& sDeprt) { // For Faculty
        bool found = false;
        sleep(2);
        int i=1;
        for (const auto& book : books) {
            if (book.Department.find(sDeprt) != string::npos) {
                if (!found){
                    cout << "\n  " << setfill('_') << setw(2) << "" << setw(6) << "" << setw(1) << "" << setw(25) << "" << setw(3) << "" << setw(25) << "" << setw(3) << "" << setw(15) << "" << setw(3) << ""
                         << setw(20) << "" << setw(3) << "" << setw(20) << "" << setw(3) << "" << setw(20) << "" << setfill(' ') << endl;

                    cout << " " << setfill(' ') << setw(1) << "|" << setw(6) << "" << setw(1) << "|" << setw(25) << "" << setw(3) << "  |" << setw(25) << "" << setw(3) << "  |" << setw(15) << "" << setw(3) << "  |"
                         << setw(20) << "" << setw(3) << "  |" << setw(20) << "" << setw(3) << "  |" << setw(20) << "" << setfill(' ') << "  |" << endl;

                    cout << " " <<  setw(1) << "| " << setw(5) << left << "S.No" << setw(3) << "|" << setw(25) << left << "Title" << setw(3) << "|" << setw(25)  << left << "Author" << setw(3) << "|" << setw(15) << left
                         << "Department" << setw(3) << "|" << setw(20) << left << "ISBN" << setw(3) << "|" << setw(20) << left << "Distribute To" << setw(3) << "|" << setw(20) << left << "Available" << "|" << endl;

                    cout << " " << setfill('_') << setw(2) << "|" << setw(5) << "" << setw(3) << "|" << setw(25) << "" << setw(3) << "|" << setw(25) << "" << setw(3) << "|" << setw(15) << "" << setw(3) << "|"
                         << setw(20) << "" << setw(3) << "|" << setw(20) << "" << setw(3) << "|" << setw(20) << "" << setfill(' ') << "|" << endl;

                    cout << " " << setfill(' ') << setw(1) << "|" << setw(6) << "" << setw(1) << "|" << setw(25) << "" << setw(3) << "  |" << setw(25) << "" << setw(3) << "  |" << setw(15) << "" << setw(3) << "  |"
                         << setw(20) << "" << setw(3) << "  |" << setw(20) << "" << setw(3) << "  |" << setw(20) << "" << setfill(' ') << "  |" << endl;

                }
                cout << " " << setw(2) << "|" << setw(1) << left << i << setw(4) << "." << setw(3) << "|" << setw(25) << left << book.Title << setw(3) << "|" << setw(25) << left << book.Author << setw(3) << "|"
                     << setw(15) << left << book.Department << setw(3) << "|" << setw(20) << left << book.ISBN << setw(3) << "|" << setw(20) << left << book.SID << setw(3) << "|" << setw(20) << left << book.checkout << "|" << endl;

                cout << " " << setw(2) << "|" << setw(5) << "" << setw(1) << "|" << setw(25) << "" << setw(3) << "  |" << setw(25) << "" << setw(3) << "  |" << setw(15) << "" << setw(3) << "  |" << setw(20) << ""
                     << setw(3) << "  |" << setw(20) << "" << setw(3) << "  |" << setw(20) << "" << "  |" << endl;

                found = true;
                i++;
            }
        }
        if (found==true){
            cout << " " << setfill('_') << setw(2) << "|" << setw(5) << "" << setw(3) << "|" << setw(25) << "" << setw(3) << "|" << setw(25) << "" << setw(3) << "|" << setw(15) << "" << setw(3) << "|" << setw(20) << "" << setw(3) << "|"
                 << setw(20) << "" << setw(3) << "|" << setw(20) << "" << setfill(' ') << "|" << endl;
        }
        if (!found) {
            cout << "\n\n\t\t\t\t Book Data Does Not Found !!!" << endl;
            }
        }

        //Searching For Enrollment In The TXT FIle
        bool searchEnroll(const string& searchUrID) {
            for (const auto& book : books) {
                if (book.SID == searchUrID) {
                    return true;
                }
            }
            return false;
        }


        //Issue Book For The Searched ISBN Number
        void issuebook(const string& searchISBN) { // For Faculty
        bool found = false;
        sleep(2);
        int i=1;
        for (auto& book : books) {
            if (book.ISBN == searchISBN) {
                    if (!found){
                        cout << "\n  " << setfill('_') << setw(2) << "" << setw(6) << "" << setw(1) << "" << setw(25) << "" << setw(3) << "" << setw(25) << "" << setw(3) << "" << setw(15) << "" << setw(3) << ""
                             << setw(20) << "" << setw(3) << "" << setw(20) << "" << setw(3) << "" << setw(20) << "" << setfill(' ') << endl;

                        cout << " " << setfill(' ') << setw(1) << "|" << setw(6) << "" << setw(1) << "|" << setw(25) << "" << setw(3) << "  |" << setw(25) << "" << setw(3) << "  |" << setw(15) << "" << setw(3) << "  |"
                             << setw(20) << "" << setw(3) << "  |" << setw(20) << "" << setw(3) << "  |" << setw(20) << "" << setfill(' ') << "  |" << endl;

                        cout << " " <<  setw(1) << "| " << setw(5) << left << "S.No" << setw(3) << "|" << setw(25) << left << "Title" << setw(3) << "|" << setw(25)  << left << "Author" << setw(3) << "|" << setw(15) << left
                             << "Department" << setw(3) << "|" << setw(20) << left << "ISBN" << setw(3) << "|" << setw(20) << left << "Distribute To" << setw(3) << "|" << setw(20) << left << "Available" << "|" << endl;

                        cout << " " << setfill('_') << setw(2) << "|" << setw(5) << "" << setw(3) << "|" << setw(25) << "" << setw(3) << "|" << setw(25) << "" << setw(3) << "|" << setw(15) << "" << setw(3) << "|"
                             << setw(20) << "" << setw(3) << "|" << setw(20) << "" << setw(3) << "|" << setw(20) << "" << setfill(' ') << "|" << endl;

                        cout << " " << setfill(' ') << setw(1) << "|" << setw(6) << "" << setw(1) << "|" << setw(25) << "" << setw(3) << "  |" << setw(25) << "" << setw(3) << "  |" << setw(15) << "" << setw(3) << "  |"
                             << setw(20) << "" << setw(3) << "  |" << setw(20) << "" << setw(3) << "  |" << setw(20) << "" << setfill(' ') << "  |" << endl;

                    }
                    cout << " " << setw(2) << "|" << setw(1) << left << i << setw(4) << "." << setw(3) << "|" << setw(25) << left << book.Title << setw(3) << "|" << setw(25) << left << book.Author << setw(3) << "|"
                         << setw(15) << left << book.Department << setw(3) << "|" << setw(20) << left << book.ISBN << setw(3) << "|" << setw(20) << left << book.SID << setw(3) << "|" << setw(20) << left << book.checkout << "|" << endl;

                    cout << " " << setw(2) << "|" << setw(5) << "" << setw(1) << "|" << setw(25) << "" << setw(3) << "  |" << setw(25) << "" << setw(3) << "  |" << setw(15) << "" << setw(3) << "  |" << setw(20) << ""
                         << setw(3) << "  |" << setw(20) << "" << setw(3) << "  |" << setw(20) << "" << "  |" << endl;

                    found = true;
                    i++;
                    if (found==true){
                        cout << " " << setfill('_') << setw(2) << "|" << setw(5) << "" << setw(3) << "|" << setw(25) << "" << setw(3) << "|" << setw(25) << "" << setw(3) << "|" << setw(15) << "" << setw(3) << "|" << setw(20) << "" << setw(3) << "|"
                             << setw(20) << "" << setw(3) << "|" << setw(20) << "" << setfill(' ') << "|" << endl;
                    }

                if (book.checkout == "Yes") {
                    char a;
                    cout << "\n\n\t\t\t\t\t Book Is Available !!! \n" << endl;
                    cout << "\n Do you want to checkout (Y/N) : ";
                    cin >> a;

                    if (a == 'Y' or a == 'y') {
                        string searchEID;
                        cout<<"\n Enter Your Enrollment Number : ";
                        cin.ignore();
                        getline(cin,searchEID);

                        while (searchEID[0] == ' ' || searchEID[0] == '\t') { // Remove leading spaces
                            searchEID.erase(0, 1);
                        }
                        while (searchEID.back() == ' ' || searchEID.back() == '\t') { // Remove trailing spaces
                            searchEID.pop_back();
                        }

                        for(int i=0;i<searchEID.length();i++){ // Capitalizing Character in Enrollment
                            if(searchEID[i]>=65 && searchEID[i]<=90)
                                continue;
                            else if(searchEID[i]>=48 && searchEID[i]<=57)
                                continue;
                            else if(searchEID[i]==' ')
                                continue;
                            else
                                searchEID[i]=toupper(searchEID[i]);
                        }

                        User stud;
                        stud.loaduser("StudXData.txt");
                        string findeno = stud.searchEnrollid(searchEID);

                        if (searchEID == findeno){  // Check Enrollment present to be done

                                bool stringid=searchEnroll(searchEID);
                                if (stringid == true ){
                                    cout<<"\n\n\t\t\t\t Student Is Already Applied For Book "<<endl;
                                }
                                else{
                                book.SID = searchEID;
                                book.checkout = "No";
                                cout <<"\n\n " << book.Title << " Book Issued To  " <<book.SID << endl;
                                }
                        }
                        else {
                            cout<<"\n\n\t\t\t\t Student Not Found With This Enrollment No. !!!"<<endl;
                        }

                    } else {
                        cout << "\n\n\t\t\t\t Book Not Checked Out " << endl;
                    }
                    break;
                } else {
                    cout << "\n\n\t\t\t\t Book is already checked out " << endl;
                    return;
                    }
                }
            }
            if (!found) {
                cout << "\n\n\t\t\t\t Book Data Does Not Found !!!" << endl;
                return;
            }

            // Update the file with the modified book data
            ofstream outFile("LibXData.txt", ios::out);
            if (!outFile.is_open()) {
                cout << "\n\n\t\t\t\t\t\t Error: Unable to open file for writing." << endl;
                cin.ignore();
                return;
            }
            // Write the entire updated books vector to the file
            for (const auto& book : books) {
                outFile << book.Title << ',' << book.Author << ',' << book.Department << ',' << book.ISBN << ',' <<book.SID << ',' << book.checkout << endl;
            }
            outFile.close();  // Close the file after writing
        }

        //Return Book From The Student
        void returnbook(const string& searchISBN) { // For Faculty
            bool found = false;
            sleep(2);
            int i=1;
            for (auto& book : books) {
            if (book.ISBN == searchISBN) {
                if (!found){
                        cout << "\n  " << setfill('_') << setw(2) << "" << setw(6) << "" << setw(1) << "" << setw(25) << "" << setw(3) << "" << setw(25) << "" << setw(3) << "" << setw(15) << "" << setw(3) << ""
                             << setw(20) << "" << setw(3) << "" << setw(20) << "" << setw(3) << "" << setw(20) << "" << setfill(' ') << endl;

                        cout << " " << setfill(' ') << setw(1) << "|" << setw(6) << "" << setw(1) << "|" << setw(25) << "" << setw(3) << "  |" << setw(25) << "" << setw(3) << "  |" << setw(15) << "" << setw(3) << "  |"
                             << setw(20) << "" << setw(3) << "  |" << setw(20) << "" << setw(3) << "  |" << setw(20) << "" << setfill(' ') << "  |" << endl;

                        cout << " " <<  setw(1) << "| " << setw(5) << left << "S.No" << setw(3) << "|" << setw(25) << left << "Title" << setw(3) << "|" << setw(25)  << left << "Author" << setw(3) << "|" << setw(15) << left
                             << "Department" << setw(3) << "|" << setw(20) << left << "ISBN" << setw(3) << "|" << setw(20) << left << "Distribute To" << setw(3) << "|" << setw(20) << left << "Available" << "|" << endl;

                        cout << " " << setfill('_') << setw(2) << "|" << setw(5) << "" << setw(3) << "|" << setw(25) << "" << setw(3) << "|" << setw(25) << "" << setw(3) << "|" << setw(15) << "" << setw(3) << "|"
                             << setw(20) << "" << setw(3) << "|" << setw(20) << "" << setw(3) << "|" << setw(20) << "" << setfill(' ') << "|" << endl;

                        cout << " " << setfill(' ') << setw(1) << "|" << setw(6) << "" << setw(1) << "|" << setw(25) << "" << setw(3) << "  |" << setw(25) << "" << setw(3) << "  |" << setw(15) << "" << setw(3) << "  |"
                             << setw(20) << "" << setw(3) << "  |" << setw(20) << "" << setw(3) << "  |" << setw(20) << "" << setfill(' ') << "  |" << endl;

                    }
                    cout << " " << setw(2) << "|" << setw(1) << left << i << setw(4) << "." << setw(3) << "|" << setw(25) << left << book.Title << setw(3) << "|" << setw(25) << left << book.Author << setw(3) << "|"
                         << setw(15) << left << book.Department << setw(3) << "|" << setw(20) << left << book.ISBN << setw(3) << "|" << setw(20) << left << book.SID << setw(3) << "|" << setw(20) << left << book.checkout << "|" << endl;

                    cout << " " << setw(2) << "|" << setw(5) << "" << setw(1) << "|" << setw(25) << "" << setw(3) << "  |" << setw(25) << "" << setw(3) << "  |" << setw(15) << "" << setw(3) << "  |" << setw(20) << ""
                         << setw(3) << "  |" << setw(20) << "" << setw(3) << "  |" << setw(20) << "" << "  |" << endl;

                    found = true;
                    i++;
                    if (found==true){
                        cout << " " << setfill('_') << setw(2) << "|" << setw(5) << "" << setw(3) << "|" << setw(25) << "" << setw(3) << "|" << setw(25) << "" << setw(3) << "|" << setw(15) << "" << setw(3) << "|" << setw(20) << "" << setw(3) << "|"
                             << setw(20) << "" << setw(3) << "|" << setw(20) << "" << setfill(' ') << "|" << endl;
                    }
                    cout << "\n\n\t\t\t\t\t Book Found !!! \n" << endl;
                    char opt;
                    cout<<"\n Do You Want To Return This Book To Library (Y/N) : ";
                    cin>>opt;
                    if (opt=='Y' or opt =='y'){

                        User stud;
                        stud.loaduser("StudXData.txt");
                        string findeno;
                        findeno = stud.searchEnrollid(book.SID);
                        if (book.SID == findeno){
                            book.SID="None";
                            book.checkout="Yes";
                            cout<<"\n\n\t\t\t\t Book Is Returned To The Library "<<endl;
                        }
                        else{
                            cout<<"\n\n\t\t\t\t Cannot Return Book For This User "<<endl;
                        }
                        break;
                    }
                    else {
                        cout<<"\n\n\t\t\t\t Book Return Process Cancelled !!!"<<endl;
                    }
                }
            }

            if (!found) {
                cout << "\n\n\t\t\t\t ISBN Number of Book Not Found " << endl;
                return;  // Exit the function if the book is not found
            }
            ofstream outFile("LibXData.txt", ios::out);

            if (!outFile.is_open()) {
                cout << "\n\n\t\t\t\t Error: Unable to open file for writing." << endl;
                return;
            }

            // Write the entire updated books vector to the file
            for (const auto& book : books) {
                outFile << book.Title << ',' << book.Author << ',' << book.Department << ',' << book.ISBN << ',' <<book.SID <<',' << book.checkout << endl;
                }
            outFile.close();  // Close the file after writing
        }

        //Delete A Book And Its Data From Library Using ISBN No.
        void deletebook(const string& searchISBN) { // For Faculty
            bool found = false;
            sleep(2);
            int i=1;
            for (auto& book : books) {
                if (book.ISBN == searchISBN) {

                    if (!found){
                        cout << "\n  " << setfill('_') << setw(2) << "" << setw(6) << "" << setw(1) << "" << setw(25) << "" << setw(3) << "" << setw(25) << "" << setw(3) << "" << setw(15) << "" << setw(3) << ""
                             << setw(20) << "" << setw(3) << "" << setw(20) << "" << setw(3) << "" << setw(20) << "" << setfill(' ') << endl;

                        cout << " " << setfill(' ') << setw(1) << "|" << setw(6) << "" << setw(1) << "|" << setw(25) << "" << setw(3) << "  |" << setw(25) << "" << setw(3) << "  |" << setw(15) << "" << setw(3) << "  |"
                             << setw(20) << "" << setw(3) << "  |" << setw(20) << "" << setw(3) << "  |" << setw(20) << "" << setfill(' ') << "  |" << endl;

                        cout << " " <<  setw(1) << "| " << setw(5) << left << "S.No" << setw(3) << "|" << setw(25) << left << "Title" << setw(3) << "|" << setw(25)  << left << "Author" << setw(3) << "|" << setw(15) << left
                             << "Department" << setw(3) << "|" << setw(20) << left << "ISBN" << setw(3) << "|" << setw(20) << left << "Distribute To" << setw(3) << "|" << setw(20) << left << "Available" << "|" << endl;

                        cout << " " << setfill('_') << setw(2) << "|" << setw(5) << "" << setw(3) << "|" << setw(25) << "" << setw(3) << "|" << setw(25) << "" << setw(3) << "|" << setw(15) << "" << setw(3) << "|"
                             << setw(20) << "" << setw(3) << "|" << setw(20) << "" << setw(3) << "|" << setw(20) << "" << setfill(' ') << "|" << endl;

                        cout << " " << setfill(' ') << setw(1) << "|" << setw(6) << "" << setw(1) << "|" << setw(25) << "" << setw(3) << "  |" << setw(25) << "" << setw(3) << "  |" << setw(15) << "" << setw(3) << "  |"
                             << setw(20) << "" << setw(3) << "  |" << setw(20) << "" << setw(3) << "  |" << setw(20) << "" << setfill(' ') << "  |" << endl;

                    }
                    cout << " " << setw(2) << "|" << setw(1) << left << i << setw(4) << "." << setw(3) << "|" << setw(25) << left << book.Title << setw(3) << "|" << setw(25) << left << book.Author << setw(3) << "|"
                         << setw(15) << left << book.Department << setw(3) << "|" << setw(20) << left << book.ISBN << setw(3) << "|" << setw(20) << left << book.SID << setw(3) << "|" << setw(20) << left << book.checkout << "|" << endl;

                    cout << " " << setw(2) << "|" << setw(5) << "" << setw(1) << "|" << setw(25) << "" << setw(3) << "  |" << setw(25) << "" << setw(3) << "  |" << setw(15) << "" << setw(3) << "  |" << setw(20) << ""
                         << setw(3) << "  |" << setw(20) << "" << setw(3) << "  |" << setw(20) << "" << "  |" << endl;

                    found = true;
                    i++;
                    if (found==true){
                        cout << " " << setfill('_') << setw(2) << "|" << setw(5) << "" << setw(3) << "|" << setw(25) << "" << setw(3) << "|" << setw(25) << "" << setw(3) << "|" << setw(15) << "" << setw(3) << "|" << setw(20) << "" << setw(3) << "|"
                             << setw(20) << "" << setw(3) << "|" << setw(20) << "" << setfill(' ') << "|" << endl;
                    }
                    cout << "\n\n\t\t\t\t\t Book Found \n!!!" << endl;

                    char opt;
                    cout<<"\n Do You Want To Delete This Book From Library (Y/N) : ";
                    cin>>opt;
                    if (opt=='Y' or opt =='y'){

                            book.Title="";
                            book.Author="";
                            book.Department="";
                            book.ISBN="";
                            book.SID="";
                            book.checkout="";

                            cout<<"\n\n\t\t\t\t Book Data Has Been Deleted From Library"<<endl;
                    }
                    else{
                        cout<<"\n\n\t\t\t\t Book Deletion Operation Cancelled "<<endl;
                    }
                }
            }

            if (!found) {
                cout << "\n\n\t\t\t\t ISBN Number of Book Not Found " << endl;
                cin.ignore();
                return;  // Exit the function if the book is not found
            }
            fstream outFile("LibXData.txt", ios::out);

            if (!outFile.is_open()) {
                cout << "\n\n\t\t\t\t Error: Unable to open file for writing." << endl;
                cin.ignore();
                return;
            }

            for (const auto& book : books) {  // Updating File To Become Empty
                    if (!book.Title.empty() || !book.Author.empty() || !book.Department.empty() || !book.ISBN.empty() || !book.SID.empty() || !book.checkout.empty()) {

                        outFile << book.Title << ',' << book.Author << ',' << book.Department << ',' << book.ISBN << ','
                                << book.SID << ',' << book.checkout << endl;
                    } // This Code Will Not Run As All Items Will Become Empty On Deletion As It Ensures That Only non-empty information is written

                }
            outFile.close();  // Close the file after writing

        }


        //Get ISBN
        string getISBN () const {
        return bookdata.ISBN;
        }

        //Finding & Returning ISBN Directly From File
        string FindISBN(const string& searchISBN, const string& filename) const {
            ifstream file(filename);
            if (file.is_open()) {
                string CutData;
                while (getline(file, CutData)) {
                    istringstream split(CutData); // istringstream read values from the string
                    Book NewData;

                    getline(split, NewData.Title, ',');
                    getline(split, NewData.Author, ',');
                    getline(split,NewData.Department, ',');
                    getline(split, NewData.ISBN, ',');
                    getline(split, NewData.SID,',');
                    getline(split, NewData.checkout);

                    if (NewData.ISBN == searchISBN){
                        file.close();
                        return NewData.ISBN;
                    }
                }
                file.close();
            } else {
                cout << " Unable to open file: " << filename << endl;
            }

            return "";
        }

};
