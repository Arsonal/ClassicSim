
#include "Bloodthirst.h"

#include <iostream>

int Bloodthirst::spell_effect(const int resource_level) const {
    // TODO: Roll special hit attack table and deal damage based on outcome.
    // TODO: Apply Flurry buff if critical.
    // TODO: Apply Overpower if dodge.
    assert(resource_level >= resource_cost);

    std::cout << engine->get_current_priority() <<
                 ": Casting Bloodthirst at " << resource_level << " rage.\n";

    return resource_cost;
}