/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapmarti <bapmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 20:39:53 by bapmarti          #+#    #+#             */
/*   Updated: 2021/02/22 17:34:11 by bapmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static void		print_char_test()
{
	ft_printf("[FT_PRINTF RESULT CHAR TEST]\n");
	printf("[result printf: %d]\n", printf("[1]\t[%%c]\t\t   printf: Hell%c$\n", 'o'));
	printf("[result ft_printf: %d]\n", ft_printf("[1]\t[%%c]\t\tft_printf: Hell%c$\n", 'o'));
	
	printf("[result printf: %d]\n", printf("[2]\t[%%.c]\t\t   printf: Hell%.c$\n", 'o'));
	printf("[result ft_printf: %d]\n", ft_printf("[2]\t[%%.c]\t\tft_printf: Hell%.c$\n", 'o'));
	
	printf("[result printf: %d]\n", printf("[3]\t[%%-c]\t\t   printf: Hell%-c$\n", 'o'));
	printf("[result ft_printf: %d]\n", ft_printf("[3]\t[%%-c]\t\tft_printf: Hell%-c$\n", 'o'));
	
	printf("[result printf: %d]\n", printf("[4]\t[%%12c]\t\t   printf: Hell%12c$\n", 'o'));
	printf("[result ft_printf: %d]\n", ft_printf("[4]\t[%%12c]\t\tft_printf: Hell%12c$\n", 'o'));
	
	printf("[result printf: %d]\n", printf("[5]\t[%%-12c]\t\t   printf: Hell%-12c$\n", 'o'));
	printf("[result ft_printf: %d]\n", ft_printf("[5]\t[%%-12c]\t\tft_printf: Hell%-12c$\n", 'o'));
	
	printf("[result printf: %d]\n", printf("[7]\t[%%-.c]\t\t   printf: Hell%-.c$\n", 'o'));
	printf("[result ft_printf: %d]\n", ft_printf("[7]\t[%%-.c]\t\tft_printf: Hell%-.c$\n", 'o'));
	
	printf("[result printf: %d]\n", printf("[8]\t[%%*c]\t\t   printf: Hell%*c$\n", 15, 'o'));
	printf("[result ft_printf: %d]\n", ft_printf("[8]\t[%%*c]\t\tft_printf: Hell%*c$\n", 15, 'o'));
	
	printf("[result printf: %d]\n", printf("[9]\t[%%*c]\t\t   printf: Hell%*c$\n", -15, 'o'));
	printf("[result ft_printf: %d]\n", ft_printf("[9]\t[%%*c]\t\tft_printf: Hell%*c$\n", -15, 'o'));
	
	printf("[result printf: %d]\n", printf("[10]\t[%%*c]\t\t   printf: Hell%*c$\n", -15, 0));
	printf("[result ft_printf: %d]\n", ft_printf("[10]\t[%%*c]\t\tft_printf: Hell%*c$\n", -15, 0));
	
	printf("[result printf: %d]\n", printf("[11]\t[%%1.c]\t\t   printf: Hell%1.c$\n", 'o'));
	printf("[result ft_printf: %d]\n", ft_printf("[11]\t[%%1.c]\t\tft_printf: Hell%1.c$\n", 'o'));
	
	printf("[result printf: %d]\n", printf("[12]\t[%%5.c]\t\t   printf: Hell%5.c$\n", 'o'));
	printf("[result ft_printf: %d]\n", ft_printf("[12]\t[%%5.c]\t\tft_printf: Hell%5.c$\n", 'o'));
}

static void		print_string_test()
{
	ft_printf("[FT_PRINTF RESULT STRING TEST]\n");
	printf("[result printf: %d]\n", printf("[1]\t[%%s]\t\t   printf: Hello %s$\n", "world"));
	printf("[result ft_printf: %d]\n\n", ft_printf("[1]\t[%%s]\t\tft_printf: Hello %s$\n", "world"));
	printf("[result printf: %d]\n", printf("[2]\t[%%4s]\t\t   printf: Hello %4s$\n", "world"));
	printf("[result ft_printf: %d]\n\n", ft_printf("[2]\t[%%4s]\t\tft_printf: Hello %4s$\n", "world"));
	printf("[result printf: %d]\n", printf("[3]\t[%%-4s]\t\t   printf: Hello %-4s$\n", "world"));
	printf("[result ft_printf: %d]\n\n", ft_printf("[3]\t[%%-4s]\t\tft_printf: Hello %-4s$\n", "world"));
	printf("[result printf: %d]\n", printf("[4]\t[%%.4s]\t\t   printf: Hello %.4s$\n", "world"));
	printf("[result ft_printf: %d]\n\n", ft_printf("[4]\t[%%.4s]\t\tft_printf: Hello %.4s$\n", "world"));
	printf("[result printf: %d]\n", printf("[5]\t[%%-.4s]\t\t   printf: Hello %-.4s$\n", "world"));
	printf("[result ft_printf: %d]\n\n", ft_printf("[5]\t[%%-.4s]\t\tft_printf: Hello %-.4s$\n", "world"));
	printf("[result printf: %d]\n", printf("[6]\t[%%50s]\t\t   printf: Hello %50s$\n", "world"));
	printf("[result ft_printf: %d]\n\n", ft_printf("[6]\t[%%50s]\t\tft_printf: Hello %50s$\n", "world"));
	printf("[result printf: %d]\n", printf("[7]\t[%%-50s]\t\t   printf: Hello %-50s$\n", "world"));
	printf("[result ft_printf: %d]\n\n", ft_printf("[7]\t[%%-50s]\t\tft_printf: Hello %-50s$\n", "world"));
	printf("[result printf: %d]\n", printf("[8]\t[%%.50s]\t\t   printf: Hello %.50s$\n", "world"));
	printf("[result ft_printf: %d]\n\n", ft_printf("[8]\t[%%.50s]\t\tft_printf: Hello %.50s$\n", "world"));
	printf("[result printf: %d]\n", printf("[9]\t[%%-.50s]\t   printf: Hello %-.50s$\n", "world"));
	printf("[result ft_printf: %d]\n\n", ft_printf("[9]\t[%%-.50s]\tft_printf: Hello %-.50s$\n", "world"));
	printf("[result printf: %d]\n", printf("[10]\t[%%s]\t   printf: Hello %s$\n", ""));
	printf("[result ft_printf: %d]\n\n", ft_printf("[10]\t[%%s]\tft_printf: Hello %s$\n", ""));
	printf("[result printf: %d]\n", printf("[11]\t[%%5s]\t   printf: Hello %5s$\n", ""));
	printf("[result ft_printf: %d]\n\n", ft_printf("[11]\t[%%5s]\tft_printf: Hello %5s$\n", ""));
	printf("[result printf: %d]\n", printf("[12]\t[%%.s]\t   printf: Hello %.0s$\n", "asdf"));
	printf("[result ft_printf: %d]\n\n", ft_printf("[12]\t[%%.s]\tft_printf: Hello %.0s$\n", "asdf"));
	printf("[result printf: %d]\n", printf("[13]\t[%%.0s]\t   printf: Hello %.0s$\n", "asdf"));
	printf("[result ft_printf: %d]\n\n", ft_printf("[13]\t[%%.0s]\tft_printf: Hello %.0s$\n", "asdf"));
	printf("[result printf: %d]\n", printf("[14]\t[%%.3s]\t   printf: Hello %.3s$\n", "asdf"));
	printf("[result ft_printf: %d]\n\n", ft_printf("[14]\t[%%.3s]\tft_printf: Hello %.3s$\n", "asdf"));
	printf("[result printf: %d]\n", printf("[15]\t[%%3s]\t   printf: Hello %3s$\n", "asdf"));
	printf("[result ft_printf: %d]\n\n", ft_printf("[15]\t[%%3s]\tft_printf: Hello %3s$\n", "asdf"));
	printf("[result printf: %d]\n", printf("[16]\t[%%*s]\t   printf: Hello %*s$\n", 15, "asdf"));
	printf("[result ft_printf: %d]\n\n", ft_printf("[16]\t[%%*s]\tft_printf: Hello %*s$\n", 15, "asdf"));
	printf("[result printf: %d]\n", printf("[17]\t[%%s]\t   printf: Hello %s$\n", NULL));
	printf("[result ft_printf: %d]\n\n", ft_printf("[17]\t[%%s]\tft_printf: Hello %s$\n", NULL));
	printf("[result printf: %d]\n", printf("[17]\t[%%*s]\t   printf: Hello %*s$\n", 15, NULL));
	printf("[result ft_printf: %d]\n\n", ft_printf("[17]\t[%%*s]\tft_printf: Hello %*s$\n", 15, NULL));
	printf("[result printf: %d]\n", printf("[18]\t[%%.s]\t   printf: Hello %.s$\n", NULL));
	printf("[result ft_printf: %d]\n\n", ft_printf("[18]\t[%%.s]\tft_printf: Hello %.s$\n", NULL));
	printf("[result printf: %d]\n", printf("[19]\t[%%7.5s]\t   printf: Hello %7.5s !$\n", "bapmarti"));
	printf("[result ft_printf: %d]\n\n", ft_printf("[19]\t[%%7.5s]\tft_printf: Hello %7.5s !$\n", "bapmarti"));
	printf("[result printf: %d]\n", printf("[19]\t[%%-7.5s]\t   printf: Hello %-7.5s !$\n", "bapmarti"));
	printf("[result ft_printf: %d]\n\n", ft_printf("[19]\t[%%-7.5s]\tft_printf: Hello %-7.5s !$\n", "bapmarti"));
	printf("[result printf: %d]\n", printf("[20]\t[%%.s]\t   printf: Hello %.s$\n", "world"));
	printf("[result ft_printf: %d]\n\n", ft_printf("[20]\t[%%.s]\tft_printf: Hello %.s$\n", "world"));
	printf("[result printf: %d]\n", printf("[21]\t[%%7.3s%%7.7s]\t   printf: %7.3s%7.7s$\n", "hello", "world"));
	printf("[result ft_printf: %d]\n\n", ft_printf("[21]\t[%%7.3s%%7.7s]\tft_printf: %7.3s%7.7s$\n", "hello", "world"));
	printf("[result printf: %d]\n", printf("[22]\t[%%*s]\t   printf: hello %*s$\n", -50, "world"));
	printf("[result ft_printf: %d]\n\n", ft_printf("[22]\t[%%*s]\tft_printf: hello %*s$\n", -50, "world"));
	printf("[result printf: %d]\n", printf("[23]\t[%%*s]\t   printf: hello %*s$\n", -2, "world"));
	printf("[result ft_printf: %d]\n\n", ft_printf("[23]\t[%%*s]\tft_printf: hello %*s$\n", -2, "world"));
}

static void		print_percent_test()
{
	ft_printf("[FT_PRINTF RESULT PERCENT TEST]\n");
	printf("[result printf: %d]\n", printf("[1]\t[%%%%]\t\t|   printf: 100%%\n"));
	printf("[result ft_printf: %d]\n", ft_printf("[1]\t[%%%%]\t\t|ft_printf: 100%%\n"));
	printf("[result printf: %d]\n", printf("[2]\t[%%5%%]\t\t|   printf: 100%5%\n"));
	printf("[result ft_printf: %d]\n", ft_printf("[2]\t[%%5%%]\t\t|ft_printf: 100%5%\n"));
	printf("[result printf: %d]\n", printf("[3]\t[%%-5%%]\t\t|   printf: 100%-5%\n"));
	printf("[result ft_printf: %d]\n", ft_printf("[3]\t[%%-5%%]\t\t|ft_printf: 100%-5%\n"));
	printf("[result printf: %d]\n", printf("[4]\t[%%.5%%]\t\t|   printf: 100%.5%\n"));
	printf("[result ft_printf: %d]\n", ft_printf("[4]\t[%%.5%%]\t\t|ft_printf: 100%.5%\n"));
	printf("[result printf: %d]\n", printf("[5]\t[%%-.5%%]\t\t|   printf: 100%-.5%\n"));
	printf("[result ft_printf: %d]\n", ft_printf("[5]\t[%%-.5%%]\t\t|ft_printf: 100%-.5%\n"));
	printf("[result printf: %d]\n", printf("[6]\t[%%-0.5%%]\t|   printf: 100%-0.5%\n"));
	printf("[result ft_printf: %d]\n", ft_printf("[6]\t[%%-0.5%%]\t|ft_printf: 100%-0.5%\n"));
	printf("[result printf: %d]\n", printf("[7]\t[%%-10.5%%]\t|   printf: 100%-10.5%\n"));
	printf("[result ft_printf: %d]\n", ft_printf("[7]\t[%%-10.5%%]\t|ft_printf: 100%-10.5%\n"));
	printf("[result printf: %d]\n", printf("[8]\t[%%10.5%%]\t|   printf: 100%10.5%\n"));
	printf("[result ft_printf: %d]\n", ft_printf("[8]\t[%%10.5%%]\t|ft_printf: 100%10.5%\n"));
	printf("[result printf: %d]\n", printf("[9]\t[%%%%%%%%%%%%%%%%%%%%]\t|   printf: 100%%%%%%%%%%\n"));
	printf("[result ft_printf: %d]\n", ft_printf("[9]\t[%%%%%%%%%%%%%%%%%%%%]\t|ft_printf: 100%%%%%%%%%%\n"));
	printf("[result printf: %d]\n", printf("[10]\t[%%%%%%%%%%%%%%%%%%9%%]\t|   printf: 100%%%%%%%%%9%\n"));
	printf("[result ft_printf: %d]\n", ft_printf("[10]\t[%%%%%%%%%%%%%%%%%%9%%]\t|ft_printf: 100%%%%%%%%%9%\n"));
	
	printf("[result printf: %d]\n", printf("[11]\t[%%05%%]\t\t|   printf: 100%05%\n"));
	printf("[result ft_printf: %d]\n", ft_printf("[11]\t[%%05%%]\t\t|ft_printf: 100%05%\n"));
	printf("[result printf: %d]\n", printf("[11]\t[%%05%%]\t\t|   printf: 100%05c\n", 'c'));
	printf("[result ft_printf: %d]\n", ft_printf("[11]\t[%%05%%]\t\t|ft_printf: 100%05c\n", 'c'));
	printf("[result printf: %d]\n", printf("[11]\t[%%05%%]\t\t|   printf: 100%-05c\n", 'c'));
	printf("[result ft_printf: %d]\n", ft_printf("[11]\t[%%05%%]\t\t|ft_printf: 100%-05c\n", 'c'));
}
int		main()
{
	char test = 'h';

	printf("Welcome in my own printf tester\n");
	printf("enter 'h' if you need help !\n");
	scanf(" %c", &test);
	while (test != 'e' && test != 'q') {
		printf("char scanned: %c\n", test);
		if (test == '%') {
			system("clear");
			printf("========================================\n");
			print_percent_test();
			printf("========================================\n");
		}
		else if (test== 'c') {
			system("clear");
			printf("========================================\n");
			print_char_test();
			printf("========================================\n");
		}
		else if (test == 's') {
			system("clear");
			printf("========================================\n");
			print_string_test();
			printf("========================================\n");
		}
		else if (test == 'h'){
			system("clear");
			printf("Made with ❤️  by bapmarti\n");
			printf("My github: https://github.com/baptistemrt\n");
			printf("Use char to see test on your own printf and the real printf\n");
			printf("[p = percent, c = char, s = string, q = quit or e = exit]\n");
		}
		scanf(" %c", &test);
	}
	printf("goodbye !\n");
	return (0);
}