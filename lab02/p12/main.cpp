//accepted
#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

void computeDigits(int n, int &sum, int &num)
{
    sum = 0;
    num = 0;
    do
    {
        sum += n % 10;
        n /= 10;
        ++num;
    } while (n != 0);
}

int main()
{
    iostream::sync_with_stdio(false);

    for (int n; cin >> n && n != 0;)
    {
        int sumOfDigits;
        int numOfDigits;

        do
        {
            computeDigits(n, sumOfDigits, numOfDigits);
            n = sumOfDigits;
        } while (numOfDigits != 1);

        cout << sumOfDigits << "\n";
    }
}