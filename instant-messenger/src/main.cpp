#include "include/mainwindow.h"
#include <fstream>

#include <QApplication>

std::vector<std::string> readFile (std::string filename){
    std::vector<std::string> vector;
    std::string readText;
    std::fstream readFile(filename);
    while (getline(readFile, readText)) {
        vector.push_back(readText);
    }
    readFile.close();
    return vector;
}

bool checkLogin(QString username, QString password){ //Checks the username and password against all stored usernames and passwords
    std::vector<std::string> usernameList = readFile("usernames.txt");
    std::vector<std::string> passwordList;
    std::string readText; //This string will be used to hold the text read from each line so it can be pushed into the vector
    std::fstream readPasswords("passwords.txt");
    while (getline(readPasswords, readText)) {
        for (int i = 0; i < readText.length(); ++i) {
            readText[i] = readText[i] - 7; //Decrypts the password by decreasing the character by 7
        }
        passwordList.push_back(readText);
    }
    readPasswords.close();
    for (int i = 0; i < usernameList.size(); ++i) {
        if (username.toStdString() == usernameList[i] && password.toStdString() == passwordList[i]) { //Compares usernames and passwords for each entry in usernameList
            return true;
        }
    }
    return false;
}

bool checkUsername(QString username){ //Checks just the username against all stored usernames - used for creating new account
    std::vector<std::string> usernameList = readFile("usernames.txt");
    for (int i = 0; i < usernameList.size(); ++i) {
        if (username.toStdString() == usernameList[i]) {
            return true;
        }
    }
    return false;
}

void storeLogin(QString username,QString password){ //Stores the values of login in text files
    std::ofstream writeUsername;
            writeUsername.open("usernames.txt", std::ios::app); //Opens with append mode, as to not overwrite current data
            writeUsername << username.toStdString() << "\n"; //Stores username as an StdString rather than a QString, and creates a new line for the next piece of data
            writeUsername.close();
            std::string passwordStd = password.toStdString(); //Creates a new variable to store password as an StdString so it can be encrypted
            for (int i = 0; i < passwordStd.length(); ++i) {
                passwordStd[i] = passwordStd[i] + 7;
            }
            std::ofstream writePassword;
            writePassword.open("passwords.txt", std::ios::app); //Opens with append mode, as to not overwrite current data
            writePassword << passwordStd << "\n";
            writePassword.close();
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
