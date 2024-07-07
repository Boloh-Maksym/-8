#include <stdio.h>
#include <string.h>


unsigned long long factorial(int n) {
    unsigned long long result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}


unsigned long long count_anagrams(const char *word) {
    int len = strlen(word);
    unsigned long long total_permutations = factorial(len);

    int letter_counts[256] = {0};


    for (int i = 0; i < len; i++) {
        letter_counts[(unsigned char)word[i]]++;
    }

    for (int i = 0; i < 256; i++) {
        if (letter_counts[i] > 0) {
            total_permutations /= factorial(letter_counts[i]);
        }
    }

    return total_permutations;
}

int main() {
    char word[15];
    printf("Введіть слово: ");
    scanf("%14s", word);

    unsigned long long anagrams_count = count_anagrams(word);
    printf("Кількість анаграм: %llu\n", anagrams_count);

    return 0;
}
