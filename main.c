#include"ft_printf.h"
#include <stdio.h>
#include <string.h>

int	main(int argc, char **argv)
{
	int	result;

	(void)argc;
	if (strcmp(argv[1], "string") == 0)
	{
		printf("ORIGINAL: \n");
		result = printf("SOLO UN STRING.");
		printf("\nNUM: %d\n\n", result);
		////////////////////////////////////
		printf("FUNCION: \n");
		result = ft_printf("SOLO UN STRING.");
		printf("\nNUM: %d\n\n", result);
		////////////////////////////////////
		printf("ORIGINAL: \n");
		result = printf("CHAR RAROS: ¢@#|∞≠çñäêó$&¿?¡!");
		printf("\nNUM: %d\n\n", result);
		////////////////////////////////////
		printf("FUNCION: \n");
		result = ft_printf("CHAR RAROS: ¢@#|∞≠çñäêó$&¿?¡!");
		printf("\nNUM: %d\n\n", result);
	}
	else if (strcmp(argv[1], "%c") == 0)
	{
		printf("ORIGINAL: \n");
		result = printf("%c %c %c %c %c %c", 'a', 's', '2', 'y', '=', '?');
		printf("\nNUM: %d\n\n", result);
		////////////////////////////////////
		printf("FUNCION: \n");
		result = ft_printf("%c %c %c %c %c %c", 'a', 's', '2', 'y', '=', '?');
		printf("\nNUM: %d\n\n", result);
	}
	else if (strcmp(argv[1], "%d") == 0)
	{
		printf("ORIGINAL: \n");
		result = printf("%d %d %d %d %d %d %d", 1, 98 , -45, 1245648, -2147483647, 2147483647, 0);
		printf("\nNUM: %d\n\n", result);
		////////////////////////////////////
		printf("FUNCION: \n");
		result = ft_printf("%d %d %d %d %d %d %d", 1, 98 , -45, 1245648, -2147483647, 2147483647, 0);
		printf("\nNUM: %d\n\n", result);
	}
	else if (strcmp(argv[1], "%i") == 0)
	{
		printf("ORIGINAL: \n");
		result = printf("%i %i %i %i %i %i %i", 1, 98 , -45, 1245648, -2147483647, 2147483647, 0);
		printf("\nNUM: %d\n\n", result);
		////////////////////////////////////
		printf("FUNCION: \n");
		result = ft_printf("%i %i %i %i %i %i %i", 1, 98 , -45, 1245648, -2147483647, 2147483647, 0);
		printf("\nNUM: %d\n\n", result);
	}
	else if (strcmp(argv[1], "%u") == 0)
	{
		printf("ORIGINAL: \n");
		result = printf("%u %u %u %u %u %u %u", -1, 98 , -4545, -1000000000, -2147483647, 2147483647, 0);
		printf("\nNUM: %d\n\n", result);
		////////////////////////////////////
		printf("FUNCION: \n");
		result = ft_printf("%u %u %u %u %u %u %u", -1, 98 , -4545, -1000000000, -2147483647, 2147483647, 0);
		printf("\nNUM: %d\n\n", result);
	}
	else if (strcmp(argv[1], "%s") == 0)
	{
		printf("ORIGINAL: \n");
		result = printf("%s", "Texto simple");
		printf("\nNUM: %d\n\n", result);
		////////////////////////////////////
		printf("FUNCION: \n");
		result = ft_printf("%s", "Texto simple");
		printf("\nNUM: %d\n\n", result);
		///////////////////////////////////
		printf("\nORIGINAL: \n");
		result = printf("%s %s", "Texto simple1", "Texto simple2");
		printf("\nNUM: %d\n\n", result);
		////////////////////////////////////
		printf("FUNCION: \n");
		result = ft_printf("%s %s", "Texto simple1", "Texto simple2");
		printf("\nNUM: %d\n\n", result);
		///////////////////////////////////
		printf("\nORIGINAL: \n");
		result = printf("%s %s", "Caracteres raros", "¢@#|∞≠çñäêó$&¿?¡!");
		printf("\nNUM: %d\n\n", result);
		////////////////////////////////////
		printf("FUNCION: \n");
		result = ft_printf("%s %s", "Caracteres raros", "¢@#|∞≠çñäêó$&¿?¡!");
		printf("\nNUM: %d\n\n", result);
		///////////////////////////////////
		printf("\nORIGINAL: \n");
		result = printf("NULL %s NULL", NULL);
		printf("\nNUM: %d\n\n", result);
		////////////////////////////////////
		printf("FUNCION: \n");
		result = ft_printf("NULL %s NULL", NULL);
		printf("\nNUM: %d\n\n", result);
	}
	system("leaks a.out\n");
	return (0);
}
