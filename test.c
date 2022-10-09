#include <stdio.h>
#include <stdarg.h>

void test(int i,...)
{
	va_list	ap;

	va_start(ap, i);
	for (int j = 0; j < 5; j++)
		printf("%d\n", va_arg(ap, int));
}

int	main(void)
{
	printf("%#.5d", 10);
}