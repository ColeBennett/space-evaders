#include <iostream>
#include <string>
#include <fstream>

class LeaderBoardEntry
{
public:
	LeaderBoardEntry(float newScore = 0);
	~LeaderBoardEntry();
	float getScore() const;
	LeaderBoardEntry*  getNext() const;
	void setScore(float newTime);
	void setNext(LeaderBoardEntry* pNewNext);

private:
	float score;
	LeaderBoardEntry * pNext;
};