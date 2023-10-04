//
// Created by Scors on 04/10/2023.
//

#include "Client.h"

void Client::connect()
{
  if(socket->connect("127.0.0.1", 53000) == sf::Socket::Status::Done)
  {
    std::cout << "You're connected!" << std::endl;
    connected = true;
  }
  else
  {
    std::cout << "failed to connect";
  }
}