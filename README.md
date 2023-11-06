# Email Address Validator (C++)
This C++ program checks the validity of email addresses according to specific rules. It simulates a finite automaton with states and transitions to determine whether a given email address adheres to the specified format.

## Program Description
The program reads an email address as input and validates it character by character based on the rules. It checks for lowercase alphabets, digits, the '@' symbol, and specific sequences. If the email address adheres to the rules, it is accepted; otherwise, it is rejected.

## Program Flow
The program utilizes a finite automaton with various states:
- **State 1**: The initial state, checking for a lowercase alphabet character.
- **State 2**: Validating lowercase alphabets and digits.
- **State 3**: Ensuring a valid '@' symbol.
- **State 4**: Checking for lowercase alphabets.
- **State 5**: Checking for a specific email domain ('.com').
- **State 6-8**: Validating specific sequences 'co' and 'm' of the email domain.
- **Trap State (State 9)**: Used to handle invalid characters and transitions.

The program progresses from one state to another as it reads characters from the email address. If it reaches State 8 and the input is valid, it prints "String is accepted." If it reaches a trap state (State 9) or encounters an invalid character, it prints "String is rejected."

## Usage
1. Compile the C++ code using a C++ compiler.
2. Run the compiled program.
3. When prompted, enter an email address (only lowercase characters).
4. The program will validate the input email address character by character and print whether it is accepted or rejected.
5. You can enter multiple email addresses by responding with 'y' to the prompt until you decide to exit ('n').

## Additional Information
The program is designed for educational purposes to demonstrate the functioning of a finite automaton and its validation process. The rules for email validation are predefined and limited to the described states and transitions.
