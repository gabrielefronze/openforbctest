/////////////////////////////////////////////////////////////////////////////////////////////
//  _____                                        _                   
// |_   _|                                      / |_                 
//   | |   _ .--.   .--.  _ .--.   .---.  .---.`| |-' .--.   _ .--.  
//   | |  [ `.-. | ( (`\][ '/'`\ \/ /__\\/ /'`\]| | / .'`\ \[ `/'`\] 
//  _| |_  | | | |  `'.'. | \__/ || \__.,| \__. | |,| \__. | | |     
// |_____|[___||__][\__) )| ;.__/  '.__.''.___.'\__/ '.__.' [___]    
//                       [__|                                        
// 
// Create a program capable of summing element-by-element two equally long std::vectors.
// The sum can happen in a sequential or parallel way. The latter is a bonus.
// The result must be returned in the form of another std::vector.
//
// Keep track of the progress by logging the status to stdout. No constraints are given
// on the logging format (you can use multi lines, a progres bar or anything you want).
//
// The peculiarity of this exercise is that the status logging has to be performed by 
// another thread with respect to the one (or the ones) performing the sum.
//
/////////////////////////////////////////////////////////////////////////////////////////////
#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <random>
#include <pthread.h>

using namespace std;
using namespace chrono;

// Size of the two vectors - preferably power of 2
int N = 2048;

// Number of threads - preferably (power of 2) + 1 (or a factor of N + 1)
int NUM_THREADS = 5;

// The two vectors to be added
vector<int> v1(N);
vector<int> v2(N);
vector<int> res(N);

//Helper variables
int part = 0;
int progress = 0;
std::mutex mu;

/**
 * Prints out a vector on the console
 * @param v - the vector to be printed
 */
void print_vector(vector<int> &v) {
    for (const auto & iter : v)
        cout << iter << ", ";
    cout << endl;
}

/**
 * Generates a vector filled with random integers of size N
 * @param v - vector to be filled
 */
void generate_vector(vector<int> &v) {
    random_device rnd_device;
    mt19937 mersenne_engine {rnd_device()};
    // Generates random 2 digit integers (for easy visually verifying correctness on console)
    uniform_int_distribution<int> dist {10, 99};

    auto gen = [&dist, &mersenne_engine](){
        return dist(mersenne_engine);
    };

    generate(begin(v), end(v), gen);
    std::shuffle(begin(v), end(v), mersenne_engine);
}

/**
 * Performs the logging operations
 * @param arg
 * @return
 */
void* log_operation(void* arg) {
    auto t1 = high_resolution_clock::now(); // start timer
    int k = 1;
    while(progress < N) {
        if(progress > N*k/10) {
            auto t2 = high_resolution_clock::now();  // finishing timer
            cout << k*10 << "% task completed in " <<  duration_cast<microseconds>( t2 - t1 ).count()<<" \xC2\xB5s\n";
            k++;
        }
    }
    auto t2 = high_resolution_clock::now();  // finishing timer
    cout << "100% task completed in " <<  duration_cast<microseconds>( t2 - t1 ).count()<<"\xC2\xB5s\n";
}

/**
 * Performs the parallel adding operations
 * @param arg
 * @return
 */
void* parallel_add(void* arg) {
    int thread_part = part++;
    for (int i = thread_part * (N / (NUM_THREADS-1)); i < (thread_part + 1) * (N / (NUM_THREADS-1)); i++) {
        res[i] = v1[i] + v2[i];
        mu.lock();
        progress++;
        mu.unlock();
    }
}

int main() {
    // Generate the vectors
    cout << "========= The first Vector ======" << endl;
    generate_vector(v1);
    print_vector(v1);

    cout << "========= The second Vector ======" << endl;
    generate_vector(v2);
    print_vector(v2);

    cout << "========= Logging ======" << endl;

    pthread_t threads[NUM_THREADS];

    // Creating NUM_THREADS threads. The last thread is for logging and threads 0 to NUM_THREADS - 1 do the addition.
    pthread_create(&threads[NUM_THREADS-1], nullptr, log_operation, (void *) nullptr);
    for (int i = 0; i < NUM_THREADS-1; i++)
        pthread_create(&threads[i], nullptr, parallel_add, (void *) nullptr);

    // joining NUM_THREADS threads i.e. waiting for all NUM_THREADS threads to complete
    for (int i = 0; i < NUM_THREADS; i++)
        pthread_join(threads[i], nullptr);

    cout << "========= The sum Vector ======" << endl;
    print_vector(res);

    // Free up the memory
    v1.clear();
    v2.clear();
    res.clear();
}