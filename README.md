*This project has been created as part of the 42 curriculum by luricci.*

# ft_printf

## Description

The **ft_printf** project is a reimplementation of the standard C library function `printf`.  
The goal of this project is to gain a deep understanding of **variadic functions**, **format parsing**, and **low-level output handling** in C, while strictly respecting coding standards and constraints.

This custom implementation reproduces the behavior of `printf` for the mandatory conversions, without using dynamic memory allocation (`malloc` / `free`) or relying on external libraries such as `libft`.

## Features

This implementation supports all **mandatory conversions** required by the 42 subject:

- `%c` — character
- `%s` — string
- `%p` — pointer address
- `%d` / `%i` — signed decimal integer
- `%u` — unsigned decimal integer
- `%x` / `%X` — hexadecimal (lowercase / uppercase)
- `%%` — literal percent sign

Additional features:
- Fully compliant with `-Wall -Wextra -Werror`
- No memory allocation
- No use of `libft`
- Output written using low-level system calls
- Clean and modular design

## Algorithm and Data Structures

### Overall Algorithm

The function `ft_printf` processes the format string character by character:

1. **Format String Parsing**
   - Iterate through the format string.
   - If a character is not `%`, print it directly.
   - If `%` is encountered, analyze the following character to determine the conversion type.

2. **Variadic Argument Handling**
   - Use `va_start`, `va_arg`, and `va_end` to retrieve arguments.
   - Each conversion specifier fetches the corresponding argument type.

3. **Conversion Dispatching**
   - A dedicated function routes each specifier (`c`, `s`, `d`, etc.) to the appropriate handler.
   - Each handler is responsible for formatting and printing its value.

4. **Output**
   - All output is written using `write(1, ...)`.
   - A character counter is maintained to return the total number of printed characters, matching `printf`’s behavior.

### Data Structures

No complex data structures are used due to project constraints.

- **Primitive types** (`int`, `unsigned int`, `char *`)
- **Recursive integer printing** for numeric conversions
- **Base conversion logic** for hexadecimal output

This approach ensures simplicity, efficiency, and compliance with the restriction of not using dynamic memory allocation.

## Instructions

### Compilation

The project is compiled using `make`:

```bash
make
```

Compilation uses:
```bash
cc -Wall -Wextra -Werror
```

### Makefile Rules

The Makefile includes the following rules:

- `make` — compile the library
- `make clean` — remove object files
- `make fclean` — remove object files and executable/library
- `make re` — recompile everything

### Integration

Include the header and link the object files or library in your project:

```c
#include "ft_printf.h"
```

## Usage Example

```c
#include "ft_printf.h"

int main(void)
{
    int count;

    count = ft_printf("Hello %s! Number: %d, Hex: %x\n", "42", 42, 42);
    ft_printf("Printed %d characters\n", count);
    return (0);
}
```

Expected output:
```
Hello 42! Number: 42, Hex: 2a
Printed 29 characters
```

## Technical Constraints

- No use of `malloc` or `free`
- No use of `libft`
- No bonus features implemented
- Only mandatory conversions supported
- Fully compliant with 42 Norm

## Resources

### Technical References

- `man printf`
- `man stdarg`
-  Internet
-  youtube
-  42 ft_printf subject PDF

## License

This project is licensed under the **MIT License**.
