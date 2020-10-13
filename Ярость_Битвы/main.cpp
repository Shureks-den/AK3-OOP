#include <iostream>
#include <algorithm>
class BattleFury {
public:
    BattleFury(int ennum, int dmg, int clv) {
        army = new  int[ennum];
        damage = dmg;
        cleave = clv;
        unit_n = ennum;
    }
    void armyhp() {
        for (int i = 0; i < unit_n; i++) {
            scanf("%10d", &army[i]);
        }
    }
    int battle() {
        std::sort(army, army + this->unit_n, std::greater<int>());
        int axe_swing = 0;
        while (army[0] > 0) {
            dmg();
            insert();
            axe_swing++;
        }
    return axe_swing;
    }

private:
     int *army;
    unsigned int damage;
    unsigned int cleave;
    unsigned int unit_n;
    void dmg() {
        army[0] -= damage;
        int i = 1;
        while (army[i] > 0 && i < unit_n) {
            army[i] -= cleave;
            i++;
        }
    }
    void insert() {
        int temp;
        int i = 0;
        while (army[i] < army[i + 1] && i< unit_n-1) {
            temp = army[i];
            army[i] = army[i + 1];
            army[i + 1] = temp;
            i++;
        }
    }
};

int main() {
    unsigned int ennum;
    unsigned int dmg;
    unsigned int clv;
    unsigned int axe;
    scanf("%6u", &ennum);
    scanf("%10u", &dmg);
    scanf("%10u", &clv);
    printf("%10u", clv -4);
    BattleFury *Magina = new BattleFury(ennum, dmg, clv);
    Magina->armyhp();
    axe = Magina->battle();
    printf("%10d", axe);
    return 0;
}
