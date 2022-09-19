#include "duck.h"

struct duck
{
    void *data;
    duck_ask_fn_t ask;
    duck_tell_fn_t tell;
};

const unsigned long sizeof_duck = sizeof(struct duck);

void duck_default_tell_fn(void *data, void * args)
{
}

void * duck_default_ask_fn(void *data, void * args)
{
    return NULL;
}

void duck_initialize(duck_t self)
{
    self->data = NULL;
    self->ask = duck_default_ask_fn;
    self->tell = duck_default_tell_fn;
}

void duck_set_data(duck_t self, void *it)
{
    self->data = it;
}

void duck_set_ask_fn(duck_t self, duck_ask_fn_t it)
{
    self->ask = it;
}

void * duck_ask(duck_t self, void * args)
{
    return self->ask(self->data, args);
}

void duck_set_tell_fn(duck_t self, duck_tell_fn_t it)
{
    self->tell = it;
}

void duck_tell(duck_t self, void * args)
{
    self->tell(self->data, args);
}