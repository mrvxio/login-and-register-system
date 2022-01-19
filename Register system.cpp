
#include <iostream>

std::string logins[10] = {};
std::string passwords[10] = {};

void loginSystem(std::string nickname, std::string password)
{
    for (unsigned short i = 0; i < sizeof(logins) / sizeof(logins[0]); i++)
    {
        if (logins[i] == nickname)
        {
            unsigned short ind = i;
            if (passwords[ind] == password)
            {
                std::cout << "Hello " << nickname << ", you have been logged in!";
                exit(0);
            }
        }
    }
    std::cout << "The account with the given login and password does not exist";
}

void registerSystem(std::string nickname, std::string password)
{
    logins[(sizeof(logins) / sizeof(logins[0]))-1] = nickname;
    passwords[(sizeof(passwords) / sizeof(logins[0]))-1] = password;
    std::cout << "You are register now!" << std::endl;
}

void appEngine()
{
    while (true)
    {
        std::string nickname;
        std::string password;
        std::string option;
        std::cout << "Hello! Do you want login or register?" << std::endl;
        std::cin >> option;
        if (option == "login")
        {
            std::cout << "Your choose is login." << std::endl;
            std::cout << "Write your nickname: " << std::endl;
            std::cin >> nickname;
            std::cout << "Write your password: " << std::endl;
            std::cin >> password;
            loginSystem(nickname, password);
        }
        else if (option == "register")
        {
            std::cout << "Your choose is register." << std::endl;
            std::cout << "Write your nickname: " << std::endl;
            std::cin >> nickname;
            std::cout << "Write your password: " << std::endl;
            std::cin >> password;
            registerSystem(nickname, password);
        }
    }
}

int main()
{
    appEngine();
}

