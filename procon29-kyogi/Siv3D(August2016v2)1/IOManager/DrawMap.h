#pragma once
class DrawMap {
public:
	void draw(void);
private:
	void drawMap(void);
	void drawAgent(void);
	void drawTilePoint(void);
	void drawScore(void);
	void drawMovableTile(void);
	void drawTurn(void);
};