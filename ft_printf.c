/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvarags@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 22:19:13 by dvargas           #+#    #+#             */
/*   Updated: 2022/06/22 18:37:24 by dvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

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

int	ft_treatchar(char str, va_list list)
{
	int	i;

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

int	ft_printf(const char *str, ...)
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
			f += ft_putchar(str[i]);
		i++;
	}
	va_end(list);
	return (f);
}
/*
 * Esse pojeto visa recriar a fun????o printf.
 * A fun????o printf tem como objetivo imprimir um output na sa??da padr??o do 
 * terminal.
 * Printf ?? uma fun????o do tipo "Variadic" ou seja, ela consegue lidar com uma 
 * quantidade "infinita" de argumentos, por isso ela tem (...) no fim de sua
 * declara????o.
 * Ela deve ser prototipada dessa forma
 *
 * int ft_printf(const char*, ...)
 *
 * Podemos utilizar a LIBFT no projeto.
 * As fun????es liberadas para utilizar nesse projto s??o:
 * Malloc, Free, Write, va_start, va_arg, va_copy, va_end
 *
 * ========================NOVAS FUN????ES (OU MACROS) =========================
 * Oque s??o essas novas fun????es?
 * Na verdade elas s??o macros de manipula????o das fun????es ditas Variadic.
 * Como funcionam essas novas fun????es ?
 * 
 * Fazem parte da biblioteca "stdarg.h"
 *
 * Precisamos inicializar um ponteiro do tipo
 * va_list para conseguirmos ler os argumentos passados.
 *
 * va_start = void va_start(va_list ap, last-required)
 * Esse macro inicializar?? o ponteiro AP para o primeiro argumento, last-require
 * ?? sempre o ultimo argumento fixo que foi requisitado pela variadic function.
 * 
 * va_arg = type va_arg(va_list ap, type)
 * Esse macro retorna o valor do pr??ximo argumento opcional e define o valor de 
 * ap para apontar para ele.
 * O tipo retornado ser?? especificado peltype dado na chamada do macro
 * Type deve ser um valor auto-promovido(nao poder?? ser char, short int ou float
 *
 * va_copy = void va_copy(va_list dest, va_list src)
 * Podemos fazer umma copia de dest para src caso necess??rio.
 *
 * va_end = void va_end(va_list ap)
 * Esse macro termina o uso do ponteiro ap, fazendo com que futuras chamadas 
 * do macro va_args para esse mesmo ap nao funcionem, esse ?? o macro usado 
 * antes do retorno
 *
 * Resumindo
 *
 * va_list ap;
 *
 * va_start(ap, string a ser lida)
 * Trabalhamos o c??digo, caso necess??rio utilizar outras macros.
 * no momento de trabalhar a string precisamos chamar o macro va_args, exemplo:
 * if 'c'
 *	string = ft_putchar (va_args(ap, int));
 *
 * va_end(ap) // fechando a lista de argumentos.
 * return(int); // no caso da ft_printf retornaremos um int;
 *============================================================================
 *
 * Pq diabos a printf retorna um inteiro ?
 * simples fato de que a fun????o responsavel por escrever no fd padr??o (1)
 * ser?? write, chamada no meio da nossa printf
 *
 * Ideia inicial da printf.
 * Leia um caractere passado no primeiro argumento
 * - Ele ?? um "%" ? NAO ---> imprima o caractere.
 * - Ele ?? um "%" ? SIM ---> o proximo caractere ?? o tipo de informa????o que 
 *   ser?? tratado e impresso.
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
 * A ideia aqui ?? que a fun????o principal fa??a a varredura na string e identifiqe
 * o caractere %, ela chamar?? outra fun????o que tem como objetivo selecionar a fo
 * rma como ser?? feita a tratativa do caractere 
 *
 *
 *
 * ===========================================================================
 * B??NUS !!!! 
 * O b??nus consiste em recriar o printf em sua forma original que tem
 * a seguinte estrutura
 * printf %[parameter][flags][width][.precision][lenght] "type"
 *
 * Tamb??m ?? necess??rio lidar com os outros parametros
 * '# -' (sim tem um espa??o no meio)
 *
 * A printf podera ser adicionada a nossa libft ao final do projeto
 * */
