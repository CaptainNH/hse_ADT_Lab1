#include <cmath>

extern "C" {
    void find_nearest_indices(const double* timestamps1, int size1,
                              const double* timestamps2, int size2,
                              int* matching) {
        int j = 0;
        for (int i = 0; i < size1; ++i) {
            while (j < size2 - 1 && std::abs(timestamps1[i] - timestamps2[j + 1]) < std::abs(timestamps1[i] - timestamps2[j])) {
                ++j;
            }
            matching[i] = j;
        }
    }
}
