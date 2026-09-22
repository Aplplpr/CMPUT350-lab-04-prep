#include <cassert>  // assert
#include <cstddef>  // size_t
#include <cstdint>  // uint64_t, uint32_t

// Expands the binary representation of input by a factor of scale.
// e.g., expand(0b1111ull, 3) == 0b001001001001
uint64_t expand(uint64_t input, uint32_t scale) {
    assert(scale > 0);

    uint64_t result = 0;

    for (uint32_t i = 0; i <= 63 / scale; i++) {
        if (((input >> i) & 1ull) == 1) {
            result |= (1ull << (i * scale));
        }
    }

    return result;
}

int main() {
    // test here...
    assert(expand(0b1111ull, 3) == 0b001001001001ull);

    assert(expand(0b1ull, 3) == 0b1ull);

    assert(expand(0b11ull, 2) == 0b0101ull);

    assert(expand(0b101ull, 2) == 0b10001ull);
    
    return 0;
}
