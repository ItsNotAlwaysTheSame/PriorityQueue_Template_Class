//https://www.geeksforgeeks.org/generics-in-c/ 
#ifndef P_QUEUE_H
#define P_QUEUE_H

#include <algorithm>
#include <vector>
#include <queue>
template<typename T,  typename S = std::less<>>
class p_queue
{
public:
	T pop()
	{
		T result = elements.top();//declared as the top value in the container (priority_queue)
		elements.pop(); //remove first element
		return result; //return its value
	}

	void push(const T & value)
	{
		elements.push(value);
	}

	size_t size() const
	{
		return elements.size();
	}

	bool empty() const
	{
		return elements.empty();
	}
	

private:
//explicit priority_queue( const Compare& compare = Compare(),
//                         const Container& cont = Container() );

	std::priority_queue<T, std::vector<T>, S> elements; //https://en.cppreference.com/w/cpp/container/priority_queue
	//The queues are arranged so that the orders with the lowest price have the highest priority.
};
//define classes for buy and sell orders, and comparison functions or function objects
struct Broker 
{
	std::string name;
	int price;
};
#endif