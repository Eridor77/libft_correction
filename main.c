#include <stdio.h>
#include <ctype.h>
#include "libft.h"

#define RED		"\x1b[31m"
#define GREEN		"\x1b[32m"
#define RESET		"\x1b[0m"
#define SUCCESS(X)	printf("%s%s%s", GREEN, X, " : Success" RESET "\n")	
#define FAIL(X)		printf("%s%s%s", RED, X, " : <<<<Fail>>>>" RESET "\n")
#define ATOI_TEST(X)	ft_atoi(X) == atoi(X)

// ****** Partie 1 ******

void	ft_memset_test()
{
	char	s1[20];
	char	s2[20];

	ft_memset(s1, 42, 20);
	memset(s2, 42, 20);
	if (memcmp(s1, s2, 20) == 0)
	{
		if ((memcmp(memset(strdup("blop"), 'A', 5), ft_memset(strdup("blop"), 'A', 5), 5) == 0) &&
				(memcmp(memset(strdup("blop"), 0, 0), ft_memset(strdup("blop"), 0 , 0), 5) == 0))
			SUCCESS("ft_memset");
		else
			FAIL("ft_memset");
	}
	else
		FAIL("ft_memset");
}

void	ft_bzero_test()
{
	char	s1[5];
	char	s2[] = "blop";
	char	s3[] = "blop";
	char	s4[] = "blop";
	char	s5[] = "blop";
	char	s6[] = "blop";

	bzero(s1, 5);
	ft_bzero(s2, 5);
	bzero(s3, 2);
	ft_bzero(s4, 2);
	bzero(s5, 0);
	ft_bzero(s6, 0);
	if ((memcmp(s1, s2, 5) == 0) && (memcmp(s3, s4, 5) == 0) &&
			(memcmp(s5, s6, 5) == 0))
	{
		s2[0] = 'b';
		ft_bzero(s2, 0);
		if(s2[0] == 'b')
			SUCCESS("ft_bzero");
		else
			FAIL("ft_bzero");
	}
	else
		FAIL("ft_bzero");
}

void	ft_memcpy_test()
{
	char	s1[20], s2[20];

	memset(s1, 42, 20);
	memset(s2, 21, 20);

	ft_memcpy(s1, s2, 20);
	if ((memcmp(s1, s2, 20) == 0) && (ft_memcpy(s1, s2, 0) == s1))
		SUCCESS("ft_memcpy");
	else
		FAIL("ft_memcpy");
}

void	ft_memccpy_test()
{
	char	s1[] = "L'abeille coule.";
	char	s2[20];
	char	s3[] = "La fleur en bouquet fane.";
	void	*p1, *p2;

	p1 = memccpy(s2, s1, 'i', 10);
	p2 = ft_memccpy(s2, s1, 'i', 10);
	if ((p1 == p2) &&
			(ft_memccpy(s2, s1, 'z', 5) == 0) && 
			(ft_memccpy(s2, s1, 0, 0) == memccpy(s2, s1, 0, 0)) &&
			(ft_memccpy(s2, s1, 0, sizeof(s1)) == memccpy(s2, s1, 0, sizeof(s1))) && 
			(ft_memccpy(s2, s1, 'L', 10) == s2 + 1) &&
			(ft_memccpy(s3, strdup("Blop\42Blop"), '\42', 14) ==
			 memccpy(s3, strdup("Blop\42Blop"), '\42', 14)))
		SUCCESS("ft_memccpy");
	else
		FAIL("ft_memccpy");

}

void	ft_memmove_test()
{
	char	s1[] = "blop";
	char	s2[] = "blop";
	char	s3[] = "blop";
	char	s4[] = "blop";

	ft_memmove(s1 + 1, s1, 3);
	ft_memmove(s1 + 1, s1, 0);
	memmove(s2 + 1, s2, 3);
	memmove(s2 + 1, s2, 0);
	ft_memmove(s3, s3 + 1, 3);
	ft_memmove(s3, s3 + 1, 0);
	memmove(s4, s4 + 1, 3);
	memmove(s4, s4 + 1, 0);
	if ((strcmp(s1, "bblo") == 0) && (strcmp(s1, s2) == 0) &&
			(strcmp(s3, "lopp") == 0) && (strcmp(s3, s4) == 0))
		SUCCESS("ft_memmove");
	else
		FAIL("ft_memmove");
}

void	ft_memchr_test()
{
	if ((ft_memchr("blop", 'a', 4) == memchr("blop", 'a', 4)) &&
			(ft_memchr("blop", 'o', 4) == memchr("blop", 'o', 4)) &&
			(ft_memchr("blop", '\0', 5) == memchr("blop", '\0', 5)) &&
			(ft_memchr("blop", 'r', 4) == memchr("blop", 'r', 4)) &&
			(ft_memchr("blop", 42, 4) == memchr("blop", 42, 4)))
		SUCCESS("ft_memchr");
	else
		FAIL("ft_memchr");
}

void	ft_memcmp_test()
{
	if ((ft_memcmp("ab\0ab", "ab\0ab", 6) == 0) &&
			(ft_memcmp("ab\0ab", "ab\0ac", 6) != 0) &&
			(ft_memcmp("aaa", "aab", 4) < 0) &&
			(ft_memcmp("aab", "aac", 2) == 0) &&
			(ft_memcmp("aww", "bpp", 0) == 0) &&
			(ft_memcmp("\200", "\0", 1) > 0))
		SUCCESS("ft_memcmp");
	else
		FAIL("ft_memcmp");
}

void	ft_strlen_test()
{
	char	s1[] = "blop";
	char	s2[] = "";
	char	s3[] = "blop\0blop";

	if ((ft_strlen(s1) == strlen(s1)) &&
			(ft_strlen(s2) == strlen(s2)) &&
			(ft_strlen(s3) == strlen(s3)))
		SUCCESS("ft_strlen");
	else
		FAIL("ft_strlen");
}

void	ft_strdup_test()
{
	if ((strcmp(ft_strdup(""), "") == 0) &&
			(strcmp(ft_strdup("Blop"), "Blop") == 0))
		SUCCESS("ft_strdup");
	else
		FAIL("ft_strdup");
}

void	ft_strcpy_test()
{
	char	s1[5], s2[5], s3[5], s4[5];

	bzero(s1, 5);
	bzero(s2, 5);
	bzero(s3, 5);
	bzero(s4, 5);
	if ((strcmp(ft_strcpy(s1, "blop"), strcpy(s2, "blop")) == 0) &&
			(strcmp(ft_strcpy(s3, "hey"), strcpy(s4, "hey")) == 0))
		SUCCESS("ft_strcpy");
	else
		FAIL("ft_strcpy");
}

void	ft_strncpy_test()
{
	char	s1[5], s2[5];

	memset(s1, 42, 5);
	memset(s2, 42, 5);
	ft_strncpy(s1, "hey", 5);
	ft_strncpy(s2, "helloworld", 5);
	if ((memcmp(s1, "hey\0", 5) == 0) &&
			(memcmp(s2, "helloworld", 5) == 0))
		SUCCESS("ft_strncpy");
	else
		FAIL("ft_strncpy");
}

void	ft_strcat_test()
{
	char	str[9];

	bzero(str, 9);
	ft_strcat(str, "");
	ft_strcat(str, "Bon");
	ft_strcat(str, "j");
	ft_strcat(str, "our.");
	ft_strcat(str, "");
	if ((strcmp(str, "Bonjour.") == 0) &&
			(str == ft_strcat(str, "")))
		SUCCESS("ft_strcat");
	else
		FAIL("ft_strcat");
}

void	ft_strncat_test()
{
	char	s1[18];
	char	s2[18];

	strcpy(s1, "abcdefghijklmnopq");
	strcpy(s1, "Hello ");
	ft_strncat(s1, "cool world!", 5);
	strcpy(s2, "Hello ");
	ft_strncat(s2, "cool world!", 5);
	ft_strncat(s2, "blop", 0);
	if ((strcmp(s1, "Hello cool ") == 0) &&
			(strcmp(s2, "Hello cool ") == 0) &&
			(s2 == ft_strncat(s2, "", 0)))
		SUCCESS("ft_strncat");
	else
		FAIL("ft_strncat");
}

void	ft_strlcat_test()
{
	char	s1[10], s2[10], s3[10];

	bzero(s1, 10);
	bzero(s2, 10);
	bzero(s3, 10);
	strcpy(s1, "abc");
	ft_strlcat(s1, "abcdefghijklmnop", 10);
	memset(s3, 'a', 10);
	if ((strcmp(s1, "abcabcdef") == 0) &&
			(ft_strlcat(s1, "abcd", 2) == 6) &&
			(ft_strlcat(s2, "abc", 10) == 3) &&
			(ft_strlcat(s2, "def", 10) == 6) &&
			(ft_strlcat(s3, "ccc", 10) == 13) &&
			(ft_strlcat(strdup("abc\0\0\0"), "ccc", 0) == 3) &&
			(ft_strlcat(strdup("abc\0\0\0"), "ccc", 1) == 4) &&
			(ft_strlcat(strdup("abc\0\0\0"), "ccc", 6) == 6) &&
			(ft_strlcat(strdup("abc\0\0\0"), "ccc", 10) == 6))
		SUCCESS("ft_strlcat");
	else
		FAIL("ft_strlcat");
}

void	ft_strchr_test()
{
	char	str[] = "Hello World.";

	if ((strchr(str, 'W') == ft_strchr(str, 'W')) &&
			(strchr(str, 0) == ft_strchr(str, 0)) &&
			(strchr(str, 'e') == ft_strchr(str, 'e')) &&
			(strchr(str, 'b') == ft_strchr(str, 'b')))
		SUCCESS("ft_strchr");
	else
		FAIL("ft_strchr");
}

void	ft_strrchr_test()
{
	char	s1[] = "Hello World";
	char	s2[] = "hello";

	if ((strrchr(s1, 'o') == ft_strrchr(s1, 'o')) &&
			(strrchr(s1, 0) == ft_strrchr(s1, 0)) &&
			(ft_strrchr(s1, 'b') == 0) &&
			(ft_strrchr(s2, 'h') == s2))
		SUCCESS("ft_strrchr");
	else
		FAIL("ft_strrchr");
}

void	ft_strstr_test()
{
	char	s1[] = "Je ne digere pas le porc.";
	char	s2[] = "sigisigismund";

	if ((ft_strstr(s1, "pas") == strstr(s1, "pas")) &&
			(ft_strstr(s1, "J") == strstr(s1, "J")) &&
			(ft_strstr(s1, ".") == strstr(s1, ".")) &&
			(ft_strstr(s1, "") == strstr(s1, "")) &&
			(ft_strstr(s1, "cccc") == strstr(s1, "cccc")) &&
			(ft_strstr(s2, "sigismund") == strstr(s2, "sigismund")) &&
			(ft_strstr("", "") == strstr("", "")) &&
			(ft_strstr("blopiblopiblopu", "blopu")))
		SUCCESS("ft_strstr");
	else
		FAIL("ft_strstr");
}

void	ft_strnstr_test()
{
	char	s1[10], s2[11], s3[10];
	char	s4[] = "sigisigismund000";

	bzero(s1, 10);
	bzero(s2, 11);
	bzero(s3, 10);
	strcpy(s1, "un deux 9");
	strcpy(s2, "un deux 9");
	strcpy(s3, "un deux 9");
	s2[9] = '6';
	s3[9] = '6';
	s3[1] = 0;
	if ((strcmp(ft_strnstr(s1, "deux", 10), "deux 9") == 0) &&
			(ft_strnstr(s1, "9", 3) == NULL) &&
			(strcmp(ft_strnstr(s1, "", 6), s1) == 0) &&
			(ft_strnstr(s1, "deux", 5) == NULL) &&
			(strcmp(ft_strnstr(s1, "9", 10), "9") == 0) &&
			(ft_strnstr(s1, "9", 8) == NULL) &&
			(strcmp(ft_strnstr(s2, "deux", 10), "deux 96") == 0) &&
			(ft_strnstr(s2, "cinq", 10) == NULL) &&
			(ft_strnstr(s2, "9682", 10) == NULL) &&
			(strcmp(ft_strnstr(s2, "6", 10), "6") == 0) &&
			(ft_strnstr(s3, "deux", 10) == 0) &&
			(strcmp(ft_strnstr(s4, "sigismund", 13), "sigismund000") == 0))
		SUCCESS("ft_strnstr");
	else
		FAIL("ft_strnstr");
}

void	ft_strcmp_test()
{
	if ((ft_strcmp("", "") == 0) &&
			(ft_strcmp("abc", "abc") == 0) &&
			(ft_strcmp("abc", "abd") < 0) &&
			(ft_strcmp("\200", "\0") > 0) &&
			(ft_strcmp("a", "abcde") != 0))
		SUCCESS("ft_strcmp");
	else
		FAIL("ft_strcmp");
}

void	ft_strncmp_test()
{
	if ((ft_strncmp("\200", "\0", 1) > 0) &&
			(ft_strncmp("abc", "abcde", 3) == 0) &&
			(ft_strncmp("abc", "abc\0defg", 100) == 0) &&
			(ft_strncmp("ab\0cde", "abcc\0e", 20) != 0) &&
			(ft_strncmp("q", "a", 0) == strncmp("q", "a", 0)))
		SUCCESS("ft_strncmp");
	else
		FAIL("ft_strncmp");
}

void	ft_atoi_test()
{
	if ((ATOI_TEST(" -sfecf")) &&
			(ATOI_TEST("")) &&
			(ATOI_TEST("+2798")) &&
			(ATOI_TEST("+0089")) &&
			(ATOI_TEST("a56")) &&
			(ATOI_TEST("	--s8")) &&
			(ATOI_TEST("0001020304")) &&
			(ATOI_TEST("-153")) &&
			(ATOI_TEST("+132")) &&
			(ATOI_TEST("++876")) &&
			(ATOI_TEST("--132")) &&
			(ATOI_TEST("dwbk")) &&
			(ATOI_TEST(" 1")) &&
			(ATOI_TEST("42jk")) &&
			(ATOI_TEST(" 21")) &&
			(ATOI_TEST("	32  ")) &&
			(ATOI_TEST("\n		42 24")) &&
			(ATOI_TEST("1-2")) &&
			(ATOI_TEST("4+2")) &&
			(ATOI_TEST("	+442")) &&
			(ATOI_TEST("	-4432")) &&
			(ATOI_TEST("4,5")) &&
			(ATOI_TEST("+")) &&
			(ATOI_TEST("-")) &&
			(ATOI_TEST("-+1")) &&
			(ATOI_TEST("+-1")) &&
			(ATOI_TEST("\200123")) &&
			(ATOI_TEST("123\200")) &&
			(ATOI_TEST("  \t\n  \r\r\v\f-899")) &&
			(ATOI_TEST("-2147483648")) &&
			(ATOI_TEST("2144748647")))
		SUCCESS("ft_atoi");
	else
		FAIL("ft_atoi");
}

void	ft_isalpha_test()
{
	if ((ft_isalpha('a') > 0 && isalpha('a') > 0) &&
			(ft_isalpha('z') > 0 && isalpha('z') > 0) &&
			(ft_isalpha('A') > 0 && isalpha('A') > 0) &&
			(ft_isalpha('Z') > 0 && isalpha('Z') > 0) &&
			(ft_isalpha('m') > 0 && isalpha('m') > 0) &&
			(ft_isalpha('1') == 0 && isalpha('1') == 0) &&
			(ft_isalpha('%') == 0 && isalpha('%') == 0) &&
			(ft_isalpha('!') == 0 && isalpha('!') == 0) &&
			(ft_isalpha(0) == 0 && isalpha(0) == 0) &&
			(ft_isalpha(1) == 0 && isalpha(1) == 0) &&
			(ft_isalpha(2) == 0 && isalpha(2) == 0) &&
			(ft_isalpha(42) == 0 && isalpha(42) == 0) &&
			(ft_isalpha(10000) == 0 && isalpha(10000) == 0) &&
			(ft_isalpha(' ') == 0 && isalpha(' ') == 0) &&
			(ft_isalpha('\t') == 0 && isalpha('\t') == 0) &&
			(ft_isalpha('\n') == 0 && isalpha('\n') == 0) &&
			(ft_isalpha('\b') == 0 && isalpha('\b') == 0))
		SUCCESS("ft_isalpha");
	else
		FAIL("ft_isalpha");
}	


void	ft_isdigit_test()
{
	if ((ft_isdigit('a') == 0 && isdigit('a') == 0) &&
			(ft_isdigit('z') == 0 && isdigit('z') == 0) &&
			(ft_isdigit('A') == 0 && isdigit('A') == 0) &&
			(ft_isdigit('Z') == 0 && isdigit('Z') == 0) &&
			(ft_isdigit('m') == 0 && isdigit('m') == 0) &&
			(ft_isdigit('1') > 0 && isdigit('1') > 0) &&
			(ft_isdigit('%') == 0 && isdigit('%') == 0) &&
			(ft_isdigit('!') == 0 && isdigit('!') == 0) &&
			(ft_isdigit(0) == 0 && isdigit(0) == 0) &&
			(ft_isdigit(1) == 0 && isdigit(1) == 0) &&
			(ft_isdigit(2) == 0 && isdigit(2) == 0) &&
			(ft_isdigit(42) == 0 && isdigit(42) == 0) &&
			(ft_isdigit(10000) == 0 && isdigit(10000) == 0) &&
			(ft_isdigit(' ') == 0 && isdigit(' ') == 0) &&
			(ft_isdigit('\t') == 0 && isdigit('\t') == 0) &&
			(ft_isdigit('\n') == 0 && isdigit('\n') == 0) &&
			(ft_isdigit('\b') == 0 && isdigit('\b') == 0))
		SUCCESS("ft_isdigit");
	else
		FAIL("ft_isdigit");

}

void	ft_isalnum_test()
{
	if ((ft_isalnum('a') > 0 && isalnum('a') > 0) &&
			(ft_isalnum('z') > 0 && isalnum('z') > 0) &&
			(ft_isalnum('A') > 0 && isalnum('A') > 0) &&
			(ft_isalnum('Z') > 0 && isalnum('Z') > 0) &&
			(ft_isalnum('m') > 0 && isalnum('m') > 0) &&
			(ft_isalnum('1') > 0 && isalnum('1') > 0) &&
			(ft_isalnum('%') == 0 && isalnum('%') == 0) &&
			(ft_isalnum('!') == 0 && isalnum('!') == 0) &&
			(ft_isalnum(0) == 0 && isalnum(0) == 0) &&
			(ft_isalnum(1) == 0 && isalnum(1) == 0) &&
			(ft_isalnum(2) == 0 && isalnum(2) == 0) &&
			(ft_isalnum(42) == 0 && isalnum(42) == 0) &&
			(ft_isalnum(10000) == 0 && isalnum(10000) == 0) &&
			(ft_isalnum(' ') == 0 && isalnum(' ') == 0) &&
			(ft_isalnum('\t') == 0 && isalnum('\t') == 0) &&
			(ft_isalnum('\n') == 0 && isalnum('\n') == 0) &&
			(ft_isalnum('\b') == 0 && isalnum('\b') == 0))
		SUCCESS("ft_isalnum");
	else
		FAIL("ft_isalnum");

}

void	ft_isascii_test()
{
	if ((ft_isascii('a') > 0 && isascii('a') > 0) &&
			(ft_isascii('z') > 0 && isascii('z') > 0) &&
			(ft_isascii('A') > 0 && isascii('A') > 0) &&
			(ft_isascii('Z') > 0 && isascii('Z') > 0) &&
			(ft_isascii('m') > 0 && isascii('m') > 0) &&
			(ft_isascii('1') > 0 && isascii('1') > 0) &&
			(ft_isascii('%') > 0 && isascii('%') > 0) &&
			(ft_isascii('!') > 0 && isascii('!') > 0) &&
			(ft_isascii(0) > 0 && isascii(0) > 0) &&
			(ft_isascii(1) > 0 && isascii(1) > 0) &&
			(ft_isascii(2) > 0 && isascii(2) > 0) &&
			(ft_isascii(42) > 0 && isascii(42) > 0) &&
			(ft_isascii(10000) == 0 && isascii(10000) == 0) &&
			(ft_isascii(' ') > 0 && isascii(' ') > 0) &&
			(ft_isascii('\t') > 0 && isascii('\t') > 0) &&
			(ft_isascii('\n') > 0 && isascii('\n') > 0) &&
			(ft_isascii('\b') > 0 && isascii('\b') > 0) &&
			(ft_isascii(-42) == 0 && isascii(-42) == 0))
		SUCCESS("ft_isascii");
	else
		FAIL("ft_isascii");

}

void	ft_isprint_test()
{
	if ((ft_isprint('a') > 0 && isprint('a') > 0) &&
			(ft_isprint('z') > 0 && isprint('z') > 0) &&
			(ft_isprint('A') > 0 && isprint('A') > 0) &&
			(ft_isprint('Z') > 0 && isprint('Z') > 0) &&
			(ft_isprint('m') > 0 && isprint('m') > 0) &&
			(ft_isprint('1') > 0 && isprint('1') > 0) &&
			(ft_isprint('%') > 0 && isprint('%') > 0) &&
			(ft_isprint('!') > 0 && isprint('!') > 0) &&
			(ft_isprint(0) == 0 && isprint(0) == 0) &&
			(ft_isprint(1) == 0 && isprint(1) == 0) &&
			(ft_isprint(2) == 0 && isprint(2) == 0) &&
			(ft_isprint(42) > 0 && isprint(42) > 0) &&
			(ft_isprint(10000) == 0 && isprint(10000) == 0) &&
			(ft_isprint(' ') > 0 && isprint(' ') > 0) &&
			(ft_isprint('\t') == 0 && isprint('\t') == 0) &&
			(ft_isprint('\n') == 0 && isprint('\n') == 0) &&
			(ft_isprint('\b') == 0 && isprint('\b') == 0))
		SUCCESS("ft_isprint");
	else
		FAIL("ft_isprint");

}

void	ft_toupper_test()
{
	if ((ft_toupper('a') == toupper('a')) &&
			(ft_toupper('z') == toupper('z')) &&
			(ft_toupper('A') == toupper('A')) &&
			(ft_toupper('Z') == toupper('Z')) &&
			(ft_toupper('m') == toupper('m')) &&
			(ft_toupper('1') == toupper('1')) &&
			(ft_toupper('%') == toupper('%')) &&
			(ft_toupper('!') == toupper('!')) &&
			(ft_toupper(0) == toupper(0)) &&
			(ft_toupper(1) == toupper(1)) &&
			(ft_toupper(2) == toupper(2)) &&
			(ft_toupper(42) == toupper(42)) &&
			(ft_toupper(' ') == toupper(' ')) &&
			(ft_toupper('\t') == toupper('\t')) &&
			(ft_toupper('\n') == toupper('\n')) &&
			(ft_toupper('\b') == toupper('\b')))
		SUCCESS("ft_toupper");
	else
		FAIL("ft_toupper");

}

void	ft_tolower_test()
{
	if ((ft_tolower('a') == tolower('a')) &&
			(ft_tolower('z') == tolower('z')) &&
			(ft_tolower('A') == tolower('A')) &&
			(ft_tolower('Z') == tolower('Z')) &&
			(ft_tolower('m') == tolower('m')) &&
			(ft_tolower('1') == tolower('1')) &&
			(ft_tolower('%') == tolower('%')) &&
			(ft_tolower('!') == tolower('!')) &&
			(ft_tolower(0) == tolower(0)) &&
			(ft_tolower(1) == tolower(1)) &&
			(ft_tolower(2) == tolower(2)) &&
			(ft_tolower(42) == tolower(42)) &&
			(ft_tolower(' ') == tolower(' ')) &&
			(ft_tolower('\t') == tolower('\t')) &&
			(ft_tolower('\n') == tolower('\n')) &&
			(ft_tolower('\b') == tolower('\b')))
		SUCCESS("ft_tolower");
	else
		FAIL("ft_tolower");

}

// ****** Partie 2 ******

void	ft_memalloc_test()
{
	void	*mem1, *mem2;

	mem1 = malloc(42);
	bzero(mem1, 42);
	mem2 = ft_memalloc(42);
	if ((!!mem1 && !!mem2) &&
			(mem1 && mem2 && memcmp(mem1, mem2, 42) == 0))
		SUCCESS("ft_memalloc");
	else
		FAIL("ft_memalloc");
}

void	ft_memdel_test()
{
	void	*mem;

	mem = malloc(42);
	ft_memdel(&mem);
	if (mem == NULL)
		SUCCESS("ft_memdel");
	else
		FAIL("ft_memdel");
}

void	ft_strnew_test()
{
	char	*s1, *s2;

	s1 = ft_strnew(42);
	s2 = malloc(43);
	bzero(s2, 43);
	if ((memcmp(s1, s2, 43) == 0) &&
			(ft_strnew(0) != NULL))
		SUCCESS("ft_strnew");
	else
		FAIL("ft_strnew");
}

void	ft_strdel_test()
{
	char	*str;

	str = malloc(42);
	ft_strdel(&str);
	if (str == NULL)
		SUCCESS("ft_strdel");
	else
		FAIL("ft_strdel");
}

void	ft_strclr_test()
{
	char	str[] = "blopiblop";

	ft_strclr(str);
	if (memcmp(str, "\0\0\0\0\0\0\0\0\0", 10) == 0)
		SUCCESS("ft_strclr");
	else
		FAIL("ft_strclr");
}

void	ft_strtoupper(char *str)
{
	size_t	i;

	i = 0;
	while (i < strlen(str))
	{
		str[i] = toupper(str[i]);
		i++;
	}
}

void	ft_striter_test()
{
	char	str[] = "aBcDeF";

	ft_striter(str, ft_strtoupper);
	if (strcmp(str, "ABCDEF") == 0)
		SUCCESS("ft_striter");
	else
		FAIL("ft_striter");
}

void	ft_strtoupperi(unsigned int i, char *str)
{	
	str[i] = toupper(str[i]);
}

void	ft_striteri_test()
{
	char	str[] = "aBcDeF";

	ft_striteri(str, ft_strtoupperi);
	if (strcmp(str, "ABCDEF") == 0)
		SUCCESS("ft_striteri");
	else
		FAIL("ft_striteri");
}

char	ft_map_test(char c)
{
	int	i;

	i = toupper((int)c);
	return (i);
}

void	ft_strmap_test()
{
	char	*src;
	char	*dest;

	src = strdup("abcde");
	dest = ft_strmap(src, ft_map_test);
	free(src);
	src = NULL;
	if (strcmp(dest, "ABCDE") == 0)
		SUCCESS("ft_strmap");
	else
		FAIL("ft_strmap");
}

char	ft_mapi_test(unsigned int i, char c)
{
	char	r;

	r = c + i;
	return (r);
}

void	ft_strmapi_test()
{
	char	*src;
	char	*dest;

	src = strdup("aaaa");
	dest = ft_strmapi(src, ft_mapi_test);
	free(src);
	src = NULL;
	if (strcmp(dest, "abcd") == 0)
		SUCCESS("ft_strmapi");
	else
		FAIL("ft_strmapi");
}

void	ft_strequ_test()
{
	if ((ft_strequ("", "") == 1) &&
			(ft_strequ("abcDEF", "abcDEF") == 1) &&
			(ft_strequ("abcDEF", "abcDEf") == 0))
		SUCCESS("ft_strequ");
	else
		FAIL("ft_strequ");
}

void	ft_strnequ_test()
{
	if ((ft_strnequ("ededeqdf", "", 0) == 1) &&
			(ft_strnequ("abcde", "abcfe", 2) == 1) &&
			(ft_strnequ("abc", "abc", 42) == 1) &&
			(ft_strnequ("abcde", "abdde", 5) == 0))
		SUCCESS("ft_strnequ");
	else
		FAIL("ft_strnequ");
}

void	ft_strsub_test()
{
	char	*str = "Un jour je serai, le meilleur dresseur !";
	if ((ft_strsub(str, 0, (size_t)-10) == NULL) &&
			(strcmp(ft_strsub(str, 8, 8), "je serai") == 0) &&
			(strcmp(ft_strsub(str, 0, 0), "") == 0))
		SUCCESS("ft_strsub");
	else
		FAIL("ft_strsub");
}

void	ft_strjoin_test()
{
	if ((strcmp(ft_strjoin("abc", "def"), "abcdef") == 0) &&
			(strcmp(ft_strjoin("", ""), "") == 0))
		SUCCESS("ft_strjoin");
	else
		FAIL("ft_strjoin");
}

void	ft_strtrim_test()
{
	if ((strcmp(ft_strtrim("\t\n  AAA \t BBB\t\n"), "AAA \t BBB") == 0) &&
			(strcmp(ft_strtrim("\t\t\n\t\t   "), "") == 0) &&
			(strcmp(ft_strtrim(""), "") == 0) &&
			(strcmp(ft_strtrim("abc"), "abc") == 0))
		SUCCESS("ft_strtrim");
	else
		FAIL("ft_strtrim");
}

void	ft_strsplit_test()
{
	char	**p1, **p2, **p3, **p4, **p5, **p6;
	
	p1 = ft_strsplit("***hey***!", '*');
	p2 = ft_strsplit("******", '*');
	p3 = ft_strsplit("hello", '*');
	p4 = ft_strsplit("hello****", '*');
	p5 = ft_strsplit("****hello", '*');
	p6 = ft_strsplit("", '*');
	if ((strcmp(p1[0], "hey") == 0) &&
			(strcmp(p1[1], "!") == 0) &&
			(p1[2] == NULL) &&
			(p2[0] == NULL) &&
			(strcmp(p3[0], "hello") == 0) &&
			(p3[1] == NULL) &&
			(strcmp(p4[0], "hello") == 0) &&
			(p4[1] == NULL) &&
			(strcmp(p5[0], "hello") == 0) &&
			(p5[1] == NULL) &&
			(p6 && p6[0] == NULL))
		SUCCESS("ft_strsplit");
	else
		FAIL("ft_strsplit");
}

void	ft_itoa_test()
{
	if ((strcmp(ft_itoa(0), "0") == 0) &&
			(ft_strcmp(ft_itoa(-1234), "-1234") == 0) &&
			(ft_strcmp(ft_itoa(123456000), "123456000") == 0) /*&&
			(ft_strcmp(ft_itoa(-2147483648), "-2147483648") == 0)*/)
		SUCCESS("ft_itoa");
	else
		FAIL("ft_itoa");
}

void	ft_putchar_test()
{
	int	out;
	int	p[2];
	char	str[4];

	out = dup(1);
	pipe(p);
	dup2(p[1], 1);
	ft_putchar('a');
	ft_putchar('b');
	ft_putchar('c');
	dup2(out, 1);
	read(p[0], str, 3);
	str[3] = 0;
	close(p[0]);
	close(p[1]);
	close(out);
	if (strcmp(str, "abc") == 0)
		SUCCESS("ft_putchar");
	else
		FAIL("ft_putchar");
}

void	ft_putstr_test()
{
	int	out;
	int	p[2];
	char	str[4];

	out = dup(1);
	pipe(p);
	dup2(p[1], 1);
	ft_putstr("abc");
	dup2(out, 1);
	read(p[0], str, 3);
	str[3] = 0;
	close(p[0]);
	close(p[1]);
	close(out);
	if (strcmp(str, "abc") == 0)
		SUCCESS("ft_putstr");
	else
		FAIL("ft_putstr");

}

void	ft_putendl_test()
{
	int	out;
	int	p[2];
	char	str[4];

	out = dup(1);
	pipe(p);
	dup2(p[1], 1);
	ft_putendl("aa"),
	dup2(out, 1);
	read(p[0], str, 3);
	str[3] = 0;
	close(p[0]);
	close(p[1]);
	close(out);
	if (strcmp(str, "aa\n") == 0)
		SUCCESS("ft_putendl");
	else
		FAIL("ft_putendl");

}

void	ft_putnbr_test()
{
	int	out;
	int	p[2];
	char	str[100];

	out = dup(1);
	pipe(p);
	dup2(p[1], 1);
	ft_putnbr(0);
	ft_putnbr(1);
	ft_putnbr(-1);
	ft_putnbr(12300);
	ft_putnbr(10203);
	ft_putnbr(-56);
	ft_putnbr(2147483647);
	//ft_putnbr(-2147483648);
	dup2(out, 1);
	str[read(p[0], str, 100)] = 0;
	close(p[0]);
	close(p[1]);
	close(out);
	//if (strcmp(str, "01-11230010203-562147483647-2147483648") == 0)
	if (strcmp(str, "01-11230010203-562147483647") == 0)
		SUCCESS("ft_putnbr");
	else
		FAIL("ft_putnbr");

}

void	ft_putchar_fd_test()
{
	int	p[2];
	char	str[100];

	pipe(p);
	ft_putchar_fd('a', p[1]);
	ft_putchar_fd('b', p[1]);
	str[read(p[0], str, 100)] = 0;
	close(p[0]);
	close(p[1]);
	if (strcmp(str, "ab") == 0)
		SUCCESS("ft_putchar_fd");
	else
		FAIL("ft_putchar_fd");

}

void	ft_putendl_fd_test()
{
	int	p[2];
	char	str[100];

	pipe(p);
	ft_putendl_fd("Blop !", p[1]);
	str[read(p[0], str, 100)] = 0;
	close(p[0]);
	close(p[1]);
	if (strcmp(str, "Blop !\n") == 0)
		SUCCESS("ft_putendl_fd");
	else
		FAIL("ft_putendl_fd");

}

void	ft_putnbr_fd_test()
{
	int	p[2];
	char	str[100];

	pipe(p);
	ft_putnbr_fd(0, p[1]);
	ft_putnbr_fd(1, p[1]);
	ft_putnbr_fd(-1, p[1]);
	ft_putnbr_fd(12300, p[1]);
	ft_putnbr_fd(10203, p[1]);
	ft_putnbr_fd(-56, p[1]);
	ft_putnbr_fd(2147483647, p[1]);
	//ft_putnbr_fd(-2147483648, p[1]);
	str[read(p[0], str, 100)] = 0;
	close(p[0]);
	close(p[1]);
	//if (strcmp(str, "01-11230010203-562147483647-2147483648") == 0)
	if (strcmp(str, "01-11230010203-562147483647") == 0)
		SUCCESS("ft_putnbr_fd");
	else
		FAIL("ft_putnbr_fd");

}

int	main(void)
{
	printf("\n------ Partie 1 ------\n\n");
	ft_memset_test();
	ft_bzero_test();
	ft_memcpy_test();
	ft_memccpy_test();
	ft_memmove_test();
	ft_memchr_test();
	ft_memcmp_test();
	ft_strlen_test();
	ft_strdup_test();
	ft_strcpy_test();
	ft_strncpy_test();
	ft_strcat_test();
	ft_strncat_test();
	ft_strlcat_test();
	ft_strchr_test();
	ft_strrchr_test();
	ft_strstr_test();
	ft_strnstr_test();
	ft_strcmp_test();
	ft_strncmp_test();
	ft_atoi_test();
	ft_isalpha_test();
	ft_isdigit_test();
	ft_isalnum_test();
	ft_isascii_test();
	ft_isprint_test();
	ft_toupper_test();
	ft_tolower_test();
	printf("\n------ Partie 2 ------\n\n");
	ft_memalloc_test();
	ft_memdel_test();
	ft_strnew_test();
	ft_strdel_test();
	ft_strclr_test();
	ft_striter_test();
	ft_striteri_test();
	ft_strmap_test();
	ft_strmapi_test();
	ft_strequ_test();
	ft_strnequ_test();
	ft_strsub_test();
	ft_strjoin_test();
	ft_strtrim_test();
	ft_strsplit_test();
	ft_itoa_test();
	ft_putchar_test();
	ft_putstr_test();
	ft_putendl_test();
	ft_putnbr_test();
	ft_putchar_fd_test();
	ft_putendl_fd_test();
	ft_putnbr_fd_test();
	return(0);
}
