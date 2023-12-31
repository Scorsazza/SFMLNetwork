//
// Created by Scors on 04/10/2023.
//

#ifndef SFMLGAME_CLIENT_H
#define SFMLGAME_CLIENT_H
#include <SFML/Network.hpp>
#include <iostream>
#include <atomic>
#include <thread>

class Client
{
 public:
  void connect();
  void input(sf::TcpSocket& iSocket) const;
  void run();

  std::atomic<bool> running = false;
  std::atomic<bool> connected = false;

 private:
  std::unique_ptr<sf::TcpSocket> socket;
};

#endif // SFMLGAME_CLIENT_H
