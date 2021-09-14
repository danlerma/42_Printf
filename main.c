#include"printf.h"
#include <stdio.h>

int	main(void)
{
	int	result;

	/*result = printf("Hola mundo\n");
	printf("ORIGINAL: %d\n", result);*/
	result = ft_printf("Hola mundo %s\n", "holaa");
	printf("FUNCION: %d\n", result);
	return (0);
}
