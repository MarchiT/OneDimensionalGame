#ifndef DEMO_ENEMIES_H_
#define DEMO_ENEMIES_H_

class DemoEnemies {
public:
    /* BASIC ENEMIES */
    static void basic_short(PassiveEnemy *p);
    static void basic_long(PassiveEnemy *p);
    static void colourful_blue(PassiveEnemy *p); //add reverse
    static void disguise(PassiveEnemy *p);
    /* MERGED ENEMIES */
    static void lift(int level, int size, int location, int speed, OneDimensionalGame* odg);
    static void reverse_lift(int level, int size, int location, int speed, OneDimensionalGame* odg);
    static void trap(int level, int size, int location, OneDimensionalGame* odg);
    /* LOCK ENEMIES */
    static void lock(LockedEnemy* a);
};

#endif //DEMO_ENEMIES_H_