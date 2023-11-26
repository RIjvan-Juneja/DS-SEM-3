#include <stdio.h>

int string_length(const char *str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

void string_copy(char *dest, const char *src) {
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
}

void string_concat(char *dest, const char *src) {
    while (*dest != '\0') {
        dest++;
    }
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
}

int string_compare(const char *str1, const char *str2) {
    while (*str1 != '\0' && *str2 != '\0') {
        if (*str1 != *str2) {
            return 0; // Not equal
        }
        str1++;
        str2++;
    }
    return (*str1 == '\0' && *str2 == '\0');
}

int main() {
    const char *str1 = "Hello";
    const char *str2 = " World!";

    
    printf("Length of str1: %d\n", string_length(str1));

    char copy[20]; // Make sure the destination has enough space
    string_copy(copy, str1);
    printf("Copied string: %s\n", copy);

    char concatenated[50]; // Make sure the destination has enough space
    string_concat(concatenated, str1);
    string_concat(concatenated, str2);
    printf("Concatenated string: %s\n", concatenated);

    if (string_compare(str1, "Hello")) {
        printf("str1 is equal to 'Hello'.\n");
    } else {
        printf("str1 is not equal to 'Hello'.\n");
    }

    return 0;
}
