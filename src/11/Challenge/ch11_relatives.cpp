// C++ Code Challenges, LinkedIn Learning

// Challenge #11: Finding Relatives
// Write an application that reads a list of people's names in a CSV file and outputs the first pair of people it finds to be possibly related based on their family names.
// Assume that all entries have one name and one family name.
// Entries are separated by commas.
// Names and family names are separated by spaces.

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <bits/stdc++.h>

// Finding Relatives, main()
// Summary: This application displays the first pair of possible relatives from a list of names in a CSV file.
int main(){
    std::fstream file ("names.csv", std::ios::in);
    
    // Read the CSV file.
    std::vector<std::string> names;
    if(file.is_open()){

        // Write your code here
        std::string line ;

        while (std::getline(file, line)) {
            std::stringstream ss(line);
            std::string name;

            while (std::getline(ss, name, ',')) {
                names.push_back(name);
            }
        } 


        file.close();
    }
    else{
        std::cout << "Something went wrong\n" << std::flush;
        return 1;
    }

    // Write your code here
    std::vector<std::string> surnames;
    for (const auto& name : names) {

        
        std::stringstream ss(name);
        std::string firstName, surname;

        ss >> firstName;

        ss >> surname;
        surnames.push_back(surname);

    }

    std::string check = surnames[0];
    int index = 0;
    int indexF;
    for (int i=1; i < surnames.size(); i++) {
        
        auto it = find(surnames.begin() + i, surnames.end(), check);

        if (it != surnames.end()) {
            indexF = it - surnames.begin();
            break;
            
        } else {
            index++;
            check = surnames[index];
        }
    } 

    std::cout << "No relatives found.\n\n" << std::flush;  

    std::cout << "Relatives with similar surnames: " << names[index] << " and " << names[indexF] << std::endl << std::endl << std::flush;  
    return 0; 
}
 