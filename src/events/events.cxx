/*
    Raspcontrol - Cotrol Raspberry PI
    Copyright (C) 2018  Radosław Ulatowski

    This library is free software; you can redistribute it and/or
    modify it under the terms of thee GNU Lesser General Public
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

#include <events/events.hpp>




namespace raspcontrol {




RCEvents::RCEvents()
{
    wait_delay = 1;
};




RCEvents::~RCEvents()
{
};




std::unique_ptr<raspcontrol::RCEvent> RCEvents::next_event()
{
    // lock loop before adding new event to list
    std::lock_guard<std::mutex> guard(loop_lock);

    std::unique_ptr<raspcontrol::RCEvent> event;

    // return empty event if list is empty
    if(events.empty())
        return event;

    event = std::move(events.front());
    events.pop_front();

    return event;
};




void RCEvents::process_event(std::unique_ptr<raspcontrol::RCEvent> event)
{
};




void RCEvents::run()
{
    // start loop
    running = true;

    // keep loop running until stop event occurs
    while(running)
    {
        auto event = next_event();
        if(event)
        {
            // if there is new event procced it
            process_event(std::move(event));
        }
        else
        {
            // if there is no new event sleep for a short while for
            std::this_thread::sleep_for(std::chrono::milliseconds(wait_delay));
        }
    };
};




void RCEvents::send_event(std::unique_ptr<raspcontrol::RCEvent> event)
{
    // lock loop before adding new event to list
    std::lock_guard<std::mutex> guard(loop_lock);

    events.push_back(std::move(event));
}




}
