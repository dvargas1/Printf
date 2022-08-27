# ft_printf :pencil2:

Write a library that contains **ft_printf()**, a function that will mimic the original printf()

## Function Prototype

The Funcion prototype should be like this:
``
int ft_printf(const char *, ...)
``

### Requirements
 - Don’t implement the buffer management of the original printf().
- Your function has to handle the following conversions: cspdiuxX%

### Implemented conversions

| Parâmetro   | Tipo       | Descrição                           |
| :---------- | :--------- | :---------------------------------- |
| ` %c` | `string` | Prints a single character. |
| `%s` | `string` | Prints a string (as defined by the common C convention). |
| `%p` | `string` | The void * pointer argument has to be printed in hexadecimal format. |
| `%d` | `string` | Prints a decimal (base 10) number. |
| `%i` | `string` | Prints an integer in base 10. |
| `%u` | `string` | Prints an unsigned decimal (base 10) number. |
| `%x` | `string` | Prints a number in hexadecimal (base 16) lowercase format. |
| `%X` | `string` | Prints a number in hexadecimal (base 16) uppercase format. |
| `%%` | `string` | Prints a percent sign |


## Grade
100/100
