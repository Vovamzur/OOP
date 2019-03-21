#pragma once

#ifndef CHESTSTATE_H
#define CHESTSTATE_H

class Chest;

struct ChestState {
    virtual void next(Chest *ch);
    virtual ~ChestState() = default;
};

struct Open : public ChestState {
    void next(Chest *ch) override final;
    ~Open() override final {}
};

struct Close : public ChestState {
    void next(Chest *ch) override final;
    ~Close() override final {}
};

#endif // CHESTSTATE_H
