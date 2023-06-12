#include <iostream>
#include <fstream>
using namespace std;

string encrypt(string text, int shift) {
    string result = "";
    for (char& c : text) {
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            c = ((c - base + shift) % 26) + base;
        }
        result += c;
    }
    return result;
}

string decrypt(string text, int shift) {
    return encrypt(text, 26 - shift);
}

void encryptFile(const string& inputFile, const string& outputFile, int shift) {
    ifstream file(inputFile);
    ofstream encryptedFile(outputFile);
    string line;
    while (getline(file, line)) {
        encryptedFile << encrypt(line, shift) << endl;
    }
    file.close();
    encryptedFile.close();
    cout << "File encrypted successfully!" << endl;
}

void decryptFile(const string& inputFile, const string& outputFile, int shift) {
    ifstream encryptedFile(inputFile);
    ofstream decryptedFile(outputFile);
    string line;
    while (getline(encryptedFile, line)) {
        decryptedFile << decrypt(line, shift) << endl;
    }
    encryptedFile.close();
    decryptedFile.close();
    cout << "File decrypted successfully!" << endl;
}

int main() {
    string inputFile, outputFile;
    int shift;
    char choice;
    
    cout << "Enter input file name: ";
    cin >> inputFile;
    cout << "Enter output file name: ";
    cin >> outputFile;
    cout << "Enter shift value: ";
    cin >> shift;
    
    cout << "Encrypt (E) or Decrypt (D)?: ";
    cin >> choice;
    
    if (choice == 'E' || choice == 'e') {
        encryptFile(inputFile, outputFile, shift);
    } else if (choice == 'D' || choice == 'd') {
        decryptFile(inputFile, outputFile, shift);
    } else {
        cout << "Invalid choice! Exiting..." << endl;
    }
    
    return 0;
}
