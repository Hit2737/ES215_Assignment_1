#include <iostream> 
#include <vector>
#include <ctime>
#include <iomanip>
#include <fstream>
#include <unistd.h>
#include <sys/times.h>
using namespace std;
#define v vector

template <typename T>
void matmul(int N, v<v<T>>& A, v<v<T>>& B, v<v<T>>& C){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            for(int k = 0; k < N; k++){
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main(){
    int sizes[] = {64, 128, 256, 512, 1024};
    for(int size: sizes){
        struct tms start, end;
        clock_t startTime, endTime;
        long ticksPerSecond = sysconf(_SC_CLK_TCK);
        v<v<int>> A(size, v<int>(size)), B(size, v<int>(size)), C(size, v<int>(size));
        
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                A[i][j] = int(double(rand() * 1000) / double(RAND_MAX));
                B[i][j] = int(double(rand() * 1000) / double(RAND_MAX));
                C[i][j] = 0;
            }
        }
        startTime = times(&start);
        matmul(size,A,B,C);
        endTime = times(&end);
       
        double userTime = (double)(end.tms_utime - start.tms_utime) / ticksPerSecond;
        double systemTime = (double)(end.tms_stime - start.tms_stime) / ticksPerSecond;
        cout << "Size: " << size << endl;
        cout << "User CPU Time: " << userTime << " seconds" << endl;
        cout << "System CPU Time: " << systemTime << " seconds" << endl;
    }
    return 0;
}