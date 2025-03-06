# Programmable Finite State Machine (FSM)

This project implements a programmable finite state machine (FSM) capable of handling a variety of string patterns and validation tasks. The FSM is designed to be flexible, allowing users to specify different sequences and conditions for validation.

## Implemented FSMs:

1. **Alternate Binary FSM**  
   - Example inputs: `"010101010101\0"`, `"0100101111\0"`

2. **FSM Accepting 00 or 11 at the End**  
   - Example inputs: `"01010100\0"`, `"000111010\0"`, `"00ahmad0111010\0"`

3. **FSM Accepting 'aa' or 'bb' at the End**  
   - Example input: `"aababaabbbaaabbabababb\0"`

4. **FSM Accepting Odd Number of Ones**  
   - Example inputs: `"01100000001\0"`, `"111\0"`, `"01100001001\0"`

5. **Balanced Parenthesis with Up to Three Nested Levels**  
   - Example inputs: `"((()))\0"`, `"(((())))\0"`, `"(()\0"`, `"()()()()\0"`, `"(())()()()(\0"`, `"(())()()())\0"`

6. **FSM Accepting 6-Digit Phone Numbers**  
   - Example inputs: `"12356"`, `"12ahmad0"`, `"666123"`

7. **FSM Accepting Valid Email Addresses**  
   - Example inputs:  
     `"ahmadmfsaleh@gmail.com"`, `"ali@gmail.com"`, `"ali1@hotmail.com"`, `"ali123@yahoo.com"`, `"yousef12434343@gmail.com"`, `"ali123@hotmail.com"`, `"abc"`

8. **Optimized FSM for Valid Email Addresses**  
   - Example inputs: Same as the above email tests.

9. **FSM for Binary Strings and Two’s Complement Output**  
   - Example inputs:  
     `"111111"`, `"000000"`, `"000101"`, `"00010001"`

10. **FSM for Binary Strings and Hexadecimal Output**  
    - Example inputs:  
      `"1000"`, `"1110"`, `"101101110101"`

11. **FSM Accepting Valid Passwords**  
    - Example inputs:  
      `"ahmad27032001"`, `"ahmd27032001"`, `"ahmd270320013"`

## Features:
- The FSM can handle a variety of input types, from binary strings to email and phone number validation.
- Each FSM is designed to either accept or reject specific patterns based on predefined conditions.
- Optimized versions for certain FSMs, like email validation, provide improved efficiency.

Feel free to use and extend this FSM implementation for your own needs!
