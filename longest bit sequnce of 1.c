/*

A non-negative integer N is Given. The Maximal binary ones stretch of N is the length of the longest sequence of consecutive bits set to 1 in the binary representation of N. For ex ample, consider N=114,067. Its binary representation is 11011110110010011. Its Maxima binary ones stretch is equal to 4. 
Write a function:
Int solution(int N);
That, given a non-negative integer N, returns the maximal binary ones stretch of N.
For ex ample, given N=114,067, the function should return 4, as explained above.
Assume that:
N is an integer within the range [0..2,147,483,647].

*/


#include <assert.h>
#include <stdio.h>

//
// 001110011
//&000111001
//========== 1
// 000110001
//&000011000
//========== 2
// 000010000
//&000001000
//========== 3
// 000000000
//
// 3 is the length of the biggest consecutive 1 stretch

/*
    Returns -1 when the provided number is negative
*/
int solution(int N)
{
    int i;
    if (N < 0) {
        return -1;
    }

    unsigned int n = N; // For bitwise operations

    for (i = 0; n; i++) {
        // ANDing n with its right shifted counterpart is
        // effectively reducing all ones stretches length by 1
        // this means that by the time we get to a number of all 0's
        // we can count how many iterations got us there.
        n &= n>>1;
    }

    return i;
}

void test(int N, int expectedResult)
{
    int result = solution(N);
    printf("solution(%d) == %d, ", N, result);
    if (result == expectedResult) {
        printf("correct!\n");
    } else {
        printf("incorrect!\n");
    }
}

int main() {
    // Result provided
    printf("Provided example:\n");
    test(114067, 4);

    // Other tests
    printf("Other tests:\n");
    test(1, 1);
    test(3, 2);
    test(7, 3);
    test(15, 4);

    test(1024, 1);
    test(1024+15, 4);

    // Maximum positive value of int
    test(2147483647, 31);
    
    test(-1, -1);
    test(-2, -1);
    test(-2147483648, -1);

    return 0;
}