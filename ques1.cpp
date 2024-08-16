/*
    IMPLEMENTATIONS OF CALCULATING FIRST 'N' FIBONACCI NUMBERS:

    - Assuming 1st fibonacci number is '0' and 2nd fibonacci number is '1'
*/

#include <iostream> 
#include <vector>
#include <ctime>
#include <iomanip>
using namespace std;

typedef long long ll;

void print(vector<ll> arr){
    cout << "-----" << endl;
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    } cout << endl;
    cout << "-----" << endl << endl;
}


ll fib_rec(int n){
    if(n == 0 || n == 1) return n;
    
    return fib_rec(n-1) + fib_rec(n-2);
}


ll fib_rec_mem(int n, vector<ll>& fib){
    if(n == 0 || n == 1) return fib[n] = n;
    
    if(fib[n] != -1) return fib[n];
    
    return fib[n] = fib_rec_mem(n-1, fib) + fib_rec_mem(n-2, fib);
}


int main(){
    int N;
    cout << "Enter Number: N = ";
    cin >> N;
    vector<ll> fib(N);


    // Question 1. (a) Using Recursion
    

    struct timespec start_a, stop_a;
    
    cout << "Calculating first " << N << " Fibonacci Numbers using recursion..." << endl << endl;
    
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start_a);
    
    for(int i = 0; i < N; i++){
        fib[i] = fib_rec(i);
    }
    
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &stop_a);
    
    cout << "Printing the Fibonacci numbers: " << endl;
    print(fib);
    
    double time_taken_a = (stop_a.tv_sec - start_a.tv_sec) * 1e9;
    time_taken_a += (stop_a.tv_nsec - start_a.tv_nsec);
    time_taken_a *= 1e-9;

    cout << "Time Taken by CPU to calculate the first " << N << " fibonacci numbers using recursion is " << time_taken_a << setprecision(9) << " sec." << endl << endl;
    cout << "--------------------------------" << endl << endl;


    // Question 1. (b) Using Loop


    fib.resize(N,0);
    
    struct timespec start_b, stop_b;
    
    cout << "Calculating first " << N << " Fibonacci Numbers using loops..." << endl << endl;
    
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start_b);
    
    for(int num = 1; num <= N; num++){
        if(num == 1){
            fib[num-1] = 0;
            continue;
        }
        if(num == 2){
            fib[num-1] = 1;
            continue;
        }
        long long a = 0, b = 1;
        for(int i = 2; i < num; i++){
            long long sum = a + b;
            a = b;
            b = sum;
        }
        fib[num-1] = b;
    }
    
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &stop_b);
    
    cout << "Printing the Fibonacci numbers: " << endl;
    print(fib);

    double time_taken_b = (stop_b.tv_sec - start_b.tv_sec) * 1e9;
    time_taken_b += (stop_b.tv_nsec - start_b.tv_nsec);
    time_taken_b *= 1e-9;

    cout << "Time Taken by CPU to calculate the first " << N << " fibonacci numbers using loops is " << time_taken_b << setprecision(9) << " sec." << endl << endl;
    cout << "--------------------------------" << endl << endl;
    

    // Question 1. (c) Using Recursion with Memoisation


    fib.resize(N,-1);
    
    struct timespec start_c, stop_c;
    
    cout << "Calculating first " << N << " Fibonacci Numbers using recursion with memoisation..." << endl << endl;
    
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start_c);
    
    fib_rec_mem(N-1, fib);
    
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &stop_c);
    
    cout << "Printing the Fibonacci numbers: " << endl;
    print(fib);
    
    double time_taken_c = (stop_c.tv_sec - start_c.tv_sec) * 1e9;
    time_taken_c += (stop_c.tv_nsec - start_c.tv_nsec);
    time_taken_c *= 1e-9;

    cout << "Time Taken by CPU to calculate the first " << N << " fibonacci numbers using recursion with memoisation is " << time_taken_c << setprecision(9) << " sec." << endl << endl;
    cout << "--------------------------------" << endl << endl;
    
    
    // Question 1. (d) Using Loop with memoisation:


    fib.resize(N,0);
    
    struct timespec start_d, stop_d;
    
    cout << "Calculating first " << N << " Fibonacci Numbers using loop with memoisation..." << endl << endl;
    
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start_d);

    fib[0] = 0;
    fib[1] = 1;

    for(int i = 2; i <= N; i++){
        fib[i] = fib[i-1] + fib[i-2];
    }

    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &stop_d);

    cout << "Printing the Fibonacci numbers: " << endl;
    print(fib);
    
    double time_taken_d = (stop_d.tv_sec - start_d.tv_sec) * 1e9;
    time_taken_d += (stop_d.tv_nsec - start_d.tv_nsec);
    time_taken_d *= 1e-9;

    cout << "Time Taken by CPU to calculate the first " << N << " fibonacci numbers using loop with memoisation is " << time_taken_d << setprecision(9) << " sec." << endl << endl;
    cout << "--------------------------------" << endl << endl;
    


    cout << " SpeedUp of Program all programs by keeping Program (a) as baseline: " << endl << endl;
    

    cout << " SpeedUp of Program (b) wrt. Program (a) = " << time_taken_a/time_taken_b << endl;
    cout << " SpeedUp of Program (c) wrt. Program (a) = " << time_taken_a/time_taken_c << endl;
    cout << " SpeedUp of Program (d) wrt. Program (a) = " << time_taken_a/time_taken_d << endl;
    
    
    return 0;
}