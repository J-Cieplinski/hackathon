#pragma once
#include <cstddef>

constexpr size_t windowWidth = 1280;
constexpr size_t windowHeight = 720;
constexpr size_t sidesBoundries = windowWidth * 0.033;
constexpr size_t topBoundry = windowHeight * 0.03;

constexpr float ballSpeed{8.f};
constexpr int ballRadius{10};

constexpr float paddleSpeed{9.f};

constexpr float blockWidth{83.f};
constexpr float blockHeight{30.f};
constexpr int blocksSpacing{2};
constexpr int spaceFromTop{static_cast<int>(blockHeight + 10)};
constexpr int blocksCol{windowWidth / static_cast<int>(blockWidth) - 1};
constexpr int blocksRow{5};

constexpr int playerLives = 3;
constexpr int playerPoints = 0;

constexpr size_t gameOverX = 500;
constexpr size_t gameOverY = 80;

#include "Background.hpp"
#include "Ball.hpp"
#include "Brick.hpp"
#include "Entity.hpp"
#include "Game.hpp"
#include "GameOver.hpp"
#include "Paddle.hpp"
#include "Player.hpp"
