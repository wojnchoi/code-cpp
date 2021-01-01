#ifndef CACHE_H
#define CACHE_H

#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stddef.h>
#include<stdlib.h>
#include<stdarg.h>
#include<errno.h>
#include<sys/mman.h>

#include<openssl/sha.h>
#include<zlib.h>

#define CACHE_SIGNATURE 0x44495243

struct cache_header {
	unsigned int signature;
	unsigned int version;
	unsigned int entries;
	unsigned char sha1[20];
};

struct cache_time {
	unsigned int sec;
	unsigned int nsec;
};

struct cache_entry {
	struct cache_time ctime;
	struct cache_time mtime;
	unsigned int st_dev;
	unsigned int st_ino;
	unsigned int st_mode;
	unsigned int st_uid;
	unsigned int st_gid;
	unsigned int st_size;
	unsigned char sha1[20];
	unsigned short namelen;
	unsigned char name[0];
};

const char* sha1_file_directory;
struct cache_entry** active_cache;
unsigned int active_nr, active_alloc;

#define DB_ENVIRONMENT "SHA1_FILE_DIRECTORY"
#define DEFAULT_DB_ENVIRONMENT ".dircache/objects"

#define cache_entry_size(len) ((offsetof(struct cache_entry,name) + (len) + 8) & ~7)
#define ce_size(ce) cache_entry_size((ce)->namelen)

#define alloc_nr(x) (((x)+16)*3/2)

extern int read_cache(void);

extern char* sha1_file_name(unsigned char* sha1);

extern int write_sha1_buffer(unsigned char* sha1, void* buf, unsigned int size);

extern void* read_sha1_file(unsigned char* sha1, char* type, unsigned long* size);
extern int write_sha1_file(char* buf, unsigned len);

extern int get_sha1_hex(char* hex, unsigned char* sha1);
extern char* sha1_to_hex(unsigned char* sha1);

extern void usage(const char* err);

#endif
