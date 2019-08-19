#include <stdio.h>

static unsigned char func_long(unsigned char v, unsigned char w, unsigned char i);

static unsigned char func2(unsigned char v, unsigned char w)
{
    unsigned char ret = 0;
    for (int i = 0; i < 4; i++) {
        ret = func_long(v, w, ret+i);
    }
    ret += 0xAB;
    return ret;
}

static unsigned char func1(unsigned char v)
{
    unsigned char ret = 0;
    unsigned char w = 1;
    ret = func2(v, w);
    ret += 0xAB;
    return ret;
}
#if 0
static unsigned char func_add(unsigned char v)
{
    return v++;
}
#endif
int main(int argc, char* argv[])
{
    unsigned char v0 = 0xF0;
    unsigned char ret = 0;
    ret = func1(v0);
    ret += 0xAB;
    return ret;
}

#define ops_100_add_1(v) \
    v += 1; v += 1; v += 1; v += 1; v += 1; v += 1; v += 1; v += 1; v += 1; v += 1; \
    v += 1; v += 1; v += 1; v += 1; v += 1; v += 1; v += 1; v += 1; v += 1; v += 1; \
    v += 1; v += 1; v += 1; v += 1; v += 1; v += 1; v += 1; v += 1; v += 1; v += 1; \
    v += 1; v += 1; v += 1; v += 1; v += 1; v += 1; v += 1; v += 1; v += 1; v += 1; \
    v += 1; v += 1; v += 1; v += 1; v += 1; v += 1; v += 1; v += 1; v += 1; v += 1; \
    v += 1; v += 1; v += 1; v += 1; v += 1; v += 1; v += 1; v += 1; v += 1; v += 1; \
    v += 1; v += 1; v += 1; v += 1; v += 1; v += 1; v += 1; v += 1; v += 1; v += 1; \
    v += 1; v += 1; v += 1; v += 1; v += 1; v += 1; v += 1; v += 1; v += 1; v += 1; \
    v += 1; v += 1; v += 1; v += 1; v += 1; v += 1; v += 1; v += 1; v += 1; v += 1; \
    v += 1; v += 1; v += 1; v += 1; v += 1; v += 1; v += 1; v += 1; v += 1; v += 1;

#define ops_1000_add_1(v) \
    ops_100_add_1(v) \
    ops_100_add_1(v) \
    ops_100_add_1(v) \
    ops_100_add_1(v) \
    ops_100_add_1(v) \
    ops_100_add_1(v) \
    ops_100_add_1(v) \
    ops_100_add_1(v) \
    ops_100_add_1(v) \
    ops_100_add_1(v)

#define ops_100_func_1(v) \
    v -= 1; v -= 1; v -= 1; v -= 1; v -= 1; v -= 1; v -= 1; v -= 1; v -= 1; v -= 1; \
    v -= 1; v -= 1; v -= 1; v -= 1; v -= 1; v -= 1; v -= 1; v -= 1; v -= 1; v -= 1; \
    v -= 1; v -= 1; v -= 1; v -= 1; v -= 1; v -= 1; v -= 1; v -= 1; v -= 1; v -= 1; \
    v -= 1; v -= 1; v -= 1; v -= 1; v -= 1; v -= 1; v -= 1; v -= 1; v -= 1; v -= 1; \
    v -= 1; v -= 1; v -= 1; v -= 1; v -= 1; v -= 1; v -= 1; v -= 1; v -= 1; v -= 1; \
    v -= 1; v -= 1; v -= 1; v -= 1; v -= 1; v -= 1; v -= 1; v -= 1; v -= 1; v -= 1; \
    v -= 1; v -= 1; v -= 1; v -= 1; v -= 1; v -= 1; v -= 1; v -= 1; v -= 1; v -= 1; \
    v -= 1; v -= 1; v -= 1; v -= 1; v -= 1; v -= 1; v -= 1; v -= 1; v -= 1; v -= 1; \
    v -= 1; v -= 1; v -= 1; v -= 1; v -= 1; v -= 1; v -= 1; v -= 1; v -= 1; v -= 1; \
    v -= 1; v -= 1; v -= 1; v -= 1; v -= 1; v -= 1; v -= 1; v -= 1; v -= 1; v -= 1;

#define ops_1000_func_1(v) \
    ops_100_func_1(v) \
    ops_100_func_1(v) \
    ops_100_func_1(v) \
    ops_100_func_1(v) \
    ops_100_func_1(v) \
    ops_100_func_1(v) \
    ops_100_func_1(v) \
    ops_100_func_1(v) \
    ops_100_func_1(v) \
    ops_100_func_1(v)

static unsigned char func_long(unsigned char v, unsigned char w, unsigned char i)
{
    unsigned ret = v + w + i;
    ops_1000_func_1(ret);
    ret += 0xAB;
    return ret;
}
