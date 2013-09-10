/* Scanner for a poker hands judge */

%option noyywrap

%{
#include <stdio.h>
#include <stdlib.h>

int handval[2][14];
int handsuit[2][4];

int cards, player;
int wins0 = 0;

void reset() {
    for(int i = 0; i < 14; ++i) {
        handval[0][i] = handval[1][i] = 0;
    }
    for(int i = 0; i < 4; ++i) {
        handsuit[0][i] = handsuit[1][i] = 0;
    }

    cards = player = 0;
}

int winner () {
    return 0;
}

%}

Suit        [CDHS]
NumValue    [1-9]
FigValue    [ATJQK]
W           [ \t\v]

%%

{Suit}      { 
                switch(yytext[0]) {
                    case 'C':
                       ++handsuit[player][0];
                       break;
                    case 'D':
                       ++handsuit[player][1];
                        break;
                    case 'H':
                       ++handsuit[player][2];
                        break;
                    case 'S':
                       ++handsuit[player][3];
                        break;
                    default:
                        fprintf(stderr, "Bad suit detected!\n");
                }
            }
{NumValue}  { ++handval[player][atoi(yytext)]; }
{FigValue}  { 
                switch(yytext[0]) {
                    case 'A':
                       ++handval[player][1];
                        break;
                    case 'T':
                       ++handval[player][10];
                        break;
                    case 'J':
                       ++handval[player][11];
                       break;
                    case 'Q':
                       ++handval[player][12];
                        break;
                    case 'K':
                       ++handval[player][13];
                        break;
                    default:
                        fprintf(stderr, "Bad figure value detected!\n");
                }
            }
{W}+        {   
                ++cards;
                if (cards > 4)
                    player = 1;
            }
\n          {
                if (0 == winner()) {
                    ++wins0;
                }
                reset();

            }
<<EOF>>     { return 0; }
.           { fprintf(stderr, "Bad input detected! %s\n", yytext); }

%%


int main ()
{
    yylex();
    printf("Player 0 wins %d hands.\n", wins0);
}
