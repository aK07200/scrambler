#include <iostream>

bool step_encode(int i, bool* a1, bool* a2) {
    if (i < 5)
        return a1[i];
    else if (i < 9)
        return (a1[i] xor a2[i - 5]);
    else if (i < 11)
        return (a1[i] xor a2[i - 5] xor a2[i - 9]);
    else
        return (a1[i] xor a2[i - 5] xor a2[i - 9] xor a2[i - 11]);;
}

std::string encode(std::string letter) {
    bool *arr = new bool[sizeof(letter)], *ans = new bool[sizeof(letter)];
    for (int i = 0; i < letter.size(); i++) {
        if (letter[i] == '1') arr[i] = true;
        else if (letter[i] == '0') arr[i] = false;
        else {
            std::cout << "Fatal err: non-binary code.";
            exit(-1);
        }
    }
    for (int i = 0; i < letter.size(); i++) {
        ans[i] = step_encode(i, arr, ans);
    }
    std::string to_return = "";
    for (int i = 0; i < letter.size(); i++) {
        if (ans[i] == true) to_return.push_back('1');
        else to_return.push_back('0');
    }
    return to_return;
}

bool step_decode(int i, bool* a1) {
    if (i < 5)
        return a1[i];
    else if (i < 9)
        return (a1[i] xor a1[i - 5]);
      else if (i < 11)
        return (a1[i] xor a1[i - 5] xor a1[i - 9]);
    else
        return (a1[i] xor a1[i - 5] xor a1[i - 9] xor a1[i - 11]);;
}

std::string decode(std::string letter) {
    bool* arr = new bool[sizeof(letter)], * ans = new bool[sizeof(letter)];
    for (int i = 0; i < letter.size(); i++) {
        if (letter[i] == '1') arr[i] = true;
        else if (letter[i] == '0') arr[i] = false;
        else {
            std::cout << "Fatal err: non-binary code.";
            exit(-1);
        }
    }
    for (int i = 0; i < letter.size(); i++) {
        ans[i] = step_decode(i, arr);
    }
    std::string to_return = "";
    for (int i = 0; i < letter.size(); i++) {
        if (ans[i] == true) to_return.push_back('1');
        else to_return.push_back('0');
    }
  return to_return;
}

int main() {
    std::cout << "\nВведите исходное сообщение: ";
    std::string input; std::cin >> (input);
    std::cout << "\nСкремблер: " << encode(input);
    std::cout << "\nДескремблер: " << decode(input);
    if (encode(decode(input)) == input) std::cout << "\nФункции работают стабильно.\n\n";
    else std::cout << "\nФункции несиправны.\n\n";
    return 0;
}
