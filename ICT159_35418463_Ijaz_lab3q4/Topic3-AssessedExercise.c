#include <stdio.h>

int main()
{
    // Let's define two variables. These will hold the result of the expression 
    // before and after adding the parenthesis
    float expression_without_parenthesis, expression_with_parenthesis;

    // 1. Expression 1
    expression_without_parenthesis = 1 + 3 / 2;
    expression_with_parenthesis    = (1 + (3 / 2));

    printf("Expression 1 - without parenthesis: %f, with parenthesis: %f\n",
        expression_without_parenthesis, expression_with_parenthesis);

    // 2. Expression 2
    expression_without_parenthesis = 2 - 3 * 4;
    expression_with_parenthesis    = (2 - (3 * 4));

    printf("Expression 2 - without parenthesis: %f, with parenthesis: %f\n",
        expression_without_parenthesis, expression_with_parenthesis);

    // 3. Expression 3
    expression_without_parenthesis = 2 / 3 * 4;
    expression_with_parenthesis    = ((2 / 3) * 4);

    printf("Expression 3 - without parenthesis: %f, with parenthesis: %f\n",
        expression_without_parenthesis, expression_with_parenthesis);

    // 4. Expression 4
    expression_without_parenthesis = 2 * 3 / 4;
    expression_with_parenthesis    = ((2 * 3) / 4);

    printf("Expression 4 - without parenthesis: %f, with parenthesis: %f\n",
        expression_without_parenthesis, expression_with_parenthesis);

    // 5. Expression 5
    expression_without_parenthesis = 2 / 3 / 4;
    expression_with_parenthesis    = ((2 / 3) / 4);

    printf("Expression 5 - without parenthesis: %f, with parenthesis: %f\n",
        expression_without_parenthesis, expression_with_parenthesis);

    // 6. Expression 6
    expression_without_parenthesis = 4 / 3 * 2 / 5;
    expression_with_parenthesis    = (((4 / 3) * 2) / 5);

    printf("Expression 6 - without parenthesis: %f, with parenthesis: %f\n",
        expression_without_parenthesis, expression_with_parenthesis);

    // 7. Expression 7
    expression_without_parenthesis = 6 * 3 / 4 * 5;
    expression_with_parenthesis    = (((6 * 3) / 4) * 5);

    printf("Expression 7 - without parenthesis: %f, with parenthesis: %f\n",
        expression_without_parenthesis, expression_with_parenthesis);

    // 8. Expression 8
    expression_without_parenthesis = 4 * 3 * 3; // Original Exponent: 3^2 = 3 * 3
    expression_with_parenthesis    = (4 * (3 * 3));

    printf("Expression 8 - without parenthesis: %f, with parenthesis: %f\n",    
        expression_without_parenthesis, expression_with_parenthesis);

    // 9. Expression 9
    expression_without_parenthesis = 2 - 2 * 2 * 2 * 2; // Original Exponent: 2^3 = 2 * 2 * 2
    expression_with_parenthesis    = (2 - (2 * 2 * 2 * 2));

    printf("Expression 9 - without parenthesis: %f, with parenthesis: %f\n",
        expression_without_parenthesis, expression_with_parenthesis);

    // 10. Expression 10
    expression_without_parenthesis = 2 / 3 * 4 * 4; // Original Exponent: 4^2 = 4 * 4
    expression_with_parenthesis    = ((2 / 3) * (4 * 4));

    printf("Expression 10 - without parenthesis: %f, with parenthesis: %f\n",
        expression_without_parenthesis, expression_with_parenthesis);

    // 11. Expression 11
    expression_without_parenthesis = 1 + 2 / 3 * 4 + 5;
    expression_with_parenthesis    = ((1 + ((2 / 3) * 4)) + 5);

    printf("Expression 11 - without parenthesis: %f, with parenthesis: %f\n",
        expression_without_parenthesis, expression_with_parenthesis);

    // 12. Expression 12
    expression_without_parenthesis = 5 / 2 * 2 + 4 % 3 + 9 - 3;
    expression_with_parenthesis    = (((((5 / 2) * 2) + (4 % 3)) + 9) - 3);
    
    printf("Expression 12 - without parenthesis: %f, with parenthesis: %f\n",
        expression_without_parenthesis, expression_with_parenthesis);

    getchar();
    return(0);
}
