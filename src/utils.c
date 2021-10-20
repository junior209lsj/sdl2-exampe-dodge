/**
 @file      utils.c
 @brief     액션 수행에 필요한 부가적 계산을 수행하는 함수 정의
 @author    이성재 (seongjae.lee.1118@gmail.com)
*/
#include "utils.h"

int CheckCollisionWall(Entity *object) {

    if (object->pos.x < 0 || object->pos.x + object->pos.w > SCREEN_WIDTH ||
        object->pos.y < 0 || object->pos.y + object->pos.h > SCREEN_HEIGHT) {
        return 1;
    } else {
        return 0;
    }
}

int CheckCollisionObjects(Entity *object_a, Entity *object_b) {

    if (SDL_HasIntersection(&(object_a->pos), &(object_b->pos))) {
        return 1;
    } else {
        return 0;
    }
}

void RandSpawnBullet(Entity *object) {
    int side = RandInt(0, 4);
    int lhs_width = SCREEN_WIDTH / 8;
    int rhs_width = 7 * (SCREEN_WIDTH / 8);
    int lhs_height = SCREEN_HEIGHT / 8;
    int rhs_height = 7 * (SCREEN_HEIGHT / 8);
    switch (side) {
        case 0:
            object->pos.x = RandInt(0, lhs_width - BULLET_WIDTH);
            object->pos.y = RandInt(0, lhs_height - BULLET_HEIGHT);
            break;
        case 1:
            object->pos.x = RandInt(rhs_width, SCREEN_WIDTH - BULLET_WIDTH);
            object->pos.y = RandInt(0, lhs_height - BULLET_HEIGHT);
            break;
        case 2:
            object->pos.x = RandInt(0, lhs_width - BULLET_WIDTH);
            object->pos.y = RandInt(rhs_height, SCREEN_HEIGHT - BULLET_HEIGHT);
            break;
        case 3:
            object->pos.x = RandInt(rhs_width, SCREEN_WIDTH - BULLET_WIDTH);
            object->pos.y = RandInt(rhs_height, SCREEN_HEIGHT - BULLET_HEIGHT);
            break;
        default:
            break;
    }
    double direction_x = player.pos.x - object->pos.x;
    double direction_y = player.pos.y - object->pos.y;
    double direction = acos(direction_x / sqrt(direction_x * direction_x +
                                               direction_y * direction_y));
    object->theta =
        RandDouble(direction - (M_PI / 10.0), (direction + (M_PI / 10.0)));
    
    return;
}

int RandInt(int min_val, int max_val) {
    if (min_val >= max_val) {
        return 0;
    } else {
        int ranval;
        ranval = rand() % (max_val - min_val);
        ranval += min_val;

        return ranval;
    }
}

double RandDouble(double min_val, double max_val) {

    if (min_val >= max_val) {
        return 0.0;
    } else {
        double ranval;
        ranval = (double)rand() / (double)RAND_MAX;
        ranval = ranval * (max_val - min_val) + min_val;

        return ranval;
    }
}