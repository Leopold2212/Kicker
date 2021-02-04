#ifndef GAME_H_
#define GAME_H_

#include "Animator.h"

#define MAX_SCORE 10

enum Team { S04, BVB };

#define COLOR_S04 Strip::Color(0,0,255);
#define COLOR_BVB Strip::Color(255,191,0);

class Game {
    private:
        int _score[2];
        Strip _strips[2];
        uint32_t _colors[2];
        
        void goal_Animation(Team team);
        void win_Animation(Team team);
        AnimationInfo generate_animation_info(Team team);
    public:
        Game(Strip stripS04, Strip stripBVB);

        void score(Team team);
        void reset();
};

#endif
