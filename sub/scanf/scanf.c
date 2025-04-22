#include <stdarg.h>
#include <stdio.h>
#include <ctype.h>

void skip_input_space()
{
    int ch;
    while (isspace(ch = fgetc(stdin)) && ch != EOF)
        ;
    if (ch != EOF)
        ungetc(ch, stdin);
}

int scan_char(va_list ap)
{
    int ch = fgetc(stdin);
    if (ch == EOF)
        return 1; // error
    char *arg = va_arg(ap, char *);
    *arg = ch;
    return 0;
}

int scan_int(va_list ap)
{
    int result = 0;
    int ch;
    int found = 0;

    while ((ch = fgetc(stdin)) != EOF)
    {
        if (isdigit(ch))
        {
            result = result * 10 + (ch - '0');
            found = 1;
        }
        else
        {
            ungetc(ch, stdin);
            break;
        }
    }

    if (!found)
        return 1; // no digits found

    int *arg = va_arg(ap, int *);
    *arg = result;
    return 0;
}

int scan_string(va_list ap)
{
    char *str = va_arg(ap, char *);
    int ch;
    int i = 0;

    while ((ch = fgetc(stdin)) != EOF && !isspace(ch))
        str[i++] = ch;
    str[i] = '\0';

    if (i == 0)
        return 1; // nothing read
    if (ch != EOF)
        ungetc(ch, stdin);
    return 0;
}

int receive_input(const char **format, va_list ap)
{
    if (**format == '\0')
        return -1;

    char spec = **format;

    switch (spec)
    {
        case 'c':
            return scan_char(ap);
        case 'd':
            skip_input_space();
            return scan_int(ap);
        case 's':
            skip_input_space();
            return scan_string(ap);
        default:
            return -1;
    }
}

int ft_scanf(const char *format, ...)
{
    int i = 0;
    int result = 0;
    va_list ap;

    va_start(ap, format);

    while (format[i] != '\0')
    {
        if (isspace(format[i]))
        {
            skip_input_space();
            i++;
            continue;
        }

        if (format[i] == '%')
        {
            i++;
            if (format[i] == '\0')
                break;
            if (receive_input(&format[i], ap) != 0)
                break;
            result++;
        }
        else
        {
            // match literal
            int ch = fgetc(stdin);
            if (ch != format[i])
                break;
        }
        i++;
    }

    va_end(ap);
    return result;
}
