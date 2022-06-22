/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvarags@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 22:19:13 by dvargas           #+#    #+#             */
/*   Updated: 2022/06/22 02:13:42 by dvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_putchar(int c)
{
	write(1,&c, 1);
	return (1);
}

int ft_putstr(char *str)
{
	int i;

	i = 0;
	if (str == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int ft_treatchar(char str, va_list list)
{
	int i;

	i = 0;
	if (str == 'c')
		i += ft_putchar(va_arg(list, int));
	else if (str == 's')
		i += ft_putstr(va_arg(list, char *));
	else if (str == 'p')
		i += ft_putp(va_arg(list, void *));
	else if (str == 'd' || str == 'i')
		i += ft_putnbr(va_arg(list, int));
	else if (str == 'u')
		i += ft_putnbru(va_arg(list, unsigned int));
	else if (str == 'x')
		i += ft_puthex(va_arg(list, unsigned int), "0123456789abcdef");
	else if (str == 'X')
		i += ft_puthex(va_arg(list, unsigned int), "0123456789ABCDEF");	
	else if (str == '%')
		i += ft_putchar('%');
	else
		return (0);
	return (i);
}

int ft_printf(const char *str, ...)
{
	int		i;
	int		f;
	va_list	list;

	i = 0;
	f = 0;
	va_start(list, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			f += ft_treatchar(str[i + 1], list);
			i++;
		}
		else 
			f+= ft_putchar(str[i]);
		i++;
	}
	va_end(list);
	return(f);
}






/*
 * Esse pojeto visa recriar a função printf.
 * A função printf tem como objetivo imprimir um output na saída padrão do 
 * terminal.
 * Printf é uma função do tipo "Variadic" ou seja, ela consegue lidar com uma 
 * quantidade "infinita" de argumentos, por isso ela tem (...) no fim de sua
 * declaração.
 * Ela deve ser prototipada dessa forma
 *
 * int ft_printf(const char*, ...)
 *
 * Podemos utilizar a LIBFT no projeto.
 * As funções liberadas para utilizar nesse projto são:
 * Malloc, Free, Write, va_start, va_arg, va_copy, va_end
 *
 * ========================NOVAS FUNÇÕES (OU MACROS) =========================
 * Oque são essas novas funções?
 * Na verdade elas são macros de manipulação das funções ditas Variadic.
 * Como funcionam essas novas funções ?
 * 
 * Fazem parte da biblioteca "stdarg.h"
 *
 * Precisamos inicializar um ponteiro do tipo
 * va_list para conseguirmos ler os argumentos passados.
 *
 * va_start = void va_start(va_list ap, last-required)
 * Esse macro inicializará o ponteiro AP para o primeiro argumento, last-required
 * é sempre o ultimo argumento fixo que foi requisitado pela variadic function.
 * 
 * va_arg = type va_arg(va_list ap, type)
 * Esse macro retorna o valor do próximo argumento opcional e define o valor de 
 * ap para apontar para ele.
 * O tipo retornado será especificado peltype dado na chamada do macro
 * Type deve ser um valor auto-promovido(nao poderá ser char, short int ou float)
 *
 * va_copy = void va_copy(va_list dest, va_list src)
 * Podemos fazer umma copia de dest para src caso necessário.
 *
 * va_end = void va_end(va_list ap)
 * Esse macro termina o uso do ponteiro ap, fazendo com que futuras chamadas 
 * do macro va_args para esse mesmo ap nao funcionem, esse é o macro usado antes do retorno
 *
 * Resumindo
 *
 * va_list ap;
 *
 * va_start(ap, string a ser lida)
 * Trabalhamos o código, caso necessário utilizar outras macros.
 * no momento de trabalhar a string precisamos chamar o macro va_args, exemplo:
 * if 'c'
 *	string = ft_putchar (va_args(ap, int));
 *
 * va_end(ap) // fechando a lista de argumentos.
 * return(int); // no caso da ft_printf retornaremos um int;
 *============================================================================
 *
 * Pq diabos a printf retorna um inteiro ?
 * simples fato de que a função responsavel por escrever no fd padrão (1)
 * será write, chamada no meio da nossa printf
 *
 * Ideia inicial da printf.
 * Leia um caractere passado no primeiro argumento
 * - Ele é um "%" ? NAO ---> imprima o caractere.
 * - Ele é um "%" ? SIM ---> o proximo caractere é o tipo de informação que 
 *   será tratado e impresso.
 *   %c = imprime um unico caractere == ft_putchar
 *   %s = imprime uma string == ft_putstr
 *   %p = o * Ponteiro do argumento deve ser impresso e forma hexadecimal == ???
 *   %d = imprime um numero decimal == ft_putbr?
 *	 %i = imprime um inteiro em base 10 == ft_putnbr
 *	 %u = imprime um unsigned decimal == ft_putnbr
 *	 %x = Imprime um numero em hexadecimal (base16) em minusculo == novo putnbr?
 *	 %X = Imprime um numero em hexadecimal (base16) em MAIUSCULO == novo putnbr?
 *	 %% = Imprime um sinal de porcentagem. == ft_putchar('%')
 * - Repira o processo ate chegar ao fim da string passada.
 * 
 * A ideia aqui é que a função principal faça a varredura na string e identifiqe
 * o caractere %, ela chamará outra função que tem como objetivo selecionar a fo
 * rma como será feita a tratativa do caractere 
 *
 *
 *
 * ===========================================================================
 * BÔNUS !!!! 
 * O bônus consiste em recriar o printf em sua forma original que tem
 * a seguinte estrutura
 * printf %[parameter][flags][width][.precision][lenght] "type"
 *
 * Também é necessário lidar com os outros parametros
 * '# -' (sim tem um espaço no meio)
 *
 * A printf podera ser adicionada a nossa libft ao final do projeto
 * */
