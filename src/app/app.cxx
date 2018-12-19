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

#include <app/app.hpp>




namespace raspcontrol {




RCApp::RCApp()
{
    events     = std::make_shared<raspcontrol::RCEvents>();
    controller = std::make_shared<raspcontrol::RCController>();
    gpio       = std::make_shared<raspcontrol::RCGpio>();
    server     = std::make_shared<raspcontrol::RCServer>();
};




RCApp::~RCApp()
{
    // stop http server first
    if(server)
        server->stop();

    // next stop controller
    if(controller)
        controller->stop();

    // finally stop gpio subsystem
    if(gpio)
        gpio->stop();
};




void RCApp::init(int argc, char *argv[])
{
    //set up http server
    int http_port = 8080;
    std::string http_address = "0.0.0.0";
    bool http_ssl = false;

    server->set_port(http_port);
    server->set_address(http_address);
    server->set_ssl(http_ssl);
    server->set_events_loop(events);

    // set up gpio device
    std::string gpio_device = "/dev/gpiodevice0";
    gpio->set_device(gpio_device);
    gpio->set_events_loop(events);

    // set up controller
    controller->set_gpio(gpio);
    controller->set_server(server);
    controller->set_events_loop(events);
};




void RCApp::run()
{
    gpio->run();
    controller->run();
    server->run();

    events->run();
};




}
