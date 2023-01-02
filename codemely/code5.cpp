// code mely
// Chúc mừng năm mới
#include "bits/stdc++.h"

using namespace std;

int sum_of_digit(int n) {
    // hàm lấy tổng các chữ số
    int s = 0; // lưu tổng các chữ số;
    while (n > 0) {
        s += n % 10;
        n /= 10;
    }
    return s;
}

int sum_of_digit_square(int n) {
    // hàm lấy tổng bình phương các chữ số
    int s = 0; // lưu tổng bình phương các chữ số
    while (n > 0) {
        s += (n % 10) * (n % 10);
        n /= 10;
    }
    return s;
}

int main() {
    int max_number = 10000;

    cout << "Các số đặc biệt: " << endl;

    for (int number = 1; number <= max_number; number++) {
        // kiêm tra điều kiện và in ra số đó
        if (number % sum_of_digit(number) == 0
            && number % sum_of_digit_square(number) == 0) {
            cout << number << " ";
        }
    }

    return 0;
}