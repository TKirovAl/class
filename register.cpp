#include <iostream>
#include <string>
#define MAX_USERS 100 

class User {
    private:
        std::string name;
        std::string password;
    public:
        User() {};
        User(std::string name, std::string password) {
            this->name = name;
            this->password = password;
        }
        std::string getName() {
            return name;
        }
        std::string getPassword() {
            return password;
        }
};

class RegistrationSystem {
    private:
        User users[MAX_USERS];
        int numUsers = 0;
        int findUser(std::string name) {
            for (int i = 0; i < numUsers; i++) {
                if (users[i].getName() == name) {
                    return i;
                }
            }
            return -1;
        }
    public:
        bool addUser(std::string name, std::string password) {
            if (numUsers >= MAX_USERS) {
                return false;
            }
            if (findUser(name) != -1) {
                return false;
            }
            users[numUsers] = User(name, password); 
            numUsers++; 
            return true;
        }
        bool login(std::string name, std::string password) { 
            int index = findUser(name); 
            if (index == -1) { 
                return false;
            }
            if (users[index].getPassword() != password) { 
                return false;
            }
            return true; 
        }
};

int main() {
    RegistrationSystem system;
    system.addUser("Alice", "qwerty");
    std::cout << "Alice registered" << std::endl;
    system.addUser("Bob", "12345")

    std::cout << "Bob registered" << std::endl;
    bool loginResult1 = system.login("Alice", "qwerty");

        std::cout << "Alice logged in" << std::endl;
    } else {
        std::cout << "Alice login failed" << std::endl;
    }
    bool loginResult2 = system.login("Bob", "wrongpassword");

        std::cout << "Bob logged in" << std::endl;
    } else {
        std::cout << "Bob login failed" << std::endl;
    }
    bool loginResult3 = system.login("Charlie", "mypassword");
        std::cout << "Charlie logged in" << std::endl;
    } else {
        std::cout << "Charlie login failed" << std::endl;
    }
    return 0;
}
