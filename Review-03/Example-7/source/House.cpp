#include <utility>
#include <algorithm>
#include <numeric>
#include <iterator>

#include "House.h"

//------------------------------------------------------------------------------
House::House()
    :name("House")
{
}

//------------------------------------------------------------------------------
House::House(std::string name)
    :name(name)
{
}

//------------------------------------------------------------------------------
void House::addRoom(Room toAdd)
{
    rooms.push_back(toAdd);
}

//------------------------------------------------------------------------------
size_t House::size() const {
    return rooms.size();
}

//------------------------------------------------------------------------------
House::iterator House::begin()
{
    return rooms.begin();
}

//------------------------------------------------------------------------------
House::const_iterator House::begin() const
{
    return rooms.begin();
}

//------------------------------------------------------------------------------
House::iterator House::end()
{
    return rooms.end();
}

//------------------------------------------------------------------------------
House::const_iterator House::end() const
{
    return rooms.end();
}

//------------------------------------------------------------------------------
void House::display(std::ostream& outs) const
{
    outs << "--------" << this->name << "--------" << "\n";

    // What type of iterator am I using--i.e.,
    // iterator or const_iterator?

    // Print the rooms
    /*
    for (const Room& prtRoom : rooms) {
        outs << prtRoom;
    }
    */
    std::ostream_iterator<Room> outs_it(outs);
    std::copy(begin(), end(), outs_it);

    // Compute and print the total
    /*double total = 0;
    std::for_each(rooms.begin(), rooms.end(),
                  [&total](const Room& rm)
                  {
                      total += rm.flooringCost();
                  });*/

    double total = std::accumulate(rooms.begin(), rooms.end(), 0.0,
                                   [](double t, const Room& rm) -> double
                                   {
                                       return t + rm.flooringCost();
                                   });
    double avg   = total / this->size();

    outs << "\n";
    outs << "------------------------------";
    outs << "\n";

    outs << "Total Cost   : $ " << total << "\n";
    outs << "Avg Room Cost: $ " << avg   << "\n";
}

//------------------------------------------------------------------------------
void swap(House& lhs, House& rhs)
{
    using std::swap;

    swap(lhs.name, rhs.name);
    swap(lhs.rooms, rhs.rooms);
}