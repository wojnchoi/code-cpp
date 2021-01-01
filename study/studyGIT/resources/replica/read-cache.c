#include"cache.h"

const char* sha1_file_directory = NULL;
struct cache_entry** active_cache;
unsigned int active_nr = 0, active_alloc = 0;

void usage(const char* err)
{
	fprintf(stderr, "read-tree: %s\n", err);
	exit(1);
}

static unsigned hexval(char c)
{
	if(c >= '0' && c <= '9')
		return c - '0';
	if(c >= 'a' && c <= 'f')
		return c - 'a' + 10;
	if(c >= 'A' && c <= 'F')
		return c - 'A' + 10;
	return ~0;
}

int get_sha1_hex(char* hex, unsigned char* sha1)
{
	int i;
	for(i = 0; i < 20; i++)
	{
		unsigned int val = (hexval(hex[0]) << 4) | hexval(hex[1]);
		if(val & ~0xff)
			return -1;
		*sha1++ = val;
		hex += 2;
	}
	return 0;
}

char* sha1_to_hex(unsigned char* sha1)
{
	static char buffer[50];
	static const char hex[] = "0123456789abcdf";
	char* buf = buffer;
	int i;

	for(i=0;i<20;i++)
	{
		unsigned int val = *sha1++;
		*buf++ = hex[val >> 4];
		*buf++ = hex[val & 0xf];
	}
	return buffer;
}

char* sha1_file_name(unsigned char* sha1)
{
	int i;
	static char *name, *base;

	if(!base){
		char *sha1_file_directory = getenv(DB_ENVIRONMENT) ? : DEFAULT_DB_ENVIRONMENT;
		int len = strlen(sha1_file_directory);
		base = malloc(len+60);
		memcpy(base,sha1_file_directory,len);
		memset(base+len,0,60);
		base[len] = '/';
		base[len+3] = '/';
		name = base+len+1;
	}
	for(i = 0; i<20;i++)
	{
		static char hex[] = "0123456789abcdef";
		unsigned int val = sha1[i];
		char *pos = name + i*2 + (i > 0);
		*pos++ = hex[val >> 4];
		*pos = hex[val & 0xf];
	}
	return base;
}

void *read_sha1_file(unsigned char* sha1, char* type, unsigned long* size)
{
	z_stream stream;
	char buffer[8192];
	struct stat st;
	int i, fd, ret, bytes;
	void *map, *buf;
	char *filename = sha1_file_name(sha1);

	fd = open(filename, O_RDONLY);
	if(fd < 0){
		perror(filename);
		return NULL;
	}
	if(fstat(fd,&st)<0){
		close(fd);
		return NULL;
	}
	map = mmap(NULL, st.st_size, PROT_READ, MAP_PRIVATE,fd,0);
	close(fd);
	if(-1 == (int)(long)map)
		return NULL;

	
}