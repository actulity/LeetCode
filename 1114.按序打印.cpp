/*
 * @lc app=leetcode.cn id=1114 lang=cpp
 *
 * [1114] 按序打印
 */

// @lc code=start
#include<semaphore.h>

class Foo {
protected:
    sem_t firstJobDone;
    sem_t secondJobDone;

public:
    Foo() {
        sem_init(&firstJobDone, 0, 0);
        sem_init(&secondJobDone, 0, 0);
    }

    void first(function<void()> printFirst) {
        sem_post(&firstJobDone);
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
    }

    void second(function<void()> printSecond) {
        sem_wait(&firstJobDone);
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();

        sem_post(&secondJobDone);
    }

    void third(function<void()> printThird) {
        sem_wait(&secondJobDone);
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};
// @lc code=end

