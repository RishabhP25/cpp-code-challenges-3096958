// C++ Code Challenges, LinkedIn Learning

// Challenge #8: IP Address Validation
// Write an application that reads a string from the terminal and responds with a message indicating whether the string is a valid IP address or not.
// Assume decimal IP addresses.
// 158.25.0.33
// All numbers between 0 and 255.

#include <iostream>
#include <sstream>
#include <vector>
#include <string>

// is_valid_ip()
// Summary: This function validates an IP address.
// Arguments:
//           ip: The string to analyze with a potential ip address.
// Returns: A boolean value. True for valid ip addresses, false otherwise.
bool is_valid_ip(std::string ip){

    // Write your code here
    std::stringstream ss(ip);
    std::vector<std::string> tokens;

    // Split the string using ","
    while (std::getline(ss, ip, '.')) {
        tokens.push_back(ip);
    }

    if (tokens.size() == 4) {
        for (const auto& token : tokens) {
            int part = std::stoi(token);
            if (part < 0 || part > 255) {
                return false;
            }
        }
        return true; 
    }

    return false;
}

// Main function
int main(){
    std::string s;
    
    std::cout << std::endl << "Enter an IP address in decimal: " << std::flush;
    std::getline(std::cin,s);
    std::cout << " \n" << s << (is_valid_ip(s) ? " is" : " is not" ) << " a valid IP address.\n\n";
    return 0;

}