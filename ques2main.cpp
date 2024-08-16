#include <iostream> 
#include <vector>
#include <ctime>
#include <iomanip>
#include <fstream>
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
    
    v<double> time_int;
    v<double> time_dbl;

    cout << "Integer Matrix Multiplication" << endl;
    for(int size : sizes){
        struct timespec start_exe, stop_exe;

        clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start_exe);

        v<v<int>> A(size, v<int>(size)), B(size, v<int>(size)), C(size, v<int>(size));
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                A[i][j] = int(double(rand() * 1000) / double(RAND_MAX));
                B[i][j] = int(double(rand() * 1000) / double(RAND_MAX));
                C[i][j] = 0;
            }
        }
        
        struct timespec start, stop;
        
        clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);
        matmul(size,A,B,C);
        clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &stop);
        
        double time_taken = (stop.tv_sec - start.tv_sec) * 1e9;
        time_taken += (stop.tv_nsec - start.tv_nsec);
        time_taken *= 1e-9;
        
        time_int.push_back(time_taken);

        clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &stop_exe);

        double time_exe = (stop_exe.tv_sec - start_exe.tv_sec) * 1e9;
        time_exe += (stop_exe.tv_nsec - start_exe.tv_nsec);
        time_exe *= 1e-9;

        cout << "Size: " << size << " -> " << time_exe << " sec." << endl;
    }
    

    cout << "Double Matrix Multiplication" << endl;

    for(int size : sizes){
        struct timespec start_exe, stop_exe;

        clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start_exe);

        v<v<double>> A(size, v<double>(size)), B(size, v<double>(size)), C(size, v<double>(size));
        
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                A[i][j] = double(rand() * 1000) / double(RAND_MAX);
                B[i][j] = double(rand() * 1000) / double(RAND_MAX);
                C[i][j] = 0;
            }
        }
        
        struct timespec start, stop;
        
        clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);
        matmul(size,A,B,C);
        clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &stop);
        
        double time_taken = (stop.tv_sec - start.tv_sec) * 1e9;
        time_taken += (stop.tv_nsec - start.tv_nsec);
        time_taken *= 1e-9;
        
        time_dbl.push_back(time_taken);

        clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &stop_exe);

        double time_exe = (stop_exe.tv_sec - start_exe.tv_sec) * 1e9;
        time_exe += (stop_exe.tv_nsec - start_exe.tv_nsec);
        time_exe *= 1e-9;

        cout << "Size: " << size << " -> " << time_exe << " sec." << endl;
    }
    
    ofstream MyFile("data2.txt");
    
    for(int i = 0; i < 5; i++){
        MyFile << time_int[i] << " ";
        MyFile << time_dbl[i] << endl;
        cout << time_int[i] << " ";
        cout << time_dbl[i] << endl;
    }cout << endl;
    
    MyFile.close();
    
    return 0;
}