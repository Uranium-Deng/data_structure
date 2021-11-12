/*************************************************************************
	> File Name: hug.thread_pool.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年08月15日 星期六 15时53分17秒
 ************************************************************************/

#include <iostream>
#include <thread>
#include <map>
#include <mutex>
#include <functional>
#include <set>
#include <queue>
#include <unistd.h>
#include <condition_variable>
#include <vector>
using namespace std;

#define MAX_N 1000000

namespace haizei {
class Task {
public:
    template<typename T, typename ...ARGS>
    Task(T func, ARGS... args) {
        this->func = std::bind(func, std::forward<ARGS>(args)...);
    }
    void operator()() {
        this->func();
        return ;
    }
    ~Task() {}

private:
    std::function<void()> func;
};

class ThreadPool {
public :
    ThreadPool(int n = 5) 
    : max_threads_num(n),
    m_mutex(),
    m_cond() {}
    void start() {
        for (int i = 0; i < this->max_threads_num; i++) {
            threads.push_back(new std::thread(&ThreadPool::worker, this));
        }
        return ;
    }
    void worker() {
        std::thread::id id = std::this_thread::get_id();
        is_running[id] = true;
        while (is_running[id]) {
            Task *t = this->getOneTask();
            (*t)();
            delete t;
        }
        return ;
    }
    void stop() {
        for (int i = 0; i < this->max_threads_num; i++) {
            this->addOneTask(&ThreadPool::stop_task, this);
        }
        for (int i = 0; i < this->max_threads_num; i++) {
            threads[i]->join();
            delete threads[i];
        }
        threads.clear();
        return ;
    }

    template<typename T, typename ...ARGS>
    void addOneTask(T func, ARGS...args) {
        std::unique_lock<std::mutex> lock(m_mutex);
        //std::cout << std::this_thread::get_id() << " add one task" << std::endl;
        this->task_queue.push(new Task(func, std::forward<ARGS>(args)...));
        m_cond.notify_one();
        return ;
    }

private:
    void stop_task() {
        std::thread::id id = std::this_thread::get_id();
        is_running[id] = false;
        return ;
    }
    Task *getOneTask() {
        std::unique_lock<std::mutex> lock(m_mutex); // 抢碗
        while (task_queue.empty()) {
            //std::cout << std::this_thread::get_id() << " wait one task" << std::endl;
            m_cond.wait(lock);
        }// 等待，直到队列中存在任务
        //std::cout << std::this_thread::get_id() << " take one task" << std::endl;
        Task *t = task_queue.front();
        task_queue.pop();
        return t;
    }

    int max_threads_num;
    std::vector<std::thread *> threads;
    std::queue<Task *> task_queue;
    std::map<std::thread::id, bool> is_running;
    
    std::mutex m_mutex;
    std::condition_variable m_cond;
};
} // end of namespace haizei

void thread_func1(int a, int b) {
    std::cout << a << " + " << b << " = " << a + b << std::endl;
    return ;
}

void thread_func2(int &n) {
    n += 1;
    return ;
}

void (*func)();

void task_func(int x) {
    std::cout << "thread task func" << std::endl;
    return ;
}

int cnt = 0;
int prime[MAX_N + 5], is_prime[MAX_N + 5];
void init() {
    for (int i = 2; i <= MAX_N; i++) {
        if (!is_prime[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0]; j++) {
            if (i * prime[j] > MAX_N) break;
            is_prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}

void count_prime(int head, int tail) {
    for (int i = head; i <= tail; i++) {
        if (is_prime[i] == 1) continue;
        __sync_fetch_and_add(&cnt, i);
        // 无锁化，原子操作
    }
}


int main() {
    haizei::Task t1(thread_func1, 3, 4);
    haizei::Task t2(thread_func1, 5, 6);
    haizei::Task t3(thread_func1, 7, 8);
    t1(), t2(), t3();
    int n = 0;
    
    haizei::Task t4(thread_func2, std::ref(n));
    t4(), t4(), t4();
    std::cout << n << std::endl;

    haizei::ThreadPool tp(6);
    tp.start();
    /*
    tp.addOneTask(task_func, 123);
    tp.addOneTask(task_func, 123);
    tp.addOneTask(task_func, 123);
    tp.addOneTask(task_func, 123);
    */

    for (int i = 0, j = 1; i < 5; i++; j += 200000) {
        tp.addOneTask(count_prime, j, j + 200000 - 1);
    }

    tp.stop();
    cout << cnt << endl;
    
    tp.addOneTask(task_func, 123);
    tp.addOneTask(task_func, 123);
    tp.addOneTask(task_func, 123);
    std::cout << "hello world" << std::endl;

    return 0;
}
