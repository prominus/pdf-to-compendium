#ifndef TEST_DOC
#define TEST_DOC



int factorial(int number)
{
    return number <= 1 ? number : factorial(number - 1) * number;
}


#endif // TEST_DOC