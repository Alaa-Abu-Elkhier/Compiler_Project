#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>

// Returns 'true' if the character is an OPERATOR.
bool isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' ||
        ch == '/' || ch == '>' || ch == '<' ||
        ch == '=')
        return (true);
    return (false);
}
// Returns 'true' if the string is a KEYWORD.
bool isKeyword(char* str)
{
    if (!strcmp(str, "if") || !strcmp(str, "else") ||
        !strcmp(str, "while") || !strcmp(str, "do") ||
        !strcmp(str, "break") ||
         !strcmp(str, "continue") || !strcmp(str, "int")
        || !strcmp(str, "double") || !strcmp(str, "float")
        || !strcmp(str, "return") || !strcmp(str, "char")
        || !strcmp(str, "case") || !strcmp(str, "char")
        || !strcmp(str, "sizeof") || !strcmp(str, "long")
        || !strcmp(str, "short") || !strcmp(str, "typedef")
        || !strcmp(str, "switch") || !strcmp(str, "unsigned")
        || !strcmp(str, "void") || !strcmp(str, "static")
        || !strcmp(str, "struct") || !strcmp(str, "goto"))
        return (true);
    return (false);
}

bool is_special_char(char ch)
{
    if (ch == ' ' ||ch == ',' || ch == ';' || ch == '(' || ch == ')' ||
        ch == '[' || ch == ']' || ch == '{' || ch == '}'|| ch == '!' ||
         ch == '%'|| ch == '&' || ch == '^'|| ch == '|' || ch == '"')
        return (true);
    return (false);
}
// Returns 'true' if the string is a VALID IDENTIFIER.
bool Identifier(char* str)
{
    if (str[0] == '0' || str[0] == '1' || str[0] == '2' ||
        str[0] == '3' || str[0] == '4' || str[0] == '5' ||
        str[0] == '6' || str[0] == '7' || str[0] == '8' ||
        str[0] == '9' || is_special_char(str[0]) == true||isOperator(str[0])== true)
        return (false);
    return (true);
}



bool isInteger(char* str)
{
    int i, len = strlen(str);

    if (len == 0)
        return (false);
    for (i = 0; i < len; i++) {
        if (str[i] != '0' && str[i] != '1' && str[i] != '2'
            && str[i] != '3' && str[i] != '4' && str[i] != '5'
            && str[i] != '6' && str[i] != '7' && str[i] != '8'
            && str[i] != '9' || (str[i] == '-' && i > 0))
            return (false);
    }
    return (true);
}

// Returns 'true' if the string is a floatL NUMBER.
bool isFloat_Number(char* str)
{
    int i, len = strlen(str);
    bool Float = false;

    if (len == 0)
        return (false);
    for (i = 0; i < len; i++) {
        if (str[i] != '0' && str[i] != '1' && str[i] != '2'
            && str[i] != '3' && str[i] != '4' && str[i] != '5'
            && str[i] != '6' && str[i] != '7' && str[i] != '8'
            && str[i] != '9' && str[i] != '.' ||
            (str[i] == '-' && i > 0))
            return (false);
        if (str[i] == '.')
             Float = true;
    }
    return ( Float);
}












int  main()

 {
    int len;
    int i;
    char exp[100];
    char *token;
    const char s[2] = " ";;
    char *str;



   printf("\n---------------------Lexical Analysis--------------------------\n\n");
   //input expression
   printf("Enter the string \n");
   printf("Please put space between characters \n");
   scanf("%[^\n]%*c",exp);
   printf("your string  :%s\n",exp);
   //the length of string
   len=strlen(exp);
   printf("string lenght is :%d",len);



   /////////////////////////////////
   token = strtok(exp,s);


   while( token != NULL )
      {



        if(isKeyword(token))

              printf(" \n %s ----> Is  Keyword \n",token);\


        if(Identifier(token)&& isKeyword(token)!=1 )

             printf(" \n %s ----> Is  Identifier \n",token);


        if(isInteger(token) || isFloat_Number(token) )

            printf(" \n %s  ----> Is Number  \n",token);




        token = strtok(NULL, s);


        }






    for (i=0;i<len;i++)

   {
     if( isOperator(exp[i]))

         printf(" \n %c  ----> Is  Opreator \n",exp[i]);
     if(is_special_char(exp[i]))
        printf(" \n %c  ----> Is  special caracter \n",exp[i]);


   }







   return(0);





}
