#include <iostream>
#include <vector>
#include "p_queue.h"
#include <random>
#include <chrono>    

int main()
{

std::mt19937 generator(std::chrono::system_clock::now().time_since_epoch().count());
std::uniform_int_distribution<int> dist(15, 30);

int random_price = dist(generator);


	struct CompBroker
	{ //and comparison functions
		bool operator()(const Broker & lhs, const Broker & rhs) const
		{
			return lhs.price < rhs.price;
		}
	};
	//Define two queues. One for sell orders, one for buy orders.
	p_queue<Broker, CompBroker> buyers, sellers;

	int n = 7;
	for(int i = 0; i < n; i++)
	{
		//set up 21 buy and sell orders with brokers 'Erik Pendel', 'Jarl Wallenburg' and 'Joakim von Anka'.
		// Each broker receives seven sell and buy orders each. The price of sell and buy orders is randomized between,
		// say, 15 and 30 kroner. When the program is run, it should print the results of all sales. 
		//So there will probably be fewer than 21 buy/sell printed on the screen.
		buyers.push({"Erik Pendel", dist(generator)});
		buyers.push({"Jarl Wallenburg", dist(generator)});
		buyers.push({"Joakim von Anka", dist(generator)});
		//A sales order contains the name of the seller and the price the seller wants.
		sellers.push({"Erik Pendel", dist(generator)});
		sellers.push({"Jarl Wallenburg", dist(generator)});
		sellers.push({"Joakim von Anka", dist(generator)});
	}
	//A buy/sell is made if the seller requests a lower price than what the buyer offers. 
	//If the buyer bids less than the sell order, the buy order becomes invalid and discarded. 
	//Otherwise, the purchase is completed and the buyer's name and seller's name and agreed price are printed on the screen.
	while(!buyers.empty() && !sellers.empty())
	{
		
		auto buyer = buyers.pop();
		auto seller = sellers.pop();

		if(buyer.price >= seller.price)
		{
			std::cout << buyer.name << " bought shares worth " << seller.price << " for the price of "
				<< buyer.price << " from " << seller.name<< '\n';
		}
		else
		{
			buyers.push({buyer.name, buyer.price});
			sellers.push({seller.name, seller.price});

		}
		
	}
	
	return 0;
}
