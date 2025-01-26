#include <stdio.h>
#include <stdlib.h>

int main()
{
    char ch;
    system("cls");
    printf("Enter an character : ");
    scanf("%c", &ch);
    switch (ch)
    {
    case 'A':
    case 'a':
        printf("\n %c is Vowel", ch);
        break;
    case 'E':
    case 'e':
        printf("\n %c is Vowel", ch);
        break;
    case 'I':
    case 'i':
        printf("\n %c is Vowel", ch);
        break;
    case 'O':
    case 'o':
        printf("\n %c is Vowel", ch);
        break;
    case 'U':
    case 'u':
        printf("\n %c is Vowel", ch);
        break;
    default:
        printf("\n %c is Not a vowel", ch);
        break;
    }
    return 0;
}