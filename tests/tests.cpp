extern "C"{
#include <stddef.h>
#include <stdarg.h>
#include <setjmp.h>
#include <cmocka.h>
#include <stdbool.h>
}

#include <random>
#include <cassert>
#include <sparse_set.h>
#include <unordered_map>

static auto test_create_sparse_set(void **) -> void {
    sparse_set<int> s;

    assert_int_equal(s.size(), 0);
}

static auto test_insert_and_get(void **) -> void {
    sparse_set<int> s;

    s.insert(0, 5);
    s.insert(3, 20);
    s.insert(40, 6);

    assert_int_equal(s.size(), 3);
    assert_int_equal(s[0], 5);
    assert_int_equal(s[3], 20);
    assert_int_equal(s[40], 6);
}

static auto test_check_no_random_inserts(void **) -> void {
    sparse_set<int> s;
    std::unordered_map<int, int> random_ints;
    std::random_device rd;
    std::mt19937 gen = std::mt19937(rd());
    std::uniform_int_distribution<int> dist(0, 1000);;


    for (size_t i = 0; i < 100; i++) {
     //   random_ints[
    }
}

static auto test_erase(void **) -> void {
    sparse_set<int> s;
    s.insert(0, 5);
    s.insert(3, 20);
    s.insert(40, 6);


    s.erase(3);

    assert_int_equal(s.size(), 2);

}

auto main() -> int {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_create_sparse_set),
        cmocka_unit_test(test_insert_and_get),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);

}
