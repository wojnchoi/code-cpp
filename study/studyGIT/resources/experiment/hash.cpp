#include<iostream>
unsigned long hash(unsigned char *str)
{
    unsigned long hash = 5381;
    int c;

    while (c = *str++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash;
}

int main(int argc, char *argv[])
{
    unsigned char sha1[20] = "workingdir";
    std::cout<<hash(sha1)<<std::endl;
    return 0;
}