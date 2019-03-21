#include "cheststate.h"

#include <chest.h>

void Open::next(Chest *ch) {
    ch->closeChest();
    ch->setState(new Close());
    delete this;
}

void Close::next(Chest *ch) {
    ch->openChest();
    ch->setState(new Open());
    delete this;
}
