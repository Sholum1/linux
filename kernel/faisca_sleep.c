#include <linux/syscalls.h>
#include <linux/random.h>

SYSCALL_DEFINE1(faisca_sleep, unsigned int, seconds)
{
    unsigned long remaining_jiffies;
    unsigned long additional_time;

    if (seconds == 0)
        return 0;


    get_random_bytes((u8*)&additional_time, 4);

    additional_time %= 1000; // Setting the additional time to be at most 1 second

    remaining_jiffies = schedule_timeout_interruptible(
        msecs_to_jiffies(1000*seconds + additional_time)
    );

    if (signal_pending(current))
        return -ERESTARTSYS;

    return 0;
}
