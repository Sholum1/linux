#include <linux/syscalls.h>
#include <linux/random.h>

SYSCALL_DEFINE3(faisca_sleep, unsigned int, low_milli, unsigned int, high_milli, unsigned int*, decided_time)
{
    unsigned int remaining_jiffies;
    unsigned int additional_time;

    if(low_milli > high_milli){
        return -EINVAL; // cant have maximum below minimum
    }

    if(decided_time == NULL){
        return -EINVAL; // pointer must be non-NULL
    }

    get_random_bytes((u8*)&additional_time, 4);

    additional_time %= high_milli-low_milli+1; // bounding additional time to not exceed high_milli
    *decided_time = low_milli+additional_time;

    remaining_jiffies = schedule_timeout_interruptible(
        msecs_to_jiffies(*decided_time)+1 // +1 to avoid sending 0 jiffies
    );

    return 0;
}
