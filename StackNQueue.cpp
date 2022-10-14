#include <iostream>
#include <stack>
#include <queue>

int main()
{
  std::stack<int> tower;
  
  tower.push(3);
  tower.push(2);
  tower.push(1);
  
  while(!tower.empty()) {
    std::cout << tower.top() << " ";
    tower.pop();
  }
  // Outputs: 1 2 3
  
  std::queue<int> order;

  order.push(10);
  order.push(9);
  order.push(8);
  
  while(!order.empty()) {
    std::cout << order.front() << " ";
    order.pop();
  }
  // Outputs: 10 9 8

  return 0;
}