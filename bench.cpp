#include <iostream>
#include <vector>
#include <chrono>

#define DATA_SIZE 50000000 
#define ACTIVE_COUNT 10000  

int main() {
    std::vector<int> pool(DATA_SIZE, 0);
    std::vector<int> idx;

    for(int i = 0; i < ACTIVE_COUNT; ++i) {
        int pos = rand() % DATA_SIZE;
        pool[pos] = 1;
        idx.push_back(pos);
    }

    std::cout << "--- STARTING SYNC SIMULATION (10 CYCLES) ---" << std::endl;

    for(int frame = 1; frame <= 10; ++frame) {
        // Метод А: Тяжелая синхронизация (Bottleneck simulation)
        auto start_a = std::chrono::high_resolution_clock::now();
        long long res_a = 0;
        for(int i = 0; i < DATA_SIZE; ++i) { if(pool[i] == 1) res_a++; }
        auto end_a = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> d_a = end_a - start_a;

        // Метод Б: Оптимизированный доступ
        auto start_b = std::chrono::high_resolution_clock::now();
        long long res_b = 0;
        for(int p : idx) { res_b++; }
        auto end_b = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> d_b = end_b - start_b;

        // Вывод FPS и времени
        std::cout << "Cycle " << frame << " | A: " << d_a.count() << "s (~" 
                  << (int)(1.0/d_a.count()) << " FPS) | B: " << d_b.count() << "s" << std::endl;
    }

    return 0;
}
