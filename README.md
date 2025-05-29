# ft_printf

A custom implementation of the C standard library `printf` function, created as part of the 42 School curriculum.

## Description

ft_printf is a recreation of the printf function from the C standard library. This project aims to understand variadic functions and improve programming skills through implementing one of the most complex and well-known C library functions.

## Features

The ft_printf function supports the following conversions:

- `%c` - Character
- `%s` - String
- `%p` - Pointer address in hexadecimal format
- `%d` - Decimal (base 10) number
- `%i` - Integer in base 10
- `%u` - Unsigned decimal (base 10) number
- `%x` - Number in hexadecimal (base 16) lowercase format
- `%X` - Number in hexadecimal (base 16) uppercase format
- `%%` - Percent sign

## Project Structure

```
.
├── ft_printf.c      # Main printf function implementation
├── ft_printf.h      # Header file with function prototypes
├── putchar.c        # Character output function
├── putstr.c         # String output function
├── putnbr.c         # Integer output function
├── putnbr_uns.c     # Unsigned integer output function
├── hexa.c           # Hexadecimal output function
├── pointer_hx.c     # Pointer address output function
└── Makefile         # Build configuration
```

## Installation

1. Clone the repository:
```bash
git clone https://github.com/Marouane0107/printf.git
cd printf
```

2. Compile the library:
```bash
make
```

This will create a `libftprintf.a` static library file.

## Usage

Include the header file in your C program and link with the compiled library:

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello, %s!\n", "world");
    ft_printf("Number: %d\n", 42);
    ft_printf("Hex: %x\n", 255);
    ft_printf("Pointer: %p\n", &main);
    return (0);
}
```

Compile your program with the library:
```bash
gcc -Wall -Wextra -Werror your_program.c libftprintf.a -o your_program
```

## Makefile Rules

- `make` or `make all` - Compile the library
- `make clean` - Remove object files
- `make fclean` - Remove object files and the library
- `make re` - Recompile everything from scratch

## Implementation Details

The ft_printf function uses variadic arguments (`stdarg.h`) to handle a variable number of parameters. The implementation includes:

- **ft_printf**: Main function that processes the format string and calls appropriate helper functions
- **ft_type**: Parser function that identifies format specifiers and calls corresponding output functions
- **Helper functions**: Individual functions for each data type conversion and output

### Key Functions

- `ft_putchar(char c)` - Outputs a single character
- `ft_putstr(char *s)` - Outputs a string (handles NULL strings)
- `ft_putnbr(int n)` - Outputs signed integers (handles INT_MIN)
- `ft_putnbr_uns(unsigned int n)` - Outputs unsigned integers
- `ft_hexa(unsigned long nb, int base)` - Outputs hexadecimal numbers
- `ft_pointer_hx(unsigned long nb)` - Outputs pointer addresses

## Testing

The function returns the number of characters printed, just like the original printf function. You can test the implementation by comparing outputs with the standard printf:

```c
#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
    int std_ret, ft_ret;
    
    std_ret = printf("Standard: %d\n", 42);
    ft_ret = ft_printf("Custom:   %d\n", 42);
    
    printf("Standard returned: %d\n", std_ret);
    printf("Custom returned: %d\n", ft_ret);
    
    return (0);
}
```

## Compilation Flags

The project is compiled with strict flags to ensure code quality:
- `-Wall` - Enable all common warnings
- `-Wextra` - Enable extra warnings
- `-Werror` - Treat warnings as errors

## Learning Objectives

This project helps understand:
- Variadic functions in C
- String parsing and manipulation
- Type conversion and formatting
- Memory management
- Modular programming
- Makefile usage

## Author

**Marouane Aouzal**  
Student at **1337**  
GitHub: [@Marouane0107](https://github.com/Marouane0107)

## License

This project is part of the 42 School curriculum and follows the school's academic policies.

---

*Note: This implementation is for educational purposes and may not include all features of the standard printf function.*
