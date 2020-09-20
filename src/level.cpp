#include <iostream>
#include <GL/glut.h>
#include "level.h"
#include "paddle.h"
#include "ball.h"
#include "texto.h"
#include "speedbar.h"

void Level::createObjects(){
    // Cria o conjunto de tiles
    float TILE_WIDTH = (WINDOW_W - (T_COL*TILE_H_SPACE))/T_COL;
    float TILE_HEIGHT = TILE_WIDTH/2;
    float MAP_X = TILE_H_SPACE - 4;
    // std::cout << TILE_WIDTH << std::endl;
    float curX = MAP_X;
    float curY = WINDOW_H - MAP_OFFSET;
    for (int i = 0; i < T_ROW; i++){
        for (int j = 0; j < T_COL; j++){
            std::shared_ptr<Tile> t = \
                std::make_shared<Tile>(curX, curY,TILE_HEIGHT,TILE_WIDTH);
            this->tileMap.push_back(t);
            curX += TILE_H_SPACE;
            curX += TILE_WIDTH;
        }
        curY += TILE_HEIGHT+TILE_V_SPACE;
        curX = MAP_X;
    }

    // Cria o paddle
    this->paddle = std::make_shared<Paddle>(WINDOW_W/2 - PADDLE_WIDTH/2, PADDLE_Y);
    this->objects.push_back(this->paddle);

    // Cria a bola
    this->ball = std::make_shared<Ball>(WINDOW_W/2 - BALL_SIZE/2, WINDOW_W/4+40);

    // Cria a barra de velocidade
    this->speedbar = std::make_shared<SpeedBar>(WINDOW_W/2, 12.5);
    this->objects.push_back(this->speedbar);
}

void Level::createTextos(){
    // Cria placar
    this->placar = std::make_shared<Placar>();

    // Cria conta-vidas
    this->vidas = std::make_shared<Vidas>();
}

Level::Level(){
    this->score = 0;
    this->isPaused = true;
    this->gameStarted = false;
    this->createObjects();
    this->createTextos();
}

void Level::setMousePos(int _x, int _y){
    this->mouseX = _x;
    this->mouseY = _y;

    float meio = WINDOW_W/2;
    // Tolerância e velocidade para mouse à direita
    float tol = MOUSE_CENTER_TOLERANCE;
    float speed = PADDLE_MAX_SPEED*(mouseX - meio - tol)/(meio - tol);
    if (mouseX < meio){
        // Tolerância e velocidade para mouse à esquerda
        tol = -MOUSE_CENTER_TOLERANCE;
        speed = PADDLE_MAX_SPEED*(mouseX - meio - tol)/(meio - tol);
    }

    
    if (abs(mouseX - meio) <= MOUSE_CENTER_TOLERANCE){
        this->speedbar->setSpeed(0);
        this->paddle->setSpeed(0);
    }else{
        this->speedbar->setSpeed(speed);
        this->paddle->setSpeed(speed);
    }
}

bool Level::getIsPaused(){
    return this->isPaused;
}

void Level::changePauseState(){
    if (!gameStarted){
        ball->randomSpeed();
        gameStarted = true;
    }
    this->isPaused = !this->isPaused;
}

bool Level::ballCollides(GameObject& obj){
    if (ball->collides(obj)){
        ball->handleCollision(obj);
        if (obj.getNome() == "tile"){
            this->removeTile(obj);
            return true;
        }
        // std::cout << "Colide3" << "Obj: " << std::endl;
    }
    return false;
}

void Level::removeTile(GameObject& _tile){
    Tile& tile = dynamic_cast<Tile&>(_tile);
    std::vector<std::shared_ptr<Tile>>::iterator it1;
    int i = 0;
	for (it1 = tileMap.begin(); it1 != tileMap.end(); it1++) { 
		if (**it1 == tile){
            it1 = tileMap.erase(tileMap.begin() + i);
            break;
        }
        i++;
	}

}

void Level::draw(){
    std::vector<std::shared_ptr<GameObject>>::iterator it;
    for (it = textos.begin(); it != textos.end(); it++) { 
		(*it)->draw();
    }

    std::vector<std::shared_ptr<Tile>>::iterator it1;
	for (it1 = tileMap.begin(); it1 != tileMap.end(); it1++) { 
		(*it1)->draw();
	}

	for (it = objects.begin(); it != objects.end(); it++) { 
		(*it)->draw();
    }
    placar->draw();
    vidas->draw();
    ball->draw();

}

void Level::update(){
    //Collision check
    std::vector<std::shared_ptr<Tile>>::iterator it1;
	for (it1 = tileMap.begin(); it1 != tileMap.end(); it1++) { 
		if (ballCollides(**it1)){
            score += TILE_SCORE;
            placar->addScore(TILE_SCORE);
            break;
        }
	}
	std::vector<std::shared_ptr<GameObject>>::iterator it;
	for (it = objects.begin(); it != objects.end(); it++) { 
		ballCollides(**it);
    }

    // Detectar se bola não saiu dos limites
    if (ball->isOutOfBounds() and !this->isPaused){
        if (vidas->isLastVida()){
            
            vidas->addVida(-1);
            this->isPaused = true;
            std::cout << "Aqui1" << std::endl;
        }else{
            
            vidas->addVida(-1);
            this->isPaused = true;
            std::cout << "Aqui2" << std::endl;
        }
    }
}