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




#include "events/events.hpp"




#ifndef __RASPCONTROL_GPIO_HPP__
#define __RASPCONTROL_GPIO_HPP__




namespace raspcontrol {




class RCGpio
{
private:
    std::string gpio_device;                                        //< GPIO device path
    std::shared_ptr<raspcontrol::RCEvents> events;                  //< Events loop object pointer

public:
    RCGpio();
    ~RCGpio();

public:
    /**
     * Run gpio loop
     */
    void run();

    /**
     * Stop gpio loop
     */
    void stop();

public:
    /**
     * Set GPIO device
     *
     * @param _gpio_device New GPIO device path
     */
    void set_device(std::string _gpio_device);

    /**
     * Set events loop
     *
     * @param _events Events loop object pointer
     */
    void set_events_loop(std::shared_ptr<raspcontrol::RCEvents> _events);
};




}




#endif
