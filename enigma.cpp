#include <iostream>
#include <string>
#include <algorithm>
#include <map>


struct Rotor {
    int position = 0;
    std::string permutation;

    void rotate () {
        position = (position + 1) % 26;
        std::rotate(permutation.begin(), permutation.begin() + 1, permutation.end());
    }
};

int main() {
    
    Rotor rotorI;
    rotorI.permutation = "dmtwsilruyqnkfejcazbpgxohv";
    Rotor rotorII;
    rotorII.permutation = "hqzgpjtmoblncifdyawveusrkx";
    Rotor rotorIII;
    rotorIII.permutation = "uqntlszfmrehdpxkibvygjcwoa";

    std::map<char, char> reflector {
        {'a', 'y'},
        {'b', 'r'},
        {'c', 'u'},
        {'d', 'h'},
        {'e', 'q'},
        {'f', 's'},
        {'g', 'l'},
        {'i', 'p'},
        {'j', 'x'},
        {'k', 'n'},
        {'m', 'o'},
        {'t', 'z'},
        {'v', 'w'},

        {'y', 'a'},
        {'r', 'b'},
        {'u', 'c'},
        {'h', 'd'},
        {'q', 'e'},
        {'s', 'f'},
        {'l', 'g'},
        {'p', 'i'},
        {'x', 'j'},
        {'n', 'k'},
        {'o', 'm'},
        {'z', 't'},
        {'w', 'v'},
    };

    // Get input
    std::string input;    
    std::cout << "Enter: ";
    std::cin >> input;

    std::string newWord;

    for (char const &c: input) { // Loop through string
        char newChar;
        int index;

        //std::cout << c << " -> "; 

        // Foward
        index = c - 'a'; 
        newChar = rotorI.permutation[index];

        index = newChar - 'a'; 
        newChar = rotorII.permutation[index];

        index = newChar - 'a'; 
        newChar = rotorIII.permutation[index];
        
        // Reflector
        newChar = reflector[newChar];
        
        // Backward
        index = rotorIII.permutation.find(newChar);
        newChar = 'a' + index;

        index = rotorII.permutation.find(newChar);
        newChar = 'a' + index;

        index = rotorI.permutation.find(newChar);
        newChar = 'a' + index;
        
        //std::cout << newChar << std::endl;

        // Rotate
        if (rotorI.position == 25) {
            rotorII.rotate();
            if (rotorII.position == 25) {
                rotorIII.rotate();
            }
        }

        rotorI.rotate();

        newWord += newChar;
        //std::cout << rotorI.position << " | " << rotorII.position << " | " << rotorIII.position  << std::endl;       
        //std::cout << "out: " << newWord << std::endl;
    }
    std::cout << std::endl;
    std::cout << "out: " << newWord << std::endl;    
    return 0;
}
