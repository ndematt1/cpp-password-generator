#include "password_generator.h"   // import the header file
#include <iostream>               // imports the I/O stream library
#include <string>                 // imports the std::string class
#include <random>                 // imports the random number generation library


int getPasswordLength(){
    int password_length;
    bool valid = false;
    do {  
        std::cout << "Length (recommended 16+): ";
        std::cin >> password_length;

        if (std::cin.fail() || std::cin.peek() != '\n'){ 
            std::cout << "Invalid input. Please enter an integer.\n ";
            std::cin.clear();
            std::cin.ignore();                                         
        }

        else if (password_length <= 0){ 
            std::cout << "Invalid password length. Please enter a value greater than zero.\n "; 
        }

        else {
            valid = true;                                             
        }

    } while (!valid);

    return password_length;
}


bool getYesNo(std::string prompt) {
    int input; 

    do {
        std::cout << prompt;
        std::cin >> input;

        if (std::cin.fail()) {                       
                std::cout << "Invalid input. Please enter 1 or 0.\n";
                std::cin.clear();                         
                std::cin.ignore();                        


        } else if (input != 0 && input != 1) {        
                std::cout << "Invalid input. Please enter 1 or 0.\n";
        }

    }while (std::cin.fail() || (input != 0 && input != 1));

    return input;
}


std::string generateCharacterPool(){
    std::string upper_char = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";      //create variable for uppercase letters
    std::string lower_char = "abcdefghijklmnopqrstuvwxyz";      //create variable for lowercase letters
    std::string numeric_char = "0123456789";                    //create variable for numeric values
    std::string symbolic_char = "!@#$%^&*()-_=+[]{}|;:,.<>?";   //create variable for special characters
    std::string character_pool;
    do {
        bool use_upper_char = getYesNo("Include uppercase letters in your password? \n(1 = yes, 0 = no): ");
        if (use_upper_char == true){character_pool += upper_char;}

        bool use_lower_char = getYesNo("Include lowercase letters in your password? \n(1 = yes, 0 = no): ");    
        if (use_lower_char == true){character_pool += lower_char;}

        bool use_numeric_char = getYesNo("Include numbers in your password? \n(1 = yes, 0 = no): ");
        if (use_numeric_char == true){character_pool += numeric_char;}

        bool use_symbolic_char = getYesNo("Include symbols in your password?\n(1 = yes, 0 = no): ");
        if (use_symbolic_char == true){character_pool += symbolic_char;}
        
        if (character_pool.length() == 0) {std::cout << "Please select at least one character type.\n";}
    } 
    while ( character_pool.length() == 0);

    return character_pool;
}


std::string generatePassword(std::string character_pool, int password_length){
    std::random_device rd; //generate random seed from the device 
    std::mt19937 gen(rd()); // mersenne twister engine seeded with rd
    std::uniform_int_distribution <> distr(0, character_pool.length() -1); // generate random index within the bounds of the pool
    
    std::string random_password; //declares the random password
    
    for (int i = 0; i < password_length; i++){ //loop the password for the amount of characters in the password 
        random_password += character_pool[distr(gen)]; //add a random character to the password
    }
    return random_password;
}