#include <stdio.h>

int	main(void)
{
	int	result;

	result = printf("Hola mundo\n");
	printf("ORIGINAL: %d", result);
	result = ft_printf("Hola mundo\n");
	printf("FUNCION: %d", result);
	return (0);
}
