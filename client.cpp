#include "headers/client.hpp"
#include <iostream> //
namespace socket_communication
{

  Client::Client() {}
  Client::Client(const std::string ip, const int port)
  {
    Init(ip, port);
  }
  Client::~Client()
  {
    close(client_);
  }

  void Client::Init(const std::string ip, const int port)
  {
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 0), &wsaData);
    this->client_ = socket(AF_INET, SOCK_STREAM, 0);

    if (this->client_ < 0)
    {
      std::cout << "[!] Unable to create socket" << std::endl;
    }
    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr((ip).c_str());
    serv_addr.sin_port = htons(port);

    if (connect(this->client_, (SOCKADDR *)&serv_addr, sizeof(sockaddr)) == SOCKET_ERROR)
    {
      std::cout << "[!] Unable to connect to remote socket" << std::endl;
    }
  }

  void Client::Send(std::string message)
  {
    // Send length of the message
    int length = message.length();
    std::string length_str = std::to_string(message.length());
    std::string message_length =
        std::string(size_message_length_ - length_str.length(), '0') + length_str;
    send(client_, message_length.c_str(), size_message_length_, 0);

    // Send message
    send(client_, message.c_str(), length, 0);
  }

  std::string Client::Receive()
  {
    // Receive length of the message
    char message_length[size_message_length_] = {0};
    int n = recv(client_, message_length, size_message_length_, 0);
    std::string message_length_string(message_length);
    int length = std::stoi(message_length_string);

    // receive message
    char message[length] = {0};
    n = recv(client_, message, length, 0);
    return message;
  }
} // namespace socket_communication