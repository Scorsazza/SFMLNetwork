//
// Created by Scors on 04/10/2023.
//

#include "Server.h"
void Server::init()
{
  if (listener == nullptr) listener = std::make_unique<sf::TcpListener>();
  // bind to port
  if (listener->listen(53000) != sf::Socket::Done)
  {
    // error...
  }
}

void Server::run()
{
  while(running)
  {
    sf::TcpSocket& cSock =
      connections.emplace_back(std::make_unique<sf::TcpSocket>()).operator*();
    if (listener->accept(cSock) != sf::Socket::Done)
    {
      connections.pop_back();
      std::cout << "Client Connected @ " << cSock.getRemotePort() << std::endl;
      return;
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }
}