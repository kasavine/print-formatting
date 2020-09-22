#include <stdio.h>
#include <stdlib.h>

void swap(char *x, char *y) {
	char t = *x; *x = *y; *y = t;
}

char* reverse(char *buffer, int i, int j)
{
	while (i < j)
		swap(&buffer[i++], &buffer[j--]);
	return buffer;
}

char* itoa(int value, char* buffer, int base)
{
	if (base < 2 || base > 32)
		return buffer;
	int n = abs(value);
	int i = 0;
	while (n)
	{
		int r = n % base;

		if (r >= 10) 
			buffer[i++] = 65 + (r - 10);
		else
			buffer[i++] = 48 + r;

		n = n / base;
	}
	if (i == 0)
		buffer[i++] = '0';

	if (value < 0 && base == 10)
		buffer[i++] = '-';
	buffer[i] = '\0'; // null terminate string
	return reverse(buffer, 0, i - 1);
}

int main(void)
{
	char buffer[33];

	int value[] = { 11184810, -25, 64, 127 };
	int base[]  = { 16, 10, 8, 2 };
	
	for (int i = 0; i < 4; i++)
	{
		printf("itoa(%d, buffer, %d) = %s\n", value[i], base[i], 
			itoa(value[i], buffer, base[i]));
	}

	int a = 10;
    int *b = &a;
	printf("%p", b);

	return 0;
}