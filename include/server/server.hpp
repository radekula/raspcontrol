/*
    Raspcontrol - Cotrol Raspberry PI
    Copyright (C) 2018  Radosław Ulatowski

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/




#include <string>
#include <memory>

#include "events/events.hpp"




#ifndef __RASPCONTROL_SERVER_HPP__
#define __RASPCONTROL_SERVER_HPP__




namespace raspcontrol {




class RCServer
{
private:
    int port;                                                       //< Server port
    std::string address;                                            //< IP address to run on
    bool ssl;                                                       //< SSL mode
    std::shared_ptr<raspcontrol::RCEvents> events;                  //< Events loop object pointer

public:
    RCServer();
    ~RCServer();

public:
    /**
     * Run http server loop
     */
    void run();

    /**
     * Stop http server loop
     */
    void stop();

public:
    /**
     * Set server port
     *
     * @param _port New port number
     */
    void set_port(int _port);

    /**
     * Set IP addres to run on
     *
     * @param _address IP address
     */
    void set_address(std::string _address);

    /**
     * Set ssl mode
     *
     * @param _ssl New ssl mode
     */
    void set_ssl(bool _ssl);

    /**
     * Set events loop
     *
     * @param _events Events loop object pointer
     */
    void set_events_loop(std::shared_ptr<raspcontrol::RCEvents> _events);
};




}




#endif
