#include "stdio.h"
#include "string.h"
#include "stdlib.h"

/* STRINGS:
 * this file contains all the basic concepts of about strings/character arrays. 
 */
int main(){
    /* declaring and defining a Character variable:
     * METHOD_00:
     */
    char x = 'c';

    /* METHOD_01:
     * declaring character variables:
     */
    char x1, y;
    // defining a character variable:
    x1 = 'f';
    
    /* printing a character variable:
     * METHOD_00:
     */
    printf("var x: %c\n", x);
    printf("var x1: %c\n", x1);
    /* taking a character as an input via the user 
     * METHOD_00:
     */
    printf("assign var y a value: ");
    scanf("%c", &y);
    printf("var y: %c\n\n", y);
    /* String, abbreviation: str
     * In computer programming, a String is traditionally a sequence of
     * characters which can either be constant literals(i.e. a-z, A-Z, 0-9,
     * !, _, -, @, #, etc.) or a variable which can be defined later on
     * in the program. 
     * In C Language there is no predefinied data type named string. 
     * So to create such a data type we use the concept of an Array, 
     * precisely Character Array.
     * But there is more to it than just creating an Character Array, 
     * first of all we need make sure that the data type is recognized
     * by the compiler and to make sure that happens we add the special 
     * character called, NULL Character: '\0'. But thankfully the C compiler
     * saves us the hassle of adding the special character in the end of 
     * Character Array and adds the special character by it self.
     *  
     * EXAMPLE_00: "hello world!"
     * EXAMPLE_01: "i'm a programmer"
     * EXAMPLE_02: "my age is 13"
     * EXAMPLE_03: "my email address is: my@example.com"
     */

    /* declaring and defining a String/Character Array variable:
     * METHOD_00:
     */
    char buff[] = "hello world!";
    
    /* declaring a String/Character Array variable:
     * METHOD_01:
     */
    char buff1[13];
    /* defining a String/Character Array variable:
     */
    /* strcpy function basically copies a char array to another char array
     * strcpy(char *str, const char *str1);
     * 
     * PARAM: @str, the destinition, where the string will be copied
     * PARAM: @str1, the source, the data to be copied
     */
    strcpy(buff1, "hello world!");  //this method is valid
    // buff1 = "hello world!";      //and this method is not

    // METHOD_02:
    char buff2[13] = "hello world!";

    // METHOD_03:
    char buff3[13] = {'h', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd', '!', '\0'};

    /* printing a String/Character Array variable:
     * METHOD_00:
     */
    printf("buffer 00: %s\n", buff);
    printf("buffer 01: %s\n", buff1);
    printf("buffer 02: %s\n", buff2);
    /* METHOD_01:
     * puts (abbreviation for Put String) function basically
     * like printf but it take only one parameter which can 
     * be a string or a variable. and also prints a newline 
     * character('\n') at the end of the string.
     * and as puts function doesn't support formatting we can 
     * only print a string at a time.
     * puts(const char *str);
     * 
     * PARAM: @str, the string to be printed
     * 
     * EXAMPLE_00: puts("hello world!");
     * EXAMPLE_01: puts(str);
     */
    puts("printing the string using puts function:\nbuffer 03: ");
    puts(buff1);
    
    /* taking a string as an input via the user
     * METHOD_00: 
     */
    printf("\nassinging buffer 01 a new string: ");
    /* fflush() function basically clears the current stream's(terminal) input/inward buffer.
     * in our case which is the last input we took from stdin(abbreviation for Standard Input).
     * and the input buffer we got from stdin was for character variable 'y'.
     * fflush(FILE *file);
     * 
     * PARAM: @file, the certain stream line's certain flow to be flushed
     */
    fflush(stdin);
    /* "%[^\n]s" is known as a scanset and this particular scanset takes input until it encounters 
     * a newline character ('\n'). 
     */
    scanf("%[^\n]s", &buff1);
    printf("buffer 01: %s\n", buff1);
    
    /* METHOD_01:
     */
    printf("\nassinging buffer 01 a new string: ");
    fflush(stdin);
    /* gets function is somewhat similar to scanf but it only takes a string as an input
     * gets(char *str);
     * 
     * PARAM: @str, the string variable 
     */
    gets(buff1);
    printf("buffer 01: %s\n", buff1);
    
    /* METHOD_02:
     */
    printf("\nassinging buffer 01 a new string: ");
    fflush(stdin); 
    /* fgets function is somewhat similar to scanf but it only takes a string as an input
     * and it can handle buffer overflow
     * gets(char *str, int len, FILE* file);
     * 
     * PARAM: @str, the string variable
     * PARAM: @len, the max length of the char array
     * PARAM: @file, the input stream, typically "stdin" is used
     */
    fgets(buff1, 13, stdin);
    printf("buffer 01: %s\n", buff1);
}