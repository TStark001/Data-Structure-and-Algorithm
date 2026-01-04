/*
*                   TIME COMPLEXITY
!    Sum of nth term , Sn = n/2(2a + (n-1)*d)
                 where n = no. of terms
                       a = first terms
                       d = common difference
todo    number of term , n = (y-x+1)
                         a = x
!                   ASYMPTOTIC ANALYSIS
                #. No. of operation w.r.t change in input
        Type of Time Complexity Analysis and their notations:
        1. Worst Case Time Complexity :- Notation (Big O)
        2. Best Case Time Complexity :- Notation (Big Omega)
        3. Average Case Time Complexity :- Notation (Big theta) 

 #. Space Complexity :- It is the extra memory space requirement of an algorithm
*/
#include <iostream>
using namespace std;

int sum_in_range(int x, int y)
{
    int result = 0;
    for (int i = x; i <= y; i++)
    {
        result += i;
    }
    return result;
}

int sum_in_range_optimised(int x, int y)
{
    int n = (y - x + 1);
    int a = x;
    int result = (n * (2 * a + (n - 1) * 1)) / 2;
    return result;
}

int main()
{
    cout << "Sum = " << sum_in_range_optimised(2, 6);
    return 0;
}