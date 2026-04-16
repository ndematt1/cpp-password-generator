#ifndef PASSWORD_GENERATOR_H    
#define PASSWORD_GENERATOR_H

#include <string>               

/**
 * @brief Prompts the user for a password length and validates the input
 * @return A valid integer greater than zero
 */
int getPasswordLength();

/**
 * @brief Prompts the user with a yes/no question and validates the input
 * @param  prompt prompt that is being asked; it will be displayed to the user
 * @return true if the user entered 1, false if 0
 */
bool getYesNo(std::string prompt);

/**
 * @brief generates character pool for the password. prompts the user which characters they would like to include
 * @return returns the pool of characters
 */
std::string generateCharacterPool();

/**
 * @brief Generates a random password from the given character pool and desired password length
 * @param character_pool The pool of characters to sample from
 * @param password_length The desired length of the password
 * @return A randomly generated password string
 */
std::string generatePassword(std::string character_pool, int password_length);

#endif                          