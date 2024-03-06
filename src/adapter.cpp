#include<iostream>

using namespace std;

// 目标接口，客户端希望使用的接口
class MediaPlayer {
	public:
		virtual void play() const = 0;
};

// 具体的英文播放器类
class EnglishMediaPlayer : public MediaPlayer {
	public:
		void play() const override {
			cout << "Playing English song" << endl;
		}
};

// 中文播放器类，接口与目标接口不一致
class ChineseMediaPlayer {
	public:
		void playChinese() const {
			cout << "播放中文歌曲" << endl;
		}
};

// 适配器类，将中文播放器适配成目标接口
class ChineseMediaPlayerAdapter : public MediaPlayer {
	private:
		ChineseMediaPlayer chineseMediaPlayer;
	public:
		void play() const override {
			chineseMediaPlayer.playChinese();
		}
};

int main() {
	// 客户端使用目标接口
	MediaPlayer* player = new EnglishMediaPlayer();
	player->play();

	// 使用适配器来适配中文播放器
	MediaPlayer* chinesePlayer = new ChineseMediaPlayerAdapter();
	chinesePlayer->play();
	delete player;
	delete chinesePlayer;
	return 0;
}

