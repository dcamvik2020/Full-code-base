#include <mutex>
#include <condition_variable>
#include <iostream>

class Restaurant {
  enum class Status { idle, newOrder, ready };
  Status orderStatus = Status::idle;
  std::mutex order;
  std::condition_variable orderBell;
    
  // extantion for several orders --> vector<mutex>

public:

  void chef() {    
    std::unique_lock<std::mutex> ul(order);
    orderBell.wait(ul, [=]() { return orderStatus == Status::newOrder; });
    //приготовление блюд из заказа
    orderStatus = Status::ready;
    orderBell.notify_one();    
  }

  void waiter() {
    { 
      std::lock_guard<std::mutex> lg(order); 
      orderStatus = Status::newOrder;
      orderBell.notify_one();
    } // lg вне области видимости = order.unlock()
        
    std::unique_lock<std::mutex> ul(order);
    orderBell.wait(ul, [=]() { return orderStatus == Status::ready; });
    orderStatus = Status::idle;
    ul.unlock();
    //приносят заказ
  }

};

#include <thread>

// example extantion : consider normal restaurant with waiters and chefs
void several_waiters_and_chefs(Restaurant & restaurant) {
  // 2 waiters, 2 chefs
  std::thread

}


int main() {
  //unsigned max_waiters;
  Restaurant restaurant;
 

  several_waiters_and_chefs(restaurant);

/* 
  //restaurant.chef();                    ---> works
  //restaurant.chef(restaurant.this);     ---> works
  
  //std::thread chef(&Restaurant::chef, std::ref(restaurant));  std::ref работает именно так хорошо, есть invoke внутри
  std::thread chef(&Restaurant::chef, &restaurant);         /// std::ref <---> std::reference_wrapper <---> pointer to object
  
  //std::thread waiter(&Restaurant::waiter, std::ref(restaurant));
  std::thread waiter(&Restaurant::waiter, &restaurant);
  chef.join();
  waiter.join();
*/

  return 0;
}
