#include <iostream>
#include <string>

void lcsAlgo(std::string S1, std::string S2, int m, int n) {
    int LCS_table[m + 1][n + 1];
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                LCS_table[i][j] = 0;
            } else if (S1[i - 1] == S2[j - 1]) {
                LCS_table[i][j] = LCS_table[i - 1][j - 1] + 1;
            } else {
                LCS_table[i][j] = std::max(LCS_table[i - 1][j], LCS_table[i][j - 1]);
            }
        }
    }

    int index = LCS_table[m][n];
    char lcs[index + 1];
    lcs[index] = '\0';

    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (S1[i - 1] == S2[j - 1]) {
            lcs[index - 1] = S1[i - 1];
            --i;
            --j;
            --index;
        } else if (LCS_table[i - 1][j] > LCS_table[i][j - 1]) {
            --i;
        } else {
            --j;
        }
    }
    std::cout << "S1 : " << S1 << "\nS2 : " << S2 << "\nLCS: " << lcs << "\n";
}

int main() {

    setlocale(LC_ALL, "");
    std::string S1;
    std::string S2;
    std::wcout << L"Введите первую строку: ";
    std::cin >> S1;
    std::wcout << L"Введите вторую строку: ";
    std::cin >> S2;

    int m = S1.length();
    int n = S2.length();
    lcsAlgo(S1, S2, m, n);
}