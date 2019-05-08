#include <stdio.h>
#include <unistd.h>

void print_bar(unsigned int curPos, unsigned int total, char *c)
{
    printf("\r");
    int offset = curPos*50/total;
    for(int i = 0; i < offset; i++)
        printf("%s", c);
    for (int i = offset; i < 50; i++)
        printf(" ");
    printf(" [%d%%]", curPos*100/total);
    fflush(stdout);
}

int main()
{
    int i;
    for (i=0; i<100; i++)
    {
        print_bar(i+1, 100, "■");
        usleep(100000);
    }
    printf("\n");
    return 0;
}
