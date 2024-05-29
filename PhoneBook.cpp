#include <iostream>
#include<iomanip>

using namespace std;

class Contact {
public:
    string name;
    string phone;

    Contact() {
        name = "";
        phone = "";
    }

    Contact(string name1, string phone1) {
        name = name1;
        phone = phone1;
    }
};

class PhoneBook
{   
    int size;
    Contact* contacts;
    int capacity;
public:
    PhoneBook(int c){
        size = 0;
        capacity = c;
        contacts = new Contact[c];
    }

    ~PhoneBook() {
        cout << "<The Phone Book was destroyed>";
        delete[]  contacts;
    }

    void addContact(string name, string phone)
    {
        for (int i = 0; i < size; i++) {
            if (contacts[i].phone == phone) {
                cout << "This phone number is already saved." << endl;
                cout << "The attempt failed." << endl;
                return; 
            }
        }

        if (size == capacity)
        {
            capacity = capacity + 1;
            Contact* newContacts = new Contact[capacity];
            for (int i = 0; i < size; i++) {
                newContacts[i] = contacts[i];
            }

            delete[] contacts;
            contacts = newContacts;
            //cout << "The Phone Book is full. " << endl;
           // return;
        }
        contacts[size].name = name;
        contacts[size].phone = phone;
        size++;
        cout << "You added a contact successfully!" << endl;
    }
    void printContact() {
        if (size == 0) {
            cout << "NO USER TO PRINT!" << endl;
        }
        else {
            cout << setw(20) << setfill(' ') << left << "Name: ";
            cout << setw(20) << setfill(' ') << left << "Phone: " << endl;
            cout << setw(35) << setfill('-') << "" << endl;
            for (int i = 0; i < size; i++) {
                cout << setw(20) << setfill(' ') << left << contacts[i].name;
                cout << setw(20) << setfill(' ') << left << "+383" + contacts[i].phone;
                cout << endl;
            }
        }

    }

    void searchContact() {
        string search;
        string phoneS;
        int numruesi = 0;
        cout << "Search your contact: ";
        cin >> search;
        bool found = false;
        int foundIndex = -1;
        for (int i = 0; i < size; i++) {

            if (contacts[i].name == search) {
                numruesi++;
            }
        }
        if (numruesi > 1) {
            cout << "Multiple contacts with name " << search << " were found." << endl;
            cout << "Please enter phone number to find the correct contact:" << endl;
            cout << "+383";
            cin >> phoneS;

            for (int i = 0; i < size; i++) {
                if (contacts[i].name == search && contacts[i].phone == phoneS) {
                    found = true;
                    foundIndex = i;
                    break;
                }
            }
        }
        else
        {
            for (int i = 0; i < size; i++) {
                if (contacts[i].name == search || contacts[i].phone == search) {
                    found = true;
                    foundIndex = i;
                    break;
                }
            }
        }

        if (found && foundIndex != 0)
        {
            Contact t = contacts[foundIndex];
            for (int i = foundIndex; i > 0; i--)
            {
                contacts[i] = contacts[i - 1];
            }
            contacts[0] = t;
        }

        if (found) {
            cout << "Your results:" << endl;
            cout << setw(35) << setfill('-') << "" << endl;
            cout << setw(20) << setfill(' ') << left << "Name: " << contacts[0].name << endl;
            cout << setw(20) << setfill(' ') << left << "Phone: " << "+383" + contacts[0].phone << endl;
        }
        else {
            cout << "CONTACT NOT FOUND!" << endl;
        }
    }

    void editContact() {
        string search;
        string phoneS;
        int numruesi = 0;
        bool found = false;
        int foundIndex = -1;
        cout << "Search for the contact to edit it.";
        cout << endl;
        cin >> search;
        char a;

        for (int i = 0; i < size; i++) {
            if (contacts[i].name == search)
                numruesi++;
        }

        if (numruesi > 1) {
            cout << "Multiple contacts with name " << search << " were found." << endl;
            cout << "Please enter phone number to edit the correct contact:" << endl;
            cout << "+383";
            cin >> phoneS;
            for (int i = 0; i < size; i++) {
                if (contacts[i].name == search && contacts[i].phone == phoneS) {
                    found = true;
                    foundIndex = i;
                    break;
                }
                else {
                    found = false;
                }
            }
        }
        else {
            for (int i = 0; i < size; i++) {
                if (contacts[i].name == search || contacts[i].phone == search) {
                    found = true;
                    foundIndex = i;
                    break;
                }
            }
        }

        if (true) {
            string newName;
            string newPhone;
            cout << "Do you want edit name or phone?/(N/P)" << endl;
            cin >> a;
            for (int i = 0; i < size; i++) {
                if (newPhone == contacts[i].phone) {
                    cout << "Same number! Try again.";
                    return;
                    break;
                }
            }

            switch (a) {
             case 'n':
             case 'N':
                cout << "Enter the new name: ";
                cin >> newName;
                contacts[foundIndex].name = newName;
                cout << "Contact updated successfully!" << endl;
                break;
             case 'p':
             case 'P':
                cout << "Enter the new phone number: +383";
                cin >> newPhone;
                for (int i = 0; i < size; i++) {
                    if (newPhone == contacts[i].phone) {
                        cout << "This number is saved." << endl;
                        cout << "Try again." << endl;
                        //cout << "Enter new number: +383";
                       // cin >> newPhone;
                       // contacts[foundIndex].phone = newPhone;
                        return;
                        break;
                    }
                        
                    }
                for (int i = 0; i < size; i++) {
                    if (newPhone != contacts[i].phone) {
                        contacts[foundIndex].phone = newPhone;
                        cout << "Contact updated successfully!" << endl;
                        break;
                    }
                    break;
                }
                break;
             default:
                cout << "Please select N or P."<<endl;
                cout << "Try again." << endl;
                return;
                break;
            }
        }
        else {
            cout << "CONTACT DOESN'T EXIST!" << endl;
        }
    }

    void deleteContact() {
        int numruesi = 0;
        string search;
        string phoneD;
        bool found = false;
        int  foundIndex = -1;
        cout << "Enter contact to delete.";
        cout << endl;
        cin >> search;
        for (int i = 0; i < size; i++) {
          
            if (contacts[i].name == search) {
                numruesi++;
            }
        }
        if (numruesi > 1) {
            cout <<"Multiple contacts with name "<<search<<" were found." << endl;
            cout << "Please enter phone number to delete the correct contact:" << endl;
            cout<<"+383";
            cin >> phoneD;

            for (int i = 0; i < size; i++) {
                if (contacts[i].name==search && contacts[i].phone ==phoneD) {
                    found = true;
                    foundIndex = i;
                    break;
                }
            }
        }
        else
        {
            for (int i = 0; i < size; i++) {
                if (contacts[i].name == search || contacts[i].phone == search) {
                    found = true;
                    foundIndex = i;
                    break;
                }
            }
        }

        if (found) {
            for (int i = foundIndex; i < size - 1; i++) {
                contacts[i] = contacts[i + 1];
            }
            size--;   
            cout << "Contact deleted successfully!" << endl;
        }
        else {
            cout << "CONTACT DOESN'T EXIST!" << endl;
        }
    }

    int getSize() {
        return size;
    }
};

int main() {
   // int madhesia;
    char option;
    bool r = true;
    //cout << "Enter the size of PHONEBOOK: ";
    //cin >> madhesia;
   // PhoneBook phonebook(madhesia);
    PhoneBook phonebook(1);//eshte shtu
    string emri;
    string numri;

    while (r)
    {
        cout << setw(27) << setfill('-') << right << "SELECT THE OPTION";
        cout << setw(8) << setfill('-') << right << "" << endl;
        cout << "1) ADD CONTACT(+)" << endl;
        cout << "2) LIST(L)" << endl;
        cout << "3) SEARCH(S)" << endl;
        cout << "4) EDIT(E)" << endl;
        cout << "5) DELETE(X)" << endl;
        cout << "6) CLOSE(C)" << endl;
        cout << setw(36) << setfill('=') << " " << endl;
        cin >> option;
        switch (option)
        {
        case '1':
        case '+':
        case 'a':
        case 'A':
            cout << setw(25) << setfill('-') << "ADD NEW CONTACT";
            cout << setw(10) << setfill('-') << "-" << endl;
            cout << "Enter name: ";
            cin >> emri;
            cout << "Enter number: +383";
            cin >> numri;
            phonebook.addContact(emri, numri);
            
            cout << setw(36) << setfill('_') << " " << endl;
            break;
        case 'l':
        case 'L':
        case '2':
            cout << setw(24) << setfill('-') << "CONTACTS LIST";
            cout << setw(11) << setfill('-') << "-";
            cout << endl;
            phonebook.printContact();
            cout << setw(35) << setfill('_') << "" << endl;
            break;
        case 's':
        case 'S':
        case '3':
            cout << setw(20) << setfill('-') << "SEARCH";
            cout << setw(14) << setfill('-') << "";
            cout << endl;
            phonebook.searchContact();
            cout << setw(35) << setfill('_') << "" << endl;
            break;
        case '4':
        case 'e':
        case 'E':
            cout << setw(24) << setfill('-') << "EDIT CONTACT";
            cout << setw(11) << setfill('-') << "";
            cout << endl;
            phonebook.editContact();
            cout << setw(35) << setfill('_') << "" << endl;
            break;
        case 'd':
        case 'D':
        case '5':
        case 'x':
        case 'X':
            cout << setw(26) << setfill('-') << "DELETE CONTACT";
            cout << setw(9) << setfill('-') << "";
            cout << endl;
            phonebook.deleteContact();
            cout << setw(35) << setfill('_') << "" << endl;
            break;
        case '6':
        case 'c':
        case 'C':
            char answer;
            cout << "CLOSING THE PHONE BOOK..." << endl;
            cout << "Phone Book has " << phonebook.getSize()<< " contacts." << endl;
            cout << "Are you sure to close Phone Book?" << endl;
            cout << "Back(B)" << endl;
            cout << "Continue(C)" << endl;
            cin >> answer;
            if (answer == 'c' || answer == 'C') {
                r = false;
                return 0;
            }
            else
                r = true;
            break;
        default:
            cout << "INVALID INPUT!"<<endl;
            cout<<"PLEASE SELECT OPTIONS 1 to 6." << endl;
            break;
        }
    }
    return 0;
}
