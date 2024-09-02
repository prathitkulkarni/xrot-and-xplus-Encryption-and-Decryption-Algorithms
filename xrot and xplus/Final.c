#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isValidPassword(const char* password)
{
    return strcmp(password, "1234") == 0;
}

void xplusEncryption(const char* filename, const char* str)
{
    char ch;
    FILE* fps, * fpq;
    int count = 0;
    int len = strlen(str);

    fps = fopen(filename, "r");
    fpq = fopen("output_encrypted.txt", "w");
    if (fps == NULL || fpq == NULL)
    {
        printf("Error opening files.\n");
        return;
    }

    while ((ch = fgetc(fps)) != EOF)
    {
        count++;
    }

    fseek(fps, 0, SEEK_SET);

    char result[len * (count / len + 1) + 1];
    result[0] = '\0';
    for (int i = 0; i < count / len; i++)
    {
        strcat(result, str);
    }
    strncat(result, str, count % len);

    for (int i = 0; i < count; i++)
    {
        ch = fgetc(fps);
        ch += (i + 1) * (result[i] - '0');
        fputc(ch, fpq);
    }

    fclose(fps);
    fclose(fpq);
    printf("\nFile %s Encrypted Successfully!\n", filename);
}

void xplusDecryption(const char* filename, const char* str)
{
    char ch;
    FILE* fps, * fpq;
    int count = 0;
    int len = strlen(str);

    fps = fopen(filename, "r");
    fpq = fopen("output_decrypted.txt", "w");
    if (fps == NULL || fpq == NULL)
    {
        printf("Error opening files.\n");
        return;
    }

    while ((ch = fgetc(fps)) != EOF)
    {
        count++;
    }

    fseek(fps, 0, SEEK_SET);

    char result[len * (count / len + 1) + 1];
    result[0] = '\0';
    for (int i = 0; i < count / len; i++)
    {
        strcat(result, str);
    }
    strncat(result, str, count % len);

    for (int i = 0; i < count; i++)
    {
        ch = fgetc(fps);
        ch -= (i + 1) * (result[i] - '0');
        fputc(ch, fpq);
    }

    fclose(fps);
    fclose(fpq);
    printf("\nFile %s Decrypted Successfully!\n", filename);
}

void xrotEncryption(const char* filename, const char* str)
{
    char ch;
    FILE* fps, * fpq;
    int count = 0;
    int len = strlen(str);

    fps = fopen(filename, "r");
    fpq = fopen("output_xrot_encrypted.txt", "w");
    if (fps == NULL || fpq == NULL)
    {
        printf("Error opening files.\n");
        return;
    }

    while ((ch = fgetc(fps)) != EOF)
    {
        count++;
    }

    fseek(fps, 0, SEEK_SET);

    char result[len * (count / len + 1) + 1];
    result[0] = '\0';
    for (int i = 0; i < count / len; i++)
    {
        strcat(result, str);
    }
    strncat(result, str, count % len);

    for (int i = 0; i < count; i++)
    {
        ch = fgetc(fps);
        ch ^= result[i] - '0'; 
        fputc(ch, fpq);
    }

    fclose(fps);
    fclose(fpq);
    printf("\nFile %s Encrypted Successfully!\n", filename);
}

void xrotDecryption(const char* filename, const char* str)
{
    char ch;
    FILE* fps, * fpq;
    int count = 0;
    int len = strlen(str);

    fps = fopen(filename, "r");
    fpq = fopen("output_xrot_decrypted.txt", "w");
    if (fps == NULL || fpq == NULL)
    {
        printf("Error opening files.\n");
        return;
    }

    while ((ch = fgetc(fps)) != EOF)
    {
        count++;
    }

    fseek(fps, 0, SEEK_SET);

    char result[len * (count / len + 1) + 1];
    result[0] = '\0';
    for (int i = 0; i < count / len; i++)
    {
        strcat(result, str);
    }
    strncat(result, str, count % len);

    for (int i = 0; i < count; i++)
    {
        ch = fgetc(fps);
        ch ^= result[i] - '0'; 
        fputc(ch, fpq);
    }

    fclose(fps);
    fclose(fpq);
    printf("\nFile %s Decrypted Successfully!\n", filename);
}

int main(int argc, char* argv[])
{
    if (argc != 5)
    {
        printf("Usage: %s --encrypt/--decrypt --xrot/--xplus password input_file\n", argv[0]);
        return 1;
    }

    char* mode = argv[1];
    char* algorithm = argv[2];
    char* password = argv[3];
    char* filename = argv[4];

    if (strcmp(mode, "--encrypt") != 0 && strcmp(mode, "--decrypt") != 0)
    {
        printf("Invalid mode. Use --encrypt or --decrypt.\n");
        return 1;
    }

    if (strcmp(algorithm, "--xrot") != 0 && strcmp(algorithm, "--xplus") != 0)
    {
        printf("Invalid algorithm. Use --xrot or --xplus.\n");
        return 1;
    }

    if (!isValidPassword(password))
    {
        printf("Incorrect password. Program stopped.\n");
        return 1;
    }

    if (strcmp(mode, "--encrypt") == 0)
    {
        if (strcmp(algorithm, "--xrot") == 0)
        {
            xrotEncryption(filename, password);
        }
        else if (strcmp(algorithm, "--xplus") == 0)
        {
            xplusEncryption(filename, password);
        }
    }
    else if (strcmp(mode, "--decrypt") == 0)
    {
        if (strcmp(algorithm, "--xrot") == 0)
        {
            xrotDecryption(filename, password);
        }
        else if (strcmp(algorithm, "--xplus") == 0)
        {
            xplusDecryption(filename, password);
        }
    }

    return 0;
}
