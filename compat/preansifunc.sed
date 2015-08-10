# Convert the delcaration of void functions to pre-ANSI style
# > do_something(void)
# becomes
# > do_something()
s/^\([a-zA-Z_][a-zA-Z0-9_]*\) *(void)/\1()/

# Convert the declaration of 1-argument functions to pre-ANSI style
# > do_something(int a)
# becomes
# > do_something(a)
# > int a;
s/^\([a-zA-Z_][a-zA-Z0-9_]*\) *(\([a-zA-Z_][a-zA-Z0-9_]* *\**\) *\([a-zA-Z_][a-zA-Z0-9_]*\))/\1(\3)\n\2 \3;/

# Convert the declaration of 2-argument functions to pre-ANSI style
# > do_something(int a, int b)
# becomes
# > do_something(a, b)
# > int a;
# > int b;
s/^\([a-zA-Z_][a-zA-Z0-9_]*\) *(\([a-zA-Z_][a-zA-Z0-9_]* *\**\) *\([a-zA-Z_][a-zA-Z0-9_]*\), *\([a-zA-Z_][a-zA-Z0-9_]* *\**\) *\([a-zA-Z_][a-zA-Z0-9_]*\))/\1(\3, \5)\n\2 \3;\n\4 \5;/

# Convert the declaration of 3-argument functions to pre-ANSI style
# > do_something(int a, int b, int c)
# becomes
# > do_something(a, b, c)
# > int a;
# > int b;
# > int c;
s/^\([a-zA-Z_][a-zA-Z0-9_]*\) *(\([a-zA-Z_][a-zA-Z0-9_]* *\**\) *\([a-zA-Z_][a-zA-Z0-9_]*\), *\([a-zA-Z_][a-zA-Z0-9_]* *\**\) *\([a-zA-Z_][a-zA-Z0-9_]*\), *\([a-zA-Z_][a-zA-Z0-9_]* *\**\) *\([a-zA-Z_][a-zA-Z0-9_]*\))/\1(\3, \5, \7)\n\2 \3;\n\4 \5;\n\6 \7;/

# Convert the declaration of 4-argument functions to pre-ANSI style
# > do_something(int a, int b, int c, int d)
# becomes
# > do_something(a, b, c, d)
# > int a;
# > int b;
# > int c;
# > int d;
s/^\([a-zA-Z_][a-zA-Z0-9_]*\) *(\([a-zA-Z_][a-zA-Z0-9_]* *\**\) *\([a-zA-Z_][a-zA-Z0-9_]*\), *\([a-zA-Z_][a-zA-Z0-9_]* *\**\) *\([a-zA-Z_][a-zA-Z0-9_]*\), *\([a-zA-Z_][a-zA-Z0-9_]* *\**\) *\([a-zA-Z_][a-zA-Z0-9_]*\), *\([a-zA-Z_][a-zA-Z0-9_]* *\**\) *\([a-zA-Z_][a-zA-Z0-9_]*\))/\1(\3, \5, \7, \9)\n\2 \3;\n\4 \5;\n\6 \7;\n\8 \9;/
