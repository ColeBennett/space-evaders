#include "LeaderBoardEntry.h"
#include <fstream>
#include <stdlib.h>

class LeaderBoard
{
public:
	LeaderBoard();
	~LeaderBoard();
	void insertInOrder(float score);
	void printLeaderBoard();
	void writeCSV();
	LeaderBoardEntry *& getHeadPtr();
private:
	LeaderBoardEntry* pHead;
	std::fstream fileStream;
};