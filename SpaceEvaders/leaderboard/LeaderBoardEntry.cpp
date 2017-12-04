#include "LeaderBoardEntry.h"

LeaderBoardEntry::LeaderBoardEntry(float newScore) {
	score = newScore;
	pNext = nullptr;
}

LeaderBoardEntry::~LeaderBoardEntry() {

}

float LeaderBoardEntry::getScore() const {
	return score;
}

LeaderBoardEntry *  LeaderBoardEntry::getNext() const {
	return pNext;
}

void LeaderBoardEntry::setScore(float newScore) {
	score = newScore;
}

void LeaderBoardEntry::setNext(LeaderBoardEntry * pNewNext) {
	pNext = pNewNext;
}