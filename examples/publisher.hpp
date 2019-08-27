#ifndef PUBLISHER_HPP
#define PUBLISHER_HPP

#include <iostream>
#include <vector>

#include <nng/nng.h>
#include <nng/protocol/pubsub0/pub.h>

class Publisher {
public:
	Publisher(std::string url);
	~Publisher();

	void publish(const char* message, ssize_t len);
	void publish(const std::vector<unsigned char> &message);
	void publish(const std::vector<char> &message);
	void publish(const std::string &message);

private:
	nng_socket _socket;
	std::string _url;
};

#endif // PUBLISHER_HPP
