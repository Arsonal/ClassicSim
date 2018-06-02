#ifndef MAINHANDATTACK_H
#define MAINHANDATTACK_H

#include "Spell.h"

class MainhandAttack: public Spell {
public:
    MainhandAttack(Engine* engine, Character* pchar, CombatRoll* roll);

    float get_next_expected_use() const;
    void update_next_expected_use(const float);
    bool attack_is_valid(const int) const;
    int get_next_iteration();
    void reset_effect() override;
    float get_cooldown() override;

    void complete_swing();
    virtual void extra_attack();

protected:
    virtual int spell_effect(const int) override;
    virtual int calculate_damage();
    float next_expected_use;
    int iteration;
    QVector<float> talent_ranks;
private:
};

#endif // MAINHANDATTACK_H
