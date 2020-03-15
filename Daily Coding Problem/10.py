""" 
# 
# Good morning! Here's your coding interview problem for today.
# This problem was asked by Apple.
# Implement a job scheduler which takes in a function f and an integer n, and calls f after n milliseconds.
#
# 
"""

import threading
import time


THREAD_COUNT = 0

# in seconds (amount of time taken by a single job)
JOB_EXEC_TIME = 10

# in milli seconds (time interval between two job threads)
JOB_FREQ_TIME = 5000


def job():
    id = THREAD_COUNT
    print("Job #" + str(id) + " started at: " + str(time.time()))
    time.sleep(JOB_EXEC_TIME)
    print("Job #" + str(id) + " ended at: " + str(time.time()))


def scheduler(f, n):
    global THREAD_COUNT
    while True:
        t = threading.Thread(target=f)
        t.start()
        time.sleep(n/1000)

        THREAD_COUNT += 1


if __name__ == '__main__':
    scheduler(job, JOB_FREQ_TIME)
