#pragma once
class Interrupt {
public:
	void interruptManager(void);
private:
	void backTurn(void);
	void goTurn(void);
	//先読みの範囲を更新
	void prefetchingInfo(void);
	//再度探索する
	void Research(void);
};