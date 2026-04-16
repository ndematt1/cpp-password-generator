#include <iostream>
#include "password_generator.h"

int main(){    
                                                     
    std::cout << "Password Generator \n";
    int password_length = getPasswordLength();
    std::string character_pool = generateCharacterPool();
    std::string generated_password = generatePassword(character_pool,password_length);
    std::cout << "\nYour password: " << generated_password << "\n";

    return 0; 
}
