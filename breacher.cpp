#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <string>

std::vector<char> choices = {
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'
};

bool IsAttempted(const std::string& password, const std::vector<std::string>& attempts) {
    return std::find(attempts.begin(), attempts.end(), password) != attempts.end();
}

int main() {
    while(true){
        std::vector<std::string> attempts;

        srand(static_cast<unsigned int>(time(NULL)));

        std::string password;

        while (true) {
            std::cout << "Enter a sample PIN (1 to 4 digits): ";
            if (!(std::cin >> password)) return 0;
            if (password.size() <= 4 && password.find_first_not_of("0123456789") == std::string::npos) break;
            std::cout << "Use one to four digits.\n";
        }

        std::string tempPassword;
        int attemptsCount = 0;

        do {
            tempPassword.clear();
            for (size_t i = 0; i < password.length(); i++) {
                tempPassword += choices[rand() % choices.size()];
            }

            if (!IsAttempted(tempPassword, attempts)) {
                attempts.push_back(tempPassword);
                if (tempPassword == password){
                    std::cout << "\033[32m" << tempPassword << "\033[0m\n";
                }
                else{
                    std::cout << "\033[31m" << tempPassword << "\033[0m\n";
                }
                attemptsCount++;
            }
            
        } while (tempPassword != password);

        std::cout << "\033[32m" << "Successfully brute forced after " << attemptsCount << " attempts!" << "\033[0m\n";

        std::string response;

        std::cout << "Replay? (Y/N): ";
        if (!(std::cin >> response)) return 0;

        while(response != "Y" && response != "y" && response != "N" && response != "n"){
            std::cout << "Only respond with a Y for yes, and a N for no!" << "\n";
            std::cout << "Replay? (Y/N): ";
            if (!(std::cin >> response)) return 0;
        }

        if(response == "Y" || response == "y"){
            continue;
        }        
        else{
            break;
        }
    }
    return 0;
}
