#pragma once
class Setting {
public:
	static Setting* getSetting();
	//総当たりを実行するかどうか1か0を保持
	int bruteForce = 0;
private:
	static Setting* InsSetting;
};


