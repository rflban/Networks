#include "queue.h"

int main(int argc, char **argv)
{
    int zeroes[20] = { 0 };
    queue_t queue = queue_create();

    queue_pop(queue);
    for (int i = 0; i < sizeof(zeroes)/sizeof(zeroes[0]); ++i)
    {
        queue_push(queue, (void *)(zeroes + i));

        if (i % 5 == 0)
            queue_pop(queue);
    }

    queue_delete(&queue);

    return 0;
}
