#ifndef GameState_h
#define GameState_h

class GameState {

public:

	GameState(char * init_stateName);
	~GameState();

	virtual void Update() = 0;
	virtual void Render() = 0;

private:

	char * stateName;

};

#endif