#include "DrawLeft.h"
#define MASU_SIZE 45
#define MAX_MAP_SIZE 12
#define AGENTS 4


DrawLeft::DrawLeft()
{
	font(15);
	//agent�̉摜�����[�h
	//Texture fri_ob(L"image/friend.png");
	//Texture ene_ob(L"image/enemy.png");
	//fri = fri_ob;
	//ene = ene_ob;
}

void DrawLeft::drawLeftManager(void)
{
	Setting *setting;
	setting = setting->getSetting();

	//Map�̕\��
	drawMap();
	drawTilePoint();
	if (setting->turnFlag == true) {
		for (int i = 0; i < AGENTS; i++) {
			drawBestTile(i);
		}
	}
	drawAgent();
}

void DrawLeft::drawMap(void) {
	Map * map;
	map = map->getMap();

	//�}�X�̕\�����W�̕⏕
	const int pos_sup = MASU_SIZE + 5;

	//�}�b�v�̃^�C����\���i��d���[�v�ŏc�����Ǘ��j
	for (int i = 0; i < 12;i++) {
		for (int j = 0; j < 12; j++) {
			
			//State�̏�Ԃɑ΂��ĕ\������}�X�̕ύX
			switch (map->board[i][j].Status) {
			case Masu::Non:
				//draw non map
				Rect(j * pos_sup + 5 , i * pos_sup + 5 ,MASU_SIZE ,MASU_SIZE).draw(Palette::Gray);
				break;
			case Masu::FriendTile :
				//draw frined map
				Rect(j * pos_sup + 5, i * pos_sup + 5, MASU_SIZE, MASU_SIZE).draw(Palette::Skyblue);
				break;
			case Masu::EnemyTile :
				//draw enemy map
				Rect(j * pos_sup + 5, i * pos_sup + 5, MASU_SIZE, MASU_SIZE).draw(Palette::Lightpink);
				break;
			case Masu::Other :
				Rect(j * pos_sup + 5, i * pos_sup + 5, MASU_SIZE, MASU_SIZE).draw(Palette::Black);
				break;
			default:
				break;

			}
		}
	}

	//�^�C���̘g��\��
	for (int i = 0; i <= MAX_MAP_SIZE; i++) {
		//�c���C���̕\��
		Line(2.5, 2.5 + i * pos_sup , MAX_MAP_SIZE * pos_sup, 2.5 + i * pos_sup).draw(5 , Palette::Black);
		//�c���C���̕\��
		Line(2.5 + i * pos_sup, 2.5 , 2.5 + i * pos_sup, MAX_MAP_SIZE * pos_sup).draw(5 , Palette::Black);
	}
	//System::Update();
}

void DrawLeft::drawAgent(void)
{
	//Map�ɏd�˂�Agent�ʒu�̕\��(����)
	Map *map;
	map = map->getMap();
	int pos_sup = MASU_SIZE + 5;
	//picture agent
	static Texture fri1(L"image/friend1.png");
	static Texture fri2(L"image/friend2.png");
	static Texture ene1(L"image/enemy1.png");
	static Texture ene2(L"image/enemy2.png");

	for (int i = 0; i < map->agents.size(); i++) {
		switch (map->agents[i].Status) {
		case Agent::friend1:
			fri1.draw(map->agents[i].position.second * pos_sup + 5, map->agents[i].position.first * pos_sup + 5);
			break;
		case Agent::friend2:
			//friend �̏ꍇ
			fri2.draw(map->agents[i].position.second * pos_sup + 5 ,map->agents[i].position.first * pos_sup + 5);
			break;
		case Agent::enemy1 :
			ene1.draw(map->agents[i].position.second * pos_sup + 5, map->agents[i].position.first * pos_sup + 5);
			break;
		case Agent::enemy2 :
			//enemy�̏ꍇ
			ene2.draw(map->agents[i].position.second * pos_sup + 5 , map->agents[i].position.first * pos_sup + 5);
			break;
		default:
			break;
		}
	}
}

void DrawLeft::drawTilePoint(void)
{
	//TilePoint��Map�ɏd�˂�`�ŕ\��
	Map *map;
	map = map->getMap();

	int pos_sup = MASU_SIZE + 5;

	for (int i = 0; i < map->Vertical; i++) {
		for (int j = 0; j < map->Width; j++) {
			//Map�O�̃^�C������Ȃ��Ȃ�True
			//Status Other : 3
			if (map->board[i][j].Status != Masu::Other) {
				//�^�C���|�C���g��\��
				font(map->board[i][j].TilePoint).draw(10 + pos_sup * j, 10 + pos_sup * i, Palette::Yellow);
			}
		}
	}
}

void DrawLeft::drawMovableTile(void)
{
	//�����̃G�[�W�F���g���ړ��o����ꏊ�̕\��
}

//�G�[�W�F���g�̎��̌��n��\��
void DrawLeft::drawNextPosition(void)
{
	
}

//�����G�[�W�F���g�̍őP���\������
void DrawLeft::drawBestTile(int AgentNum)
{
	Map *map;
	map = map->getMap();

	int pos_sup = MASU_SIZE + 5;
	//picture agent
	static Texture best_fri1(L"image/best_friend1.png");
	static Texture best_fri2(L"image/best_friend2.png");
	static Texture best_ene1(L"image/best_enemy1.png");
	static Texture best_ene2(L"image/best_enemy2.png");

	switch (AgentNum) {
	case 0 :
		best_fri1.draw(map->agents[AgentNum].nextPosition.second * pos_sup + 5, map->agents[AgentNum].nextPosition.first * pos_sup + 5);
		break;
	case 1:
		best_fri2.draw(map->agents[AgentNum].nextPosition.second * pos_sup + 5, map->agents[AgentNum].nextPosition.first * pos_sup + 5);
		break;
	case 2:
		best_ene1.draw(map->agents[AgentNum].nextPosition.second * pos_sup + 5, map->agents[AgentNum].nextPosition.first * pos_sup + 5);
		break;
	case 3:
		best_ene1.draw(map->agents[AgentNum].nextPosition.second * pos_sup + 5, map->agents[AgentNum].nextPosition.first * pos_sup + 5);
		break;
	default:
		break;
	}
}
