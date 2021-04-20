#include <check.h>
#include "../src/vector.h"

START_TEST(test_vector_mag)
{
    struct vector test = {.x = 3.0, .y = 4.0};
    double mag = vector_magnitude(&test);

    ck_assert(mag == 5.0);
}
END_TEST

START_TEST(test_vector_multiply)
{
    struct vector test = {.x = 3.0, .y = 4.0};
    vector_multiply(&test, 2.0);

    ck_assert(test.x == 6.0);
    ck_assert(test.y == 8.0);
}
END_TEST

START_TEST(test_vector_multiply_when_zero)
{
    struct vector test = {.x = 0.0, .y = 0.0};
    vector_multiply(&test, 2.0);

    ck_assert(test.x == 0.0);
    ck_assert(test.y == 0.0);
}
END_TEST

int main(void)
{
    int failed = 0;

    Suite *suite = suite_create("Vector");
    SRunner *runner = srunner_create(suite);

    TCase *tcase_vector_mag = tcase_create("Magnitude");
    tcase_add_test(tcase_vector_mag, test_vector_mag);
    suite_add_tcase(suite, tcase_vector_mag);

    TCase *tcase_vector_multiply = tcase_create("Multiply");
    tcase_add_test(tcase_vector_multiply, test_vector_multiply);
    suite_add_tcase(suite, tcase_vector_multiply);

    TCase *tcase_vector_multiply_when_zero = tcase_create("Multiply When Zero");
    tcase_add_test(tcase_vector_multiply_when_zero, test_vector_multiply_when_zero);
    suite_add_tcase(suite, tcase_vector_multiply_when_zero);

    srunner_run_all(runner, CK_NORMAL);
    failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    return failed > 0 ? 1 : 0;
}