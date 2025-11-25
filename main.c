#include "ft_printf.h"
#include <stdio.h>

int  main()
{
  ft_printf("hola %sabc%dabc%X\n", "mundo", 123, 15);
  printf("hola %sabc%dabc%X\n", "mundo", 123, 15);
  return (0);
}
