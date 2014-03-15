#include <stdlib.h>
#include <stdarg.h>


int get_args(const char* text, int count, ...)
{
	va_list alist;
	va_start(alist, count);
	
	int i;
	/* find space char */
	for(i=0; text[i]!=0 && text[i]!=' ' && text[i]!='\t'; i++);
	/* bias index i to next char - first argument */
	i++;
	/*extracting int arguments */
	for(int j=0; j<count; j++) {
		int soff = i;
		for(; text[i]!=0 && text[i] >= '0' && text[i] <= '9'; i++);
		int* p_arg = va_arg(alist, int*);
		*p_arg = atoi(text+soff);

		/* bias index i to next char - next argument */
		i++;
	}
	
	return count;
}

void strcpy(char* __dest, const char* __src)
{
	do 
	{
		*__dest = *__src;
		__dest++;
	}
	while(*__src++);
	
	return;
}

void *memcpy(void *__dest, __const void *__src, size_t __n)
{
	int i = 0;
	unsigned char *d = (unsigned char *)__dest, *s = (unsigned char *)__src;

	for (i = __n >> 3; i > 0; i--) {
		*d++ = *s++;
		*d++ = *s++;
		*d++ = *s++;
		*d++ = *s++;
		*d++ = *s++;
		*d++ = *s++;
		*d++ = *s++;
		*d++ = *s++;
	}

	if (__n & 1 << 2) {
		*d++ = *s++;
		*d++ = *s++;
		*d++ = *s++;
		*d++ = *s++;
	}

	if (__n & 1 << 1) {
		*d++ = *s++;
		*d++ = *s++;
	}

	if (__n & 1)
		*d++ = *s++;

	return __dest;
}

void *memmove(void *__dest, __const void *__src, size_t count)
{
	unsigned char *d = __dest;
	const unsigned char *s = __src;

	if (__dest == __src)
		return __dest;

	if (__dest < __src)
		return memcpy(__dest, __src, count);

	while (count--)
		d[count] = s[count];
	return __dest;
}

size_t strlen(const char *s)
{
	const char *sc = s;

	while (*sc != '\0')
		sc++;
	return sc - s;
}

int memcmp(const void *cs, const void *ct, size_t count)
{
	const unsigned char *su1 = cs, *su2 = ct, *end = su1 + count;
	int res = 0;

	while (su1 < end) {
		res = *su1++ - *su2++;
		if (res)
			break;
	}
	return res;
}

int strcmp(const char *cs, const char *ct)
{
	unsigned char c1, c2;
	int res = 0;

	do {
		c1 = *cs++;
		c2 = *ct++;
		res = c1 - c2;
		if (res)
			break;
	} while (c1);
	return res;
}

void *memchr(const void *s, int c, size_t count)
{
	const unsigned char *p = s;

	while (count--)
		if ((unsigned char)c == *p++)
			return (void *)(p - 1);
	return NULL;
}

char *strchr(const char *s, int c)
{
	while (*s != (char)c)
		if (*s++ == '\0')
			return NULL;
	return (char *)s;
}

#undef memset

void *memset(void *s, int c, size_t count)
{
	char *xs = s;
	while (count--)
		*xs++ = c;
	return s;
}

void __memzero(void *s, size_t count)
{
	memset(s, 0, count);
}
