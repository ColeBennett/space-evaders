#include <iostream>
#include <string>
#include <fstream>

class LeaderboardEntry
{
public:
	LeaderboardEntry(float newScore = 0);
	~LeaderboardEntry();
	float getScore() const;
	LeaderboardEntry*  getNext() const;
	void setScore(float newTime);
	void setNext(LeaderboardEntry* pNewNext);

private:
	float score;
	LeaderboardEntry * pNext;
};