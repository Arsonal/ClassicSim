#ifndef TESTCONDITIONVARIABLEBUILTIN_H
#define TESTCONDITIONVARIABLEBUILTIN_H

#include "TestObject.h"

class ConditionVariableBuiltin;
class Engine;
class EquipmentDb;
class Hunter;
class Race;
class Rogue;
class SimSettings;

class TestConditionVariableBuiltin : TestObject {
public:
    TestConditionVariableBuiltin(EquipmentDb* equipment_db);
    void test_all() override;

private:
    void test_values_after_initialization() override;

    void test_combo_points_less();
    void test_combo_points_leq();
    void test_combo_points_equal();
    void test_combo_points_geq();
    void test_combo_points_greater();

    void test_auto_shot_timer_less();
    void test_auto_shot_timer_greater();

    Hunter* hunter;
    Rogue* rogue;
    Race* race;
    SimSettings* sim_settings;

    void set_up_rogue();
    void set_up_hunter();

    void tear_down();

    void set_event_priority(Engine* engine, const double priority);
};

#endif // TESTCONDITIONVARIABLEBUILTIN_H
