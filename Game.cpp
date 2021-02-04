#include "Game.h"

void goal_Animation(Team team);
void win_Animation(Team team);

Game::Game(Strip stripS04, Strip stripBVB) {
    _score[S04] = 0;
    _score[BVB] = 0;
    _colors[S04] = COLOR_S04;
    _colors[BVB] = COLOR_BVB;
    _strips[S04] = stripS04;
    _strips[BVB] = stripBVB;
    _strips[S04].begin();
    _strips[BVB].begin();
}

void Game::score(Team team) {
    _score[team]++;

    if(_score[team] < MAX_SCORE) {
        goal_Animation(team);
    } else {
        win_Animation(team);
        delay(2000);
        reset();
    }
}


void Game::reset() {
    _score[S04] = 0;
    _score[BVB] = 0;
    animator_play(_strips[S04], AnimationType::READY, generate_animation_info(Team::S04));
    animator_play(_strips[BVB], AnimationType::READY, generate_animation_info(Team::BVB));
    animator_play(_strips[S04], AnimationType::SCORE_FAST, generate_animation_info(Team::S04));
    animator_play(_strips[BVB], AnimationType::SCORE_FAST, generate_animation_info(Team::BVB));
}

void Game::goal_Animation(Team team) {
    AnimationInfo info = generate_animation_info(team);

    animator_playRand(_strips[team], info);
    delay(100);
    animator_play(_strips[team], AnimationType::SCORE_SLOW, info);
    delay(100);
    animator_play(_strips[team], AnimationType::READY, info);
    animator_play(_strips[team], AnimationType::SCORE_FAST, info);
}

void Game::win_Animation(Team team) {
    AnimationInfo info = generate_animation_info(team);

    animator_playRand(_strips[team], info);
    delay(500);
    animator_play(_strips[team], AnimationType::SCORE_SLOW, info);
}

AnimationInfo Game::generate_animation_info(Team team) {
    AnimationInfo info;
    info.color = _colors[team];
    info.values[0] = _score[team];
    return info;
}
