#include<linux/syscalls.h>

SYSCALL_DEFINE1(my_sleep, unsigned int, seconds)
{
    ktime_t sleep_time;
    unsigned long remaining_jiffies;

    if (seconds == 0)
        return 0;

    sleep_time = ktime_set(seconds, 0);
    remaining_jiffies = schedule_timeout_interruptible(
        ktime_to_ms(sleep_time) / MSEC_PER_SEC * HZ
    );

    if (signal_pending(current))
        return -ERESTARTSYS;

    return 0;
}