char *generate_password(void)
{
    char *charset = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    int charset_length = 62;  /* Length of the charset */
    int password_length = 10; /* Desired password length */
    char *password = malloc((password_length + 1) * sizeof(char));

    if (password == NULL)
    {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    srand(time(NULL));

    int i; // Move declaration here
    for (i = 0; i < password_length; i++)
    {
        int random_index = rand() % charset_length;
        password[i] = charset[random_index];
    }

    password[password_length] = '\0'; /* Null-terminate the string */

    return password;
}
