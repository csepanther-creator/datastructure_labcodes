
#include <iostream>
#include <string>
std::string concat(const std::string& str, const char arr[]) {
    std::string result;
    for (size_t i = 0; i < str.length(); ++i) {
        result += str[i];
    }
    for (size_t i = 0; arr[i] != '\0'; ++i) {
        result += arr[i];
    }

    return result;
}

int main() {
    std::string s = "Hello ";
    char arr[] = "World";
    std::string combined = concat(s, arr);
    std::cout << combined << std::endl;  
    return 0;
}


#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string str = "Hello World";
    cout << "Original string: " << str << endl;
    reverse(str.begin(), str.end());
    cout << "Reversed string: " << str << endl;
    return 0;
}


#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool isVowel(char c) {
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main() {
    string str = "This is a sample string";
    string result;
    for (char c : str) {
        if (!isVowel(c))
            result += c;
    }
    cout << "String without vowels: " << result << endl;
    return 0;
}


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    vector<string> arr = {"banana", "apple", "cherry", "date"};
    sort(arr.begin(), arr.end());
    cout << "Sorted strings: ";
    for (const auto &s : arr) {
        cout << s << " ";
    }
    cout << endl;
    return 0;
}


#include <iostream>
#include <cctype>
using namespace std;

int main() {
    char ch = 'A';
    char lower = tolower(ch);
    cout << "Lowercase of " << ch << " is " << lower << endl;
    return 0;
}
#include <iostream>
#include <cctype>
using namespace std;

int main() {
    char ch = 'A';
    char lower = tolower(ch);
    cout << "Lowercase of " << ch << " is " << lower << endl;
    return 0;
}
