/*************************************************************************
	> File Name: 38.thread_pool.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年08月13日 星期四 16时08分16秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <thread>
#include <map>
#include <mutex>
#include <functional>
#include <set>
#include <unistd.h>
#include <condition_variable>
#include <vector>
using namespace std;


// 使用bind()将函数和函数参数绑定到一起 组成可执行对象

class Task {
public :
    template<typename T, typename ...ARGS>
    Task(T func, ARGS... args) {
        this->func = std::bind(func, forward<ARGS>(args)...);
    }
    void operator()() {
        this->func();
    }

private :
    function<void()> func;
};


class ThreadPool {
public :
    ThreadPool(int n = 5) 
    : is_running(false), max_threads_num(n) {}
    
    void start() {
        if (is_running) return ;
        is_running = true;
        for (int i = 0; i < max_threads_num; i++) {
            threads.push_back(new thread(&ThreadPool::worker, this));
        }
    }
    void stop() {
        // while (!task_queue.empty()) {}
        // if (is_running == false) return ;
        do { 
            unique_lock<mutex> lock(m_mutex);
            // lock析构时会自动解锁
            is_running = false;
            m_cond.notify_all();
        } while (0);
        for (int i = 0; i < this->max_threads_num; i++) {
            this->addOneTask(&ThreadPool::stop_task, this);
        }
        for (int i = 0; i < max_threads_num; i++) {
            threads[i]->join();
            delete threads[i];
        }
        threads.clear();
    }
    

    void worker() {
        // cout << "worker: hello, I'm worker" << endl;
        thread::id id = this_thread::get_id();
        is_running[id] = true;


        while (is_running[id]) {
            // 取任务
            Task *t = this->getOneTask();
            // if (t == nullptr) break;
            // 执行任务
            (*t)();
            // 释放任务
            delete t;
        }
    }

    template<typename T, typename ...ARGS>
    void addOneTask(T func, ARGS... args) {
        unique_lock<mutex> lock(m_mutex); // 抢占互斥锁
        this->task_queue.push(new Task(func, forward<ARGS>(args)...));
        cout << std::this_thread::get_id() << ": add one task" << endl;
        m_cond.notify_one();
    }
        
private :
    void stop_task() {
        thread_id id = this->thread::get_id();
        is_running[id] = false;
    }
    Task *getOneTask() {
        unique_lock<mutex> lock(m_mutex);
        while (is_running && task_queue.empty()) {
            // 队列为NULL，等待队列中存在任务
            // 临时释放互斥锁，使addOneTask向任务队列中加入Task
            // 之后会自动加锁
            cout << "task_queue empty, wait for task" << endl;
            m_cond.wait(lock);
        }
        if (is_running == false) return nullptr;
        cout << std::this_thread::get_id() << ": take one task" << endl;
        Task *t = task_queue.front();
        task_queue.pop();
        return t;
    }

    queue<Task *> task_queue;
    int max_threads_num;
    bool is_running;
    vector<thread *> threads; // 线程池
    map<thread::id, bool> running_map;


    std::mutex m_mutex; // 互斥锁
    std::condition_variable m_cond; // 条件变量
};

void task_func(int x) {
    cout << "thread task func"<< endl;
}

void thread_func1(int a, int b) {
    cout << a << " + " << b << " = " << a + b << endl;
}

void thread_func2(int &n) {
    // cout << "address of n: " << &n << endl;
    n += 1;
}

int main() {
    /*
    Task t1(thread_func1, 3, 4);
    Task t2(thread_func1, 5, 6);
    Task t3(thread_func1, 7, 8);
    t1(), t2(), t3();

    int n = 0;
    Task t4(thread_func2, ref(n));
    t4();
    t4();
    t4();
    cout << n << endl;
    */

    ThreadPool tp(3);
    tp.start();
  
    sleep(1);
    cout << "before" << endl;
    tp.addOneTask(task_func, 1);
    tp.addOneTask(task_func, 2);
    // tp.addOneTask(task_func, 3);
    cout << "end" << endl;

    sleep(1);
    tp.stop();
        
    return 0;
}


// 尝试实现线程池的类
// C++ STL中提供的都是非线程安全的临界资源
