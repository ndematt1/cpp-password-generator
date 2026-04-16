# C++ Password Generator

A terminal-based password generator written in C++. Allows you to generate a randomized password with customizable length and character sets.

## Features

- Customizable password length
- Choose which character types to include (uppercase, lowercase, numbers, symbols)
- Input validation and error handling
- Seeded random generation using Mersenne Twister

## Requirements

- C++ compiler (g++)
- C++ standard library

## Compile

```
g++ main.cpp password_generator.cpp -o main
```

## Run

```
./main
```

## Example

```
Password Generator

Length (recommended 16+): 16
Include uppercase letters in your password? (1 = yes, 0 = no): 1
Include lowercase letters in your password? (1 = yes, 0 = no): 1
Include numbers in your password? (1 = yes, 0 = no): 1
Include symbols in your password? (1 = yes, 0 = no): 1

Your password: aB3$xK9!mZ2@qL7#
```

## Project Structure

```
main.cpp                 — entry point
password_generator.h     — function declarations
password_generator.cpp   — function definitions
```

## How It Works

The program prompts the user for a desired password length and which character types to include. It builds a pool of valid characters based on the selections, then uses a Mersenne Twister random number engine seeded with a hardware random device to sample characters from the pool.
