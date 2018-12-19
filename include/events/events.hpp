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



#ifndef __RASPCONTROL_EVENTS_HPP__
#define __RASPCONTROL_EVENTS_HPP__




#include <list>
#include <memory>
#include <mutex>
#include <thread>

#include "events/event.hpp"




namespace raspcontrol {




class RCEvents
{
private:
    bool running;                                                   //< Indicates if loop should be running
    std::mutex loop_lock;                                           //< Control access to loop between threads
    std::list<std::unique_ptr<raspcontrol::RCEvent>> events;        //< List of events to process
    long wait_delay;                                                //< Number of milliseconds to wait between events

private:
    /**
     * Get next event if there is one
     *
     * @return Next event from list or null when there is no event to process
     */
    std::unique_ptr<raspcontrol::RCEvent> next_event();

    /**
     * Process event
     *
     * @param event Event to process
     */
    void process_event(std::unique_ptr<raspcontrol::RCEvent> event);

public:
    RCEvents();
    ~RCEvents();

public:
    /**
     * Run events loop
     */
    void run();

public:
    /**
     * Add new event to event loop
     *
     * @param event Event to send
     */
    void send_event(std::unique_ptr<raspcontrol::RCEvent> event);
};




}




#endif
