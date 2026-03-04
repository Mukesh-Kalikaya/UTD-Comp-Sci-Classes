/* This program reads grocery product records from a file and validates each 
field. It checks PLU codes, product names, sales types, prices, and inventory 
levels. The program reports whether the file has valid or invalid content. */
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

// Function Prototypes
string tokenize(string &s);
bool isValidPrice(string price);
bool isValidPLU(string plu);
bool isValidProductName(string name);
bool isValidSalesType(string type);
bool isValidInventory(string inventory);

int main() {
    // Define variables
    string filename;
    string line;
    string token;
    int tokenCount;
    int recordCount = 0;
    ifstream inputFile;

    // Get filename from user
    cout << "Enter input file:";
    cin >> filename;
    cout << endl;

    // Open the file
    inputFile.open(filename);

    // Check if file opened successfully
    if (!inputFile) {
        cout << "Error: Cannot open file" << endl;
        return 1;
    }

    // Print header with filename
    cout << "Checking " << filename << endl;
    for (int i = 0; i < filename.length() + 9; i++) {
        cout << "-";
    }
    cout << endl << endl;

    // Read file line by line
    while (getline(inputFile, line)) {
        if (line.empty()) {
            continue;
        }

        tokenCount = 0;
        bool recordValid = true;

        // Extract and validate each token
        while (!line.empty()) {
            // Get the next token
            token = tokenize(line);

            // If no token found, break
            if (token.empty()) {
                break;
            }

            tokenCount++;

            // Check if too many items
            if (tokenCount > 5) {
                cout << "Token #" << tokenCount << " is " << token 
                     << ", Too many items in record" << endl;
                recordValid = false;
                break;
            }

            // Validate based on token position
            if (tokenCount == 1) {
                // Validate PLU
                if (isValidPLU(token)) {
                    cout << "Token #1 is " << token << ", PLU is valid" << endl;
                } else {
                    cout << "Token #1 is " << token << ", PLU is invalid" << endl;
                    recordValid = false;
                    break;
                }
            } else if (tokenCount == 2) {
                // Validate Product Name
                if (isValidProductName(token)) {
                    cout << "Token #2 is " << token 
                         << ", Product name is valid" << endl;
                } else {
                    cout << "Token #2 is " << token 
                         << ", Product name is invalid" << endl;
                    recordValid = false;
                    break;
                }
            } else if (tokenCount == 3) {
                // Validate Sales Type
                if (isValidSalesType(token)) {
                    cout << "Token #3 is " << token 
                         << ", Sales type is valid" << endl;
                } else {
                    cout << "Token #3 is " << token 
                         << ", Sales type is invalid" << endl;
                    recordValid = false;
                    break;
                }
            } else if (tokenCount == 4) {
                // Validate Price
                if (isValidPrice(token)) {
                    cout << "Token #4 is " << token << ", Price is valid" << endl;
                } else {
                    cout << "Token #4 is " << token 
                         << ", Price is invalid" << endl;
                    recordValid = false;
                    break;
                }
            } else if (tokenCount == 5) {
                // Validate Inventory
                if (isValidInventory(token)) {
                    cout << "Token #5 is " << token 
                         << ", Inventory is valid" << endl;
                } else {
                    cout << "Token #5 is " << token 
                         << ", Inventory is invalid" << endl;
                    recordValid = false;
                    break;
                }
            }
        }

        // Check if record has exactly 5 items
        if (recordValid && tokenCount < 5) {
            cout << "Inventory is invalid, record has missing items" << endl;
            recordValid = false;
        }

        // If record is invalid, close and report
        if (!recordValid) {
            inputFile.close();
            cout << endl << "######## " << filename 
                 << " has invalid content ########" << endl;
            return 0;
        }

        // Print blank line between records
        cout << endl;
    }

    // All records are valid
    inputFile.close();
    cout << "######## " << filename 
         << " has valid content ########" << endl;

    return 0;
}

/* tokenize removes leading delimiters from the string and extracts the first 
token. It returns the token and modifies the original string by removing the 
processed characters. Delimiters are space, tab, newline, and carriage return. */
string tokenize(string &s) {
    string token = "";
    int i = 0;

    // Remove leading delimiters
    while (i < s.length() && (s[i] == ' ' || s[i] == '\t' 
           || s[i] == '\n' || s[i] == '\r')) {
        i++;
    }

    // Extract the token
    while (i < s.length() && s[i] != ' ' && s[i] != '\t' 
           && s[i] != '\n' && s[i] != '\r') {
        token += s[i];
        i++;
    }

    // Delete processed characters from the string
    s = s.substr(i);

    return token;
}

/* isValidPrice checks if a price string is valid. A valid price contains 
only digits and at most one dot, with at most two digits after the dot. */
bool isValidPrice(string price) {
    int dotCount = 0;
    int dotsPosition = -1;

    // Check for empty string
    if (price.empty()) {
        return false;
    }

    // Count dots and check characters
    for (int i = 0; i < price.length(); i++) {
        if (price[i] == '.') {
            dotCount++;
            dotsPosition = i;
            if (dotCount > 1) {
                return false;
            }
        } else if (!isdigit(price[i])) {
            return false;
        }
    }

    // If there is a dot, check digits after it
    if (dotCount == 1) {
        int digitsAfterDot = price.length() - dotsPosition - 1;
        if (digitsAfterDot > 2) {
            return false;
        }
    }

    return true;
}

/* isValidPLU checks if a PLU code is valid. It must be exactly 4 characters 
long and contain only letters and digits. */
bool isValidPLU(string plu) {
    if (plu.length() != 4) {
        return false;
    }

    for (int i = 0; i < plu.length(); i++) {
        if (!isalnum(plu[i])) {
            return false;
        }
    }

    return true;
}

/* isValidProductName checks if a product name is valid. It must start with 
a letter. */
bool isValidProductName(string name) {
    if (name.empty()) {
        return false;
    }

    return isalpha(name[0]);
}

/* isValidSalesType checks if a sales type is valid. It must be exactly one 
character and be either 0 or 1. */
bool isValidSalesType(string type) {
    if (type.length() != 1) {
        return false;
    }

    return (type[0] == '0' || type[0] == '1');
}

/* isValidInventory checks if an inventory level is valid. It must contain 
only digits. */
bool isValidInventory(string inventory) {
    if (inventory.empty()) {
        return false;
    }

    for (int i = 0; i < inventory.length(); i++) {
        if (!isdigit(inventory[i])) {
            return false;
        }
    }

    return true;
}
