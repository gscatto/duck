#include <gtest/gtest.h>

extern "C"
{
#include "duck.h"
}

struct hello
{
    int value;
};

void set_value(void *data, void *args)
{
    struct hello *hello = (struct hello *)data;
    int *new_value = (int *)args;
    hello->value = *new_value;
}

void *get_value_ptr(void *data, void *args)
{
    struct hello *hello = (struct hello *)data;
    return &hello->value;
}

TEST(duck, tell)
{
    struct hello h;

    duck_define(d);
    duck_initialize(d);
    duck_set_data(d, &h);
    duck_set_tell_fn(d, set_value);

    int new_value = 56;
    duck_tell(d, &new_value);

    EXPECT_EQ(h.value, 56);
}

TEST(duck, ask)
{
    struct hello h;

    duck_define(d);
    duck_initialize(d);
    duck_set_data(d, &h);
    duck_set_ask_fn(d, get_value_ptr);

    int *value_ptr = (int *)duck_ask(d, NULL);

    EXPECT_EQ(value_ptr, &h.value);
}