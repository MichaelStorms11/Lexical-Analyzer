# Lexical-Analyzer
This is a lexical analyzer in C that can identify lexemes and tokens found in a source code file provided
by the user. Once the analyzer has identified the lexemes of the language and matched them to a token group,
the program will print each lexeme / token pair to the screen.
The source code file provided by the user will be written in a new programming language called “DanC” and is
based upon the following grammar (in BNF):

P ::= S

S ::= V=E | read(V) | print(V) | do { S } while C | S;S

C ::= E < E | E > E | E == E | E <> E | E <= E | E >= E

E ::= T | E + T | E - T

T ::= F | T * F | T / F | T % F

F ::= (E) | N | V

V ::= a | b | … | y | z | aV | bV | … | yV | zV

N ::= 0 | 1 | … | 8 | 9 | 0N | 1N | … | 8N | 9N

The analyzer accepts the source code file as a required command line argument and display an
appropriate error message if the argument is not provided or the file does not exist.

The program is able to use whitespace, tabs, and end of line characters as delimiters between
lexemes, however the solution will ignore these characters and not report them as lexemes nor
require these characters to delimit lexemes of different types.
The program is compatible with the GNU C compiler version 5.4.0.
The program includes a functional makefile that allows for compilation using the GNC C compiler.
Lexemes that do not match to a known token will be reported as an “UNKNOWN” token, but will
not stop execution of the program or generate an error message.
