#include <iostream>
#include <string>

using namespace std;

class User {
    private:
        string username;
        string password;
    public:
        User() {}
        User(string u, string p) {
            username = u;
            password = p;
        }
        string getUsername() {
            return username;
        }
        string getPassword() {
            return password;
        }
        void setUsername(string u) {
            username = u;
        }
        void setPassword(string p) {
            password = p;
        }
};

int main() {
    User user;
    string inputUsername, inputPassword;

    cout << "Пожалуйста, введите Ваше имя: ";
    cin >> inputUsername;
    user.setUsername(inputUsername);

    cout << "Пожалуйста, введите Ваш пароль: ";
    cin >> inputPassword;
    user.setPassword(inputPassword);

    cout << "\nРегистрация завершена. Добро пожаловать, " << user.getUsername() << endl;

    return 0;
}
