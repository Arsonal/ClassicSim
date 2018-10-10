#ifndef BERSERKING_H
#define BERSERKING_H

#include "Spell.h"

class Character;

class Berserking: public Spell {
public:
    Berserking(Character* pchar);

protected:
private:
    void spell_effect() override;
    void enable_spell_effect() override;
    void disable_spell_effect() override;
};

#endif // BERSERKING_H