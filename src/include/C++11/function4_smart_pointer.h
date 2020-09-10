#pragma once
#include "../import.h"

#include <iostream>
#include <memory>
#include <thread>
#include <chrono>
#include <mutex>


// Shared ptr
namespace shared_ptr
{
    struct Base
    {
        Base() { std::cout << "  Base::Base()\n"; }
        // Note: non-virtual destructor is OK here
        ~Base() { std::cout << "  Base::~Base()\n"; }
    };

    struct Derived : public Base
    {
        Derived() { std::cout << "  Derived::Derived()\n"; }
        ~Derived() { std::cout << "  Derived::~Derived()\n"; }
    };

    void thr(std::shared_ptr<Base> p)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::shared_ptr<Base> lp = p; // thread-safe, even though the
                                      // shared use_count is incremented
        {
            static std::mutex io_mutex;
            std::lock_guard<std::mutex> lk(io_mutex);
            std::cout << "local pointer in a thread:\n"
                << "  lp.get() = " << lp.get()
                << ", lp.use_count() = " << lp.use_count() << '\n';
        }
    }

    void function4_shared_ptr() {

        std::cout << "Shared Ptr \n\n";

        std::shared_ptr<Base> p = std::make_shared<Derived>();

        std::cout << "Created a shared Derived (as a pointer to Base)\n"
            << "  p.get() = " << p.get()
            << ", p.use_count() = " << p.use_count() << '\n';
        std::thread t1(thr, p), t2(thr, p), t3(thr, p);
        p.reset(); // release ownership from main
        std::cout << "Shared ownership between 3 threads and released\n"
            << "ownership from main:\n"
            << "  p.get() = " << p.get()
            << ", p.use_count() = " << p.use_count() << '\n';
        t1.join(); t2.join(); t3.join();
        std::cout << "All threads completed, the last one deleted Derived\n";
    }
}

// Unique ptr
namespace unique_ptr
{
    class Song 
    {
    public:
        Song(std::string artist, std::string title) : _artist(artist), _title(title)
        {};
        void draw() 
        {
            std::cout << "Artist : " << _artist << " - Title : " << _title << std::endl;
        }
        std::string _artist;
        std::string _title;
    };

    std::unique_ptr<Song> SongFactory(const std::string& artist, const std::string& title)
    {
        // Implicit move operation into the variable that stores the result.
        return std::make_unique<Song>(artist, title);
    }

    void function4_unique_ptr()
    {
        std::cout << "Unique Ptr \n\n";

        // Create a new unique_ptr with a new object.
        auto song = std::make_unique<Song>("Mr. Children", "Namonaki Uta");
        song->draw();

        // Use the unique_ptr.
        std::string title = song->_title;
        std::string title2 = song.get()->_title;
        
        std::cout << title << " == " << title2 << " == " << "Namonaki Uta\n\n";

        //std::unique_ptr<Song> song2 = song; // Copy raw pointer from one unique_ptr to another. => Error

        std::cout << "Can't use assignement or copy operator with unique ptr\n\n";

        // Move raw pointer from one unique_ptr to another.
        std::unique_ptr<Song> song3 = std::move(song);
        std::cout << "Using the move operator works\n\n";
        song3.get()->draw();
    }
}

// Weak ptr
namespace weak_ptr
{
    std::weak_ptr<int> gw;

    void observe()
    {
        std::cout << "use_count == " << gw.use_count() << ": ";

        // Has to be copied into a shared_ptr before usage
        if (auto spt = gw.lock())  
            std::cout << *spt << "\n";
        else 
            std::cout << "gw is expired\n";
        
    }

    void function4_weak_ptr()
    {
        std::cout << "Weak ptr \n";
        {
            auto sp = std::make_shared<int>(123);
            gw = sp;

            observe();
        }

        observe();
    }
}
std::string function_4_smart_pointer(){
    // 4. Smart Pointer
    std::cout << "######### 4 Smart Pointer ############\n\n";

    // Shared ptr : representing shared ownership

    // The ownership of an object can only be shared with another shared_ptr 
    // by copy constructing or copy assigning its value to another shared_ptr.

    // Example from cppReference : https://en.cppreference.com/w/cpp/memory/shared_ptr

    shared_ptr::function4_shared_ptr();
    std::cout << "\n";

    // unique ptr : representing unique ownership

    // Can be moved but not copied

    unique_ptr::function4_unique_ptr();
    std::cout << "\n";


    // weak ptr : temporary ownership
    
    // when an object needs to be accessed only if it exists
    // and it may be deleted at any time by someone else
    weak_ptr::function4_weak_ptr();
    std::cout << "\n";


	return "";
}