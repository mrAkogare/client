#include <iostream>
#include <string>

struct Client
{
	std::string name;
	Client* next;
};

Client* initClient()
{
	static int initCount = 0;
	if (initCount)
	{
		std::cout << "WARNING!!!";
	}
	else 
	{
		Client* first = new Client;
		std::cout << "Enter client's name: ";
		std::cin >> first->name;
		first->next = nullptr;
		return first;
	}
}

Client* addClient(Client* pred)
{
	Client* tek = new Client;
	std::cout << "Enter clinet's name: ";
	std::cin >> tek->name;
	tek->next = pred;
	return tek;
}

void printClients(Client* client)
{
	int i = 1;
	while (client)
	{
		std::cout << i << " Name: " << client->name << '\n';
		client = client->next;
		++i;
	}
}

int main()
{
	Client* temp = initClient();

	for (int i = 0; i < 5; ++i)
	{
		temp  = addClient(temp);
	}

	printClients(temp);
}
