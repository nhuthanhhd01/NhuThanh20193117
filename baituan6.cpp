#include<iostream>
using namespace std;

int max(int a, int b) 
{
	if (a > b) return a;
	return b;
}
double max(double a, double b) {
	if (a > b) return a;
	return b;
}
double max(double a, double b, double c) {
	if (a <  b) a = b;
	if ( a < c) a = c;
	return a;
}
void swap(double &a, double &b) {
	double temp = a; a = b; b = temp;
}
double *sapxep(int N, double *seq) {
    int i,j;
    double *pA = seq; 
    for(i = 0; i < N; i++) {
        for (j = i + 1; j < N ; j++) {
            if(*(pA +i) < *(pA + j)) {
                swap(*(pA + i), *(pA + j));
            }
        }
    }
    return pA; }
double max(double *seq, int n) {
	sapxep(n, seq);
	return *(seq + 0);	
}
int main() {
	double seq[4] = {4.5, 5.2, 2.7, 1.7};
	cout << max(3.5 , 6.5) << endl;
	cout << max(seq, 3) << endl;
	cout << max(2.5, 5.2, 3.5) << endl;
	cout << max(2, 6);
}
