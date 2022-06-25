/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvarags@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 17:24:18 by dvargas           #+#    #+#             */
/*   Updated: 2022/06/25 11:24:20 by dvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
int main()
{
	ft_printf("LINDO TESTE DA PRINTF \n");
	char c = 'D';
	printf("Original tentando imprimir um caractere %c \n", c);
	ft_printf("FT imprimindo caractere: %c \n", c) ;
	ft_printf("------------------------------------ \n");
	char *s = "Luna é Linda";
	printf("Original tentando imprimir uma string %s \n", s);
	ft_printf("FT imprimindo uma string %s \n", s) ;
	ft_printf("------------------------------------ \n");
	char *p = "lindo";
	printf("Original tentando imprimir o endereço de ponteiro %p \n",p);
	ft_printf("FT imprimindo o ponteiro %p \n", p) ;
	ft_printf("------------------------------------ \n");
	int d = 0;
	printf("Original imprimindo decimal %d \n", d);
	ft_printf("FT imprimindo decimal %d \n", d) ;
	ft_printf("------------------------------------ \n");
	int i = 0;
	printf("Original imprimindo inteiro %d \n", i);
	ft_printf("FT imprimindo inteiro %d  \n", i);
	ft_printf("------------------------------------ \n");
	unsigned int u = 0;
	printf("Original imprimindo unsigned int %u \n", u);
	ft_printf("FT imprimindo unsgined nbr %u  \n", u);
	ft_printf("------------------------------------ \n");
	int x = 0;
	printf("Original imprimindo hexadecimal %x \n", x);
	ft_printf("FT imprimindo hexadecimal %x \n", x);
	ft_printf("------------------------------------ \n");
	int X = 0;
	printf("Original imprimindo HEXADECIMAL Maiusculo %X \n", X);
	ft_printf("FT imprimindo HEXADECIMAL %X \n", X);
	ft_printf("------------------------------------ \n");
	printf("Original usando a regra Porcento %% \n");
	ft_printf("FT usando a regra Porcento %% \n");
	ft_printf("==================================== \n");
	ft_printf("AGORA TESTES NA LOUCURA DA VIDA \n");
	char *s1 = "";
	ft_printf("Testando com string vazia %s \n", s1);
	printf("Testando com string vazia %s \n", s1);
	
}

