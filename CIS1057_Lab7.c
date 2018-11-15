#include <stdio.h>
#include <ctype.h>

int main(void)
{

    char sentence[] = "This is a long sentence. It has many characters in it!";
    char input;
    size_t size = sizeof(sentence)/sizeof(sentence[0]);

    int index_place = 0;
    int index[size];

    printf("The characters are: ");
    for (int i = 0; i < size - 1; ++i) {
        printf("%c", sentence[i]);
    }

    printf("\nEnter a character to search for: ");
    scanf("%c", &input);

    for (int j = 0; j < size - 1; ++j) {
        if (tolower(sentence[j]) == tolower(input))
        {
            index[index_place++] = j;
        }
    }

    if (index_place == 0)
        printf("Not found");

    else {
        printf("That character appears at indicies ");
        for (int k = 0; k < index_place; ++k) {
            printf("%i ", index[k]);
        }
    }
    return 0;
}

