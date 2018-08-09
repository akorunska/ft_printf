# ft_printf

Regardless of the programming language considered, the printf function,(or its equivalents) is always highly useful. The main reason is the ease of its formatting, and the support of diverse types in variable numbers.

This is a recoded the libc’s printf function. ft_printf assepts following conversions: sSpdDioOuUxXcC.

`%%`, `#0*-+` flags and space, minimum field-width, precision and `hh, h, l, ll, j, z` are also managed.
