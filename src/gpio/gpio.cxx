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

#include <gpio/gpio.hpp>




namespace raspcontrol {




RCGpio::RCGpio()
{
};




RCGpio::~RCGpio()
{
};




void RCGpio::run()
{
};




void RCGpio::stop()
{
};




void RCGpio::set_device(std::string _gpio_device)
{
    gpio_device = _gpio_device;
};




void RCGpio::set_events_loop(std::shared_ptr<raspcontrol::RCEvents> _events)
{
    events = _events;
};




}
