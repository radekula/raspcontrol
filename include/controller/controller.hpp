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




#include "gpio/gpio.hpp"
#include "server/server.hpp"
#include "events/events.hpp"




#ifndef __RASPCONTROL_CONTROLLER_HPP__
#define __RASPCONTROL_CONTROLLER_HPP__




namespace raspcontrol {




class RCController
{
private:
    std::shared_ptr<raspcontrol::RCGpio> gpio;                      //< GPIO object pointer
    std::shared_ptr<raspcontrol::RCServer> server;                  //< HTTP server object pointer
    std::shared_ptr<raspcontrol::RCEvents> events;                  //< Events loop object pointer

public:
    RCController();
    ~RCController();

public:
    /**
     * Run controller loop
     */
    void run();

    /**
     * Stop controller loop
     */
    void stop();

public:
    /**
     * Set GPIO handler
     *
     * @param _gpio GPIO device handler
     */
    void set_gpio(std::shared_ptr<raspcontrol::RCGpio> _gpio);

    /**
     * Set HTTP server handler
     *
     * @param _server HTTP server handler
     */
    void set_server(std::shared_ptr<raspcontrol::RCServer> _server);

    /**
     * Set events loop
     *
     * @param _events Events loop object pointer
     */
    void set_events_loop(std::shared_ptr<raspcontrol::RCEvents> _events);
};




}




#endif
