#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define DB_ENVIRONMENT "SHA1_FILE_DIRECTORY"
#define DEFAULT_DB_ENVIRONMENT ".dircache/objects"
    char *hex = "abcdef39";
    unsigned char sha1[20];
static unsigned hexval(char c) {
    if( c >= '0' && c <= '9') //0 through 9
        return c - '0';
    if( c >= 'a' && c <= 'f') // 10 through 15
        return c - 'a' + 10;
    if( c >= 'A' && c <= 'F') //same but capital
        return c - 'A' + 10;
    return ~0; // -1
}
int get_sha1_hex(char *hex, unsigned char *sha1) {
    int i;
    for(i = 0; i < 20; i++) {
        unsigned int val = (hexval(hex[0]) << 4) | hexval(hex[1]);
        if(val & ~0xff)
            return -1;
        *sha1++ = val;
        hex += 2;
    }
    return 0;
}
char *sha1_to_hex(unsigned char *sha1) {
    static char buffer[50];
    static const char hex[] = "0123456789abcdef";
    char *buf = buffer;
    int i;

    for(i = 0; i<20;i++) {
        unsigned int val = *sha1++;
        *buf++ = hex[val >> 4];
        *buf++ = hex[val & 0xf];
    }
    return buffer;
}
char *sha1_file_name(unsigned char *sha1) {
    int i;
    static char *name, *base;
    if(!base) {
        char *sha1_file_directory = getenv(DB_ENVIRONMENT) ? : DEFAULT_DB_ENVIRONMENT;
        int len = strlen(sha1_file_directory);
        base = malloc(len +60);
        memcpy(base,sha1_file_directory,len);
        memset(base+len,0,60);
        base[len] = '/';
        base[len+3] = '/';
        name = base + len + 1;
    }
    for(i = 0; i <20; i++) {
        static char hex[] = "0123456789abcdef";
        unsigned int val = sha1[i];
        char *pos = name+i*2+(i>2);
        *pos++ = hex[val >> 4];
        *pos = hex[val & 0xf];
    }
    return base;
};
int main(int argc, char **argv) {
    printf("%d\n", get_sha1_hex(hex, sha1));
    printf("%s\n", hex);
    printf("%s\n", sha1);
    printf("%s\n", sha1_to_hex(sha1));
    printf("%s\n", sha1_file_name(sha1));
    return 0;
}