#include <iostream>
#include <string>
#include <vector>

using namespace std;

class User {
private:
    string username;
    string password;
public:
    User(string username, string password) {
        this->username = username;
        this->password = password;
    }

    string getUsername() {
        return this->username;
    }
    string getPassword() {
        return this->password;
    }
};

class Authorization {
public:
    void registerUser(string username, string password) {
        User user(username, password);
            users.push_back(user);
    }

    bool login(string username, string password) {
        for (int i = 0; i < users.size(); i++) {
            if (users[i].getUsername() == username && users[i].getPassword() == password) {
                return true;
            }
        }
        return false;
    }
    
private:
    vector<User>users;
};

int main() {
    Authorization auth;
    auth.registerUser("user1", "password1");
    auth.registerUser("user2", "password2");

    string username, password;
    cout << "Пожалуйста, введите Ваше имя: ";
    cin >> username;
    cout << "Пожалуйста, введите Ваш пароль: ";
    cin >> password;

    if (auth.login(username, password)) {
        cout << "Логин верен" << endl;
    }
    else {
        cout << "Логин неверен" << endl;
    }

    return 0;
}

