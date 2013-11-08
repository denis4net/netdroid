/*

.Modifier   Type(s)
.   hh      d, i, o, u, x, n  convert input to char,
.                             store in char object
.
.   h       d, i, o, u, x, n  convert input to short,
.                             store in short object
.
.   h       D, I, O, U, X     no effect
.           e, f, c, s, p
.
.   j       d, i, o, u, x, n  convert input to intmax_t,
.                             store in intmax_t object
.
.   j       all others        no effect
.
.   l       d, i, o, u, x, n  convert input to long,
.                             store in long object
.
.   l       e, f, g           convert input to double
.                             store in a double object
.
.   l       D, I, O, U, X     no effect
.           c, s, p
.
.   ll      d, i, o, u, x, n  convert to long long,
.                             store in long long
.
.   L       d, i, o, u, x, n  convert to long long,
.                             store in long long
.
.   L       e, f, g, E, G     convert to long double,
.                             store in long double
.
.   L       all others        no effect
.
.   t       d, i, o, u, x, n  convert input to ptrdiff_t,
.                             store in ptrdiff_t object
.
.   t       all others        no effect
.
.   z       d, i, o, u, x, n  convert input to size_t,
.                             store in size_t object
.
.   z       all others        no effect
.


        o <[type]>

                A character to specify what kind of conversion
                <<scanf>> performs.  Here is a table of the conversion
                characters:

                o+
                o  %
                No conversion is done; the percent character (<<%>>) is stored.

                o c
                Scans one character.  Corresponding <[arg]>: <<(char *arg)>>.

                o s
                Reads a character string into the array supplied.
                Corresponding <[arg]>: <<(char arg[])>>.

                o  [<[pattern]>]
                Reads a non-empty character string into memory
                starting at <[arg]>.  This area must be large
                enough to accept the sequence and a
                terminating null character which will be added
                automatically.  (<[pattern]> is discussed in the paragraph following
                this table). Corresponding <[arg]>: <<(char *arg)>>.

                o d
                Reads a decimal integer into the corresponding <[arg]>: <<(int *arg)>>.

                o D
                Reads a decimal integer into the corresponding
                <[arg]>: <<(long *arg)>>.

                o o
                Reads an octal integer into the corresponding <[arg]>: <<(int *arg)>>.

                o O
                Reads an octal integer into the corresponding <[arg]>: <<(long *arg)>>.

                o u
                Reads an unsigned decimal integer into the corresponding
                <[arg]>: <<(unsigned int *arg)>>.
                        

                o U
                Reads an unsigned decimal integer into the corresponding <[arg]>:
                <<(unsigned long *arg)>>.

                o x,X
                Read a hexadecimal integer into the corresponding <[arg]>:
                <<(int *arg)>>.

                o e, f, g
                Read a floating-point number into the corresponding <[arg]>:
                <<(float *arg)>>.

                o E, F, G
                Read a floating-point number into the corresponding <[arg]>:
                <<(double *arg)>>.

                o  i
                Reads a decimal, octal or hexadecimal integer into the
                corresponding <[arg]>: <<(int *arg)>>.

                o  I
                Reads a decimal, octal or hexadecimal integer into the
                corresponding <[arg]>: <<(long *arg)>>.

                o  n
                Stores the number of characters read in the corresponding
                <[arg]>: <<(int *arg)>>.

                o  p
                Stores a scanned pointer.  ANSI C leaves the details
                to each implementation; this implementation treats
                <<%p>> exactly the same as <<%U>>.  Corresponding
                <[arg]>: <<(void **arg)>>.  
                o-

        A <[pattern]> of characters surrounded by square brackets can be used
        instead of the <<s>> type character.  <[pattern]> is a set of
        characters which define a search set of possible characters making up
        the <<scanf>> input field.  If the first character in the brackets is a
        caret (<<^>>), the search set is inverted to include all ASCII characters
        except those between the brackets.  There is also a range facility
        which you can use as a shortcut. <<%[0-9] >> matches all decimal digits.
        The hyphen must not be the first or last character in the set.
        The character prior to the hyphen must be lexically less than the
        character after it.

        Here are some <[pattern]> examples:
                o+
                o %[abcd]
                matches strings containing only <<a>>, <<b>>, <<c>>, and <<d>>.

                o %[^abcd]
                matches strings containing any characters except <<a>>, <<b>>,
                <<c>>, or <<d>>

                o %[A-DW-Z]
                matches strings containing <<A>>, <<B>>, <<C>>, <<D>>, <<W>>,
                <<X>>, <<Y>>, <<Z>>

                o %[z-a]
                matches the characters  <<z>>, <<->>, and <<a>>
                o-

        Floating point numbers (for field types <<e>>, <<f>>, <<g>>, <<E>>,
        <<F>>, <<G>>) must correspond to the following general form:

.               [+/-] ddddd[.]ddd [E|e[+|-]ddd]

        where objects inclosed in square brackets are optional, and <<ddd>>
        represents decimal, octal, or hexadecimal digits.
        o-

RETURNS
        <<scanf>> returns the number of input fields successfully
        scanned, converted and stored; the return value does
        not include scanned fields which were not stored.

        If <<scanf>> attempts to read at end-of-file, the return
        value is <<EOF>>.

        If no fields were stored, the return value is <<0>>.

        <<scanf>> might stop scanning a particular field before
        reaching the normal field end character, or may
        terminate entirely.

        <<scanf>> stops scanning and storing the current field
        and moves to the next input field (if any)
        in any of the following situations:

        O+
        o       The assignment suppressing character (<<*>>) appears
        after the <<%>> in the format specification; the current
        input field is scanned but not stored.

        o       <[width]> characters have been read (<[width]> is a
        width specification, a positive decimal integer).

        o       The next character read cannot be converted
        under the the current format (for example,
        if a <<Z>> is read when the format is decimal).

        o       The next character in the input field does not appear
        in the search set (or does appear in the inverted search set).
        O-

        When <<scanf>> stops scanning the current input field for one of
        these reasons, the next character is considered unread and
        used as the first character of the following input field, or the
        first character in a subsequent read operation on the input.

        <<scanf>> will terminate under the following circumstances:

        O+
        o       The next character in the input field conflicts
        with a corresponding non-whitespace character in the
        format string.

        o       The next character in the input field is <<EOF>>.

        o       The format string has been exhausted.
        O-

        When the format string contains a character sequence that is
        not part of a format specification, the same character
        sequence must appear in the input; <<scanf>> will
        scan but not store the matched characters.  If a
        conflict occurs, the first conflicting character remains in the input
        as if it had never been read.

PORTABILITY
<<scanf>> is ANSI C.

Supporting OS subroutines required: <<close>>, <<fstat>>, <<isatty>>,
<<lseek>>, <<read>>, <<sbrk>>, <<write>>.
*/

#include <stdarg.h>

char *scan_string (const char *str, int base)
{
        char *str_ptr = (char*) str;

        switch (base)
        {
                case 10:
                        while (!(isdigit(*str_ptr) || *str_ptr == '-' || *str_ptr == 0x0))
                        {
                                str_ptr++;
                        } 
                        break;
                case 16:
                        while (!(isxdigit(*str_ptr) || *str_ptr == 0x0))
                        {
                                str_ptr++;
                        } 
                        break;
        }

        return str_ptr;
}

int sscanf(const char *str, const char *fmt, ...)
{
        int ret;
        va_list ap;
        char *format_ptr = (char*)fmt;
        char *str_ptr = (char*)str;

        int *p_int;
        long *p_long;

        ret = 0;

        va_start (ap, fmt);

        while ((*format_ptr != 0x0) && (*str_ptr !=     0x0))
        {
                if (*format_ptr == '%')
                {
                        format_ptr++;

                        if (*format_ptr != 0x0)
                        {
                                switch (*format_ptr)
                                {
                                case 'd':       // expect an int
                                case 'i':
                                        p_int = va_arg( ap, int *);
                                        str_ptr=scan_string(str_ptr, 10);
                                        if (*str_ptr==0x0) goto end_parse; 
                                        *p_int = (int)strtol (str_ptr, &str_ptr, 10);
                                        ret ++;
                                        break;
                                case 'D':
                                case 'I':       // expect a long
                                        p_long = va_arg( ap, long *);
                                        str_ptr=scan_string(str_ptr, 10);
                                        if (*str_ptr==0x0) goto end_parse;
                                        *p_long = strtol (str_ptr, &str_ptr, 10);
                                        ret ++;
                                        break;
                                case 'x':       // expect an int in hexadecimal format
                                        p_int = va_arg( ap, int *);
                                        str_ptr=scan_string(str_ptr, 16);
                                        if (*str_ptr==0x0) goto end_parse;
                                        *p_int = (int)strtol (str_ptr, &str_ptr, 16);
                                        ret ++;
                                        break;
                                case 'X':  // expect a long in hexadecimal format       
                                        p_long = va_arg( ap, long *);
                                        str_ptr=scan_string(str_ptr, 16);
                                        if (*str_ptr==0x0) goto end_parse;
                                        *p_long = strtol (str_ptr, &str_ptr, 16);
                                        ret ++;
                                        break;
                                }
                        }
                }
                
                format_ptr++;
        }       

end_parse:      
        va_end (ap);

        if (*str_ptr == 0x0) ret = -1;
        return ret;
}
