#include <iostream>
using namespace std;

bool check_asc(int arr[], int s)
{
	if (s == 0)
		return true;
	if (arr[s - 1] > arr[s])
	{
		return false;
	}

	return check_asc(arr, s - 1);
}
int power(int b, int p)
{
    int r = 1;
    if (p != 0)
    {
        r = b * power(b, p - 1);

    }
    return r;
}
void dec(int n)
{
    if (n == 0)
    {
        cout << n << endl;
        return;
    }
    else
    {
        dec(n - 1);
    }
    cout << n << endl;
    return;
}
void fib(int p, int c, int n)
{
    if (p >= n)
    {
        return;
    }
    int t = p;
    cout << p << " ";
    p = c;
    c = t + c;
    fib(p, c, n);
}
int fibonacci(int n) {
    if (n <= 0) {
        return 0;
    }
    else if (n == 1) {
        return 1;
    }
    else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}
void printFibonacciSeries(int n) {
    for (int i = 0; i < n; ++i) {
        cout << fibonacci(i) << " ";
    }
    cout << endl;
}
int main()
{
	/*int arr[4];
	for (int i = 0; i < 4; i++)
	{
		cin >> arr[i];
	}
	cout << check_asc(arr, 3);*/

    //fib(0, 1, 20);
    
    //dec(20);

    //printFibonacciSeries(10);

    return 0;

}