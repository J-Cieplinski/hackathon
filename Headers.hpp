#pragma once
#include <cstddef>

constexpr size_t windowWidth = 1280;
constexpr size_t windowHeight = 720;

constexpr float ballSpeed{8.f};
constexpr int ballRadius{10};

constexpr float paddleSpeed{7.f};

constexpr float blockWidth{83.f};
constexpr float blockHeight{30.f};
constexpr int blocksSpacing{2};
constexpr int spaceFromTop{100};
constexpr int blocksCol{15};
constexpr int blocksRow{5};

#include "Entity.hpp"
#include "Background.hpp"
#include "Ball.hpp"
#include "Brick.hpp"
#include "Game.hpp"
#include "Paddle.hpp"