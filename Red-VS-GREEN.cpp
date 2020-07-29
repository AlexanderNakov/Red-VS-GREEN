#include <iostream>
#include <new>
using namespace std;

int main()
{
    int x, y;
    int* p;
    int* pp;
    cout << "Enter x: " << endl;
    cin >> x;
    cout << "Enter y: " << endl;
    cin >> y;

    int xy = x * y;


    p = new (nothrow) int[xy];
    pp = new (nothrow) int[xy];


    for (int n = 0; n < xy; n++)
    {
        cout << "Enter number: ";
        cin >> p[n];
    }


    // Just in case
    int count = 0;
    int rowCount = x;

    cout << "You have entered: " << endl;

    for (int i = 0; i < y; i++) {

        for (int j = count; j < rowCount; j++) {
            if (x > 1)
                cout << p[j] << ", ";
            else
                cout << p[j];
        }
        count += x;
        rowCount += x;

        cout << endl;
    }

   



    int x1, y1, x1y1, N;
    cout << "Enter x1, y1 and N: " << endl;
    cin >> x1 >> y1 >> N;
    x1y1 = (y1 * x) + x1;
    int Result = 0;


    for (size_t q = 0; q < N; q++)
    {
        if (q == 0 && p[x1y1] == 1)
            Result++;


        int level = x - 1;


        int botLeftEnd = x - 1;
        int botRightEnd = x * 2;

        int midLeftEnd = 0;
        int midRightEnd = x - 1;

        int topLeftEnd = -1 * (x);
        int topRightEnd = -1 * (x - 2);




        for (int i = 0; i < xy; i++) {

            int count1s = 0;



            if (p[x + 1 + i] == 1 && botRightEnd > (x + 1 + i) && xy > (x + 1 + i)) {
                count1s++;
            }
            if (p[x + i] == 1 && xy > (x + i)) {
                count1s++;
            }
            if (p[x - 1 + i] == 1 && botLeftEnd < (x - 1 + i) && xy >(x - 1 + i)) {
                count1s++;

            }


            if (p[i - 1] == 1 && (i - 1) >= midLeftEnd) {
                count1s++;

            }

            if (p[i + 1] == 1 && (i + 1) <= midRightEnd) {
                count1s++;

            }



            if (p[i - x + 1] == 1 && topRightEnd >= (i - x + 1) && 0 <= (i - x + 1)) {
                count1s++;
            }
            if (p[i - x] == 1 && 0 <= (i - x)) {
                count1s++;
            }
            if (p[i - x - 1] == 1 && (topLeftEnd <= (i - x - 1)) && 0 <= (i - x - 1)) {
                count1s++;

            }


            if (level == i) {

                botRightEnd += x;
                botLeftEnd += x;

                midLeftEnd += x;
                midRightEnd += x;

                topLeftEnd += x;
                topRightEnd += x;

                level += x;
            }



            if (p[i] == 0 && (count1s == 3 || count1s == 6)) {

                pp[i] = 1;

            }
            else if (p[i] == 1 && (count1s == 2 || count1s == 3 || count1s == 6)) {

                pp[i] = 1;


            }
            else {
                pp[i] = 0;
            }


            if (p[i] == 1 && i == x1y1)
                Result++;

        }

        for (size_t u = 0; u < xy; u++)
        {
            p[u] = pp[u];
        }

    }

    cout << "Result: " << Result << endl;

    delete[] p;
    delete[] pp;


    return 0;
}
