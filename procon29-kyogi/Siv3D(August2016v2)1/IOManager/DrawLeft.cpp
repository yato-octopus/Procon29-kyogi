#include "DrawLeft.h"

void DrawLeft::drawLeftManager(void)
{
	//Mapの表示
	drawMap();
}

void DrawLeft::drawMap(void) {
	map = map->getMap();

	//枠
	const Rect flame(0,0, LEFT_FLAME_VERTICAL, LEFT_FLAME_WIDTH);

	//vertical,widthで二重ループを作成
	for (int i = 0; i < map->Vertical;i++) {
		for (int j = 0; j < map->Width; j++) {
			//中身がnullじゃないならば
			switch (map->board[i][j].State) {
			case 0 :
				//draw non map
				break;
			case 1 :
				//darw frined map
				break;
			case 2 :
				//draw enemy map
				break;
			default:
				break;

			}
		}
	}
}

void DrawLeft::drawAgent(void)
{
	//Mapに重ねてAgent位置の表示(両方)
}

void DrawLeft::drawTilePoint(void)
{
	//TilePointをMapに重ねる形で表示
}

void DrawLeft::drawMovableTile(void)
{
	//自分のエージェントが移動出来る場所の表示
}