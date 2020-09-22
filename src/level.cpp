#include <iostream>
#include <GL/glut.h>
#include "level.h"
#include "paddle.h"
#include "ball.h"
#include "texto.h"
#include "speedbar.h"

void Level::createTiles(){
    std::srand(time(NULL));
    // Cria o conjunto de tiles a partir do canto superior esquerdo e descendo
    float height = TILE_WIDTH/TILE_H_W_RATIO;
    int numCols = std::rand()%(MAX_COL-MIN_COL) + MIN_COL;     // Entre 7 e 13 colunas
    int numRows = std::rand()%(MAX_ROW-MIN_ROW) + MIN_ROW;     // Entre 1 e 5 linhas
    numCols = (numCols % 2 == 0) ? (numCols + 1) : numCols;

    float initX = 0.5 * (WINDOW_W - (numCols * TILE_WIDTH) - ((numCols-1) * TILE_H_SPACE));
    float initY = WINDOW_H - MAP_OFFSET;

    int maxCor = std::rand()%5 + 2;

    float curX = initX;
    float curY = initY;
    for (int i = 0; i < numRows; i++){
        bool padraoLacuna = (std::rand()%2 + 1 == 1) ? true : false;
        bool padraoAltern = (std::rand()%2 + 1 == 1) ? true : false;
        
        // Duas cores para alternar
        int corAltern1 = std::rand()%(maxCor + 1);
        int corAltern2 = std::rand()%(maxCor + 1);
        int corSimples = std::rand()%(maxCor + 1);     //Se não vamos alternar
        
        bool flagLacuna = (std::rand()%2 + 1 == 1) ? true : false;
        bool flagAltern = (std::rand()%2 + 1 == 1) ? true : false;

        for (int j = 0; j < numCols; j++){
            if (padraoLacuna && flagLacuna){
                flagLacuna = !flagLacuna;   //Desativa para a próxima iteração
                curX += TILE_H_SPACE;
                curX += TILE_WIDTH;
                continue;
            }else{
                flagLacuna = !flagLacuna;   
            }

            Cores cor;
            // Descobrir que cor alternada colocar, se for o caso
            if (padraoAltern && flagAltern){
                cor = Cores(corAltern1);
                flagAltern = !flagAltern;
            }else{
                cor = Cores(corAltern2);
                flagAltern = !flagAltern;
            }

            // Descobrir a cor, se não estivermos alternando
            if (!padraoAltern){
                cor = Cores(corSimples);
            }

            std::shared_ptr<Tile> t = \
                std::make_shared<Tile>(curX, curY,height,TILE_WIDTH,cor);
            this->tileMap.push_back(t);
            curX += TILE_H_SPACE;
            curX += TILE_WIDTH;
        }
        curY -= height+TILE_V_SPACE;
        curX = initX;
    }
}

void Level::createObjects(){
    // Cria o paddle
    this->paddle = std::make_shared<Paddle>(WINDOW_W/2 - PADDLE_WIDTH/2, PADDLE_Y);
    this->objects.push_back(this->paddle);

    // Cria a bola
    this->ball = std::make_shared<Ball>(WINDOW_W/2 - BALL_SIZE/2, WINDOW_W/4+40);

    // Cria a barra de velocidade
    this->speedbar = std::make_shared<SpeedBar>(WINDOW_W/2, 12.5);
    this->objects.push_back(this->speedbar);

    // Cria os powerups (invisíveis, por enquanto)
    std::shared_ptr<PowerUp> p1 = std::make_shared<VidaPowerUp>(40,200);
    this->powerups.push_back(p1);
}

void Level::createTextos(int score = 0, int vidas = 3){
    // Cria placar
    this->placar = std::make_shared<Placar>(score);
    // Cria conta-vidas
    this->vidas = std::make_shared<Vidas>(vidas);

    // Cria display de informações
    std::shared_ptr<TextoLabel> p1 = std::make_shared<TextoLabel> \
            (WINDOW_W/2 + 30, WINDOW_W/4+60, "Bola.x", std::to_string(ball->x));
    this->textos.insert(std::pair<std::string, std::shared_ptr<TextoLabel>>("Bola.x",p1));
    p1 = std::make_shared<TextoLabel> \
        (WINDOW_W/2 + 30, WINDOW_W/4+40, "Bola.y", std::to_string(ball->y));
    this->textos.insert(std::pair<std::string, std::shared_ptr<TextoLabel>>("Bola.y",p1));
    p1 = std::make_shared<TextoLabel> \
        (WINDOW_W/2 + 30, WINDOW_W/4+20, "Bola.dx", std::to_string(ball->speedX));
    this->textos.insert(std::pair<std::string, std::shared_ptr<TextoLabel>>("Bola.dx",p1));
    p1 = std::make_shared<TextoLabel> \
        (WINDOW_W/2 + 30, WINDOW_W/4+0, "Bola.dy", std::to_string(ball->speedY));
    this->textos.insert(std::pair<std::string, std::shared_ptr<TextoLabel>>("Bola.dy",p1));
    p1 = std::make_shared<TextoLabel> \
        (WINDOW_W/2 - 250, WINDOW_W/4+60, "Paddle.x", std::to_string(paddle->x));
    this->textos.insert(std::pair<std::string, std::shared_ptr<TextoLabel>>("Paddle.x",p1));
    p1 = std::make_shared<TextoLabel> \
        (WINDOW_W/2 - 250, WINDOW_W/4+40, "Paddle.y", std::to_string(paddle->y));
    this->textos.insert(std::pair<std::string, std::shared_ptr<TextoLabel>>("Paddle.y",p1));
    p1 = std::make_shared<TextoLabel> \
        (WINDOW_W/2 - 250, WINDOW_W/4+20, "Paddle.dx", std::to_string(paddle->speed));
    this->textos.insert(std::pair<std::string, std::shared_ptr<TextoLabel>>("Paddle.dx",p1));
    p1 = std::make_shared<TextoLabel> \
        (WINDOW_W/2 - 250, WINDOW_W/4+0, "Qtd. tiles", std::to_string(tileMap.size()));
    this->textos.insert(std::pair<std::string, std::shared_ptr<TextoLabel>>("Qtd. tiles",p1));
}

Level::Level(){
    std::srand(time(NULL));
    this->score = 0;
    this->isPaused = true;
    this->gameStarted = false;
    this->displayInfo = false;
    this->displayInfoPause = false;
    this->gameOver = false;
    this->levelComplete = false;
    this->flagSpaceInvaders = (std::rand()%2 + 1 == 1) ? true : false;
    this->flagSpaceInvadersRight = true;
    this->flagPowerUpSpawned = false;
    this->createTiles();
    this->createObjects();
    this->createTextos();
}

Level::Level(Level& old){
    std::srand(time(NULL));
    this->score = old.score;
    this->isPaused = true;
    this->gameStarted = false;
    this->displayInfo = false;
    this->displayInfoPause = false;
    this->gameOver = false;
    this->levelComplete = false;
    this->flagSpaceInvaders = (std::rand()%2 + 1 == 1) ? true : false;
    this->flagSpaceInvadersRight = true;
    this->flagPowerUpSpawned = false;
    this->createTiles();
    this->createObjects();
    this->createTextos(old.placar->getPlacar(), old.vidas->getVidas());
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
    if (gameOver){
        exit(0);
    }else if (!gameStarted){
        ball->randomSpeed();
        gameStarted = true;
        this->isPaused = false;
    }else{
        this->isPaused = !this->isPaused;
    }
}

/*
1o clique: mostra informações e pausa (o botão de pause anda um passo)
2o clique: solta o jogo, ainda com as informações (o botão de pause funciona normal)
3o clique: retira as informações (jogo deve estar sem pausa, senão funciona como
o 2o clique)
*/
void Level::changeDisplayInfoState(){
    if(!isPaused and !displayInfo){
        displayInfo = true;
        displayInfoPause = true;
    }else if (isPaused and displayInfo){
        displayInfoPause = false;
        isPaused = false;
    }else{
        displayInfo = false;
        isPaused = false;
    }
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

void Level::spaceInvaders(){
    std::vector<std::shared_ptr<Tile>>::iterator it1;
    float rX = (rand()%2+1)/2;
    float offsetX = (rX >= 0.1) ? rX : 0.1;
    float rY = (rand()%2+1)/2;
    float offsetY = (rY >= 0.1) ? rY : 0.1;
    
    bool maxX = false;
    bool minX = false;
    bool minY = false;

	for (it1 = tileMap.begin(); it1 != tileMap.end(); it1++) {
        std::shared_ptr<Tile> t = (*it1);
        if (t->x + t->width + offsetX > WINDOW_W)
            maxX = true;
        else if (t->x - offsetX < 0)
            minX = true;
        if (t->y - offsetY <= MIN_MAP_Y)
            minY = true;
	}
    if (flagSpaceInvadersRight and maxX){
        // Batemos no canto direito da tela
        flagSpaceInvadersRight = !flagSpaceInvadersRight;
    }else if (!flagSpaceInvadersRight and minX){
        // Batemos no canto esquerdo da tela
        flagSpaceInvadersRight = !flagSpaceInvadersRight;
    }

    for (it1 = tileMap.begin(); it1 != tileMap.end(); it1++) {
        std::shared_ptr<Tile> t = (*it1);
        if (flagSpaceInvadersRight){
            t->x += offsetX;
        }else{
            t->x -= offsetX;
        }
        if ((maxX || minX) && !minY){
            t->y -= offsetY;
        }
	}


}

void Level::draw(){
    if (displayInfo){
            std::map<std::string, std::shared_ptr<TextoLabel>>::iterator it;
        for (it = textos.begin(); it != textos.end(); it++) { 
            it->second->draw();
        }
        if (displayInfoPause){
            isPaused = true;
        }
    }
    if (gameOver){
        std::string gameOverStr = "GAME OVER";
        Texto t(WINDOW_W/2 - gameOverStr.size()*5, WINDOW_W/4+40, gameOverStr);
        t.draw();
    }
    if (levelComplete){
        std::string completeStr = "PARABENS!";
        Texto t(WINDOW_W/2 - completeStr.size()*5, WINDOW_W/4+40, completeStr);
        t.draw();
        isPaused = true;
    }


    if (flagSpaceInvaders){
        this->spaceInvaders();
    }
    
    std::vector<std::shared_ptr<PowerUp>>::iterator it0;
	for (it0 = powerups.begin(); it0 != powerups.end(); it0++) {
        if ((*it0)->isInPlay()){
            (*it0)->draw();
        }
	}



    std::vector<std::shared_ptr<Tile>>::iterator it1;
	for (it1 = tileMap.begin(); it1 != tileMap.end(); it1++) { 
		(*it1)->draw();
	}

    std::vector<std::shared_ptr<GameObject>>::iterator it2;
	for (it2 = objects.begin(); it2 != objects.end(); it2++) { 
		(*it2)->draw();
    }

    placar->draw();
    vidas->draw();
    ball->draw();
}

void Level::spawnPowerUp(float x, float y){
    bool spawn = (std::rand()%100 + 1 <= POWERUP_CHANCE*100) ? true : false;
    if (spawn && !flagPowerUpSpawned){
        std::vector<std::shared_ptr<PowerUp>>::iterator it = powerups.begin();
        std::advance(it, std::rand() % powerups.size());
        (*it)->spawnAt(x + PADDLE_WIDTH/2, y);
        flagPowerUpSpawned = !flagPowerUpSpawned;
    }
}

void Level::update(){
    //Collision check
    std::vector<std::shared_ptr<Tile>>::iterator it1;
	for (it1 = tileMap.begin(); it1 != tileMap.end(); it1++) { 
		if (ballCollides(**it1)){
            score += TILE_SCORE;
            placar->addScore(TILE_SCORE);
            this->spawnPowerUp((*it1)->x, (*it1)->y);
            // isPaused = true;
            break;
        }
	}
	std::vector<std::shared_ptr<GameObject>>::iterator it;
	for (it = objects.begin(); it != objects.end(); it++) { 
		ballCollides(**it);
    }
    if (tileMap.size() == 0){
        levelComplete = true;
    }

    // Movimentar o powerup
    std::vector<std::shared_ptr<PowerUp>>::iterator it0;
	for (it0 = powerups.begin(); it0 != powerups.end(); it0++) {
        if ((*it0)->isInPlay()){
            (*it0)->update();
        }
	}


    // Detectar se bola não saiu dos limites
    if (ball->isOutOfBounds() && !gameOver){
        if (vidas->isLastVida()){
            vidas->addVida(-1);
            this->gameStarted = false;
            this->ball = std::make_shared<Ball>(-10, -10);
            gameOver = true;
        }else{
            vidas->addVida(-1);
            this->gameStarted = false;
            this->ball = std::make_shared<Ball>(WINDOW_W/2 - BALL_SIZE/2, WINDOW_W/4+40);
        }
    }

    // Update nos textos do display
    this->textos["Bola.x"]->updateText(std::to_string(ball->x));
    this->textos["Bola.y"]->updateText(std::to_string(ball->y));
    this->textos["Bola.dx"]->updateText(std::to_string(ball->speedX));
    this->textos["Bola.dy"]->updateText(std::to_string(ball->speedY));
    this->textos["Paddle.x"]->updateText(std::to_string(paddle->x));
    this->textos["Paddle.y"]->updateText(std::to_string(paddle->y));
    this->textos["Paddle.dx"]->updateText(std::to_string(paddle->speed));
    this->textos["Qtd. tiles"]->updateText(std::to_string(tileMap.size()));
}

void Level::debugComplete(){
    std::vector<std::shared_ptr<Tile>> newMap;
    this->tileMap = newMap;
}

bool Level::isCompleted(){
    return this->levelComplete;
}