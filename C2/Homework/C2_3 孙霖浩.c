int mystrcmp(const char *s1, const char *s2)
{
    int i = 0;
    for (i = 0; (s1[i] != '\0') || (s2[i] != '\0'); i++)
    {
        if (s1[i] != s2[i])
        {
            if (s1[i] > s2[i])
                return 1;
            else
                return -1;
        }
    }
    return 0;
}