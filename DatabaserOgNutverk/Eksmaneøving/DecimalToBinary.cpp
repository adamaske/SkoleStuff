#include <cstdio>
#include <cmath>
char* dec_to_bin(unsigned int d);
char* dec_to_bin_2(unsigned int d);
int main()
{
    unsigned int d = 9287;
    char *b = dec_to_bin(d);
    printf("%d = %s\n", d, b);
    b = dec_to_bin_2(d);
    printf("%d = %s\n", d, b);
    delete b;
    return 0;
}
char* dec_to_bin(unsigned int d)
{
    int len = (int) ((log( (double) d)) / log(2.0)) + 2;
    char *b = new char[len];
    b[len - 1] = '\0';
    int i = len - 2;
    while (d > 0) {
        if (d % 2 == 1) b[i] = '1';
    else b[i] = '0';
        i--;
        d /= 2;
    }
    return b;
}
// Med bitvise operatorer
char* dec_to_bin_2(unsigned int d)
{
    int len = (int) ((log( (double) d)) / log(2.0)) + 2;
    char *b = new char[len];
    b[len - 1] = '\0';
    int i = len - 2;
    int maske = 1;
    while (d > 0) {
        if ((d & maske) == 1) b[i] = '1';
        else b[i] = '0';
        i--;
        d >>= 1;
    }
    return b;
}