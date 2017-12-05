#include "LeaderboardEntry.h"
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
	LeaderboardEntry *& getHeadPtr();
private:
	LeaderboardEntry* pHead;
	std::fstream fileStream;
};