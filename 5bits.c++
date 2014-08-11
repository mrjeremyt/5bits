#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

/*
 NAME: Jeremy Thompson
 UTEID: JMT2939
 Section #: 53850
 PROGRAM 2 5bit.c++
*/

bool decode = false;

typedef char *STRING;

FILE *input;

void translate(unsigned char x, char *result);

void rev_translate( int x, char *result);



/* ***************************************************************** */
/*                                                                   */
/*                                                                   */
/* ***************************************************************** */



int logicalShift(int x, int n) {
  int mask =(1<<31); //mask for x
  int sign = (~mask) & x; //complement y & x gives the sign bit of x
  int shift = sign>>n; //shifting of sign, n spots, gives you the positive answer of x>>n
  int k = mask & x;
  return ((k>>31) & (1<<(31 + (~n + 1)))) | shift;
}


/* ***************************************************************** */
/*                                                                   */
/*                                                                   */
/* ***************************************************************** */

void scanargs(STRING s){

	while (*++s != '\0'){
	    switch (*s){

		    case 'd': /* decode option */
		       	decode = true;
		        break;

		    default:
		    	cerr << "PROGR: Bad option " << *s << endl;
		    	cerr << "usage: PROGR [-d] file" << endl;
		        exit(1);
	    }
	}
}

/* ***************************************************************** */
/*                                                                   */
/*                                                                   */
/* ***************************************************************** */

void enkode(){
	char result;
	int c, five;
	int buffer = 0, counter = 0, temp = 0, charOut = 0;

	while((c = getc(input)) != EOF){
		charOut++;
		buffer = buffer << 8;
		buffer = buffer | c;
		counter += 8;

		while(counter >= 5){
			five  = buffer & (0x1F << (counter - 5) );
			five = five >> (counter - 5);
			buffer = buffer << (32 - (counter - 5));
			buffer = logicalShift(buffer, (32 - (counter - 5)));
			counter -= 5;
			translate(five, &result);
			putchar(result);
			if(charOut > 71){
				charOut = 0;
				putchar(0xA);
			}
		}
	}

	if(counter > 0){
		buffer = buffer << (5 - counter);
		five = buffer & 0x1F;
		translate(five, &result);
		putchar(result);
		putchar(0xA);
	}
 	if(charOut > 60){
 		putchar(0x0A);
 	}
}

/* ***************************************************************** */
/*                                                                   */
/*                                                                   */
/* ***************************************************************** */

void dekode(){

	int buffer = 0, counter = 0, c, answer = 0, charOut = 0;
	char rev_character = 0;

	while((c = getc(input)) != EOF){
		if((c > 0x40 && c < 0x5B) || (c > 0x2F && c < 0x36)){
			rev_translate(c, &rev_character);
			buffer = buffer << 5;
			buffer = buffer | rev_character;
			counter += 5;
			while(counter >= 8){
				charOut++;
				answer = buffer & (0xFF << (counter - 8));
				answer = answer >> (counter - 8);
				counter -= 8;
				buffer = buffer << (32 - (counter - 8));
				buffer = logicalShift(buffer, (32 - (counter - 8)));
				putchar(answer);
			}
		}
	}
}

/* ***************************************************************** */
/*                                                                   */
/*                                                                   */
/* ***************************************************************** */


void translate(unsigned char x, char *result){

	switch(x){

		case 0x00:
			*result = 'A';
			break;
		case 0x01:
			*result = 'B';
			break;
		case 0x02:
			*result = 'C';
			break;
		case 0x03:
			*result = 'D';
			break;
		case 0x04:
			*result = 'E';
			break;
		case 0x05:
			*result = 'F';
			break;
		case 0x06:
			*result = 'G';
			break;
		case 0x07:
			*result = 'H';
			break;
		case 0x08:
			*result = 'I';
			break;
		case 0x09:
			*result = 'J';
			break;
		case 0x0A:
			*result = 'K';
			break;
		case 0x0B:
			*result = 'L';
			break;
		case 0x0C:
			*result = 'M';
			break;
		case 0x0D:
			*result = 'N';
			break;
		case 0x0E:
			*result = 'O';
			break;
		case 0x0F:
			*result = 'P';
			break;
		case 0x10:
			*result = 'Q';
			break;
		case 0x11:
			*result = 'R';
			break;
		case 0x12:
			*result = 'S';
			break;
		case 0x13:
			*result = 'T';
			break;
		case 0x14:
			*result = 'U';
			break;
		case 0x15:
			*result = 'V';
			break;
		case 0x16:
			*result = 'W';
			break;
		case 0x17:
			*result = 'X';
			break;
		case 0x18:
			*result = 'Y';
			break;
		case 0x19:
			*result = 'Z';
			break;
		case 0x1A:
			*result = '0';
			break;
		case 0x1B:
			*result = '1';
			break;
		case 0x1C:
			*result = '2';
			break;
		case 0x1D:
			*result = '3';
			break;
		case 0x1E:
			*result = '4';
			break;
		case 0x1F:
			*result = '5';
			break;
		default:
			*result = '9';

	}

}



/* ***************************************************************** */
/*                                                                   */
/*                                                                   */
/* ***************************************************************** */



void rev_translate(int x, char *result){


	switch(x){

		case 'A':
			*result = 0x00;
			break;
		case 'B':
			*result = 0x01;
			break;
		case 'C':
			*result = 0x02;
			break;
		case 'D':
			*result = 0x03;
			break;
		case 'E':
			*result = 0x04;
			break;
		case 'F':
			*result = 0x05;
			break;
		case 'G':
			*result = 0x06;
			break;
		case 'H':
			*result = 0x07;
			break;
		case 'I':
			*result = 0x08;
			break;
		case 'J':
			*result = 0x09;
			break;
		case 'K':
			*result = 0x0A;
			break;
		case 'L':
			*result = 0x0B;
			break;
		case 'M':
			*result = 0x0C;
			break;
		case 'N':
			*result = 0x0D;
			break;
		case 'O':
			*result = 0x0E;
			break;
		case 'P':
			*result = 0x0F;
			break;
		case 'Q':
			*result = 0x10;
			break;
		case 'R':
			*result = 0x11;
			break;
		case 'S':
			*result = 0x12;
			break;
		case 'T':
			*result = 0x13;
			break;
		case 'U':
			*result = 0x14;
			break;
		case 'V':
			*result = 0x15;
			break;
		case 'W':
			*result = 0x16;
			break;
		case 'X':
			*result = 0x17;
			break;
		case 'Y':
			*result = 0x18;
			break;
		case 'Z':
			*result = 0x19;
			break;
		case '0':
			*result = 0x1A;
			break;
		case '1':
			*result = 0x1B;
			break;
		case '2':
			*result = 0x1C;
			break;
		case '3':
			*result = 0x1D;
			break;
		case '4':
			*result = 0x1E;
			break;
		case '5':
			*result = 0x1F;
			break;
		default:
			*result = 0XFF;

	}

}



/* ***************************************************************** */
/*                                                                   */
/*                                                                   */
/* ***************************************************************** */


int main(int argc, char *argv[])
{
	bool filenamenotgiven = true;


    while (argc > 1){
        argc--, argv++;
        if (**argv == '-')
            scanargs(*argv);
        else{
            filenamenotgiven = false;
            input = fopen(*argv,"r");
            if (input == NULL){
            	cerr << "Can't open " << *argv << endl;
            	exit(1);
            }
            if(decode){
            	dekode();
            }else{
            	enkode();
            }
            fclose(input);      
        }
    }

    if (filenamenotgiven){
        input = stdin;
        enkode();
    }
    return 0;
}