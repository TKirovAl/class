#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class User {
    public:
        string name;
        string password;
};

class Auth {
    private:
        User user;
    public:
        void registerUser() {
            cout << "Enter your name: ";
            cin >> user.name;
            cout << "Enter your password: ";
            cin >> user.password;
            
            ofstream file("data.txt", ios::app);
            if(file.is_open()) {
                file << user.name << " " << user.password << endl;
                file.close();
                
                cout << "User registration successful" << endl;
            } else {
                cout << "Could not open file" << endl;
            }
        }
        
        bool loginUser() {
            string name, password;
            cout << "Enter your name: ";
            cin >> name;
            cout << "Enter your password: ";
            cin >> password;
            
            ifstream file("data.txt");
            if(file.is_open()) {
                string file_name, file_password;
                while(file >> file_name >> file_password) {
                    if(name == file_name && password == file_password) {
                        file.close();
                        return true;
                    }
                }
                file.close();
                return false;
            } else {
                cout << "Could not open file" << endl;
                return false;
            }
        }
};

int main() {
    Auth auth;
    int choice;
    bool isLoggedIn = false;
    
    do {
        cout << "Welcome to the system" << endl;
        cout << "1. Register" << endl;
        cout << "2. Login" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                auth.registerUser();
                break;
            case 2:
                isLoggedIn = auth.loginUser();
                if(isLoggedIn) {
                    cout << "Login successful" << endl;
                } else {
                    cout << "Login failed" << endl;
                }
                break;
            case 0:
                break;
            default:
                cout << "Invalid choice" << endl;
        }
    } while(choice != 0);
    
    return 0;
}
