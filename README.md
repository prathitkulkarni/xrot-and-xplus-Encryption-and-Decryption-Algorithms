# Xrot and Xplus Encryption and Decryption Algorithms

This project implements two custom encryption and decryption algorithms in C: Xrot and Xplus. The algorithms are designed to provide basic cryptographic functionality using simple transformation methods. 

## Features

- **Xrot Algorithm:** Encrypts and decrypts data using XOR operations with a key derived from the password.
- **Xplus Algorithm:** Encrypts and decrypts data by adding or subtracting values derived from the password.
- File-based encryption and decryption: Processes text files to apply the encryption/decryption algorithms.

## Algorithms

1. **Xrot Encryption/Decryption:**
   - Uses XOR operations to encrypt and decrypt text.
   - Key is derived from the provided password.

2. **Xplus Encryption/Decryption:**
   - Uses addition and subtraction to encrypt and decrypt text.
   - Key is derived from the provided password.

## Tech Stack

- **Programming Language:** C
- **Libraries:** Standard C Library

## Usage

To use the application, compile the code and run the executable with appropriate arguments.

### Compilation

```bash
gcc -o encryption_decryption encryption_decryption.c
