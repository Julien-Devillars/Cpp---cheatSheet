#pragma once
#include "../import.h"

#include <mutex>
#include <thread>
#include <iostream>

struct Employee {
    Employee(std::string id) : id(id) {}
    std::string id;
    std::vector<std::string> lunch_partners;
    std::mutex m;
    std::string output() const
    {
        std::string ret = "Employee " + id + " has lunch partners: ";
        for (const auto& partner : lunch_partners)
            ret += partner + " ";
        return ret;
    }
};

void send_mail(Employee&, Employee&)
{
    // simulate a time-consuming messaging operation
    std::this_thread::sleep_for(std::chrono::seconds(1));
}

void assign_lunch_partner(Employee& e1, Employee& e2)
{
    static std::mutex io_mutex;
    {
        std::lock_guard<std::mutex> lk(io_mutex);
        std::cout << e1.id << " and " << e2.id << " are waiting for locks" << std::endl;
    }

    {
        // use std::scoped_lock to acquire two locks without worrying about 
        // other calls to assign_lunch_partner deadlocking us
        // and it also provides a convenient RAII-style mechanism

        std::scoped_lock lock(e1.m, e2.m);

        // Equivalent code 1 (using std::lock and std::lock_guard)
        // std::lock(e1.m, e2.m);
        // std::lock_guard<std::mutex> lk1(e1.m, std::adopt_lock);
        // std::lock_guard<std::mutex> lk2(e2.m, std::adopt_lock);

        // Equivalent code 2 (if unique_locks are needed, e.g. for condition variables)
        // std::unique_lock<std::mutex> lk1(e1.m, std::defer_lock);
        // std::unique_lock<std::mutex> lk2(e2.m, std::defer_lock);
        // std::lock(lk1, lk2);
        {
            std::lock_guard<std::mutex> lk(io_mutex);
            std::cout << e1.id << " and " << e2.id << " got locks" << std::endl;
        }
        e1.lunch_partners.push_back(e2.id);
        e2.lunch_partners.push_back(e1.id);
    }

    send_mail(e1, e2);
    send_mail(e2, e1);
}

std::string function_22_concurrency(){
  // 22. Concurrency
	std::string toReturn = "";
    std::cout << "######### 22 Concurency ############\n\n";
	
    // code from cppreference
    
    std::cout << "In C++17, the use of locking became significantly easier by the addition of : \n"
		" - scoped_lock - to acquire an arbitrary number of locks without the possibility of deadlock\n"
		" - shared_mutex and shared_lock - to implement reader-writer locks\n\n";

    std::cout << "Adding employee lunch partner\n\n";
    std::cout << "Without Thread (1sec between each partners added)\n\n";

    Employee a("alice"), b("bob"), c("christina"), d("dave");

    assign_lunch_partner(a, b);
    assign_lunch_partner(c, b);
    assign_lunch_partner(c, a);
    assign_lunch_partner(d, b);
    
    std::cout 
        << a.output() << '\n' 
        << b.output() << '\n'
        << c.output() << '\n' 
        << d.output() << '\n';

    // THREAD

    std::cout << "With Thread (1 sec at the end too but parallel)\n\n";

    Employee alice("alice"), bob("bob"), christina("christina"), dave("dave");
    std::vector<std::thread> threads;

    threads.emplace_back(assign_lunch_partner, std::ref(alice), std::ref(bob));
    threads.emplace_back(assign_lunch_partner, std::ref(christina), std::ref(bob));
    threads.emplace_back(assign_lunch_partner, std::ref(christina), std::ref(alice));
    threads.emplace_back(assign_lunch_partner, std::ref(dave), std::ref(bob));
    
    for (auto& thread : threads) 
        thread.join();

    std::cout 
        << alice.output() << '\n' 
        << bob.output() << '\n'
        << christina.output() << '\n' 
        << dave.output() << '\n';
    
	return toReturn;
}